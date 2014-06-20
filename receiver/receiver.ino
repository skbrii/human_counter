#include <IRremote.h>

int RECV_PIN1 = 11;
int RECV_PIN2 = 12;
int dp = 0;
int counter1 = 0;
int counter2 = 0;
int flag = 0;
int r1 = 0;
int r2 = 0;

IRrecv irrecv1(RECV_PIN1);
decode_results results1;
IRrecv irrecv2(RECV_PIN2);
decode_results results2;

void setup()
{
  Serial.begin(9600);
  irrecv1.enableIRIn(); // Start the receiver
  irrecv2.enableIRIn(); // Start the receiver
}

void loop() {
  //========GET_DATA=================
  if (irrecv1.decode(&results1)) {
    //Serial.print("1: ");
    //Serial.println(results1.value, HEX);
    r1 = results1.value;
    irrecv1.resume(); // Receive the next value
  }
  if (irrecv2.decode(&results2)) {
    //Serial.print("2: ");
    //Serial.println(results2.value, HEX);
    r2 = results2.value;
    irrecv2.resume(); // Receive the next value
  }
  //================LOGICS==========================
  // if (irrecv1.decode(&results1) == irrecv2.decode(&results2))
  if (r1 == r2){
    //delay(1);
  } 
  else {
    if ((r1 == 0) && (r2 != 0)) {
      if (flag == 1) {
       // Serial.print("hmm ");
       // Serial.print(millis() - dp);
       // Serial.println(" millis");
        flag = 0;
        counter1++;
        //counter2++;
        dp = 0;
        Serial.print("Count1:");
        Serial.println(counter1);
        //Serial.print("Count2:");
        //Serial.println(counter2);
      } 
      else {
        dp = millis();
        flag = 1;
      }
    }
    if ((r1 != 0) && (r2 == 0)) {
      if (flag == 1) {
        //Serial.print("hmm ");
        //Serial.print(millis() - dp);
        //Serial.println(" millis");
        flag = 0;
        //counter1++;
        counter2++;
        dp = 0;
        //Serial.print("Count1:");
        //Serial.println(counter1);
        Serial.print("Count2:");
        Serial.println(counter2);
      } 
      else {
        dp = millis();
        flag = 1;
      }
    }
  }
  r1 = 0;
  r2 = 0;
  delay(10);
}



