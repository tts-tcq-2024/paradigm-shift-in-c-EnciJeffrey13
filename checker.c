#include <stdio.h> 
#include <assert.h>
 
int batteryIsOk(float temperature, float soc, float chargeRate)
{ 
// Define error flags 
int error = 0; 
// Check temperature range 
if (temperature < 0 || temperature > 45)
{
 printf("Temperature out of range!\n"); 
 error = 1;
} // Check State of Charge (SOC) range 
if (soc < 20 || soc > 80) 
{ 
 printf("State of Charge out of range!\n"); 
 error = 1; 
} 
// Check charge rate range 
if (chargeRate > 0.8) 
{ 
 printf("Charge Rate out of range!\n"); 
 error = 1; 
} 
// Return 1 if no errors, otherwise return 0 
return !error; 
} 
 
int main() 
{ 
assert(batteryIsOk(25, 70, 0.7)); 
assert(!batteryIsOk(50, 85, 0)); 
return 0;
}
