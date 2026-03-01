#include <stdio.h>

float celsius_to_fahrenheit(float c) {
    return (c * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float f) {
    return (f - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float c) {
    return c + 273.15;
}

float kelvin_to_celsius(float k) {
    return k - 273.15;
}

float fahrenheit_to_kelvin(float f) {
    return celsius_to_kelvin(fahrenheit_to_celsius(f));
}

float kelvin_to_fahrenheit(float k) {
    return celsius_to_fahrenheit(kelvin_to_celsius(k));
}


void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Category: Freezing\nAdvisory: Bundle up and stay warm.\n");
    } else if (celsius < 10) {
        printf("Category: Cold\nAdvisory: Wear a jacket or sweater.\n");
    } else if (celsius < 25) {
        printf("Category: Comfortable\nAdvisory: Go enjoy the weather.\n");
    } else if (celsius < 35) {
        printf("Category: Hot\nAdvisory: Dress light and hydrate.\n");
    } else {
        printf("Category: Extreme Heat\nAdvisory: Dont go outside if you can.\n");
    }
}

int main() {
    float temperature, converted_temp;
    char scale, target;


    printf("Enter the temperature value: ");
    while (scanf("%f", &temperature) != 1) {
        printf("Invalid input! Enter a number: ");
        while (getchar() != '\n');
    }


    printf("Enter the scale of your temperature (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    while (scanf(" %c", &scale) != 1 || (scale != 'C' && scale != 'F' && scale != 'K')) {
        printf("Invalid choice! Enter C, F, or K: ");
        while (getchar() != '\n');
    }

    while (scale == 'K' && temperature < 0) {
        printf("Kelvin cannot be negative. Enter again: ");
        while (scanf("%f", &temperature) != 1) {
            printf("Invalid input! Enter a number: ");
            while (getchar() != '\n');
        }
    }


    printf("Enter the conversion target (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    while (scanf(" %c", &target) != 1 || (target != 'C' && target != 'F' && target != 'K')) {
        printf("Invalid choice! Enter C, F, or K: ");
        while (getchar() != '\n');
    }


    while (target == scale) {
        printf("Cannot convert to the same scale. Enter a different target: ");
        while (scanf(" %c", &target) != 1 || (target != 'C' && target != 'F' && target != 'K')) {
            printf("Invalid choice! Enter C, F, or K: ");
            while (getchar() != '\n');
        }
    }


    if (scale == 'C') {
        if (target == 'F') converted_temp = celsius_to_fahrenheit(temperature);
        else if (target == 'K') converted_temp = celsius_to_kelvin(temperature);
    } else if (scale == 'F') {
        if (target == 'C') converted_temp = fahrenheit_to_celsius(temperature);
        else if (target == 'K') converted_temp = fahrenheit_to_kelvin(temperature);
    } else if (scale == 'K') {
        if (target == 'C') converted_temp = kelvin_to_celsius(temperature);
        else if (target == 'F') converted_temp = kelvin_to_fahrenheit(temperature);
    }


    printf("Converted temperature: %.2f %c\n", converted_temp, target);


    float temp_in_celsius;
    if (target == 'C') temp_in_celsius = converted_temp;
    else if (target == 'F') temp_in_celsius = fahrenheit_to_celsius(converted_temp);
    else temp_in_celsius = kelvin_to_celsius(converted_temp);

    categorize_temperature(temp_in_celsius);

    return 0;
}
