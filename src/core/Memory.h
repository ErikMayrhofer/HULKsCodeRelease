//
// Created by obyoxar on 20/11/18.
//

#ifndef DUCKBURG_MEMORY_H
#define DUCKBURG_MEMORY_H


#include <boost/variant/variant.hpp>
#include <unordered_map>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/transform.hpp>
#include <boost/variant/get.hpp>
#include <boost/parameter/match.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include "../hightools/BetterClass.h"
#include <string>

using std::string;

#define MEMORY_TYPES_INTERNAL (int)(double)(string)(long)
#define POSSIBLE_TYPES BOOST_PP_SEQ_ENUM(MEMORY_TYPES_INTERNAL)
#define TYPE_TO_STRING_OP(s, data, elem) BOOST_PP_STRINGIZE(elem)
#define TYPE_STRING_ARR BOOST_PP_SEQ_TRANSFORM(TYPE_TO_STRING_OP, _, MEMORY_TYPES_INTERNAL)
#define TYPE_ARR BOOST_PP_SEQ_ENUM(TYPE_STRING_ARR)

#define TYPE_ACCESSOR(type) type get##type(const std::string& key) const {return boost::get<type>(_vals.at(key));}

#define NUM_REGISTERS 10

class Memory {
    SINGLETON(Memory)
public:

    template<typename T>
    void write(const std::string &key, T data){
        _vals[key] = data;
    }
    template<typename T>
    T get(const std::string& key) const{
        return boost::get<T>(_vals.at(key));
    }

    std::string getType(const std::string& key) const;
    std::string getTypeNameFromId(int id) const;

    void* readRegister(int index);
    void writeRegister(int index, void* data);

    void debugMemory();

private:
    std::unordered_map<std::string, boost::variant<POSSIBLE_TYPES>> _vals;
    void * _registers[NUM_REGISTERS];

    std::string _types[BOOST_PP_SEQ_SIZE(TYPE_STRING_ARR)] = {
        TYPE_ARR
    };
};

#undef TYPE_ARR
#undef TYPE_STRING_ARR
#undef TYPE_TO_STRING_OP
#undef POSSIBLE_TYPES
#undef MEMORY_TYPES_INTERNAL

#endif //DUCKBURG_MEMORY_H
