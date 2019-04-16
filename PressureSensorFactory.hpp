#pragma once
#include "AbstractSensorFactory.hpp"

struct PressureSensorFactory : AbstractSensorFactory
{
    std::unique_ptr<AbstractSensor> deploy() const override {
        return std::make_unique<PressureSensor>();
    }
};