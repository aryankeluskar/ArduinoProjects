/* -------------------------------------
 *             MFRC522      Arduino     
 *             Reader/PCD   Uno/101     
 * Signal      Pin          Pin         
 * -------------------------------------
 * RST/Reset   RST          9            
 * SPI SS      SDA(SS)      10           
 * SPI MOSI    MOSI         11 / ICSP-4  
 * SPI MISO    MISO         12 / ICSP-1  
 * SPI SCK     SCK          13 / ICSP-3  
 */
/// include the library code:
#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  analogWrite(6,100);  
  while (!Serial);   // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop(){
    lcd.setCursor(1,0);
  // Look for new cards, if nothing found, quit
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
      return;
    
    }
    
    // Select one of the cards, if nothing found, quit
    if ( ! mfrc522.PICC_ReadCardSerial()) {
      return;
    }
    
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "5D 85 56 D3") //change here the UID of the card/cards that you want to give access
  {
    lcd.clear();
    lcd.print(content);
    lcd.setCursor(1,1);
    lcd.print("Who Are You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("Who Are You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("ho Are You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("o Are You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print(" Are You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("Are You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("re You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("e You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print(" You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("You? Calling 911");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("ou? Calling 911 ");
    delay(500);
  }
  if (content.substring(1) == "D6 62 F2 1E") //change here the UID of the card/cards that you want to give access
  {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(content);
    lcd.setCursor(1,1);
    lcd.print("Access Granted");
  }
}

