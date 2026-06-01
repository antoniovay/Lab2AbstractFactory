#ifndef CSHFACTORY_H
#define CSHFACTORY_H

#include "Factory.hpp"

class CSHFactory : public Factory {
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) override {
        return std::make_shared<CSHClassUnit>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<CSHMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override {
        return std::make_shared<CSHPrintOperatorUnit>(text);
    }
};

#endif
