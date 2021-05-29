#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position

void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object

}


void loop() {
  mirar (3000);
  no ();
   no ();


}


//FUNCIONES

void mirar (int speed) {

  myservo.write(pos);
  sonido(100);
  delay(speed);
  myservo.write(pos + random(1, 80));
  sonido(200);
  delay(speed);
  myservo.write(pos - random(1, 80));
  sonido(100);
  delay(speed);


}

void no () {

  myservo.write(pos + 45);
  delay(200);
  myservo.write(pos - 45);
  delay(200);
  myservo.write(pos + 45);
  delay(200);
  myservo.write(pos - 45);
  myservo.write(pos);
  delay(1000);



}

void sonido (int speed) {

  for ( int s = 0; s <= 10; s += 1) {

    tone(11, random(1, 233), speed);
    delay(speed);

  }




}
