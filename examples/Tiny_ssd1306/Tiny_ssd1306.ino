#include <font6x8.h>
#include <font8x16.h>
#include <ssd1306xled.h>
#include <ssd1306xled8x16.h>

// ============================================================================

#include "img0_128x64c1.h"
#include "img1_128x64c1.h"

// SSD1306Device SSD1306;

void setup() {
  // put your setup code here, to run once:
  _delay_ms(40);
  SSD1306.ssd1306_init();

}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t p = 0xff;
  for (uint8_t i = 0; i < 4; i++)
  {
    p = (p >> i);
    SSD1306.ssd1306_fillscreen(~p);
    _delay_ms(100);
  }

  SSD1306.ssd1306_fillscreen(0x00);
  SSD1306.ssd1306_setpos(0, 1);
  SSD1306.ssd1306_string_font6x8("That's the");
  SSD1306.ssd1306_char_f8x16(64, 0, "Tinusaur");
  SSD1306.ssd1306_setpos(43, 3);
  SSD1306.ssd1306_string_font6x8("project");
  SSD1306.ssd1306_setpos(0, 3);
  SSD1306.ssd1306_string_font6x8("The platform that gives you everything you need for your first microcontroller project");
  SSD1306.ssd1306_setpos(12, 7);
  SSD1306.ssd1306_string_font6x8("http://tinusaur.org");
  _delay_ms(6000);

  SSD1306.ssd1306_draw_bmp(0, 0, 128, 8, img1_128x64c1);
  _delay_ms(4000);

  SSD1306.ssd1306_draw_bmp(0, 0, 128, 8, img0_128x64c1);
  _delay_ms(6000);
}
