

#define red 10
#define green 9
#define blue 8

int sensor = A0;

int umidade;  

void setup() {
  
 Serial.begin(9600);
 pinMode(sensor, INPUT);
 pinMode(red, OUTPUT);
 pinMode(blue, OUTPUT);
 pinMode(green, OUTPUT);
 pinMode(12, OUTPUT); 
}


void loop() {
  
  umidade= analogRead(sensor);
 
  Serial.print("umidade: ");
   Serial.print(umidade);
  
  
  if (umidade < 850){
    
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      digitalWrite(12, HIGH);
      
      
      }
      
if (umidade >= 850)
{
     digitalWrite(red, HIGH);
     digitalWrite(green, LOW);
     digitalWrite(12, LOW);


     
     }
      
  
  
  
  delay(50);
}
 
