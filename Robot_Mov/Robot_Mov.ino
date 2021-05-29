#include <Servo.h>

Servo myservo;


int pos = 90; //90º cabeza centrada

/*=== Inicio del programa ===*/
void setup() {
  
  myservo.attach(8);  //A Derecha   PIN 8
  myservo.attach(9);  //B Izquierda PIN 9
  myservo.attach(10); //C Arriba    PIN 10

}

void loop() {
  
  //Movimiento de cabeza
  c_mirar (3000);

}


/*=== FUNCIONES ===*/


/*C Arriba - Cabeza*/
void c_mirar (int speed) {

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

void c_no () {

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
