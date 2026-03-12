#ifndef IREWARDRULE_H
#define IREWARDRULE_H

class IRewardRule {
public:
    virtual int compute(int baseScore, int round) = 0;
    virtual ~IRewardRule() {}
};

#endif // IREWARDRULE_H
