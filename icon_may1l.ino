#include <Adafruit_NeoPixel.h>

#define LED_PIN     6
#define LED_COUNT  64  
#define BRIGHTNESS 50
#define FADE_DELAY 10  


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600); 
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
  //sunAnimation();
 
  //rainAnimation();
}

void loop() {
  if (Serial.available() > 0) {
    String receivedChar = Serial.readString();
    if (receivedChar[0] == 'A') {
      // Receives an 'A' from the serial port,
      //indicating that the animation needs to be changed
      digitalWrite(13, HIGH);
      delay(50);
      digitalWrite(13, LOW);
      digitalWrite(13, HIGH);
      delay(50);
      digitalWrite(13, LOW);
      delay(500);

      //String inputString = Serial.readStringUntil('\n'); // Read precipitation probability information
      //inputString.trim(); // clean the space
    

      // Play the corresponding animation according to the probability of precipitation
   
        sunAnimation();
      
    }
    else{
      digitalWrite(13, HIGH);
      delay(50);
      digitalWrite(13, LOW);
      delay(500);

      rainAnimation();
    }
  }
}

void sunAnimation() {
  // Keep specified areas of sun icon constantly lit
  int sunPixels[] = {18, 19, 20, 21, 26, 27, 28, 29, 34, 35, 36, 37, 42, 43, 44, 45};
  for (int i = 0; i < sizeof(sunPixels) / sizeof(sunPixels[0]); i++) {
    strip.setPixelColor(sunPixels[i], strip.Color(255, 255, 0));  // Yellow for sun
  }

  // Blink 9 and 0 in a loop with red color
  for (int j = 0; j < 3; j++) {  // Repeat 3 times
    strip.setPixelColor(9, strip.Color(255, 0, 0));  // Red for 9
    strip.setPixelColor(12, strip.Color(255, 0, 0));
    strip.setPixelColor(33, strip.Color(255, 0, 0));
    strip.setPixelColor(49, strip.Color(255, 0, 0));
    strip.setPixelColor(51, strip.Color(255, 0, 0));
    strip.setPixelColor(54, strip.Color(255, 0, 0));
    strip.setPixelColor(30, strip.Color(255, 0, 0));
    strip.setPixelColor(14, strip.Color(255, 0, 0));
    strip.show();
    delay(500);  // Hold red color for 500ms

    // Fade out red color gradually
    for (int fadeValue = 255; fadeValue > 0; fadeValue -= 5) {
      strip.setBrightness(fadeValue);
      strip.show();
      delay(FADE_DELAY);
    }
  for (int i = 0; i < sizeof(sunPixels) / sizeof(sunPixels[0]); i++) {
    strip.setPixelColor(sunPixels[i], strip.Color(255, 255, 0));  // Yellow for sun
  }

    strip.setPixelColor(0, strip.Color(255, 0, 0));  // Red for 0
    strip.setPixelColor(32, strip.Color(255, 0, 0));
    strip.setPixelColor(56, strip.Color(255, 0, 0));
    strip.setPixelColor(59, strip.Color(255, 0, 0));
    strip.setPixelColor(63, strip.Color(255, 0, 0));
    strip.setPixelColor(31, strip.Color(255, 0, 0));
    strip.setPixelColor(7, strip.Color(255, 0, 0));
    strip.setPixelColor(4, strip.Color(255, 0, 0));
    strip.show();
    delay(500);  // Hold red color for 500ms

    // Fade out red color gradually
    for (int fadeValue = 255; fadeValue > 0; fadeValue -= 5) {
      strip.setBrightness(fadeValue);
      strip.show();
      delay(FADE_DELAY);
    }
  for (int i = 0; i < sizeof(sunPixels) / sizeof(sunPixels[0]); i++) {
    strip.setPixelColor(sunPixels[i], strip.Color(255, 255, 0));  // Yellow for sun
  }

    // Clear pixels
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
    strip.show();
    delay(500);  // Pause before next loop iteration

  }
}


void rainAnimation() {
  // Keep specified areas of rain icon constantly lit
  int rainPixels[] = {33, 25, 50, 42, 34, 26, 18, 43, 35, 27, 19, 11};
  for (int i = 0; i < sizeof(rainPixels) / sizeof(rainPixels[0]); i++) {
    strip.setPixelColor(rainPixels[i], strip.Color(0, 0, 255));  // Blue for rain
  }

  // Blink 52, 37, 20 in a loop with blue color
  for (int j = 0; j < 3; j++) {  // Repeat 3 times
    strip.setPixelColor(52, strip.Color(0, 0, 255));  // Blue for 52
    strip.setPixelColor(37, strip.Color(0, 0, 255));
    strip.setPixelColor(20, strip.Color(0, 0, 255));
    strip.show();
    delay(500);  // Hold blue color for 500ms

 for (int i = 0; i < sizeof(rainPixels) / sizeof(rainPixels[0]); i++) {
    strip.setPixelColor(rainPixels[i], strip.Color(0, 0, 255));  // Blue for rain
  }

    // Fade out blue color gradually
    for (int fadeValue = 255; fadeValue > 0; fadeValue -= 5) {
      strip.setBrightness(fadeValue);
      strip.show();
      delay(FADE_DELAY);
    }
 // Blink 53, 38, 21 in a loop with blue color
  for (int j = 0; j < 3; j++) {  // Repeat 3 times
    strip.setPixelColor(53, strip.Color(0, 0, 255));  // Blue for 52
    strip.setPixelColor(38, strip.Color(0, 0, 255));
    strip.setPixelColor(21, strip.Color(0, 0, 255));
    strip.show();
    delay(500);  // Hold blue color for 500ms

 for (int i = 0; i < sizeof(rainPixels) / sizeof(rainPixels[0]); i++) {
    strip.setPixelColor(rainPixels[i], strip.Color(0, 0, 255));  // Blue for rain
  }

    // Fade out blue color gradually
    for (int fadeValue = 255; fadeValue > 0; fadeValue -= 5) {
      strip.setBrightness(fadeValue);
      strip.show();
      delay(FADE_DELAY);
    }

    // Clear pixels
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
    strip.show();
    delay(500);  // Pause before next loop iteration
  }
}
}