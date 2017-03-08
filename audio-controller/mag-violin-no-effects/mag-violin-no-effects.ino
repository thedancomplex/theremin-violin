#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
int i = 0;

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=197,83
AudioSynthWaveform       triangle1;      //xy=199,174
AudioSynthWaveform       square1;      //xy=200,130
AudioMixer4              mixer1;         //xy=359,145
AudioMixer4              gain_final;         //xy=528,166
AudioOutputI2S           i2s1;           //xy=812,263
AudioConnection          patchCord1(sine1, 0, mixer1, 0);
AudioConnection          patchCord2(triangle1, 0, mixer1, 2);
AudioConnection          patchCord3(square1, 0, mixer1, 1);
AudioConnection          patchCord4(mixer1, 0, gain_final, 0);
AudioConnection          patchCord5(gain_final, 0, i2s1, 0);
AudioConnection          patchCord6(gain_final, 0, i2s1, 1);
// GUItool: end automatically generated code

AudioControlSGTL5000 audioShield;

int tr[] = {0, 0, 0, 0, 0, 0, 0, 0};
double a = 1.0;  // amplitude starting
double f = 440;  // frequency starting
int    p = 0;       // phase starting
double w = 0.5;  // pulse width
double g = 0.5;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  AudioMemory(100);
  audioShield.enable();
  audioShield.volume(0.5);
  sine1.frequency(f);
  sine1.phase(p);
  sine1.amplitude(a);

  square1.begin(WAVEFORM_PULSE);
  square1.frequency(f);
  square1.phase(p);
  square1.amplitude(a);
  square1.pulseWidth(w);

  triangle1.begin(WAVEFORM_TRIANGLE);
  triangle1.frequency(f);
  triangle1.phase(p);
  triangle1.amplitude(a);

  mixer1.gain(0,1.0);
  mixer1.gain(1,1.0);
  mixer1.gain(2,1.0);
  mixer1.gain(3,0.0);

  gain_final.gain(0, g);
  gain_final.gain(1,0.0);
  gain_final.gain(2,0.0);
  gain_final.gain(3,0.0);

}

void loop() {
  // put your main code here, to run repeatedly:

  int ana00 = analogRead(A20);
  int ana01 = analogRead(A16); 
  int ana02 = analogRead(A17);   double square_width = ana02/1023.0;
  int ana03 = analogRead(A18);   double flag_set_phase = ana03/1023.0;
   
  int ana10 = analogRead(A15);
  int ana11 = analogRead(A19);   int triangle_phase = (int)(ana11/1023.0 * 360);
  int ana12 = analogRead(A12);   int square_phase   = (int)(ana12/1023.0 * 360);
  int ana13 = analogRead(A13);   int sine_phase     = (int)(ana13/1023.0 * 360);

  int ana20 = analogRead(A11);   
  int ana21 = analogRead(A10);   double triangle_amp = ana21/1023.0;
  int ana22 = analogRead(A6);    double square_amp   = ana22/1023.0;
  int ana23 = analogRead(A7);    double sine_amp     = ana23/1023.0;

  
  int tr0 = touchRead(1);
  int tr1 = touchRead(0);
  int tr2 = touchRead(32);
  int tr3 = touchRead(33);
  int tr4 = touchRead(25);
  int tr5 = touchRead(16);
  int tr6 = touchRead(17);
  int tr7 = touchRead(15);


  int thresh = 3000;
  //if(     tr7 > thresh){ g = 1.0; f = 783.991; }
  if(     tr6 > thresh){ g = 1.0; f = 659.255; }
  else if(tr5 > thresh){ g = 1.0; f = 622.254; }
  else if(tr4 > thresh){ g = 1.0; f = 554.365; }
  else if(tr3 > thresh){ g = 1.0; f = 493.883; }
  else if(tr2 > thresh){ g = 1.0; f = 466.164; }
  else if(tr1 > thresh){ g = 1.0; f = 415.305; }
  else if(tr0 > thresh){ g = 1.0; f = 391.995; }
  else g = 0.0;

  gain_final.gain(0,g);
  sine1.frequency(f);
  square1.frequency(f);
  triangle1.frequency(f);

  sine1.amplitude(sine_amp);
  square1.amplitude(square_amp);
  triangle1.amplitude(triangle_amp);

  square1.pulseWidth(square_width);
  
  if(flag_set_phase > 0.5){
    sine1.phase(sine_phase);
    square1.phase(square_phase);
    triangle1.phase(triangle_phase);
  }
  
//int ana = 123;
 //Serial.println(tr0);
 delay(10);
}
