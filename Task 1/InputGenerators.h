#ifndef INPUTGENERATORS_H
#define INPITGENERATORS_H

#include "IInputGenerator.h"
#include <cstdlib>

// Base implementation: Always return a fixed value
class FixedInputGenerator : public IInputGenerator {
public:
    TurnInput generate() override {
        return TurnInput{3};
    }
};

// Modification 1: Returns a random value between 1 and 10
class RandomInputGenerator : public IInputGenerator {
public:
    TurnInput generate() override {
        return TurnInput{(rand() % 10) + 1};
    }
};

#endif // INPUTGENERATORS_H
