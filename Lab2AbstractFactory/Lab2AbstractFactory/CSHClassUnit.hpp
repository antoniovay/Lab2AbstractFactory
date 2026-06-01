#ifndef CSHCLASSUNIT_H
#define CSHCLASSUNIT_H

#include <vector>

#include "ClassUnit.hpp"

class CSHClassUnit : public ClassUnit
{
public:
    enum CSHAccessModifier : Flags {
            PUBLIC = AccessModifier::PUBLIC,
            PROTECTED = AccessModifier::PROTECTED,
            PRIVATE = AccessModifier::PRIVATE,
            PRIVATE_PROTECTED,
            FILE,
            INTERNAL,
            PROTECTED_INTERNAL
        };
    
    static const std::vector<std::string> CSH_ACCESS_MODIFIERS;

public:
    explicit CSHClassUnit(const std::string& name) : ClassUnit(name) {
        m_fields.resize(STANDART_ACCESS_MODIFIERS.size() + CSH_ACCESS_MODIFIERS.size());
    }
    
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override {
        if(!abstract & static_cast<bool>(unit->getFlags() & CSHMethodUnit::ABSTRACT))
            abstract = true;
        
        int accessModifier = PRIVATE;
        
        if (flags < (STANDART_ACCESS_MODIFIERS.size() + CSH_ACCESS_MODIFIERS.size()))
            accessModifier = flags;
        
        m_fields[accessModifier].push_back(unit);
    }
    
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level) + (abstract ? "abstract " : "") + "class " + m_name + " {\n";
        
        int accessModifiersSize = STANDART_ACCESS_MODIFIERS.size() + CSH_ACCESS_MODIFIERS.size();
        
        for (size_t i = 0; i < accessModifiersSize; ++i) {
            if (m_fields[i].empty()) {
                continue;
            }
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

const std::vector<std::string> CSHClassUnit::CSH_ACCESS_MODIFIERS = {"private protected", "file", "internal", "protected internal"};

#endif
