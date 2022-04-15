
#define MOSFET 3
#define SENSOR 5 
#define LED 6
bool temp; 
int sensorSTATE=HIGH; //means no input, works in the other way
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(MOSFET, OUTPUT);
pinMode(SENSOR, INPUT);
pinMode(LED, OUTPUT);
temp=false;
 Serial.println("Sensor Reading");
}

void loop() {

 sensorSTATE=digitalRead(SENSOR); //read sensors initial state
  if(sensorSTATE==LOW && temp==false)
  {
    Serial.println("Sensor detects distance");
    digitalWrite(LED, HIGH);
    digitalWrite(MOSFET, HIGH);
    delay(2000);
    digitalWrite(MOSFET,LOW);
    temp=true;
    
    
    
    
  }
  else if(sensorSTATE==LOW && temp==true)
  {
    
  }
  else{
   Serial.println("Sensor DOES NOT detects distance");
digitalWrite(LED, LOW);
    if(temp==true){digitalWrite(MOSFET, LOW);
    }
    temp=false;
   }
delay(500);
}
