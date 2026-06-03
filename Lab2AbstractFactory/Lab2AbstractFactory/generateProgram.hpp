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
                factory->createMethod("testFunc2", "void", 1),
                ClassUnit::PRIVATE
                );
    myClass->add(
                factory->createMethod("testFunc3", "void", (1 << 1) | (1 << 2)),
                ClassUnit::PUBLIC
                );
    auto method = factory->createMethod("testFunc4", "void", 1);
    method->add(factory->createPrintOperator(R"(Hello, world!\n)"), 0);
    myClass->add(method, 1);
    return myClass->compile();
}

#endif
