# TTGO-TAudio

Got shipped a TTGO TAudio 9 V1.6
When powered, the device runs a lightshow on the LED array.

Here I describe tests of the board's features.

## Features of the board

### Tested
 - Play sound WM8978 over headphone jack                                        TTGO_TAudio_arifshanji.ino (play mp3 stream from web)
 - WiFi                                                                         TTGO_TAudio_arifshanji.ino
  - Play synthesized sound                                                      espTuto.ino from Faust project (ESP32 part)  ,  C++ code also available                               
  - LED array           WS2812 / Adafruit_NeoPixel                              TTGO_TAudio_RGB_LED.ino  (original light show firmware erased)
 - Motion processing unit MPU9250 with accelerometer, magnetometer, gyroscope   TTGO_TAudio_MPU9250.ino (test does not include gyroscope)

check presence in repo of all code files

### To be tested

 - Play sound WM8978                                               
   - over headphone control volume (main, L/R channels?)  use TTGO_TAudio_arifshanji.ino
   - over board speakers,  control volume (main, L/R channels?), requires proper hardware
   - equalizer    extendTTGO_TAudio_arifshanji.ino
 - MPU gyroscope, extend TTGO_TAudio_MPU9250.ino
 - Microphone           ,  control volume? 
 - Recording function        microphone?, line in?, i2S in ?
 - SD card
   - read / write 
 - Battery
   - charging function? 
 - On/off switch
 - Push buttons (4x)
 - Audio in over BT  ?
 - Audio out over BT ? (this feature is not specific for this board, REMARK) 


REMARK: is it possible to stream / synthesize sound on a board without a WM8978 and send it over BT to a wireless speaker?  

## Tooling for C, C++
Learn about code conversion. How to use C++ snippets or non-CMake C snippets in ESP-IDF:
-  https://www.deeptronic.com/software-design/developing-esp32-application-with-esp-idf-and-c-in-windows
-  https://github.com/goofy2k/ESPIDF-Code-Conversion (in progress)

## Sources of examples


#### Audio WM8978
 - In schreibfaul1/ESP32-audioI2S  (repo for Audio.h) https://github.com/schreibfaul1/ESP32-audioI2S
 - In LilyGO/ TTGO-TAudio repo
 - In issues of LilyGO/ TTGO-TAudio repo
 - Faust project https://faust.grame.fr/  or Faust for ESP32: https://hal.archives-ouvertes.fr/hal-02988312/document (faust2esp32, https://faustdoc.grame.fr/tutorials/esp32/)
 - Phil Schatzmann repos, pschatzmann https://github.com/pschatzmann
 - Cellie @CelliesProjects https://github.com/CelliesProjects
 - WM8978 docs (e.g. equalizer function)
 - Google: TTGO-TAudio use cases / examples / projects
#### Motion processing unit MPU9250
 - https://github.com/kriswiner/MPU9250  repo with lots of documentation and examples
 - https://www.seeedstudio.com/blog/2020/06/17/how-to-use-an-mpu9250-accelerometer-and-gyroscope-with-arduino/
 
#### LEDS
#### SD card reader
https://github.com/climufat/TTGO_mp3_player,  stripped down Liligo example. Only SD card and WM8978. No WiFi.   C++ ESP-IDF NOK
 
#### General
https://www.reddit.com/r/esp32/comments/93xwx8/ttgo_taudio/ and 
https://github.com/whyengineer/esp32_snow

## Learning experiences during trials to upload some demos

- The docs on the Github page suggests a demo on playing mp3 sound from an SD card. Burning this firmware and running did not succeed. 
- Erased the shipped firmware. Apparently that was driving the lightshow on the LED's.
- The info on the Github page  https://github.com/LilyGO/TTGO-TAudio is pretty thin, so I am looking for examples on the web
- Found a demo in the issues (nr 12): Example Code - WM8978 Arduino playing Icecast streams
  - Because of updates in the Audio.h library you need to use the code in a response by arifshanji (file available in repo)
  - You need to download the correct Audio.h: https://github.com/schreibfaul1/ESP32-audioI2S. This is NOT available from the Arduino IDE
- Need a special USB driver (CH341SER) before serial interface can be used for firmware uploads.

### From WM8978 datasheet (available in repo)

The WM8978 is a low power stereo codec with integrated pre-amps for stereo differential mics and includes drivers for speakers, headphone and differential or stereo line output. External component requirements are reduced as no separate microphone or headphone amplifiers are required. Advanced on-chip digital signal processing includes a five-band equalizer, a mixed-signal automatic level control for the microphone or line input through the A/D converter, as well as a purely digital limiter function for record or playback. Additional digital filtering options are available in the ADC path to provide application filtering such as ‘wind noise reduction.’ The WM8978 codec can operate as a main or secondary device. An internal PLL can generate all required audio clocks for the codec from common reference clock frequencies, such as 12 and 13 MHz. Individual sections of the chip can also be powered down under software control.

## Creating firmware with ESP-IDF (idf.py route)
- https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/
- https://blog.espressif.com/esp-idf-development-tools-guide-part-i-89af441585b
also see the hello_world readme.md and links therein, such as 
- https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html how to start a new project (and folder structure)
- Code conversion. How to use C++ code or non-CMake C code in the ESP-IDF environment:
  - https://www.deeptronic.com/software-design/developing-esp32-application-with-esp-idf-and-c-in-windows
  - https://github.com/goofy2k/ESPIDF-Code-Conversion (in progress)

Need to make an overview of relevant examples and libraries.
Need to translate example on other hardware to the TTGO TAudio T9 V1.6
Preparing a table with on board hardware (chips) and available code per platform

