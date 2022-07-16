/* **************************************************************/
/*       .-.      _______                 			*/
/*      {}``; |==|_______D                	Jaime Nevado	*/
/*      / ('        /|\                    			*/
/*  (  /  |        / | \         	  	   Robot.ino	*/
/*  \(_)_]]      /  |  \                   			*/
/*                                        			*/
/* ************************************************************ */

//Declaración de variables que asignaremos a cada salida digital

int echo = 10;
int trigger = 9;
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int distancia, duracion;
int buzzer = 3;
int espera_pitido = 100;    

void setup() {
   Serial.begin(9600);          //Abrimos el puerto serial para leer la distancia
   pinMode(IN1, OUTPUT);        //Declaramos como salida
   pinMode(IN2, OUTPUT);        //Declaramos como salida
   pinMode(IN3, OUTPUT);        //Declaramos como salida
   pinMode(IN4, OUTPUT);        //Declaramos como salida
   pinMode(trigger, OUTPUT);    //Declaramos como salida al trigger (Para el ultrasonidos)
   pinMode(echo, INPUT);        //Declaramos como salida al echo (Para el ultrasonidos)
}
void loop() {
    
    seguir();

    digitalWrite(trigger, HIGH);      //Estas líneas
    delay(1);                         //de código
    digitalWrite(trigger, LOW);       //nos ingresan
    duracion = pulseIn(echo, HIGH);   //el valor
    distancia = duracion / 58.2;      //de la distancia
    Serial.println(distancia);        //a la que está
    delay(20);                        //el objeto.

   if(distancia<=30){                        
            digitalWrite(trigger, HIGH);      //Estas líneas
            delay(1);                         //de código
            digitalWrite(trigger, LOW);       //nos ingresan
            duracion = pulseIn(echo, HIGH);   //el valor
            distancia = duracion / 58.2;      //de la distancia
            Serial.println(distancia);        //a la que está
            delay(20);                        //el objeto.
          parar();
          atras();
          pitido();
          girar();
          seguir();
      }
 }

 void pitido(){
    for(int i=0; i<4; i++){             //Iteramos 3 veces:
          digitalWrite(buzzer, HIGH);   //el encendido
          delay(espera_pitido);
          digitalWrite(buzzer, LOW);    //y apagado del buzzer
          delay(espera_pitido);
    }
  }
 void parar(){                //Para los dos motores
    digitalWrite(IN1, LOW);         
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);  
  }


 void atras(){                //Invierte el sentido de giro 
    digitalWrite(IN1, HIGH);  //en los dos motores para 
    digitalWrite(IN2, LOW);   //retroceder
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(200);               //Y espera 200ms
 }

 void girar(){                //Invierte el sentido de giro
    digitalWrite(IN1, HIGH);  //En el motor izquierdo
    digitalWrite(IN2, LOW);   //Para girar hacia la izquierda
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(400);               //Durante 400ms para dar el giro
  
 }

void seguir(){                //Hace girar los motores
    digitalWrite(IN1, LOW);   //hacia delante
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
 
