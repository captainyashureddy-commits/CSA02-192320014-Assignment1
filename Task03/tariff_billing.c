
#include <stdio.h>
#include <limits.h>

#define FREE_UNITS 100
#define SECOND_SLAB_LIMIT 200
#define RATE_SLAB2_PAISE 225LL
#define RATE_SLAB3_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL

long long calculate_energy_charge(unsigned int units)
{
    if (units <= FREE_UNITS)
        return 0;

    if (units <= SECOND_SLAB_LIMIT)
        return (long long)(units - FREE_UNITS)
               * RATE_SLAB2_PAISE;

    return (SECOND_SLAB_LIMIT - FREE_UNITS)
           * RATE_SLAB2_PAISE
           + (long long)(units - SECOND_SLAB_LIMIT)
           * RATE_SLAB3_PAISE;
}

int main(void)
{
    unsigned int units;
    long long energyCharge, totalBill;

    printf("Enter units consumed: ");

    if (scanf("%u", &units) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    energyCharge = calculate_energy_charge(units);
    totalBill = energyCharge + FIXED_CHARGE_PAISE;

    printf("\n--- ELECTRICITY BILL ---\n");
    printf("Units consumed: %u\n", units);
    printf("Energy charge: Rs. %lld.%02lld\n",
           energyCharge / 100, energyCharge % 100);
    printf("Fixed charge: Rs. 50.00\n");
    printf("Total bill: Rs. %lld.%02lld\n",
           totalBill / 100, totalBill % 100);

    return 0;
}
