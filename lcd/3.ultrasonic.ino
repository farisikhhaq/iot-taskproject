#define trigger_pin 15 //D8
#define Echo_pin 13 //D7

long duration;
int distance;

void setup() {
pinMode(trigger_pin, OUTPUT); 
pinMode(Echo_pin, INPUT); 
Serial.begin(9600); 
}

void loop() {
  
digitalWrite(trigger_pin, LOW); 
delayMicroseconds(2);

digitalWrite(trigger_pin, HIGH);  
delayMicroseconds(10);            
digitalWrite(trigger_pin, LOW);  

duration = pulseIn(Echo_pin, HIGH); // save time duration value in "duration variable
distance= duration*0.034/2; //Convert pulse duration into distance

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
delay(1000);
}
