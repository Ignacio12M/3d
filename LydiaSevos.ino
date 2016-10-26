/* En este programa se controla el jiro de tres servomotores los cuales estan declarados en la etiqueta (Servos) y cullos pinesr se de declaran en la etiqueta de (constantes).
 * Usamos "Serial.print(...)" para detectar errores de modo que se imprimira el ultimo comentario antes del error, tambien lo usaremos para momonitorizar las acciones.
 * Este programa esta formado por cuatro funciones 
        Void setup(): se declara los pines de los servos y se yama al puerto serial
        Void loop(): se ejecuta un bucles infinito yamando a moberServo(ID) (ID = servo que se pretende mover)
        Void moberServo(ID): en esta funcion se clasifica en casos, en cada caso se mueve un servo sefun la ID enviada. Tanvien se llama a la funcion "direccion(ID)"
        Void direcion(ID): si pos[ID] es igual a 0 entonces direccion[ID] es true polo que se suma un grado en pos[ID] y eso se cumples asta que pos[ID] es igual a poslimi[ID]
            en este caso direccion[ID] es false y se resta un grado a pos[ID] asta que pos[ID] es igual a 0 que se repite lo del principio
  *¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡NO ES LO MISMO " direcion() " QUE " direccion[] " CON UNA "C" ES LA FUNCION Y CON DOS "C" ES LA VARIABLE!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

#include <Servo.h>

//Servos
Servo servo0;
Servo servo1;
Servo servo2;

//variables
//int pos[]={1,1,1};                    //la posicion inicial debe de se 1 praque el la funcion "direcion()" no combi la direccion y reste
int pos[]={0,0,0};                    //quia esta bariable y el comentario de la de arriba si decides cambial "direcion()"
boolean direccion[]={true,true,true}; //esta variable decide si suma o resta a pos[] 

//Constantes
//Pines de servos
const int pinServo0 = 9;
const int pinServo1 = 10;
const int pinServo2 = 6;
//Posicon limite
const int poslimi[]={180,480,90};

void setup() {
//servos
  servo0.attach(pinServo0);
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
//posicion inicial
  servo0.write(pos[0]);
  servo1.write(pos[1]);
  servo2.write(pos[2]); 
//llama a un puerto serial
  Serial.begin(9600);
}

void loop() {
  moberServos(0);
  moberServos(1);
  moberServos(2);
  
}


void moberServos(int ID){
  direcion(ID);
  switch(ID){
  case 0:
    servo0.write(pos[0]);
    Serial.print("Servo 0 posicion "); Serial.print(pos[0]); Serial.println("º");
    break;
  case 1:
    servo1.write(pos[1]);
    Serial.print("Servo 1 posicion "); Serial.print(pos[1]); Serial.println("º");
    break;
  case 2:
    servo2.write(pos[2]);
    Serial.print("Servo 2 posicion "); Serial.print(pos[2]); Serial.println("º");
    break;
  }
} 

void direcion(int ID){
  Serial.print("ID = ");Serial.print(ID);Serial.print(" ");Serial.print("Posicion = ");Serial.print(pos[ID]);Serial.print(" ");Serial.print("Direccion= ");Serial.println(direccion[ID]);
  /*if (pos[ID]==0 || pos[ID]==poslimi[ID]) //si deseas siplificar el programa quita los comentarios y borra la condicion anterior y declara pos[] como {1,1,1} desde el principio
      {direcion[ID]=!direcion[ID];}*/
  if(pos[ID]==0)
      {direccion[ID]=true;}
    else if(pos[ID]==poslimi[ID])
       {direccion[ID]= false;}
  Serial.print("Direccion = ");Serial.println(direccion[ID]);
  
  if (direcion)
      {pos[ID]++;}
  else {pos[ID]--;}
}
