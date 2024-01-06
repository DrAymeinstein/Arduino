#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define led1   9
#define led2   10
#define buzzer 4
#define sensor 5
#define state  LOW

#define B0  31
#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A6  1760
#define AS6 1865
#define B6  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A7  3520
#define AS7 3729
#define B7  3951
#define C8  4186
#define CS8 4435
#define D8  4699
#define DS8 4978
#define R   0

int melody[] = {

  D5,-4, E5,-4, A4,4, //     |:
  E5,-4, FS5,-4, A5,16, G5,16, FS5,8,
  D5,-4, E5,-4, A4,2,
  A4,16, A4,16, B4,16, D5,8, D5,16,
  D5,-4, E5,-4, A4,4, //     :|
  E5,-4, FS5,-4, A5,16, G5,16, FS5,8,
  D5,-4, E5,-4, A4,2,
  A4,16, A4,16, B4,16, D5,8, D5,16,
  R,4, B4,8, CS5,8, D5,8, D5,8, E5,8, CS5,-8,
  B4,16, A4,2, R,4, 

  R,8, B4,8, B4,8, CS5,8, D5,8, B4,4, A4,8,
  A5,8, R,8, A5,8, E5,-4, R,4, 
  B4,8, B4,8, CS5,8, D5,8, B4,8, D5,8, E5,8, R,8,
  R,8, CS5,8, B4,8, A4,-4, R,4,
  R,8, B4,8, B4,8, CS5,8, D5,8, B4,8, A4,4,
  E5,8, E5,8, E5,8, FS5,8, E5,4, R,4,
   
  D5,2, E5,8, FS5,8, D5,8,
  E5,8, E5,8, E5,8, FS5,8, E5,4, A4,4,
  R,2, B4,8, CS5,8, D5,8, B4,8,
  R,8, E5,8, FS5,8, E5,-4, A4,16, B4,16, D5,16, B4,16,
  FS5,-8, FS5,-8, E5,-4, A4,16, B4,16, D5,16, B4,16,

  E5,-8, E5,-8, D5,-8, CS5,16, B4,-8, A4,16, B4,16, D5,16, B4,16,
  D5,4, E5,8, CS5,-8, B4,16, A4,8, A4,8, A4,8, 
  E5,4, D5,2, A4,16, B4,16, D5,16, B4,16,
  FS5,-8, FS5,-8, E5,-4, A4,16, B4,16, D5,16, B4,16,
  A5,4, CS5,8, D5,-8, CS5,16, B4,8, A4,16, B4,16, D5,16, B4,16,

  D5,4, E5,8, CS5,-8, B4,16, A4,4, A4,8, 
  E5,4, D5,2, R,4,
  R,8, B4,8, D5,8, B4,8, D5,8, E5,4, R,8,
  R,8, CS5,8, B4,8, A4,-4, R,4,
  R,8, B4,8, B4,8, CS5,8, D5,8, B4,8, A4,4,
  R,8, A5,8, A5,8, E5,8, FS5,8, E5,8, D5,8,
  
  R,8, A4,8, B4,8, CS5,8, D5,8, B4,8,
  R,8, CS5,8, B4,8, A4,-4, R,4,
  B4,8, B4,8, CS5,8, D5,8, B4,8, A4,4, R,8,
  R,8, E5,8, E5,8, FS5,4, E5,-4, 
  D5,2, D5,8, E5,8, FS5,8, E5,4, 
  E5,8, E5,8, FS5,8, E5,8, A4,8, A4,4,

  R,-4, A4,8, B4,8, CS5,8, D5,8, B4,8,
  R,8, E5,8, FS5,8, E5,-4, A4,16, B4,16, D5,16, B4,16,
  FS5,-8, FS5,-8, E5,-4, A4,16, B4,16, D5,16, B4,16,
  E5,-8, E5,-8, D5,-8, CS5,16, B4,8, A4,16, B4,16, D5,16, B4,16,
  D5,4, E5,8, CS5,-8, B4,16, A4,4, A4,8, 

  E5,4, D5,2, A4,16, B4,16, D5,16, B4,16, 
  FS5,-8, FS5,-8, E5,-4, A4,16, B4,16, D5,16, B4,16,
  A5,4, CS5,8, D5,-8, CS5,16, B4,8, A4,16, B4,16, D5,16, B4,16,
  D5,4, E5,8, CS5,-8, B4,16, A4,4, A4,8,  
  E5,4, D5,2, A4,16, B4,16, D5,16, B4,16,
   
  FS5,-8, FS5,-8, E5,-4, A4,16, B4,16, D5,16, B4,16, //    |:
  A5,4, CS5,8, D5,-8, CS5,16, B4,8, A4,16, B4,16, D5,16, B4,16,
  D5,4, E5,8, CS5,-8, B4,16, A4,4, A4,8,  
  E5,4, D5,2, A4,16, B4,16, D5,16, B4,16,
  FS5,-8, FS5,-8, E5,-4, A4,16, B4,16, D5,16, B4,16, //    :|
  
  A5,4, CS5,8, D5,-8, CS5,16, B4,8, A4,16, B4,16, D5,16, B4,16,
  D5,4, E5,8, CS5,-8, B4,16, A4,4, A4,8, 

  E5,4, D5,2, R,4
};

int s = sizeof(melody) / sizeof(melody[0]) / 2;
int tempo = 114;
int whole = (60000 * 4) / tempo;

int divider = 0, Duration = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
}

void Nope() {
  if (state == LOW) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    noTone(buzzer);
  }
}

void loop() {
  int val = digitalRead(sensor);
  if (val == HIGH) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    for (int i = 1000; i >= 50; i--) {
      digitalWrite(led1, HIGH);
      tone(buzzer, i);
      delay(5);
      for (int this = 0; this < s * 2; this = this + 2) {

        divider = melody[this + 1];
        if (divider > 0) {
          Duration = (whole) / divider;
        } else if (divider < 0) {
          Duration = (whole) / abs(divider);
          Duration *= 1.5;
        }

        tone(buzzer, melody[this], Duration * 0.9);

        delay(Duration);

        noTone(buzzer);

        Nope();
      }
      if (i == 50) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
      }
    }
  }

}
