/*
   modified 26 Feb 2021
   by Chris Swagler
   purpose: to use the rfid reader to recognize a tag
   Note: this sketch was designed with the use of specifically the RC522 model
         - more information regarding this rfid reader can be found in the MFRC522 library
         - you can use the DumpInfo sketch from the MFRC522 library to obtain the
           ID and all info on your desired tags
         - if you just need the ID number, you can use this sketch to find the
           card ID, then copy paste the string to the variable _id_

 * Typical pin layout used:
 * ---------------------------------------
 *             MFRC522      Arduino       
 *             Reader/PCD   Uno/101       
 * Signal      Pin          Pin           
 * ---------------------------------------
 * POWER       3.3V         3.3V
 * RST/Reset   RST          9             
 * GROUND      GND          GND
 * SPI MISO    MISO         12
 * SPI MOSI    MOSI         11
 * SPI SCK     SCK          13
 * SPI SS      SDA(SS)      10                
  */

//NOTE: THE RC522 READER CANNOT BE CONNECTED TO 5 V, ONLY USE 3.3 V!
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

//change this String id to the one obtained from this sketch
String id = "00 00 00 00";

void setup()
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
}

void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  //Show UID on serial monitor
  Serial.print("UID tag :");
  
  //obtain id
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();

  //check if this id matches with the one declared above
  Serial.print("Message : ");
  if (content.substring(1) == id)
  {
    Serial.println("Authorized access");
    delay(2000);
  }
  else   {
    Serial.println("Access denied");
    delay(2000);
  }
  //loop
  Serial.println();
  Serial.println("Approximate your card to the reader...");
}
