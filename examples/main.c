/*
 * SSD1306xLED - Drivers for SSD1306 controlled dot matrix OLED/PLED 128x64 displays
 *
 * @created: 2014-08-08
 * @author: Neven Boyanov
 *
 * Source code available at: https://bitbucket.org/tinusaur/ssd1306xled
 *
 */

// ============================================================================

#define F_CPU 1000000UL

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

// ======================================
//                ATtiny
//               25/45/85
//              +----------+
//        RST --+ PB5  Vcc +---(+)-------
//            --+ PB3  PB2 +---SCL-------
//            --+ PB4  PB1 +-- 
// -------(-)---+ GND  PB0 +---SDA-------
//              +----------+
// ======================================

// -----(+)--------------->	// Vcc,	Pin 1 on SSD1306 Board
// -----(-)--------------->	// GND,	Pin 2 on SSD1306 Board
#define SSD1306_SCL		PB2	// SCL,	Pin 3 on SSD1306 Board
#define SSD1306_SDA		PB0	// SDA,	Pin 4 on SSD1306 Board

#define SSD1306_SA		0x78	// Slave address

// ----------------------------------------------------------------------------

#include "../ssd1306xled/ssd1306xled.h"
#include "../ssd1306xled/ssd1306xled8x16.h"

// ============================================================================

#include "img0_128x64c1.h"
#include "img1_128x64c1.h"

// ============================================================================

int main(void)
{
	// ---- Initialization ----
	
	// Small delay is necessary if ssd1306_initis the first operation in the application.
	_delay_ms(40);
	ssd1306_init();

	// ---- Main Loop ----

	while (1) {

		uint8_t p = 0xff;
		for (uint8_t i = 0; i < 4; i++)
		{
			p = (p >> i);
			ssd1306_fillscreen(~p);
			_delay_ms(100);
		}

		ssd1306_fillscreen(0x00);
		ssd1306_setpos(0, 1);
		ssd1306_string_font6x8("That's the");
		ssd1306_char_f8x16(64, 0, "Tinusaur");
		// ssd1306_setpos(43, 3);
		// ssd1306_string_font6x8("project");
		ssd1306_setpos(0, 3);
		ssd1306_string_font6x8("The platform that gives you everything you need for your first microcontroller project");
		ssd1306_setpos(12, 7);
		ssd1306_string_font6x8("http://tinusaur.org");
		_delay_ms(6000);
		
		ssd1306_draw_bmp(0,0,128,8, img1_128x64c1);
		_delay_ms(4000);

		ssd1306_draw_bmp(0,0,128,8, img0_128x64c1);
		_delay_ms(6000);
	}
	
	return (0);
}
