#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

#define A 8
#define B 9
#define C 10

int pos = 90; //90º cabeza centrada

int speed = 5; //Velocidad general de los movimientos

/*=== Inicio del programa ===*/
void setup() {

  Serial.begin(9600);

  // La posiciones corresponden mirando frontalmente
  // al robot

  myservo3.attach(A);  //A Derecha   PIN 8
  myservo2.attach(B);  //B Izquierda PIN 9
  myservo1.attach(C); //C Arriba    PIN 10

  //Posicion inicial
  myservo1.write(pos);
  myservo2.write(pos);
  myservo3.write(pos);

  myservo1.detach();
  myservo2.detach();
  myservo3.detach();

}

void loop() {


  //andar(500, 1);
  //delay(6000);
  //c_mirar (3000);
  //delay(3000);
  //c_no ();
  //c_no ();

    /*
    girar_izquierda_C();
    sonido(100);
    levantar_B();
    bajar_B();
    reset_izquierda_C();
    delay(1000);

    girar_derecha_C();
    sonido(100);
    levantar_A();
    bajar_A();
    reset_derecha_C();
    delay(1000);

    sonido(100);
    levantar_A();
    levantar_B();
    bajar_A();
    bajar_B();
    girar_izquierda_C();
    reset_izquierda_C();
    girar_derecha_C();
    reset_derecha_C();
    delay(1000);
    */

}


/*=== FUNCIONES ===*/

//Ambos brazos
void levantar_A_B() {

  myservo3.attach(A);
  myservo2.attach(B);
  int p = pos;

  for ( int m = pos; m >= 0; m --) {
    ////for ( int m = pos; m <= 180; m ++) {
    myservo3.write(m);
    myservo2.write(m);
    delay(speed);
  }
  myservo3.detach();
  myservo2.detach();

}


//Brazo derecho
void levantar_A() {

  myservo3.attach(A);
  for ( int m = pos; m >= 0; m --) {
    myservo3.write(m);
    delay(speed);
  }
  myservo3.detach();

  Serial.println("Levantar_A: Fin");
}

void bajar_A() {

  myservo3.attach(A);
  for ( int m = 0; m <= pos; m ++) {
    myservo3.write(m);
    delay(speed);
  }
  myservo3.detach();

  Serial.println("Bajar_A: Fin");
}

//Brazo izquierdo
void levantar_B() {

  myservo2.attach(B);
  for ( int m = pos; m <= 180; m ++) {
    myservo2.write(m);
    delay(speed);
  }
  myservo2.detach();
}

void bajar_B() {

  myservo2.attach(B);
  for ( int m = 180; m >= pos; m --) {
    myservo2.write(m);
    delay(speed);
  }
  myservo2.detach();
}

// Cabeza
void girar_derecha_C() {

  myservo1.attach(C);
  for ( int m = pos; m <= 180; m ++) {
    myservo1.write(m);
    delay(speed);
  }
  myservo1.detach();
}

void reset_derecha_C() {

  myservo1.attach(C);
  for ( int m = 180; m >= pos; m --) {
    myservo1.write(m);
    delay(speed);
  }
  myservo1.detach();
}

void girar_izquierda_C() {

  myservo1.attach(C);
  for ( int m = pos; m >= 0; m --) {
    myservo1.write(m);
    delay(speed);
  }
  myservo1.detach();
}

void reset_izquierda_C() {

  myservo1.attach(C);
  for ( int m = 0; m <= pos; m ++) {
    myservo1.write(m);
    delay(speed);
  }
  myservo1.detach();
}



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
