#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=215,359
AudioOutputI2S           headphones;     //xy=476,356
AudioConnection          patchCord3(sine1, 0, headphones, 0);
AudioConnection          patchCord4(sine1, 0, headphones, 1);
AudioConnection          patchCord3(sine1, 0, mixer1, 0);
AudioConnection          patchCord4(mixer1, 0, headphones, 0);
AudioConnection          patchCord5(mixer1, 0, headphones, 1);
// GUItool: end automatically generated code
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example

AudioControlSGTL5000 audioShield;
int i = 0;
int imax = 2;
int theAmp = 1;
int led = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  AudioMemory(100);
  audioShield.enable();
  audioShield.volume(0.5);
}

void loop() {
  sine1.frequency(640);
  sine1.phase(0);
  sine1.amplitude(1.0);
  int tr = touchRead(0);
  Serial.println(tr);

  if(tr> 1000) sine1.amplitude(1.0);
  else sine1.amplitude(0.0);

   // delay(200);
  /*
  if ( i >= imax) {
    
    if(theAmp == 1)
    {
      theAmp = 0;
      sine1.amplitude(1.0);
    }
    else
    {
      sine1.amplitude(0.0);
      theAmp = 1;
    }
    i = 0;
  }
  i++;
  delay(500);
  */
  /*
  delay(100);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led,LOW);
  */
  // put your main code here, to run repeatedly:
  //amplitude(1.0);

}
