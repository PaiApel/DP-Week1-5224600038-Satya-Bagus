#ifndef SCORINGRULES_H
#define SCORINGRULES_H

#include "IScoringRule.h"

// Base scoring: Score equals the input value directly
class SimpleScoring : public IScoringRule {
public:
    int compute(TurnInput input) override {
        return input.value;
    }
};

#endif // SCORINGRULES_H
