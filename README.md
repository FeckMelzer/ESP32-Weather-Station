# ESP32-Weather-Station
simple weather station on an ESP32

### IMPORTANT: Before you try the code for the weather station, check out the "getting started" markdown file above and follow the steps provided!


## Installing the libraries needed for this project

#### Installing Libraries
You need to install a couple of libraries for this project:

1) The DHT and the Adafruit Unified Sensor Driver libraries to read from the DHT sensor.
2) ESPAsyncWebServer and Async TCP libraries to build the asynchronous web server.
____________
#### Follow the next instructions to install those libraries:

### 1) Installing the DHT Sensor Library
To read from the DHT sensor using Arduino IDE, you need to install the DHT sensor library. Follow the next steps to install the library.

- Click [here](https://github.com/adafruit/DHT-sensor-library/archive/master.zip) to download the DHT Sensor library.
- You should have a .zip folder in your Downloads folder
- Unzip the .zip folder and you should get DHT-sensor-library-master folder
- Rename your folder from DHT-sensor-library-master to  *DHT_sensor*
- Move the DHT_sensor folder to your Arduino IDE installation libraries folder
- Finally, re-open your Arduino IDE
_____________
### 2) Installing the Adafruit Unified Sensor Driver

You also need to install the Adafruit Unified Sensor Driver library to work with the DHT sensor. Follow the next steps to install the library.

- Click [here](https://github.com/adafruit/Adafruit_Sensor/archive/master.zip) to download the Adafruit Unified Sensor library. 
- You should have a .zip folder in your Downloads folder
- Unzip the .zip folder and you should get Adafruit_*sensor-master folder*
- Rename your folder from Adafruit_sensor-master to Adafruit_sensor
- Move the Adafruit_sensor folder to your Arduino IDE installation libraries folder
- Finally, re-open your Arduino IDE
____________
### 3) Installing the ESPAsyncWebServer library

Follow the next steps to install the ESPAsyncWebServer library:

- Click [here](https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip) to download the ESPAsyncWebServer library.
-  You should have a .zip folder in your Downloads folder
- Unzip the .zip folder and you should get ESPAsyncWebServer-master folder
- Rename your folder from ESPAsyncWebServer-master to ESPAsyncWebServer
- Move the ESPAsyncWebServer folder to your Arduino IDE installation libraries folder
- Finally, re-open your Arduino IDE
________________
### 4) Installing the Async TCP Library for ESP32

The ESPAsyncWebServer library requires the AsyncTCP library to work. Follow the next steps to install that library:

- Click [here](https://github.com/me-no-dev/AsyncTCP/archive/master.zip) to download the AsyncTCP library. 
- You should have a .zip folder in your Downloads folder.
- Unzip the .zip folder and you should get AsyncTCP-master folder
- Rename your folder from AsyncTCP-master to AsyncTCP
- Move the AsyncTCP folder to your Arduino IDE installation libraries folder
- Finally, re-open your Arduino IDE

___________________________
# Now you are ready to try the code (found in the directory "simple server")

### This sets up a webserver displaying the currently measured Temperature and Humidity

1) Open the code provided in the .ino file in your Arduino IDE
2) Change the SSID and Password variables to your Home-Network-Data
3) Upload to your ESP32
4) Press the EN button on the ESP32 itself
5) Click on the lens symbol in the top right corner of the Arduino IDE
6) Copy the IP adress of the ESP32 and enter it to your browser
