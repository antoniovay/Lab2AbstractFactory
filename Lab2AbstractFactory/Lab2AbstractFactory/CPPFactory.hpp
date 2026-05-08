#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "CPPClassUnit.hpp"
#include "CPPMethodUnit.hpp"
#include "CPPPrintOperatorUnit.hpp"

class CPPFactory : public Factory {
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) override {
        return std::make_shared<CPPClassUnit>(name);
    };
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<CPPMethodUnit>(name, returnType, flags);
    };
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override {
        return std::make_shared<CPPPrintOperatorUnit>(text);
    };
};

#endif
