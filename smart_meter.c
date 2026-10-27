#include <stdio.h>
#include <stdint.h>

#define INTERVALS_PER_DAY 96
#define DAYS_IN_MONTH 30
#define FREE_UNITS 100
#define SLAB2_LIMIT 200
#define SLAB2_RATE_PAISE 225LL
#define SLAB3_RATE_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL

/* Illustrative time-of-day design: 18:00–22:00 is peak. */
#define PEAK_START_INTERVAL 72
#define PEAK_END_INTERVAL 88
#define PEAK_MULTIPLIER_PERCENT 125LL
#define NORMAL_MULTIPLIER_PERCENT 100LL

static long long base_charge_paise(long long units_wh) {
    /* Input in Wh; tariff in paise/kWh. Rounds once at the end. */
    long long free_wh = FREE_UNITS * 1000LL;
    long long slab2_wh = (SLAB2_LIMIT - FREE_UNITS) * 1000LL;
    long long remaining, charge_numerator = 0;
    if (units_wh <= free_wh) return 0;
    remaining = units_wh - free_wh;
    if (remaining <= slab2_wh) charge_numerator = remaining * SLAB2_RATE_PAISE;
    else charge_numerator = slab2_wh * SLAB2_RATE_PAISE
        + (remaining - slab2_wh) * SLAB3_RATE_PAISE;
    return (charge_numerator + 500LL) / 1000LL;
}

int main(void) {
    long long daily_wh = 0, daily_peak_wh = 0, daily_offpeak_wh = 0;
    long long monthly_wh, energy_paise, total_paise;
    int i;
    printf("SMART METER - 96 FIFTEEN-MINUTE INTERVALS\n");
    printf("Enter energy consumed in Wh during each interval.\n");
    for (i = 0; i < INTERVALS_PER_DAY; ++i) {
        long long wh;
        printf("Interval %d (Wh): ", i + 1);
        if (scanf("%lld", &wh) != 1 || wh < 0 || wh > 1000000000LL) {
            puts("Invalid reading. Enter a nonnegative Wh value up to 1000000000.");
            return 1;
        }
        daily_wh += wh;
        if (i >= PEAK_START_INTERVAL && i < PEAK_END_INTERVAL)
            daily_peak_wh += wh;
        else daily_offpeak_wh += wh;
    }
    monthly_wh = daily_wh * DAYS_IN_MONTH;
    energy_paise = base_charge_paise(monthly_wh);
    total_paise = energy_paise + FIXED_CHARGE_PAISE;
    printf("\nDaily energy: %.3f kWh\n", daily_wh / 1000.0);
    printf("Daily peak energy: %.3f kWh\n", daily_peak_wh / 1000.0);
    printf("Daily off-peak energy: %.3f kWh\n", daily_offpeak_wh / 1000.0);
    printf("Estimated monthly energy: %.3f kWh\n", monthly_wh / 1000.0);
    printf("Base tariff bill: Rs. %lld.%02lld\n", total_paise / 100, total_paise % 100);
    puts("Time-of-day tariff proposal: apply a 25% peak premium (18:00-22:00),");
    puts("subject to cooperative approval; not included in the base tariff bill.");
    return 0;
}
