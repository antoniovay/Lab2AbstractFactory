#ifndef CSHPRINTOPERATORUNIT_H
#define CSHPRINTOPERATORUNIT_H

#include "PrintOperatorUnit.hpp"

class CSHPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit CSHPrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text)
    {}
    
    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

#endif
