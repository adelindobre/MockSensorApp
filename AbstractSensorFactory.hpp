#pragma once
#include "AbstractSensor.hpp"
#include "PressureSensor.hpp"

struct AbstractSensorFactory
{
    virtual std::unique_ptr<AbstractSensor> deploy() const = 0;
};