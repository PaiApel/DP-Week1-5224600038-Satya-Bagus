#ifndef IINPUTGENERATOR_H
#define IINPUTGENERATOR_H

#include "TurnInput.h"

class IInputGenerator {
public:
    virtual TurnInput generate() = 0;
    virtual ~IInputGenerator() {}
};

#endif // IINPUTGENERATOR_H
