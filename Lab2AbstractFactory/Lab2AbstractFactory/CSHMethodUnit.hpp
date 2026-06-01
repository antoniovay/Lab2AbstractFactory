#ifndef CSHMETHODUNIT_H
#define CSHMETHODUNIT_H

#include <vector>

#include "MethodUnit.hpp"

class CSHMethodUnit : public Unit {
public:
    enum Modifier : Flags {
        STATIC = 1,
        VIRTUAL = 1 << 1,
        ABSTRACT = 1 << 2,
        SEALED = 1 << 3,
        READONLY = 1 << 4,
        CONST = 1 << 5
    };
    
public:
    CSHMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
        MethodUnit(name, returnType, flags)
    {}
    
public:
    void add(const std::shared_ptr<Unit>& unit, Flags /* flags */ = 0) override {
        m_body.push_back(unit);
    }
    
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level);
        
        if (m_flags & ABSTRACT)
            result += "abstract ";
        if ((m_flags & STATIC) && !(m_flags & ABSTRACT))
            result += "static ";
        else if (m_flags & VIRTUAL)
            result += "final ";
        if ((m_flags & SEALED) && !(m_flags & ABSTRACT))
            result += "sealed ";
        if (m_flags & READONLY)
            result += "readonly ";
        else if (m_flags & CONST)
            result += "const ";
        
        
        result += m_returnType + " ";
        result += m_name + "()";
        
        if (m_flags & ABSTRACT) {
            result += ";\n";
            return result;
        }
        
        result += " {\n";
        
        for (const auto& b : m_body)
            result += b->compile(level + 1);
        
        result += generateShift(level) + "}\n";
        
        return result;
    }
    
    Flags getFlags() const override {
        return m_flags;
    }
};

#endif
