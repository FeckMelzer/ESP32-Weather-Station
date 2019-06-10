# ESP32-Weather-Station
simple weather station on an ESP32


# Getting started with the ESP32
### IMPORTANT NOTE:

- if this is your first time installing the ESP32 on the Arduino IDE, simply follow the installation procedure described below
- If you’ve already installed the ESP32 add-on using the old method, you should remove the espressif folder first.
_______________________________________
## 1. Installing the ESP32 Board in ARDUINO STUDIO
  1) Open the preferences window from the Aduino IDE. Go to *File>Preferences*
  
   ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard1.png)
   
   
  2) Enter *https://dl.espressif.com/dl/package_esp32_index.json* into the "Additional Board Manager URLs" field as shown in the                figure below. Then, click the "OK" button:
  
  
  ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard2.png)
  
  3) Open boards manager. Go to *Tools > Board > Boards Manager…*
  
  ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard3.png)
  
  4) Search for ESP32 and press install button for the “ESP32 by Espressif Systems“:
  
  ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard4.png)
  
  5) That’s it. It should be installed after a few seconds.
  
  _________________________________
## 2. Testing the Installation
  1) Open the Arduino IDE

  2) Select your Board in Tools > Board menu (in my case it’s the DOIT ESP32 DEVKIT V1)
  
  ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard5.png)
  
  3) Select the Port (if you don’t see the COM Port in your Arduino IDE, you need to install the ESP32 CP210x USB to UART Bridge VCP        Drivers):
  
  ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard6.png)
  
  4) Open the following example under File > Examples > WiFi (ESP32) > WiFi Scan
  
  ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard7.png)
  
  5) A new sketch opens:
  
  ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard8.png)

  6) Press the Upload button in the Arduino IDE. Wait a few seconds while the code compiles and uploads to your board.

  7) If everything went as expected, you should see a “Done uploading.” message.
  
  ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard9.png
  
  8) Open the Arduino IDE Serial Monitor with a click on the lens in the top right corner of the IDE, at a baud rate of 115200
  
  9) Press the ESP32 on-board Enable button and you should see the networks available near your ESP32:
  
  ![img2](https://github.com/FeckMelzer/ESP32-Weather-Station/blob/master/ard10.png
__________________________________________

#### If everything worked, you are good to go!
  
  

  

  
