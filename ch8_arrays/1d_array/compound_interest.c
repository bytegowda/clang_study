#include <stdio.h>
#include <math.h>

#define NUM_RATES   ((int) sizeof(value) / sizeof(value[0]))
#define INIT_BALANCE    100.00

double compoundInterest(double pri, double rate, int years) {
    double val = 0;

    // Fixed the issue with integer division for rate
    val = (pri * pow(1 + (rate / 100.00), years));
    //printf("\n\n%s:%d pri=%f, years=%d val = %f, rate=%d\n", __func__, __LINE__, pri, years, val, rate);

    return val;
}

int main() {
    int i, low_rates, num_years, year;
    double value[5] = {0};

    printf("Enter the rate of interest\n");
    scanf("%d", &low_rates);

    printf("Enter the no of years\n");
    scanf("%d", &num_years);

    printf("NUM_RATES = %d\n", NUM_RATES);

    printf("\n\nYears");
    for(i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rates + i); // Display interest rates
        value[i] = INIT_BALANCE; // Initialize values for each rate
    }
    printf("\n");

    // Initialize the value array before using it in calculations
    /*for(i = 0; i < NUM_RATES; i++) {
        value[i] = INIT_BALANCE; // Initialize values for each rate
    }*/

    //printf("low_rate = %d\n", low_rates);

    for(year = 1; year <= num_years; year++) {
        printf("%3d ", year);
        for(i = 0; i < NUM_RATES; i++) {
            value[i] = compoundInterest(value[i], (double)(low_rates + i), year); // Update value for each year and rate
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}

