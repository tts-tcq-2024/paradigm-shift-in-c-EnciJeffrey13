#include <stdio.h>
#include <assert.h>

int main() {
    float temperature1 = 25, soc1 = 70, chargeRate1 = 0.7;
    float temperature2 = 50, soc2 = 85, chargeRate2 = 0;

    int isTemperatureInRange1 = (temperature1 >= 0 && temperature1 <= 45); 
    int isSocInRange1 = (soc1 >= 20 && soc1 <= 80); 
    int isChargeRateInRange1 = (chargeRate1 <= 0.8); 

    if (!isTemperatureInRange1) { 
        printf("Temperature out of range!\n"); 
    } 
    if (!isSocInRange1) { 
        printf("State of Charge out of range!\n"); 
    } 
    if (!isChargeRateInRange1) { 
        printf("Charge Rate out of range!\n"); 
    } 

    assert(isTemperatureInRange1 && isSocInRange1 && isChargeRateInRange1);

    // int isTemperatureInRange2 = (temperature2 >= 0 && temperature2 <= 45); 
    // int isSocInRange2 = (soc2 >= 20 && soc2 <= 80); 
    // int isChargeRateInRange2 = (chargeRate2 <= 0.8); 

    // if (!isTemperatureInRange2) { 
    //     printf("Temperature out of range!\n"); 
    // } 
    // if (!isSocInRange2) { 
    //     printf("State of Charge out of range!\n"); 
    // } 
    // if (!isChargeRateInRange2) { 
    //     printf("Charge Rate out of range!\n"); 
    // } 

    // assert(!(isTemperatureInRange2 && isSocInRange2 && isChargeRateInRange2));

    return 0;
}
