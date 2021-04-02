/*
 * modified 19 March 2021
 * by Chris Swagler
 * purpose: to use the flex sensor and read the voltage based on how much it's flexed
 * 
 * Note: you can change the unflexed voltage value to calibrate it to your sensor
 *       Also, the resistor value used in the circuit can be 10k - 100k. This sketch used 10 k
 */
   
const int flexPin = A0; //pin A0 to read analog input
int unflexedVoltage = 305; //this value should be calibrated for resting position
int threshold = 10;

void setup(){
  Serial.begin(9600);       //Begin serial communication
}

void loop(){
  int value = analogRead(flexPin);         //Read and save analog value from potentiometer
  Serial.print(value);               //Print value

  if (value < (unflexedVoltage - threshold)) {
    Serial.println("\t flexed forward!");
  } else if (value > (unflexedVoltage + threshold)) {
    Serial.println("\t flexed backwards!");
  } else {
    Serial.println("\t unbent");
  }
  
  delay(100);                          //Small delay
}
