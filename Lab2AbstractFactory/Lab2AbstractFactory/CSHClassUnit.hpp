#ifndef CSHCLASSUNIT_H
#define CSHCLASSUNIT_H

#include <vector>

#include "ClassUnit.hpp"

class CSHClassUnit : public ClassUnit
{
public:
    enum CSHAccesModifier : Flags {
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
    explicit CSHClassUnit(const std::string& name) : m_name(name) {
        m_fields.resize(ACCESS_MODIFIERS.size() + CSH_ACCESS_MODIFIERS.size());
    }
    
    void add(const std::shared_ptr<Unit>& unit, Flags flags) {
        if(!abstract)
            abstract = true;
        
        int accessModifier = PRIVATE;
        if (flags < (ACCESS_MODIFIERS.size() + CSH_ACCESS_MODIFIERS.size())) {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }
    
    std::string compile(unsigned int level = 0) const
    {
        std::string result = generateShift(level) + (abstract ? "abstract " : "") + "class " + m_name + " {\n";
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            if (m_fields[i].empty()) {
                continue;
            }
            result += ACCESS_MODIFIERS[i] + ":\n";
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
