# Task 04 — Safe Macros and Preprocessing

**Register Number:** 192320014

## Objective

Demonstrate the use of C preprocessor macros, identify unsafe macro expressions, and implement safe macros for the electricity billing program.

## Unsafe Macro

`#define UNSAFE_SQUARE(x) x * x`

When the expression `2 + 3` is passed, it expands to `2 + 3 * 2 + 3`, giving 11 instead of 25.

## Safe Macro

`#define SAFE_SQUARE(x) ((x) * (x))`

Parentheses protect the arguments and complete expression from operator-precedence errors.

## Billing Constants

The tariff values are defined using named constants:

- First 100 units: Free
- Units 101–200: 225 paise per unit
- Units above 200: 450 paise per unit
- Fixed charge: 5000 paise

## Preprocessing

The C preprocessor handles directives such as `#include` and `#define` before compilation.

The command `gcc -E Task04/safe_macros.c -o Task04/preprocessed.i` generates the expanded source code.

## Limitations of Macros

Macros do not provide type checking. Macros that evaluate an argument more than once can also produce unexpected behavior if the argument has side effects, such as `i++`.

For more complex calculations, functions are generally safer than function-like macros.

## Complexity Analysis

The demonstration uses a constant number of arithmetic operations.

- Time complexity: O(1)
- Extra space complexity: O(1)

## Result

The program demonstrates unsafe and safe macro expansion and calculates the electricity bill using named tariff constants and integer-paise arithmetic.
