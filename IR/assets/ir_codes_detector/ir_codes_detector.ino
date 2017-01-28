#include <IRremote.h> //include the library
//PIN
int receiver = 12;
IRrecv irrecv(receiver); //create a new instance of receiver
decode_results results;
void setup() {
 Serial.begin(9600);
 irrecv.enableIRIn(); //start the receiver
}
void loop() {
 if (irrecv.decode(&results)) { //we have received an IR
   Serial.print ("HEX code received: "); //display HEX
 Serial.println (results.value, HEX); //display HEX
 irrecv.resume(); //next value
 }
}
