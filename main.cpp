#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "AbstractSensor.hpp"
#include "SensorFactory.hpp"

int main()
{
    SensorFactory sf;
    std::unique_ptr<PressureSensor> local_sensor(static_cast<PressureSensor*>(sf.deploy("MS511").release()));

    local_sensor->readRawPressure();
    std::this_thread::sleep_for (std::chrono::seconds(1));

    int i = 10;
    while(i > 0)
    {
        local_sensor->update();
        local_sensor->readRawPressure();
        std::this_thread::sleep_for (std::chrono::seconds(1));
        --i;
    }
    
    return 0;
}