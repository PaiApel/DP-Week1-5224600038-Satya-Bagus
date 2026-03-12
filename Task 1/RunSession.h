#ifndef RUNSESSION_H
#define RUNSESSION_H

#include <iostream>
#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

class RunSession {
private:
    IInputGenerator* inputGen;
    IScoringRule* scoringRule;
    IRewardRule* rewardRule;
    ShopSystem* shop;
    int money;

public:
    RunSession(IInputGenerator* ig, IScoringRule* sr, IRewardRule* rr, ShopSystem* sh)
        : inputGen(ig), scoringRule(sr), rewardRule(rr), shop(sh), money(0) {}

    ~RunSession() {
        delete inputGen;
        delete scoringRule;
        delete rewardRule;
        delete shop;
    }

    void run() {
        std::cout << "=== RUN START ===\n";

        for (int round = 1; round <= 3; round++) {
            std::cout << "\nRound " << round << "\n";

            // Phase 1 — Generate input
            TurnInput input = inputGen->generate();
            std::cout << "[PLAY] input generated: " << input.value << "\n";

            // Phase 2 — Compute base score
            int baseScore = scoringRule->compute(input);
            std::cout << "[SCORE] base score: " << baseScore << "\n";

            // Phase 3 — Compute reward
            int gain = rewardRule->compute(baseScore, round);

            // Phase 4 — Update money
            money += gain;
            std::cout << "[REWARD] gain: " << gain << " | money: " << money << "\n";

            // Phase 5 — Shop phase
            shop->visit(money);

            // Phase 6 — Advance round (implicit via loop)
        }

        std::cout << "\n=== RUN END ===\n";
        std::cout << "Final money: " << money << "\n";
    }
};

#endif
