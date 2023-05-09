#include <Servo.h> // include Servo library 

// 180 horizontal MAX
Servo horizontal; // horizontal servo
int servoh = 180;   // 90;     // stand horizontal servo

int servohLimitHigh = 180;
int servohLimitLow = 65;

// 65 degrees MAX
Servo vertical;   // vertical servo 
int servov = 50;    //   90;     // stand vertical servo

int servovLimitHigh = 80;
int servovLimitLow = 15;

// LDR pin connections
// define name analog_pin
#define ldrlt A3 //LDR top left 
#define ldrrt A2 //LDR top right
#define ldrld A4 //LDR down left 
#define ldrrd A5 //LDR down right

#define CLEANER_SERVO_PIN 8
#define HORIZONTAL_SERVO_PIN 9
#define VERTICAL_SERVO_PIN 10

Servo cleaner_servo; // servo controller (multiple can exist)
String cleaner_input_command;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // servo connections
  horizontal.attach(HORIZONTAL_SERVO_PIN); 
  vertical.attach(VERTICAL_SERVO_PIN);

  // set default servos to initial position
  horizontal.write(90);
  vertical.write(45);
  delay(3000);

  cleaner_servo.attach(CLEANER_SERVO_PIN); // start servo control
  cleaner_servo.write(87); // start servo at 0

  // pinMode(RED_LIGHT_PIN, OUTPUT);
  // pinMode(YELLOW_LIGHT_PIN, OUTPUT);
  // pinMode(GREEN_LIGHT_PIN, OUTPUT);
}

void loop() {
  // Read all photo resistors
  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt

  int dtime = 10;
  int tol = 40;
  
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt
  
    
  if (-1*tol > dvert || dvert > tol) // check if the diffirence is in the tolerance else change vertical angle
  {
  if (avt > avd)
  {
    servov = ++servov;
     if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
  }
  else if (avt < avd)
  {
    servov= --servov;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
  }
  vertical.write(servov);
  }
  
  if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
  {
    if (avl > avr)
    {
      servoh = --servoh;
      if (servoh < servohLimitLow)
      {
      servoh = servohLimitLow;
      }
    }
    else if (avl < avr)
    {
      servoh = ++servoh;
      if (servoh > servohLimitHigh)
      {
      servoh = servohLimitHigh;
      }
    }
    else if (avl = avr)
    {
      // nothing
    }
    horizontal.write(servoh);
  }

  if (Serial.available()) {
    cleaner_input_command = Serial.readStringUntil('\n');
    // Serial.println(cleaner_input_command + "input");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    if (cleaner_input_command == "clean") {
        cleaner_servo.write(120);
        delay(5000);

        cleaner_servo.write(60);
        delay(5000);

        cleaner_servo.write(87);
    }
  }

  delay(dtime);
}


