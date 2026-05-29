#ifndef JavaCLASSUNIT_H
#define JavaCLASSUNIT_H

#include <vector>

#include "ClassUnit.hpp"
#include "JavaMethodUnit.hpp"

class JavaClassUnit : public ClassUnit
{    
public:
    explicit JavaClassUnit(const std::string& name) : ClassUnit(name) {}
    
    void add(const std::shared_ptr<Unit>& unit, Flags flags) {
        if(!abstract & static_cast<bool>(unit->getFlags() & JavaMethodUnit::ABSTRACT))
            abstract = true;
        
        int accessModifier = PRIVATE;
        
        if (flags < STANDART_ACCESS_MODIFIERS.size()) {
            accessModifier = flags;
        }
        
        m_fields[accessModifier].push_back(unit);
    }
    
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level) + (abstract ? "abstract " : "") + "class " + m_name + " {\n";
        
        for (size_t i = 0; i < STANDART_ACCESS_MODIFIERS.size(); ++i) {
            if (m_fields[i].empty())
                continue;
            
            result += STANDART_ACCESS_MODIFIERS[i] + ":\n";
            
            for(const auto& f : m_fields[i]) {
                result += f->compile(level + 1);
            }
            
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }
    
private:
    bool abstract = false;
};

#endif
