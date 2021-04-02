/******************************************
  Website: www.elegoo.com

  Time:2017.12.12

 ******************************************/
/*
 * modified 24 March 2021
 * by Chris Swagler
 * purpose: to use the avoidance module to detect if the sensor is blocked or not
 * 
 * Note: this sensor is called "avoidance" in the Elegoo kit, but has the same
 *       functionality as your typical IR sensor (see IRsensor sketch)
 */
int Led = 13; //define LED port
int buttonpin = 3; //define switch port
int  val; //define digital variable val
void  setup() {
  pinMode(Led, OUTPUT); //define LED as a output port
  pinMode(buttonpin, INPUT); //define switch as a output port
}
void  loop() { 
  val = digitalRead(buttonpin); //read the value of the digital interface 3 assigned to val
  if (val == 1) //when the switch sensor have signal, LED on
  {
    digitalWrite(Led, HIGH);
  }
  else
  {
    digitalWrite(Led, LOW);
  }
}
