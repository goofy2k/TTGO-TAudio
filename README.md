# TTGO-TAudio

Got shipped a TTGO TAudio 9 V1.6
When powered, the device runs a lightshow on the LED array.

Here I describe tests of the board's features.

## Features of the board
 - Play sound WM8978                  TESTED OK, .....ino
   - over headphone jack,  control volume (main, L/R channels?)
   - over board speakers,  control volume (main, L/R channels?)
   - equalizer
 - Microphone           ,  control volume? 
 - Recording function
 - SD card
   - read / write 
 - Play synthesized sound
   - use Faust for synthesis? 
 - LED array
   - original light show erased 
 - Accelerometer, magnetometer    MPU9250                    DONE ???Gyroscope, orientation sensors, .....
 - Battery
   - charging function? 
 - On/off switch
 - Push buttons (4x)
 - Audio in over BT  ?
 - Audio out over BT ? (this feature is not specific for this board, REMARK) 


REMARK: is it possible to stream / synthesize sound on a board without a WM8978 and send it over BT to a wireless speaker?  

## Sources of examples
 - In schreibfaul1/ESP32-audioI2S  (repo for Audio.h)
 - In LilyGO/ TTGO-TAudio repo
 - In issues of LilyGO/ TTGO-TAudio repo
 - Faust project https://faust.grame.fr/  or Faust for ESP32: https://hal.archives-ouvertes.fr/hal-02988312/document (faust2esp32, https://faustdoc.grame.fr/tutorials/esp32/)
 - Phil Schatzmann repos, pschatzmann https://github.com/pschatzmann
 - Cellie @CelliesProjects https://github.com/CelliesProjects
 - WM8978 docs (e.g. equalizer function)
 - Google: TTGO-TAudio use cases / examples / projects

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
