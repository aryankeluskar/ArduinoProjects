#include <dht.h>

 /*
 OLED GND --> ARDUINO GND
 OLED VCC --> ARDUINO 5V
 OLED D0  --> ARDUINO D10
 OLED D1  --> ARDUINO D9
 OLED RES --> ARDUINO D13
 OLED DC  --> ARDUINO D11
 OLED CS  --> ARDUINO D12
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
dht DHT;

#define DHT22_PIN 7

void setup(){
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds
  // Clear the buffer
  display.clearDisplay();
}

void loop()
{
  display.clearDisplay();
  int chk = DHT.read22(DHT22_PIN);
  display.setTextSize(3); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(5, 0);
  display.print(DHT.temperature);
  display.println(" C");
  display.print(DHT.humidity);
  display.println(" %");
  display.display();
  delay(1000);
}
