#pragma once
#include "PressureSensorReactor.hpp"

double PressureSensorReactor::getPressureAtm(const uint16_t& value)
{
    double raw_value = value;
    double atm_value = (raw_value * max_pressure_atm) / max_pressure_raw;

    return atm_value;
}

double PressureSensorReactor::getPressureBar(const uint16_t& value)
{
    double atm_value = getPressureAtm(value);

    return atm_value * one_atm_in_bar;
} 

double PressureSensorReactor::getSeaLevel(const uint16_t& value)
{
    double raw_value = value;
    double sea_level = (raw_value * max_sea_level) / max_pressure_raw; 

    return sea_level;
}

struct ProcessedData PressureSensorReactor::collectInfo(const uint16_t& value)
{
    struct ProcessedData final_result;
    
    final_result.atm_pressure_value = getPressureAtm(value);
    final_result.bar_pressure_value = getPressureBar(value);
    final_result.current_sea_level = getSeaLevel(value);

    return final_result;
}
