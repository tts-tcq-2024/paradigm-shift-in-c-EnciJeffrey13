#include <stdio.h>
#include <assert.h>

// Function to check if temperature is within range
int isTemperatureOk(float temperature) {
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  }
  return 1;
}

// Function to check if State of Charge (SoC) is within range
int isSocOk(float soc) {
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  }
  return 1;
}

// Function to check if charge rate is within range
int isChargeRateOk(float chargeRate) {
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

// Main function to check if battery is okay
int batteryIsOk(float temperature, float soc, float chargeRate) {
  return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  printf("All tests passed.\n");
  return 0;
}
