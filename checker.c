#include <stdio.h> 
#include <assert.h>
 
int batteryIsOk(float temperature, float soc, float chargeRate)
{ 
int isTemperatureInRange = (temperature >= 0 && temperature <= 45); 
int isSocInRange = (soc >= 20 && soc <= 80); 
int isChargeRateInRange = (chargeRate <= 0.8); 
if (!isTemperatureInRange || !isSocInRange || !isChargeRateInRange) 
{ 
  if (!isTemperatureInRange)
  {
   printf("Temperature out of range!\n"); 
  }
  if (!isSocInRange) 
  { 
   printf("State of Charge out of range!\n"); 
  } 
  if (!isChargeRateInRange) 
  {
   printf("Charge Rate out of range!\n");
  } 
  return 0;
} 
return 1;
}
 
int main() 
{ 
assert(batteryIsOk(25, 70, 0.7)); 
assert(!batteryIsOk(50, 85, 0)); 
return 0;
}
