#include "AbstractSensor.hpp"
#include "PressureSensor.hpp"

PressureSensor::PressureSensor(int i2cbus, int address) 
{
    i2c = new I2C(i2cbus);
    this->address = address;

    i2c->m_i2c_address(address);
}

PressureSensor::~PressureSensor()
{
    delete i2c;
}

void PressureSensor::update() 
{
    i2c->m_i2c_update_bytes_data();
}

uint16_t PressureSensor::readRawPressure()
{
    uint16_t value;
    uint8_t buf[2];

    int bytesRead = i2c->m_i2c_read_bytes_data(PRESSURE_SENSOR_ADC_READ, buf, 2);
    if(bytesRead != 2)
        throw std::runtime_error(std::string(__FUNCTION__) + ": Pressure value read failed");

    value = ((uint16_t)buf[0] << 8) | buf[1];

    // Notify the observer about new pressure value 
    ObservedEvent(getSensorName(), value);
    
    return value;
}

void PressureSensor::init(const std::string& sensor_name)
{
    this->name = sensor_name;
    std::cout << "Initializing " << this->name << " sensor...\n";
}
