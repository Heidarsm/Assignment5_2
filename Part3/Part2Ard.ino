#include <Arduino.h>
/* Arduino Serial Command Program - Derek Molloy (www.derekmolloy.ie)
*   for the book Exploring Raspberry Pi */

int ledPin = 11;          // LED with PWM brightness control
int msgLen = 2;
uint8_t msg[2];           //2 bytes

void setup() {            // called once on start up
   // A baud rate of 115200 (8-bit with No parity and 1 stop bit)
   Serial.begin(9600, SERIAL_8N1);
   pinMode(ledPin, OUTPUT);         // the LED is an output
   
}

void loop() {              // loops forever
   int command;
   char buffer[100];       // stores the return buffer on each loop   
   if (Serial.available()>0){// bytes received
      Serial.readBytes(msg, msgLen); // readBytes used for correct length 
      //Serial.println(msg[1]);
      if(msg[1]>=0 && msg[1]<=255){
        analogWrite(ledPin, msg[1]);       // yes, write out
        sprintf(buffer, "Set brightness to %d", msg[1]);
      }
      else{sprintf(buffer, "Unknown command: %s", msg[1]); }
      Serial.println(buffer);               // send the buffer to the RPi*/
   }  
}
