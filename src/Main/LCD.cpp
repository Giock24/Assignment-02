#include "LCD.h"
#include "Arduino.h"

#include <LiquidCrystal_I2C.h>

LCD::LCD() {
  /* Wiring: SDA => A4, SCL => A5 */
  /* I2C address of the LCD: 0x27 */
  /* Display grid: 20 rows: 4 cols */
  lcd.init();
  lcd.backlight();
  //Serial.println("LCD initialize...");
}

void LCD::turnOn() {
  lcd.backlight();
  lcd.display();
}

void LCD::turnOff() {
  lcd.noBacklight();
  lcd.noDisplay();
}

void LCD::write(int row, int col, char* text) {
  lcd.setCursor(col, row); // Set the cursor on the third column and first row.
  lcd.print(text);
}

void LCD::clear() {
  lcd.clear(); // Clear all display, set cursor to 1,1
}

void LCD::clear(int row, int col, int length) {
  char* SpaceString = (char*) malloc((length+1) * sizeof(char));
  //char SpaceString[length];

  for (int i = 0; i < length; i++) {
    SpaceString[i] = ' ';
  }
  SpaceString[length] = '\0';

  this->LCD::write(row, col, SpaceString);
  free(SpaceString);

  //for (int i = col; i < col+length; i++) {
  //  this->LCD::write(row, i, " ");
  //}

}
