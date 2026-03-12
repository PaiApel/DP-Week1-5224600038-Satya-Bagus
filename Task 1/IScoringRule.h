#ifndef ISCORINGRULE_H
#define ISCORINGRULE_H

#include "TurnInput.h"

class IScoringRule {
public:
    virtual int compute(TurnInput input) = 0;
    virtual ~IScoringRule() {}
};

#endif // ISCORINGRULE_H
