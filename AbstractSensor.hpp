#pragma once 
#include <memory>
#include <string>
#include <map>
#include <iostream>
#include "Logic.hpp"

class AbstractSensor 
{
public:
    virtual ~AbstractSensor() = default;
    virtual void init(const std::string& sensor_name) = 0;
    virtual void connectTo(Logic* unit) = 0;
    virtual const std::string& getSensorName() = 0;

    // HANDLER triggered when actual sensor returns new pressure value
    void ObservedEvent(const std::string& sensor_name, const uint16_t& value) 
    {
        observer->CorrectiveAction(sensor_name, value);
    }

protected:
    Logic* observer;
};
