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

#endif
