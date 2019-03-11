//
// Created by ZekReshi on 06.11.2018.
//

#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include "RemoteEngine.h"
#include "../hightools/Dyllo.h"
#include <boost/property_tree/json_parser.hpp>
#include "../core/Logger.h"
#include "../hightools/BetterClass.h"

#define LOG_TAG LOGGER(RemoteEngine)

using boost::asio::ip::tcp;

bool RemoteEngine::isRunning() {
    return this->_isRunning;
}

void RemoteEngine::onLoad() {
    Brain::getInstance()->addDispatcher(INTENTID_ON_BRAIN_TICK, BINDTHIS(RemoteEngine::issueIntent));
    Brain::getInstance()->addDispatcher(INTENTID_ON_BRAIN_RUN, BINDTHIS(RemoteEngine::onRun));
}

void RemoteEngine::onRun(void*) {
    std::thread serverThread(&RemoteEngine::startServer, this);
    serverThread.detach();
}

void RemoteEngine::startServer() {
    boost::asio::io_service io_service;
    auto port = this->config->get<unsigned short>("PORT",8081);
    LFINFO("Opening Server on Port: " << port);
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), port));
    LFINFO("IsRunning: " << isRunning());
    this->_isRunning = true;
    while (!Brain::getInstance()->isStopped())
    {
        tcp::socket socket(io_service);
        acceptor.accept(socket);
        boost::system::error_code ignored_error;
        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, '\n', ignored_error);
        std::istream is(&buffer);
        boost::property_tree::ptree root;
        boost::property_tree::read_json(is, root);
        std::string id = root.get<std::string>("id");
        std::string data = root.get<std::string>("data");
        int delay = root.get<int>("delay");
        Intent* intent = new Intent(id, const_cast<char*>(data.c_str()), static_cast<unsigned int>(delay));
        intents.push(intent);
        socket.close();
    }
    acceptor.close();
    this->_isRunning = false;
    LINFO("Closed thread successfully");
}

void RemoteEngine::issueIntent(void *) {
    if (!intents.empty()) {
        Intent* qIntent;
        intents.pop(qIntent);
        Intent intent = *qIntent;
        delete qIntent;
        intent.issue();
    }
}

const char *RemoteEngine::getName() {
    return "RemoteEngine";
}

unsigned int RemoteEngine::getEngineBaseVersion() {
    return ENGINE_BASE_VERSION;
}

DL_CLASS_PUBLISH(RemoteEngine)