#ifndef GENERATEPROGRAM_H
#define GENERATEPROGRAM_H

#include "ClassUnit.hpp"
#include "MethodUnit.hpp"
#include "PrintOperatorUnit.hpp"

std::string generateProgram() {
    ClassUnit myClass( "MyClass" );
    myClass.add(
                std::make_shared<MethodUnit>("testFunc1", "void", 0),
                ClassUnit::PUBLIC
                );
    myClass.add(
                std::make_shared<MethodUnit>("testFunc2", "void", MethodUnit::STATIC),
                ClassUnit::PRIVATE
                );
    myClass.add(
                std::make_shared<MethodUnit>("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST),
                ClassUnit::PUBLIC
                );
    auto method = std::make_shared<MethodUnit>("testFunc4", "void", MethodUnit::STATIC);
    method->add(std::make_shared< PrintOperatorUnit >(R"(Hello, world!\n)"));
    myClass.add(method, ClassUnit::PROTECTED);
    return myClass.compile();
}

#endif
