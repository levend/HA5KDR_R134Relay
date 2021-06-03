/*
 * 
 * This sketch is created for HA5KDR HAM radio club to control 
 * the linear amplifier and the R-134 radio in FT8 and similar digital modes.
 * 
 * How it works:
 * 
 * There are 2 wires coming from the PC:
 - 1 with a resistor soldered to it. Color: red
 - 1 without a resistor. Color: red/black

 Connect the pin without the resistor to 5V on the Arduino board
 Connect the resistor to GND
 Connect the other pin with the resistor to the A5 pin of the Arduino board
*/


int ledPin = 13;  // LED connected to digital pin 13

int relay_1_Pin = 9; //the 4 relay
int relay_2_Pin = 10;
int relay_3_Pin = 11;
int relay_4_Pin = 12;

 
int inPin = A5;    // TX signal coming in this pin
int val = 0; // variable to store the read value

int RELAY_OFF = 1;
int RELAY_ON = 0;
int TX_TRESHOLD = 900;


void setup() {
  pinMode(ledPin, OUTPUT);  // sets the led pin as output
  pinMode(inPin, INPUT);    // sets the A5 pin as input

  //set the 4 pin connected to the relay as output
  pinMode(relay_1_Pin, OUTPUT);
  pinMode(relay_2_Pin, OUTPUT);
  pinMode(relay_3_Pin, OUTPUT);
  pinMode(relay_4_Pin, OUTPUT);
}

void loop() {
  val = analogRead(inPin); // read the input pin

  //operator triggered TX mode if analog read is over a treshold
  if (val >= TX_TRESHOLD) {
    
    digitalWrite(ledPin, 1);  // sets the LED to the button's value
    digitalWrite(relay_2_Pin, RELAY_ON);
    digitalWrite(relay_4_Pin, RELAY_ON);
    delay(100);
    digitalWrite(relay_1_Pin, RELAY_ON);
    digitalWrite(relay_3_Pin, RELAY_ON);
    
  } else {
    digitalWrite(ledPin, 0);  // sets the LED to the button's value
    digitalWrite(relay_1_Pin, RELAY_OFF);
    digitalWrite(relay_3_Pin, RELAY_OFF);
    
    delay(100);
    digitalWrite(relay_2_Pin, RELAY_OFF);
    digitalWrite(relay_4_Pin, RELAY_OFF);
  }
  delay(10);
}
