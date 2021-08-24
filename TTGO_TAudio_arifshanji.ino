// https://githubmemory.com/repo/LilyGO/TTGO-TAudio/issues

// Required Libraries (Download zips and add to the Arduino IDE library).
#include <WM8978.h> // https://github.com/CelliesProjects/wm8978-esp32
#include <Audio.h>  // https://github.com/schreibfaul1/ESP32-audioI2S

// T-Audio 1.6 WM8978 I2C pins.
#define I2C_SDA     19
#define I2C_SCL     18

// T-Audio 1.6 WM8978 I2S pins.
#define I2S_BCK     33
#define I2S_WS      25
#define I2S_DOUT    26
#define I2S_DIN     27

// T-Audio 1.6 WM8978 MCLK gpio number?
#define I2S_MCLKPIN  0

WM8978 dac;
Audio audio;


void setup() {

  // Setup wm8978 I2C interface.
  if (!dac.begin(I2C_SDA, I2C_SCL)) {
    ESP_LOGE(TAG, "Error setting up dac: System halted.");
    while (1) delay(100);
  }

  // Select I2S pins
  audio.setPinout(I2S_BCK, I2S_WS, I2S_DOUT);
  audio.i2s_mclk_pin_select(I2S_MCLKPIN);

  // WiFi Settings here.
  WiFi.begin("your_ssid", "your_password");
  while (!WiFi.isConnected()) {
    delay(10);
  }
  ESP_LOGI(TAG, "Connected. Starting MP3...");
  // Enter your Icecast station URL here.
  audio.connecttohost("http://hestia2.cdnstream.com/1458_128"); 
  // Volume control.
  dac.setSPKvol(40); // Change volume here for board speaker output (Max 63).
  dac.setHPvol(52, 52); // Change volume here for headphone jack left, right channel.
}

void loop() {
  // Start the stream.
  audio.loop();
}
