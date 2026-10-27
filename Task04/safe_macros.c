
#include <stdio.h>

#define FREE_UNITS 100
#define SLAB2_LIMIT 200
#define SLAB2_RATE_PAISE 225LL
#define SLAB3_RATE_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL

/* Unsafe macro: multiplication has higher precedence */
#define UNSAFE_SQUARE(x) x * x

/* Safe macro: parenthesize parameters and expression */
#define SAFE_SQUARE(x) ((x) * (x))

/* Safe calculation of total bill in integer paise */
#define TOTAL_BILL(energy) ((energy) + FIXED_CHARGE_PAISE)

long long energyCharge(unsigned int units)
{
    if (units <= FREE_UNITS)
        return 0;

    if (units <= SLAB2_LIMIT)
        return (long long)(units - FREE_UNITS)
               * SLAB2_RATE_PAISE;

    return (SLAB2_LIMIT - FREE_UNITS)
           * SLAB2_RATE_PAISE
           + (long long)(units - SLAB2_LIMIT)
           * SLAB3_RATE_PAISE;
}

int main(void)
{
    unsigned int units = 250;
    long long energy = energyCharge(units);
    long long bill = TOTAL_BILL(energy);

    printf("Unsafe square of 2+3: %d\n",
           UNSAFE_SQUARE(2 + 3));

    printf("Safe square of 2+3: %d\n",
           SAFE_SQUARE(2 + 3));

    printf("Units consumed: %u\n", units);
    printf("Energy charge: Rs. %lld.%02lld\n",
           energy / 100, energy % 100);
    printf("Total bill: Rs. %lld.%02lld\n",
           bill / 100, bill % 100);

    return 0;
}
