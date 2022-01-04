#include <ESP32Encoder.h>
#define PI acos(-1.0)

ESP32Encoder encoder;
//BluetoothSerial SerialBT;

#define PWMa 14
#define PWMb 27
#define PWMc 26
#define PWMd 25

char t;

void setup() {
  pinMode(PWMa, OUTPUT);
  pinMode(PWMb, OUTPUT);
  pinMode(PWMc, OUTPUT);
  pinMode(PWMd, OUTPUT);

  Serial.begin(115200);
  //SerialBT.begin("ESP32iz");
  // Enable the weak pull down resistors

  //ESP32Encoder::useInternalWeakPullResistors=DOWN;
  // Enable the weak pull up resistors
  ESP32Encoder::useInternalWeakPullResistors=UP;

  // use pin 19 and 18 for the first encoder
  encoder.attachHalfQuad(32, 33);

    
  // set starting count value after attaching
  encoder.setCount(0);


  //Serial.println("Encoder Start = " +  String((int32_t)encoder.getCount()));
  // set the lastToggle
  

}


void stopMotors(){
  digitalWrite(PWMa, LOW);
  digitalWrite(PWMb, LOW);
  digitalWrite(PWMc, LOW);
  digitalWrite(PWMd, LOW);
}


int calculateDistance(){

  // Loop and read the count
  Serial.println("Encoder count = " + String(((-0.06*PI)/12)*(int32_t)encoder.getCount()));
  delay(100);
  
  if (((-0.06*PI)/12)*(int32_t)encoder.getCount() > 10){

    stopMotors();
    delay(60000);}
 
}


void loop() {

  calculateDistance();
  
  if (((-0.06*PI)/12)*(int32_t)encoder.getCount() == 0){

    digitalWrite(PWMa, LOW);
    digitalWrite(PWMb, HIGH );
    digitalWrite(PWMc, HIGH);
    digitalWrite(PWMd, LOW);
  
    delay(3000);}

  calculateDistance();

  int i=0;
  for(i=0;i<4;i++){
  
    digitalWrite(PWMa, LOW);
    digitalWrite(PWMb, HIGH );
    digitalWrite(PWMc, HIGH);
    digitalWrite(PWMd, LOW);
    delay(1000);
    calculateDistance();
  
    }

  calculateDistance();
  
  digitalWrite(PWMa, LOW);
  digitalWrite(PWMb, LOW);
  digitalWrite(PWMc, HIGH);
  digitalWrite(PWMd, LOW);

  delay(110);
 
  calculateDistance();

  i=0;
  for(i=0;i<4;i++){
  
    digitalWrite(PWMa, LOW);
    digitalWrite(PWMb, HIGH );
    digitalWrite(PWMc, HIGH);
    digitalWrite(PWMd, LOW);
    delay(1000);
    calculateDistance();
  
    }

  digitalWrite(PWMa, LOW);
  digitalWrite(PWMb, HIGH);
  digitalWrite(PWMc, LOW);
  digitalWrite(PWMd, LOW);

  delay(110); 
  
  
}
