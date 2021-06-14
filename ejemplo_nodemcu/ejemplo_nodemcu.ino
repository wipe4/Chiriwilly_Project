#include <Servo.h>

Servo myservo_A;
Servo myservo_B;
Servo myservo_C;

//#define LED_BUILTIN 2
#define D4 2 //D4
#define D3 0 //D3
#define D2 4 //D2

int pos = 90; //90º cabeza centrada
int speed = 5; //Velocidad general de los movimientos

void setup() {

  ///Serial.begin(9600);

  myservo_A.attach(D4);  //A Arriba
  myservo_B.attach(D3);  //B Izquierda
  myservo_C.attach(D2); //C Derecha

  //Posicion inicial
  myservo_A.write(pos);
  myservo_B.write(pos);
  myservo_C.write(pos);

  myservo_A.detach();
  myservo_B.detach();
  myservo_C.detach();

}

void loop() {

  //micVal = analogRead(micPin);
  //readMicrophone(micVal);


  //andar(500, 1);
  //delay(6000);
  //c_mirar (3000);
  //delay(3000);
  //c_no ();
  //c_no ();


  levantar_C();
  delay(1000);
  bajar_C();
  delay(1000);
  levantar_B();
  delay(1000);
  bajar_B();
  delay(1000);


}


/*=== FUNCIONES ===*/

//**** Brazo derecho
void levantar_C() {

  myservo_C.attach(D2);
  for ( int m = pos; m >= 0; m --) {
    myservo_C.write(m);
    delay(speed);
  }
  myservo_C.detach();

  ///Serial.println("Levantar_A: Fin");
}

void bajar_C() {

  myservo_C.attach(D2);
  for ( int m = 0; m <= pos; m ++) {
    myservo_C.write(m);
    delay(speed);
  }
  myservo_C.detach();

  ///Serial.println("Bajar_A: Fin");
}



//***** Brazo izquierdo
void levantar_B() {

  myservo_B.attach(D3);
  for ( int m = pos; m <= 180; m ++) {
    myservo_B.write(m);
    delay(speed);
  }
  myservo_B.detach();
}

void bajar_B() {

  myservo_B.attach(D3);
  for ( int m = 180; m >= pos; m --) {
    myservo_B.write(m);
    delay(speed);
  }
  myservo_B.detach();
}



//***** Cabeza
void girar_derecha_A() {

  myservo_A.attach(D4);
  for ( int m = pos; m <= 180; m ++) {
    myservo_A.write(m);
    delay(speed);
  }
  myservo_A.detach();
}

void reset_derecha_A() {

  myservo_A.attach(D4);
  for ( int m = 180; m >= pos; m --) {
    myservo_A.write(m);
    delay(speed);
  }
  myservo_A.detach();
}

void girar_izquierda_A() {

  myservo_A.attach(D4);
  for ( int m = pos; m >= 0; m --) {
    myservo_A.write(m);
    delay(speed);
  }
  myservo_A.detach();
}

void reset_izquierda_A() {

  myservo_A.attach(D4);
  for ( int m = 0; m <= pos; m ++) {
    myservo_A.write(m);
    delay(speed);
  }
  myservo_A.detach();
}
