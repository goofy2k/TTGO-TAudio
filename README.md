# TTGO-TAudio

Got shipped a TTGO TAudio 9 V1.6
When powered, the device runs a lightshow on the LED array.

## Learning experiences during trials to upload some demos

- The docs on the Github page suggests a demo on playing mp3 sound from an SD card. Burning this firmware and running did not succeed. 
- Erased the shipped firmware. Apparently that was driving the lightshow on the LED's.
- The info on the Github page  https://github.com/LilyGO/TTGO-TAudio is pretty thin, so I am looking for examples on the web
- Found a demo in the issues (nr 12): Example Code - WM8978 Arduino playing Icecast streams
  - Because of updates in the Audio.h library you need to use the code in a response by arifshanji (file available in repo)
  - You need to download the correct Audio.h: https://github.com/schreibfaul1/ESP32-audioI2S. This is NOT available from the Arduino IDE
- Need a special USB driver (CH341SER) before serial interface can be used for firmware uploads.
