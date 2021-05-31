#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;


int pos = 90; //90º cabeza centrada


/*=== Inicio del programa ===*/
void setup() {

  myservo3.attach(8);  //A Derecha   PIN 8
  myservo2.attach(9);  //B Izquierda PIN 9
  myservo1.attach(10); //C Arriba    PIN 10

}

void loop() {

  //Movimiento de cabeza
  //c_mirar (3000);


  //andar(500, 2);
  delay(9000);
  c_mirar (3000);

}


/*=== FUNCIONES ===*/

void andar(int frames, int veces) {

  for ( int a = 0; a <= veces; a += 1) {

    delay(frames);
    myservo1.write(150);
    myservo2.write(180);
    myservo3.write(180);
    delay(frames);
    myservo1.write(60);
    myservo2.write(90);
    myservo3.write(90);
    delay(frames);
    myservo1.write(-150);
    myservo2.write(-180);
    myservo3.write(-180);
    delay(frames);
    myservo1.write(60);
    myservo2.write(90);
    myservo3.write(90);
  }

}

void aleatorio() {

  myservo2.write(pos + random(30, 180));
  delay(300);
  myservo3.write(pos - random(30, 180));
  delay(300);
  myservo1.write(pos - random(-80, 80));
  sonido(30);
  delay(500);

}


/*C Arriba - Cabeza*/
void c_mirar (int speed) {


  myservo1.write(pos);
  sonido(100);
  delay(speed);
  myservo1.write(pos + random(1, 80));
  sonido(200);
  delay(speed);
  myservo1.write(pos - random(1, 80));
  sonido(50);
  delay(speed);


}

void c_no () {

  myservo1.write(pos + 45);
  delay(200);
  myservo1.write(pos - 45);
  delay(200);
  myservo1.write(pos + 45);
  delay(200);
  myservo1.write(pos - 45);
  myservo1.write(pos);
  delay(1000);



}

void sonido (int speed) {

  for ( int s = 0; s <= 10; s += 1) {

    tone(11, random(1, 233), speed);
    delay(speed);

  }



}
