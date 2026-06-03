#ifndef JavaMETHODUNIT_H
#define JavaMETHODUNIT_H

#include <vector>

#include "MethodUnit.hpp"

class JavaMethodUnit : public MethodUnit {
public:
    enum Modifier : Flags {
        STATIC = 1,
        FINAL = 1 << 1,
        ABSTRACT = 1 << 2
    };
    
public:
    JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags = 0) :
        MethodUnit(name, returnType, flags)
    {}
    
public:
    void add(const std::shared_ptr<Unit>& unit, Flags /* flags */ = 0) override {
        if (m_flags & ABSTRACT)
            return;
        
        m_body.push_back(unit);
    }
    
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level);
        
        if (m_flags & ABSTRACT)
            result += "abstract ";
        if (m_flags & FINAL && !(m_flags & ABSTRACT))
            result += "final ";
        else if ((m_flags & STATIC) && !(m_flags & ABSTRACT))
            result += "static ";
        
        result += m_returnType + ' ';
        result += m_name + "()";
        
        if (m_flags & ABSTRACT) {
            result += ";\n";
            return result;
        }
        
        result += " {\n";
        
        for (auto it = m_body.begin(); it != m_body.end(); ++it)
            result += (*it)->compile(level + 1);
        
        result += generateShift(level) + "}\n";
        
        return result;
    }
    
    Flags getFlags() const override {
        return m_flags;
    }
};

#endif
