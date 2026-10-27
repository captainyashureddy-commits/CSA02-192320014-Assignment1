
#include <stdio.h>
#include <limits.h>

/* 16-bit meter counter: 65535 rolls over to 0 */
typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
    /* Unsigned 16-bit modular arithmetic, without if-else */
    return (unsigned int)(
        (unsigned int)(current - previous) &
        (unsigned int)USHRT_MAX
    );
}

int main(void)
{
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",
           sizeof(meter_t), (unsigned)USHRT_MAX);

    printf("Consumption: %u units\n",
           consumption(1200, 1530));

    printf("Consumption: %u units\n",
           consumption(65400, 120));

    return 0;
}
