#pragma once 
#include "AbstractSensor.hpp"
#include "PressureSensorFactory.hpp"
#include "AbstractReactor.hpp"
#include "PressureSensorReactorFactory.hpp"
#include "Logic.hpp"

#include <map>
#include <functional>

class SensorFactory
{
    Logic unit;
    std::map<std::string, std::unique_ptr<AbstractSensorFactory>> sensor_list;
    std::map<std::string, std::unique_ptr<AbstractReactorFactory>> reactor_list;
public:
    SensorFactory() 
    {
        sensor_list["MS511"] = std::make_unique<PressureSensorFactory>();
        reactor_list["r_MS511"] = std::make_unique<PressureSensorReactorFactory>();
    }

    std::unique_ptr<AbstractSensor> deploy(const std::string& name)
    {
        auto sensor = sensor_list[name]->deploy();
        auto react =  reactor_list[std::string("r_" + name)]->deploy();
        
        sensor->init(name);
        sensor->connectTo(&unit);
        
        unit.abs_sensor = sensor.get();
        unit.abs_react  = std::move(react);

        return sensor;
    }

};