# MockSensorApp
Academic project with implementation of four different design patterns: Observer, Mediator, Reactor and Abstract Factory

The logic begind the implementation is the next one: 

                                  -------------------------------------
                                  |          Logic Module             | 
                                  |  - reference to Sensor Module     |
                                  |  - reference to Reactor Module    |
                                  -------------------------------------     
                                          |          |             |              -------------------------
------------------------                  |          |             |              | AbstractReactorFactory |
|AbstractSensorFactory |                  |          |             |              |      interface         |            
| interface            |                  |          |             |              --------------------------
------------------------                  |          |             |                          | 
           |                              |          |             |                          |
           |                              |          |             |               -----------------------------      
           |                              |          |             |               | AbstractReactor Interface |        
---------------------------               |          |             |               ----------------------------- 
|AbstractSensor Interface |               |          |             |                                |
---------------------------               |          |             |                                |
           |                              |          |             |                         -------------------------------                                   
           |                              |          |             |                         |      Sensor Module          |
           |                              |          |             \-------------------------| - reference to Logic Module |
           |                              |          |                                       -------------------------------
------------------------------            |          |                                   
|      Sensor Module          |----------/           \
| - reference to Logic Module |                        \
| - I2C module instance       |                          \
-------------------------------                            \
                                                             \
                                                       ---------------------------------------------                             
                                                       |           SensorFactory Module            |
                                                       | - std::map<key, AbstractSensorFactory>    |
                                                       | - std::map<Key, AbstractReactorFactory>   |
                                                       | - Logic Module instance                   |
                                                       ---------------------------------------------
