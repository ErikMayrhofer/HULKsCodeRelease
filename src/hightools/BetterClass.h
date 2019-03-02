//
// Created by obyoxar on 17.09.18.
//

#ifndef DUCKBURG_BETTERCLASS_H
#define DUCKBURG_BETTERCLASS_H

#define UNUSED __attribute__((unused))

#define SINGLETON_FIELD_NAME(classname) __singleton_the##classname##Instance
#define SINGLETON(classname) \
public: \
static void setInstance(classname* theNewInstance){SINGLETON_FIELD_NAME(classname) = theNewInstance; } \
static classname* getInstance(){return SINGLETON_FIELD_NAME(classname); } \
static void setInstanceToNew(){delete SINGLETON_FIELD_NAME(classname);setInstance(getNewInstance());} \
static classname* getNewInstance() noexcept{ return new classname(); } \
classname(classname const &) = delete; \
void operator=(classname const &) = delete; \
private: \
classname() = default; \
static classname* SINGLETON_FIELD_NAME(classname);

#define IMPLEMENT_SINGLETON(classname) classname* classname::SINGLETON_FIELD_NAME(classname) = classname::getNewInstance();

#endif //DUCKBURG_BETTERCLASS_H
