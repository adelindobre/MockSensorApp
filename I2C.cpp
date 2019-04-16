#pragma once

#include "I2C.hpp"

    I2C::I2C(int bus, bool raw)
    {
        if(raw) {
            m_i2c_initraw(bus);
        } else {
            throw std::invalid_argument("Invalid i2c bus");
        }

        m_i2c->addr = MOCK_I2C_SENSOR_ADDR;
   }

    int I2C::m_i2c_address(uint8_t addr)
    {
        const uint8_t MAX_I2C_ADDR = 0x9F;

        if(addr > MAX_I2C_ADDR) {
            throw std::invalid_argument("Invalid device address");
        } else {
            m_i2c->addr = addr;
            m_i2c->mock_dev_addr = addr;
        }

        return 0;
    }

    m_i2c_context I2C::m_i2c_initraw(int bus)
    {
        m_i2c = new _i2c;
        m_i2c->busnum = bus;

        m_i2c->mock_dev_addr = MOCK_I2C_SENSOR_ADDR;
        m_i2c->mock_dev_data_len = MOCK_I2C_SENSOR_DATA_LEN;

        m_i2c->mock_dev_data = new uint8_t[m_i2c->mock_dev_data_len];

        memset(m_i2c->mock_dev_data, MOCK_I2C_SENSOR_DATA_INIT_BYTE, m_i2c->mock_dev_data_len);
    }

    int I2C::m_i2c_read_bytes_data(uint8_t reg, uint8_t* data, int length) 
    {

        if(m_i2c->addr == m_i2c->mock_dev_addr) 
        {
            if(reg >= m_i2c->mock_dev_data_len)
                throw std::invalid_argument("Register number is too big");

            if(length <= 0)
                throw std::invalid_argument("Length to read is invalid");
            
            int i = 0;
            for (i = reg; (i < (reg + length)) && (i < m_i2c->mock_dev_data_len); ++i)
                data[i - reg] = m_i2c->mock_dev_data[i];

            return (i - reg);
        } else
        {
            return -1;
        }
    }

    void I2C::m_i2c_update_bytes_data() 
    {
        std::stringstream ss;
        std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
        std::uniform_int_distribution<> die(0,255);

        for(int i = 0; i < m_i2c->mock_dev_data_len; ++i)
        {
            ss << std::hex << die(mersenne);
            ss >> m_i2c->mock_dev_data[i];
        }
    }
