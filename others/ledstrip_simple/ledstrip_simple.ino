

#include <Adafruit_NeoPixel.h>

int PIN = 6; 

int NUMPIXELS = 8;


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {


  pixels.begin(); 
   pixels.show();
}

void loop() {
  
    pixels.setPixelColor(4, pixels.Color(0, 150, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

  
}
