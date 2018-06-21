/*
* Digital Wallet 
* 2018
* Giovanni Gentile
* projectg.it
*
*/
 
#include <Keyboard.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int button = 10;
int button2 = 9;
boolean pressed = true;
boolean pressed2 = true;

int switcher = 0;

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


void setup() {
  pinMode(button, INPUT_PULLUP);  
  pinMode(button2, INPUT_PULLUP);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.clearDisplay();

  // text display tests
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Digital");
  display.println("Wallet");
  //display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.display();
  delay(2000);
  //while(!Serial);
  Keyboard.begin();
  Serial.println("START");
}

void loop() {
  pressed = digitalRead(button);   //10
  delay(20);
  pressed2 = digitalRead(button2); //9
  
  // pin 10
  if (!pressed) {
    Serial.println("Stamp");
    delay(500);
    switch (switcher) {
      case 1:
        Keyboard.print(“email”);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.print(";");
        delay(30);
        Keyboard.releaseAll();
        Keyboard.print("domain.com");
        delay(50);
        Keyboard.press(KEY_TAB);
        Keyboard.releaseAll();
        Keyboard.print(“password”);
        delay(50);
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        delay(1000);
        break;
      case 2:
        Keyboard.print(“email”);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.print(";");
        Keyboard.releaseAll();
        Keyboard.print("domain.com");*/
        delay(50);
        Keyboard.press(KEY_TAB);
        Keyboard.releaseAll();
        delay(50);
        Keyboard.print(“password”);
        delay(100);
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        delay(1000);
        break;
      case 3:
        Keyboard.print(“password”);
        delay(50);
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        delay(1000);
        break;
      case 4:
        Keyboard.print(“password”);
        delay(50);
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        delay(1000);
        break;
     case 5:
        Keyboard.print(“password”);
        delay(50);
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();
        delay(1000);
        break;
      
      default:
        Keyboard.print("..default");
        break;
    }
  }
  // pin 9 change text
  if (!pressed2) { 
    switcher = switcher + 1;
    delay(500);
    Serial.println("Switch");
    switch (switcher) {
      case 1:
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("Facebook");
        display.display();
        Serial.print(switcher);
        Serial.println(" one");
        break;
      case 2:
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("Instagram");
        display.display();
        Serial.print(switcher);
        Serial.println(" two");
        break;
      case 3:
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("Google");
        display.println("-->");
        display.display();
        Serial.print(switcher);
        Serial.println(" three");
        break;
      case 4:
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("MacBook");
        display.display();
        Serial.print(switcher);
        Serial.println(" four");
        break;
      case 5:
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(0,0);
        display.println("Facebook");
        display.println("-->");
        display.display();
        Serial.print(switcher);
        Serial.println(" five");
        break; 
        
      default:
        display.setCursor(0,0);
        display.println("No");
        Serial.print(switcher);
        Serial.println(" NO");
        break;
    }
    if (switcher > 5) {switcher = 0;}
  }
}
