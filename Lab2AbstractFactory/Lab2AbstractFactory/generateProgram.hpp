#ifndef GENERATEPROGRAM_H
#define GENERATEPROGRAM_H

#include "Factory.hpp"

std::string generateProgram(Factory *factory) {
    std::shared_ptr<ClassUnit> myClass = factory->createClass("MyClass");

    myClass->add(
                factory->createMethod("testFunc1", "void", 0),
                ClassUnit::PUBLIC
                );
    myClass->add(
                factory->createMethod("testFunc2", "void", MethodUnit::STATIC),
                ClassUnit::PRIVATE
                );
    myClass->add(
                factory->createMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST),
                ClassUnit::PUBLIC
                );
    auto method = factory->createMethod("testFunc4", "void", MethodUnit::STATIC);
    method->add(factory->createPrintOperator(R"(Hello, world!\n)"));
    myClass->add(method, ClassUnit::PROTECTED);
    return myClass->compile();
}

#endif
