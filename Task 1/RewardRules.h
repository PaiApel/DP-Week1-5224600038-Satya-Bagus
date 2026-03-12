#ifndef REWARDRULES_H
#define REWARDRULES_H

#include "IRewardRule.h"

// Base reward: Gain equals base score
class SimpleRewardRule : public IRewardRule {
public:
    int compute(int baseScore, int round) override {
        return baseScore;
    }
};

// Modification 2: Reward = baseScore + 2 on odd rounds, baseScore * 2 on even rounds
class ModifiedRewardRule : public IRewardRule {
public:
    int compute(int baseScore, int round) override {
        if (round % 2 == 0) {
            return baseScore * 2;
        }
        else {
            return baseScore + 2;
        }
    }
};

#endif // REWARDRULES_H
