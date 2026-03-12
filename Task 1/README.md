# Task 1 — Balatro-Like Run Loop

## Reflection

### 1. What is the invariant structure in your program?

The invariant is the phase order enforced by `RunSession::run()`:
1. Generate input
2. Compute base score
3. Compute reward
4. Update money
5. Shop phase
6. Advance round

This order is hardcoded inside the loop in `RunSession` and must never change. It represents the structural contract of the game, the sequence that defines what a "round" means. No other class is allowed to alter this order, and `RunSession` itself contains no scoring, reward, or input logic.

### 2. Which parts are mutable?

The mutable parts are the concrete implementations injected into `RunSession`:
- **IInputGenerator**: can be swapped between `FixedInputGenerator` and `RandomInputGenerator`
- **IScoringRule**: the formula for computing base score can change
- **IRewardRule**: the formula for computing money gain can change
- **ShopSystem**: the shop offer or cost can be modified

These can all change freely because `RunSession` only depends on their interfaces, not their internal logic.

### 3. When you replaced the InputGenerator, why didn't RunSession change?

Because `RunSession` holds a pointer to `IInputGenerator`, not to any specific implementation. It only ever calls `inputGen->generate()`, it has no idea whether the result is fixed or random. The concrete class is decided in `main.cpp` at construction time and injected via the constructor. This is dependency injection: the behavior is supplied from outside, so the caller never needs to know what changed.

### 4. What would happen if scoring logic was placed inside RunSession?

If scoring logic lived inside `RunSession`, then changing the scoring formula would require modifying `RunSession` itself, breaking the invariant. The phase order and the behavior would be tangled together, making it impossible to change one without risking the other. It would also make the system harder to test, since you could no longer swap scoring rules independently. Separation of the loop structure from the logic it calls is precisely what keeps the invariant stable across modifications.