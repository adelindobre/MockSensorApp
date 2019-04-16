#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include "AbstractReactor.hpp"

#define MAX_PRESSURE        65535  // raw maximum pressure in decimal value
#define MAX_PRESSURE_ATM    58.09  // maximum pressure in atm / at 600 m depth   
#define MAX_SEA_LEVEL       600    // depth measured in meters    

typedef struct ProcessedData
{
    double atm_pressure_value;
    double bar_pressure_value;
    double current_sea_level;
} ProcessedData;

class PressureSensorReactor : public AbstractReactor {
public:
    virtual double getPressureAtm(const uint16_t& value);
    virtual double getPressureBar(const uint16_t& value); 
    virtual double getSeaLevel(const uint16_t& value);

    ProcessedData collectInfo(const uint16_t& value);

private:
    double max_pressure_raw = MAX_PRESSURE;
    double max_sea_level = MAX_SEA_LEVEL; 
    double max_pressure_atm = MAX_PRESSURE_ATM;
    double one_atm_in_bar = 1.01325;
};