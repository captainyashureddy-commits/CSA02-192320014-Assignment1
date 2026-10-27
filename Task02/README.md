# Task 02 — Choose the Data Types

**Register Number:** 192320014  
**Marks:** 4

## Data Type Selection

| Data item | Suggested C type | Reason |
|---|---|---|
| Household number | `unsigned int` | Non-negative identifier |
| Consumer category | `enum` | Represents a defined set of categories |
| Previous meter reading | `unsigned short` | Holds a 16-bit meter reading |
| Current meter reading | `unsigned short` | Holds a 16-bit meter reading |
| Units consumed | `unsigned int` | Stores non-negative consumption |
| Tariff rates | `long` (paise) | Exact integer monetary values |
| Energy charge | `long long` (paise) | Reduces overflow risk for large amounts |
| Fixed charge | `long` (paise) | Exact fixed monetary amount |
| Total bill | `long long` (paise) | Preserves monetary precision |

## Size and Range

On a typical system with 8-bit bytes and a 16-bit `unsigned short`:

- `char`: usually 1 byte
- `short`: usually 2 bytes
- `int`: commonly 4 bytes
- `long`: 4 or 8 bytes, depending on the system
- `long long`: at least 8 bytes
- `float`: commonly 4 bytes
- `double`: commonly 8 bytes

The exact sizes should be verified using `sizeof` on the compiler used for the assignment. Integer limits are available in `limits.h`, while floating-point limits are available in `float.h`.

An unsigned 16-bit meter register can represent values from 0 to 65535. After 65535, it returns to 0.

## Meter Rollover

For the test case:

Previous reading = 65400  
Current reading = 120

Consumption = (65536 - 65400) + 120 = 256 units.

The C program uses modular arithmetic without `if–else`.

## Why Monetary Values Should Not Be Stored as Float Rupees

Binary floating-point types cannot exactly represent many decimal values, including ₹2.25 in some operations involving other decimal fractions. Repeated arithmetic and rounding can produce small errors.

For example, adding `0.1f` repeatedly in a C program may not give the same stored result as an exact decimal calculation. Across 4,000 bills, accumulated rounding differences can affect reported totals.

Instead, store money in integer paise:

- ₹2.25 = 225 paise
- ₹4.50 = 450 paise
- ₹50.00 = 5000 paise

Integer arithmetic gives exact results for these amounts, provided overflow is prevented.

## Alternative Concept and Complexity Analysis

If money is stored as `double` rupees instead of integer paise, each arithmetic operation is still O(1), but decimal rounding may be required before displaying or accumulating bills.

Both fixed-width floating-point values and integer monetary values use O(1) storage per amount.

For N bills, adding all bills requires O(N) time. Floating-point totals may accumulate representation error, whereas integer-paise totals remain exact within the chosen integer range.

## Result

The program calculates 330 units for ordinary readings and 256 units for a 16-bit meter rollover. It demonstrates how selecting appropriate unsigned integer types prevents negative consumption values.
