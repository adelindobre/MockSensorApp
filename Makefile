SensorApp: Logic.hpp AbstractReactor.hpp PressureSensorReactor.hpp PressureSensorReactor.cpp AbstractSensor.hpp PressureSensor.hpp PressureSensor.cpp I2C.hpp I2C.cpp AbstractSensorFactory.hpp PressureSensorFactory.hpp AbstractReactorFactory.hpp PressureSensorReactorFactory.hpp SensorFactory.hpp main.cpp 
	g++ -w -o SensorApp Logic.hpp AbstractReactor.hpp PressureSensorReactor.hpp PressureSensorReactor.cpp AbstractSensor.hpp PressureSensor.hpp PressureSensor.cpp I2C.hpp I2C.cpp AbstractSensorFactory.hpp PressureSensorFactory.hpp AbstractReactorFactory.hpp PressureSensorReactorFactory.hpp SensorFactory.hpp main.cpp -I.

clean:
	rm -f *.gch
	rm -f SensorApp
