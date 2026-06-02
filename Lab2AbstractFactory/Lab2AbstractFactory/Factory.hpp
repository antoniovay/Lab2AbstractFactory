#ifndef FACTORY_H
#define FACTORY_H

#include "CPPClassUnit.hpp"
#include "CPPMethodUnit.hpp"
#include "CPPPrintOperatorUnit.hpp"

#include "JavaClassUnit.hpp"
#include "JavaMethodUnit.hpp"
#include "JavaPrintOperatorUnit.hpp"

#include "CSHClassUnit.hpp"
#include "CSHMethodUnit.hpp"
#include "CSHPrintOperatorUnit.hpp"

class Factory {
public:
    virtual std::shared_ptr<ClassUnit> createClass(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) = 0;
};


class CPPFactory : public Factory {
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) override {
        return std::make_shared<CPPClassUnit>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<CPPMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override {
        return std::make_shared<CPPPrintOperatorUnit>(text);
    }
};


class JavaFactory : public Factory {
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) override {
        return std::make_shared<JavaClassUnit>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};


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
