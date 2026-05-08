#ifndef JavaFACTORY_H
#define JavaFACTORY_H

#include "JavaClassUnit.hpp"
#include "JavaMethodUnit.hpp"
#include "JavaPrintOperatorUnit.hpp"

class JavaFactory : public Factory {
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) override {
        return std::make_shared<JavaClassUnit>(name);
    };
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    };
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    };
};

#endif
