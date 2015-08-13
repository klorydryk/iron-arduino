#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins

#define PIN_LCD_RS      12
#define PIN_LCD_ENABLE  11
#define PIN_LCD_D4      5
#define PIN_LCD_D5      4
#define PIN_LCD_D6      3
#define PIN_LCD_D7      2

LiquidCrystal lcd(
  PIN_LCD_RS,
  PIN_LCD_ENABLE,
  PIN_LCD_D4,
  PIN_LCD_D5,
  PIN_LCD_D6,
  PIN_LCD_D7
);


char* texte_lines[2];
int   texte_sizes[2] = {0,0};
int   texte_decal[2] = {0,0};

int delai_decalage = 100;  // Bigger is slower
int delai_decalage_now = 0;  // Bigger is slower

void lcd_setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd_setText(0,"Hello, wonderful arduino world ! ");
}

void lcd_setText(int line, char* message) {
  texte_lines[line] = message;
  texte_sizes[line] = strlen(message);
  texte_decal[line] = 0;
}

void lcd_decale(int line) {
    if (delai_decalage_now++ == delai_decalage) {
        delai_decalage_now = 0;
        texte_decal[line]++;
        if (texte_decal[line] == texte_sizes[line]) {
          texte_decal[line] = 0;
        }
        
        lcd.setCursor(0,line);
        lcd.print(texte_lines[line]+ texte_decal[line]);

    }
}

