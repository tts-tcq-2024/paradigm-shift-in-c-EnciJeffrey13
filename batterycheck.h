#ifndef BATTERY_STATUS_H
#define BATTERY_STATUS_H

#include <stdbool.h>

// Language enumeration
typedef enum {
    EN,
    DE 
} Language;  

// Global language variable, default to English
Language language = EN;

// Messages in both languages
const char* messages[2][5] = {
    // EN
    {
        "Normal",
        "Warning: Approaching discharge",
        "Warning: Approaching charge-peak",
        "Alarm: Low limit breached",
        "Alarm: High limit breached"
    },
    // DE
    {
        "Normal",
        "Warnung: Entladung nähert sich",
        "Warnung: Ladehöhe nähert sich",
        "Alarm: Untergrenze überschritten",
        "Alarm: Obergrenze überschritten"
    }
};

// Configuration structure for parameter limits and warning levels
typedef struct {
    float min;
    float max;
    float warning_tolerance;
    bool enable_warning;
} ParameterConfig;

#endif // BATTERY_STATUS_H
