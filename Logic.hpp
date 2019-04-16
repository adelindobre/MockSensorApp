#pragma once
#include <iostream>
#include <cstdint>
#include "AbstractReactor.hpp"
#include "PressureSensorReactor.hpp"

class AbstractSensor;

class Logic 
{
    public:
    // For multiple sensors, we could use a std::vector of sensors and reactors
    AbstractSensor* abs_sensor;
    std::unique_ptr<AbstractReactor> abs_react;

    // HANDLER for ObservedEvent from concrete sensor like PressureSensor
    void CorrectiveAction(const std::string& sensor_name, const uint16_t& value) 
    {
        PressureSensorReactor* d = dynamic_cast<PressureSensorReactor*>(abs_react.get());
        ProcessedData pd = d->collectInfo(value);

        std::cout << sensor_name << " statistics:\n";
        std::cout << " - " << "Pressure(bar): " << pd.bar_pressure_value << "\n";
        std::cout << " - " << "Pressure(atm): " << pd.atm_pressure_value << "\n";
        std::cout << " - " << "Sea Level(meters): " << pd.current_sea_level << "\n"; 
    }

    // HANDLER for ObservedEvent from concrete reactor like PressureSensorReactor
    void StabilizingInfo(AbstractReactor& source)
    {

    }

};
