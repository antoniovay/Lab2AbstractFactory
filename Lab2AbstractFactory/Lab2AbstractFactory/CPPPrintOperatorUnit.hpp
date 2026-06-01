#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H

#include "PrintOperatorUnit.hpp"

class CPPPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit CPPPrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text)
    {}
    
    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif
