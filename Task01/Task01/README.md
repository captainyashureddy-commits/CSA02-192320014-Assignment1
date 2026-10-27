# Task 01 — Understand the Problem and Identify the Data

**Assignment:** CO1 — Rural Electricity Co-operative Billing System  
**Register Number:** 192320014  
**Marks:** 4  
**Bloom's Level:** K4 — Analyse

## 1. Problem Analysis

Grama Jyothi Rural Electricity Co-operative generates monthly electricity bills for approximately 4,000 households. The system receives previous and current meter readings, calculates electricity consumption, applies slab-based tariff rates, and adds a fixed charge.

The existing spreadsheet has produced incorrect bills because of rounding errors, meter rollover, and incomplete tariff updates. A reliable C program must calculate bills accurately to the paise and handle valid meter readings correctly.

## 2. Inputs

| Data | Purpose |
|---|---|
| Household number | Uniquely identifies the consumer |
| Consumer category | Identifies the applicable tariff category |
| Previous meter reading | Starting reading for the billing period |
| Current meter reading | Ending reading for the billing period |

The meter readings are used to calculate consumption. The household number and category are needed for identification and tariff selection.

## 3. Outputs

| Data | Purpose |
|---|---|
| Units consumed | Difference between meter readings, accounting for rollover |
| Energy charge | Charge calculated using tariff slabs |
| Fixed charge | Constant monthly charge |
| Total bill | Sum of energy charge and fixed charge |

## 4. Constants

For the example tariff specified in the assignment:

- First 100 units: free
- Units 101–200: ₹2.25 per unit
- Units above 200: ₹4.50 per unit
- Fixed monthly charge: ₹50
- Maximum 16-bit meter reading: 65535

Tariff rates, slab limits, and the meter-register limit should be defined as named constants so they can be updated consistently.

## 5. Data Characteristics

**Negative values:** Household numbers, consumption, and bill amounts must not be negative. A lower current meter reading may nevertheless be valid when the 16-bit meter has rolled over.

**Fractional values:** Meter readings and consumption are treated as whole units in the given examples. Monetary values can contain paise, so the bill should be stored and calculated in integer paise rather than floating-point rupees.

**Very large values:** The number of households may increase from 4,000 to 60,000 and eventually 800,000. Data types and storage should support this growth without overflow.

## 6. Rules Every Correct Bill Must Satisfy

1. Electricity consumption must be non-negative.
2. A meter rollover must not produce negative consumption.
3. The first 100 units must be charged at the free-slab rate.
4. The next 100 units must be charged at ₹2.25 per unit.
5. Units above 200 must be charged at ₹4.50 per unit.
6. The total bill must equal the energy charge plus the fixed charge.
7. All monetary calculations must remain accurate to the paise.
8. A tariff revision must be applied consistently to all consumers.

## 7. Assumptions

- Meter readings are whole numbers.
- The meter is a 16-bit unsigned register with values from 0 to 65535.
- At most one rollover occurs between successive readings.
- The example tariff is used for the demonstrated consumer category.
- The fixed charge is applied once per monthly bill.
- Taxes, subsidies, and arrears are excluded because they are not specified in the question.

## 8. Alternative Concept and Complexity Analysis

**Question:** What changes if meter readings are stored as character strings such as "01530" instead of integers?

If readings are stored as strings, the program must convert them to integer values before performing subtraction or checking rollover.

For example, the text "01530" is converted to the integer 1530 using a validated conversion routine such as `strtoul()`.

If a reading contains d digits:

- Reading an integer already stored in memory requires O(1) arithmetic operations.
- Converting a text reading requires O(d) time because the digits must be examined.
- A text representation requires O(d) characters of storage, including the null terminator, while a fixed-width integer occupies constant space.

String input also requires checking for invalid characters, out-of-range values, and empty readings.

**Conclusion:** Integer meter readings are preferable for billing calculations because they simplify arithmetic and rollover handling. Strings are appropriate when reading input but should be validated and converted before calculations.

## 9. Task 01 Result

The required inputs, outputs, constants, assumptions, data constraints, and billing correctness rules have been identified. These form the basis for selecting C data types and implementing the billing program in the next tasks.
