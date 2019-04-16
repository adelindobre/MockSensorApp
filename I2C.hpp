#pragma once

#include <cstdint>
#include <cstring>
#include <random>
#include <ctime>
#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h>

// Mock I2C sensor default address
#define MOCK_I2C_SENSOR_ADDR 0x33
// Mock I2C sensor data registers block length in bytes
#define MOCK_I2C_SENSOR_DATA_LEN 16
// Initial value for each byte in the mock I2C sensor data registers
#define MOCK_I2C_SENSOR_DATA_INIT_BYTE 0xAB


struct _i2c {
    int busnum;
    int addr;

    uint8_t mock_dev_addr; /* address of the mock I2C sensor */
    uint8_t mock_dev_data_len; /* lenght in bytes of the mock sensor data register block */
    uint8_t* mock_dev_data; /* actual data register block content */
};

typedef struct _i2c* m_i2c_context;

class I2C
{
public:
    I2C(int bus, bool raw = true);
    int m_i2c_address(uint8_t addr);
    m_i2c_context m_i2c_initraw(int bus);
    int m_i2c_read_bytes_data(uint8_t reg, uint8_t* data, int length); 
    void m_i2c_update_bytes_data(); 

private:
    m_i2c_context m_i2c;
};
