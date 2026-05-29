#ifndef JavaMETHODUNIT_H
#define JavaMETHODUNIT_H

#include <vector>

#include "MethodUnit.hpp"

class JavaMethodUnit : public Unit {
public:
    enum Modifier : Flags {
            STATIC = 1,
            FINAL = 1 << 1,
            ABSTRACT = 1 << 2,
        };
};

#endif
