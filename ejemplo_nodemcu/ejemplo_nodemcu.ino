#include <Servo.h>

Servo myservo_A;
Servo myservo_B;
Servo myservo_C;

//#define LED_BUILTIN 2
#define D4 2 //D4
#define D3 0 //D3
#define D2 4 //D2
#define BUZZER_PIN 5 // Sonido

#define D5 14 //D5 microfono

int pos = 90; //90º cabeza centrada
int speed = 30; //Velocidad general de los movimientos
int steps = 6; // pasos de movimientos
int tono; //Tono

int H_arm = 180; //Altura máxima de los brazo


const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0

int sensorValue = 0;  // value read from the pot

void setup() {

  Serial.begin(115200);

  pinMode(D5,INPUT);

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

  /*
    girar_izquierda_A();
    levantar_B();
    bajar_B();
    delay(1000);
    girar_derecha_A();
    levantar_C();
    bajar_C();
    delay(1000);

  */


  //sonido(50, 50);
  //delay(100);

  // read the analog in value
  sensorValue = digitalRead(D5);

  // print the readings in the Serial Monitor
  Serial.print("sensor = ");
  Serial.println(sensorValue);

  delay(100);

}


/*=== FUNCIONES ===*/

//**** Brazo derecho
void levantar_C() {

  myservo_C.attach(D2);
  for ( int m = pos; m >= 0; m = m - steps) {
    myservo_C.write(m);
    delay(speed);
  }
  myservo_C.detach();

  Serial.println("levantar_C: Fin");
}

void bajar_C() {

  myservo_C.attach(D2);
  for ( int m = 0; m <= pos; m = m + steps) {
    myservo_C.write(m);
    delay(speed);
  }
  myservo_C.detach();

  Serial.println("Bajar_C: Fin");
}



//***** Brazo izquierdo
void levantar_B() {

  myservo_B.attach(D3);
  for ( int m = pos; m <= 180; m = m + steps) {
    myservo_B.write(m);
    delay(speed);
  }
  myservo_B.detach();
}

void bajar_B() {

  myservo_B.attach(D3);
  for ( int m = 180; m >= pos; m = m - steps) {
    myservo_B.write(m);
    delay(speed);
  }
  myservo_B.detach();
}



//***** Cabeza
void girar_derecha_A() {

  myservo_A.attach(D4);
  for ( int m = pos; m <= 180; m = m + steps) {
    myservo_A.write(m);
    delay(speed);
  }
  myservo_A.detach();
}

void reset_derecha_A() {

  myservo_A.attach(D4);
  for ( int m = 180; m >= pos; m = m - steps) {
    myservo_A.write(m);
    delay(speed);
  }
  myservo_A.detach();
}

void girar_izquierda_A() {

  myservo_A.attach(D4);
  for ( int m = pos; m >= 0; m = m - steps) {
    myservo_A.write(m);
    delay(speed);
  }
  myservo_A.detach();
}

void reset_izquierda_A() {

  myservo_A.attach(D4);
  for ( int m = 0; m <= pos; m = m + steps) {
    myservo_A.write(m);
    delay(speed);
  }
  myservo_A.detach();
}


int tonox() {

  return random(1, 233);
}


void sonido (int time, int tono) {


  tone (BUZZER_PIN, tono, time);
  delay(time);





}
