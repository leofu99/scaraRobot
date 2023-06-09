// Prueba Shield CNC, Driver, Motores de Pasos y Arduino UNO
// By: www.dinastiatecnologica.com
//
#define x_paso 2    // Define el Pin de STEP para Motor de eje X
#define x_dire 5    // Define el Pin de DIR  para Motor de eje X
#define x_habi 8    // Define el Pin de ENABLE  para Motor de eje X
#define y_paso 3
#define y_dire 6
#define y_habi 8
#define z_paso 4
#define z_dire 7
#define z_habi 8
#define r_paso 12
#define r_dire 13
#define r_habi 8

#include <Servo.h>

Servo servo; // Crear un objeto de la clase Servo

int servoPin = 9; // Pin al que está conectado el servo
int anguloInicial = 90; // Ángulo inicial del servo


int retardo = 3000;    // Menor numero el giro es mas rapido
//int tiempo = 600;   // durante cuanto timpo da el giro el motor (vueltas)

void setup() {
servo.attach(A0, 600, 2500); // Asociar el pin al objeto Servo
servo.write(anguloInicial); // Mover el servo al ángulo inicial
pinMode(x_paso, OUTPUT); pinMode(x_dire, OUTPUT); pinMode(x_habi, OUTPUT);     
pinMode(y_paso, OUTPUT); pinMode(y_dire, OUTPUT); pinMode(y_habi, OUTPUT);
pinMode(z_paso, OUTPUT); pinMode(z_dire, OUTPUT); pinMode(z_habi, OUTPUT);

}    

void loop() {
  giro(x_paso,x_dire,x_habi,400);
  giro(r_paso,r_dire,r_habi,500);
  giro(y_paso,y_dire,y_habi,500);
  giro(z_paso,z_dire,z_habi,500);
}

void giro(int paso_,int dire_,int habi_,int tiempo) {
   digitalWrite(habi_, LOW);  // Habilita el Driver
   digitalWrite(dire_, LOW);   // direccion de giro 1
   for(int i=0;i<tiempo;i++){  // da  pasos por un tiempo  
    digitalWrite(paso_, HIGH);      
    delayMicroseconds(retardo);          
    digitalWrite(paso_, LOW);       
    delayMicroseconds(retardo); 
   }
  digitalWrite(dire_, HIGH);   // direccion de giro 2
  for(int i=0;i<tiempo;i++){   // da  pasos por un tiempo  
    digitalWrite(paso_, HIGH);      
    delayMicroseconds(retardo);          
    digitalWrite(paso_, LOW);       
    delayMicroseconds(retardo);  
  }
  digitalWrite(habi_, HIGH);   // quita la habilitacion del Driver

 delay(1000);
   servo.write(160);
  delay(1000); // Esperar 1 segundo

  // Girar el servo hacia la posición de 90 grados
  // Esperar 1 segundo

  // Girar el servo hacia la posición de 180 grados
  servo.write(20);
  delay(1000); // Esperar 1 segundo
}
