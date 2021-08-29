/*
inspired by esp32Tuto from ESP32 Faust https://faustdoc.grame.fr/tutorials/esp32/

some slight changes by FCKX:

- reduced the headphone volume
- added panning over LR channels

*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "WM8978.h"
#include "FaustSawtooth.h"

FaustSawtooth faustSawtooth(48000,8)
;
WM8978 wm8978;

void setup() {
  //WM8978 wm8978;
  wm8978.init();
  wm8978.addaCfg(1,1); 
  wm8978.inputCfg(1,0,0);     
  wm8978.outputCfg(1,0); 
  wm8978.micGain(30);
  wm8978.auxGain(0);
  wm8978.lineinGain(0);
  wm8978.spkVolSet(0);
  wm8978.hpVolSet(10,10);
  wm8978.i2sCfg(2,0);
  
  faustSawtooth.start();
}

void loop() {
  wm8978.hpVolSet(10,10);
  faustSawtooth.setParamValue("freq",rand()%(2000-50 + 1) + 50);
  delay(1000);
  wm8978.hpVolSet(10,0);
    faustSawtooth.setParamValue("freq",rand()%(2000-50 + 1) + 50);
  delay(1000);
    wm8978.hpVolSet(0,10);
    faustSawtooth.setParamValue("freq",rand()%(2000-50 + 1) + 50);
  delay(1000);
}
