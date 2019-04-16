#pragma once 

#include <iostream>
#include <string>
#include <cstdint>
#include "AbstractSensor.hpp"
#include "I2C.hpp"

#define PRESSURE_SENSOR_ADDR 0x76
#define PRESSURE_SENSOR_ADC_READ 0x00

class PressureSensor : public AbstractSensor {

public:
    PressureSensor(int i2cbus = 0, int address = PRESSURE_SENSOR_ADDR);
    virtual ~PressureSensor();
    virtual void update();
    virtual uint16_t readRawPressure();
    virtual const std::string& getSensorName(){ return this->name; };
    void init(const std::string& sensor_name) override;
    void connectTo(Logic* unit){ this->observer = unit; }

private:
    I2C* i2c;
    std::string name;
    int address;
};