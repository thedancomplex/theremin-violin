#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine2;          //xy=215,238
AudioSynthWaveformSine   sine1;          //xy=216,179
AudioMixer4              mixer1;         //xy=439,205
AudioOutputI2S           i2s1;           //xy=678,204
AudioConnection          patchCord1(sine2, 0, mixer1, 1);
AudioConnection          patchCord2(sine1, 0, mixer1, 0);
AudioConnection          patchCord3(mixer1, 0, i2s1, 0);
AudioConnection          patchCord4(mixer1, 0, i2s1, 1);
// GUItool: end automatically generated code

AudioControlSGTL5000 audioShield;
int i = 0;
int imax = 50;
int theAmp = 1;
int led = 13;
int phi = 0;
double f = 440;
void setup() {
  // put your setup code here, to run once:
  analogReadRes(16);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  AudioMemory(100);
  audioShield.enable();
  audioShield.volume(0.5);
  sine1.frequency(f);
  sine1.phase(0);
  sine1.amplitude(1.0);

  sine2.frequency(f);
  sine2.phase(0);
  sine2.amplitude(1.0);
  mixer1.gain(0,0.1);
  mixer1.gain(1,0.1);
}

void loop() {

  int tr = touchRead(0);
  int ana = analogRead(14);
  double ftemp = (double)ana/65536.0 * 160.0 - 80.0;
  double f0 = f + ftemp;
  sine1.frequency(f0);
  Serial.println(f0);
  //sine1.phase(30);
  //sine2.phase((int)phi - 360);


  delay(20);
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
