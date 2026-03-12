#include <cstdlib>
#include <ctime>
#include "RunSession.h"
#include "InputGenerators.h"
#include "ScoringRules.h"
#include "RewardRules.h"
#include "ShopSystem.h"

int main() {
    srand(time(0)); // seed for RandomInputGenerator

    // Modification 1: swap FixedInputGenerator -> RandomInputGenerator
    // Modification 2: swap SimpleRewardRule -> ModifiedRewardRule
    // RunSession never changes, only this wiring changes.
    RunSession session(
        new RandomInputGenerator(),
        new SimpleScoring(),
        new ModifiedRewardRule(),
        new ShopSystem()
    );

    session.run();
    return 0;
}
