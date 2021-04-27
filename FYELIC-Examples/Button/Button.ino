/*
  modified 27 Nov 2020
  by Chris Swagler
  purpose: display to the serial monitor when the button is in its "pressed" state
  wire diagram :
     - Note : buttons can be wired across the breadboard gap or within as shown in
              the wire diagram. Just be sure the legs of the button line up with the rows
              If you're using several components, it saves space to wire the button on one side
              rather than across the gap
  https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-5-push-buttons
*/

/*
   Note: there are often TWO different ways to wire your button
   
   The first way has a default value of HIGH when unpressed and LOW when pressed
      - the upper button in the wire diagram works this way (no resistor)
      
   The second way has a default value of LOW when unpressed and HIGH when pressed
      - the lower button in the wire diagram works this way (with resistor)
      
   THIS EXAMPLE HAS HIGH AS UNPRESSED
   If your button is doing the inverse behavior, you can either change the if statements to
   reflect the actual LOW/HIGH values, or you can rewire the buttons to the other configuration
*/

int buttonPin = 6;  // pushbutton pin
//int buttonPin = 7; //pushbutton pin in wire diagram above with resistor
int buttonState;  // variable to hold the pushbutton states

void setup()
{
  // Set up the pushbutton pin to be an input:
  pinMode(buttonPin, INPUT_PULLUP); //INPUT_PULLUP uses the built-in pull-up resistors
  //pinMode(buttonPin, INPUT);     //only use if your button wiring uses a 10k resistor
  Serial.begin(9600);
}


void loop()
{
  buttonState = digitalRead(buttonPin); //read the state of the button

  //if the button is pressed
  if (buttonState == LOW) {
    Serial.println("Button pressed!"); //print to the serial monitor that it was pressed
    delay(100);
  } else if (buttonState == HIGH) {
    Serial.println("Button unpressed!"); //print to the serial monitor that it was not pressed
    delay(100);
  }

}
