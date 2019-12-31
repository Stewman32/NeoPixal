

#define CUSTOM_SETTINGS
#define INCLUDE_ACCELEROMETER_SENSOR_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>
#include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMPIXELS      14
int pix = 5;
int value = 0;
int blue;
int red = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
OneSheeld.begin();
strip.begin();
}

void loop() {
  reset();
  movement();
  Show();
}
void reset() {
        for(int i = 1; i<14;i++){
          strip.setPixelColor(pix+i,strip.Color(0,0,0));
          strip.setPixelColor(pix-i,strip.Color(0,0,0));

        }
}
void Show(){
      strip.show();
      delay(50);
}
void movement() {


      if(AccelerometerSensor.getX()>1.5){
        value= 1;
      }else if(AccelerometerSensor.getX()<-1.5){
        value= -1;
      }else{
        value= 0;
      }
      if(AccelerometerSensor.getY()>1.5 && red < 255){
        red= red + 15;
      }
      if(AccelerometerSensor.getY()<1.5 && red > 0){
        red= red -15;
      }
      pix = pix + value;
      if(value>0){
        for(int i = 0; i<5;i++){
          strip.setPixelColor(pix-i,strip.Color(red/(i+1),0,255-(51*i)));
        }
      }
      if(value<0){
        for(int i = 0; i<5;i++){
          strip.setPixelColor(pix+i,strip.Color(red/(i+1),0,255-(51*i)));
        }
      }else{
          strip.setPixelColor(pix,strip.Color(red,0,255));
      }

}





