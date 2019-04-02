/**
 ******************************************************************************
 * @file    Test01/main.c
 * @author  Goofie 31
 * @version V1.0.0
 * @date    03-December-2011
 * @brief   Main program body
 ******************************************************************************
 */
#define	_welcome
//#define  _gamma18
//#define  _gamma20
//#define  _mario
//#define  _mireCouleur
//#define  _mireGris
#define  _gradientCouleur
#define  _gradientGris
#define  _fractal
#define  _colorBox
//#define _trackTouch
//#define _drawGrid
//#define _showMenu
//#define _TC_calibrate
#define _testReadRam
#define _testFPU

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fpu.h"
#include "stm32f4xx_conf.h"
#include "ILI9325.h"
#include "AD7846.h"
#include "AsciiLib.h"
#ifdef 	_gamma18
#include "gamma1.8.h"
#endif
#ifdef 	_gamma20
#include "gamma2.0.h"
#endif
#ifdef 	_fractal
#include "julia.h"
#endif
#ifdef 	_mario
#include "mario.h"
#endif
#ifdef 	_mireCouleur
#include "mireCouleur.h"
#endif
#ifdef 	_mireGris
#include "mireGris.h"
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;
uint16_t imageDelay = 4000;
uint32_t priority;
long i;
long j;
u8 TP_Press = 0;
u8 red = 0xFF;
u8 green = 0x00;
u8 blue = 0x00;
volatile uint32_t TimingDelay;
volatile uint32_t TimeCounter = 0;
volatile uint32_t Counter = 0;

/* Private function prototypes -----------------------------------------------*/
void gammaAdjust(void);
void fractal(void);
void dispMario(void);
void dispMireCouleur(void);
void dispMireGris(void);
void dispGradientCouleur(void);
void dispGradientGris(void);
void dispGamma18(void);
void dispGamma20(void);
void clear(void);
void dispWelcome(void);
void dispColorBox(void);
void testReadRam(void);
void drawGrid(u8 xScale, u8 yScale);
void initStatusBar(char info[]);
void writeStatus(char info[]);
void initSystick(void);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
	initSystick();
	LCD_Init();
	LCD_SetBackLight(75);
	TC_Init();
#ifdef _TC_calibrate
	TS_Calibrate();
#endif
#ifdef _showMenu
	initMenu();
#endif

	while (1) {
		TP_Press = 0;
#ifdef _welcome
		dispWelcome();
#endif
#ifdef _testReadRam
		testReadRam();
#endif
#ifdef _testFPU
		testFPU();
#endif
#ifdef _gamma18
		dispGamma18();
#endif
#ifdef	_gamma20
		dispGamma20();
#endif
#ifdef _mireCouleur
		dispMireCouleur();
#endif
#ifdef	_mireGris
		dispMireGris();
#endif
#ifdef	_gradientCouleur
		dispGradientCouleur();
#endif
#ifdef	_gradientGris
		dispGradientGris();
#endif
#ifdef	_colorBox
		dispColorBox();
#endif
#ifdef	_mario
		dispMario();
#endif
#ifdef	_fractal
		fractal();
#endif
#ifdef _drawGrid
		drawGrid(20, 20);
#endif
#ifdef _trackTouch
		while (1) {
			//Delay(10);
			//trackTouch(TrackTouch_Cursor | TrackTouch_ShowXY);
		}
#endif
	}
}

void fractal(void) {
#ifdef	_fractal
	int zoom = 500;
	int32_t time;
	LCD_Clear(0, 0, 0);
	LCD_SetColors(0xFF, 0XFF, 0xFF, 0, 0, 0);
	LCD_CharSize(16);

//	LCD_StringLine(0, 303, (uint8_t*) "Julia 1\0");
//	time = GetTicks();
//	Julia(240, 300, 120, 150, 500, 123874.4576654543F);
//	time = (GetTicks() - time) / 10;
//	displayTime(170, 304, (uint16_t) time, 0xffffff, 0x00);

//	LCD_StringLine(0, 303, (uint8_t*) "Julia 2\0");
//	time = GetTicks();
//	Julia2(240, 300, 120, 150, zoom);
//	time = (GetTicks() - time) / 10;
//	displayTime(170, 304, (uint16_t) time, 0xffffff, 0x00);

	LCD_StringLine(0, 304, "Julia 3\0");
	time = GetTicks();
	Julia3(240, 300, 120, 150, zoom);
	time = (GetTicks() - time) / 10;
	displayTime(170, 304, (uint16_t) time, 0xffffff, 0x00);

//	LCD_StringLine(0, 304, "Julia 4\0");
//	time = GetTicks();
//	Julia4(240, 300, 120, 150, zoom);
//	time = (GetTicks() - time) / 10;
//	displayTime(170, 304, (uint16_t) time, 0xffffff, 0x00);

//	LCD_StringLine(0, 304, (uint8_t*) "Julia 5\0");
//	time = GetTicks();
//	Julia5(240, 300, 120, 150, zoom);
//	time = (GetTicks() - time) / 10;
//	displayTime(170, 304, (uint16_t) time, 0xffffff, 0x00);

//	LCD_StringLine(0, 304, (uint8_t*) "Julia 6\0");
//	time = GetTicks();
//	Julia6(240, 300, 120, 150, zoom);
//	time = (GetTicks() - time) / 10;
//	displayTime(170, 304, (uint16_t) time, 0xffffff, 0x00);

//	LCD_StringLine(0, 304, (uint8_t*) "Julia 7\0");
//	time = GetTicks();
//	Julia7(240, 300, 120, 150, zoom);
//	time = (GetTicks() - time) / 10;
//	displayTime(170, 304, (uint16_t) time, 0xffffff, 0x00);

//	LCD_StringLine(0, 304, (uint8_t*) "Julia 8\0");
//	time = GetTicks();
//	Julia8(240, 300, 120, 150, zoom);
//	time = (GetTicks() - time) / 10;
//	displayTime(170, 304, (uint16_t) time, 0xffffff, 0x00);

	LCD_StringLine(0, 304, (char*) "Julia 9\0");
	time = GetTicks();
	Julia9(240, 300, 120, 150, zoom);
	time = (GetTicks() - time) / 10;
	displayTime(170, 304, (uint16_t) time, 0xffffff, 0x00);

	Delay_ms(imageDelay);
#endif
}

void dispGamma18(void) {
#ifdef	_gamma18

	LCD_Clear(0, 0, 0);
	LCD_Disp_Image(gamma18);
	Delay_ms(imageDelay);
#endif
}
void dispGamma20(void) {
#ifdef	_gamma20
	LCD_Clear(0,0,0);
	LCD_Disp_Image(gamma20);
	Delay_ms(imageDelay);
#endif
}
void dispMireGris(void) {
#ifdef	_mireGris
	LCD_Clear(0, 0, 0);
	LCD_Disp_Image(mireGris);
	Delay_ms(imageDelay);
#endif
}
void dispMireCouleur(void) {
#ifdef	_mireCouleur
	LCD_Clear(0, 0, 0);
	LCD_Disp_Image(mireCouleur);
	Delay_ms(imageDelay);
#endif
}
void dispGradientCouleur(void) {
#ifdef	_gradientCouleur
	//Color gradient
	const u8 maxCol = 53;
	Counter = TimeCounter;
	LCD_Clear(0, 0, 0);
	LCD_SetCursor(0, 0);
	LCD_WriteRAM_Prepare();
	red = maxCol;
	green = 0;
	blue = 0;
	for (i = 0; i < 320; i++) {
		for (j = 0; j < 240; j++) {
			LCD_WriteRAM((red << 2) * 63.0F / maxCol,
					(green << 2) * 63.0F / maxCol,
					(blue << 2) * 63.0F / maxCol);
		}
		if (red == maxCol && green < maxCol && blue == 0) {
			green++;
		} else if (green == maxCol && red > 0) {
			red--;
		} else if (green == maxCol && blue < maxCol) {
			blue++;
		} else if (blue == maxCol && green > 0) {
			green--;
		} else if (blue == maxCol && red < maxCol) {
			red++;
		} else if (red == maxCol && blue > 0) {
			blue--;
		}
	}
	Counter = (TimeCounter - Counter) / 10;
	displayTime(170, 304, Counter, 0xffffff, 0x00);
	Delay_ms(imageDelay);
#endif
}
void dispGradientGris(void) {
#ifdef _gradientGris
	// White gradient
	signed int dir;
	LCD_Clear(0, 0, 0);
	Counter = TimeCounter;
	red = 0;
	green = 0;
	blue = 0;
	LCD_SetCursor(0, 0);
	LCD_WriteRAM_Prepare();
	for (i = 0; i < 320; i += 5) {
		for (j = 0; j < 240; j++) {
			LCD_WriteRAM(red << 2, green << 2, blue << 2);
			LCD_WriteRAM(red << 2, green << 2, blue << 2);
			LCD_WriteRAM(red << 2, green << 2, blue << 2);
			LCD_WriteRAM(red << 2, green << 2, blue << 2);
			LCD_WriteRAM(red << 2, green << 2, blue << 2);
		}
		if (red == 63) {
			dir = -1;
		} else if (red == 0) {
			dir = 1;
		}
		red += dir;
		green += dir;
		blue += dir;
	}
	Counter = (TimeCounter - Counter) / 10;
	displayTime(170, 304, Counter, 0xffffff, 0x00);
	Delay_ms(imageDelay);
#endif
}
void dispMario(void) {
#ifdef	_mario
	LCD_Clear(0, 0, 0);
	Counter = TimeCounter;
	LCD_Disp_Image((unsigned short*) mario);
	Counter = (TimeCounter - Counter) / 10;
	displayTime(170, 304, Counter, 0xffffff, 0x00);
	Delay_ms(imageDelay);
#endif
}

void dispColorBox(void) {
#ifdef	_colorBox
	// Boxes
	LCD_Clear(0, 0, 0);
	Counter = TimeCounter;
	red = 63;
	green = 0;
	blue = 0;
	LCD_SetCursor(0, 0);
	LCD_WriteRAM_Prepare();
	for (i = 0; i < 320; i++) {
		for (j = 0; j < 240; j++) {
			if (j < 60) {
				LCD_WriteRAM(red << 2, green << 2, blue << 2);
			} else if (j < 120) {
				LCD_WriteRAM(red << 1, green << 1, blue << 1);
			} else if (j < 180) {
				LCD_WriteRAM(red, green, blue);
			} else {
				LCD_WriteRAM(red >> 1, green >> 1, blue >> 1);
			}
		}
		if (i == 40) {
			green = 63;
		} else if (i == 80) {
			red = 0;
		} else if (i == 120) {
			blue = 63;
		} else if (i == 160) {
			green = 0;
		} else if (i == 200) {
			red = 63;
		} else if (i == 240) {
			green = 63;
		} else if (i == 280) {
			red = 0;
			green = 0;
			blue = 0;
		}
	}
	Counter = (TimeCounter - Counter) / 10;
	displayTime(170, 304, Counter, 0xffffff, 0x00);
	Delay_ms(imageDelay);
#endif
}
void gammaAdjust(void) {
	// R48 Fine Gamma KP1 - KP0 	[2:0] [2:0]
	// R49 Fine Gamma KP2 - KP3 	[2:0] [2:0]
	// R50 Fine Gamma KP4 - KP5 	[2:0] [2:0]
	// R53 Gradient RP1 - RP0 		[2:0] [2:0]
	// R54 Amplitude VRP1 - VRP0	[5:0] [5:0]
	// R55 Fine Gamma KN1 - KN0 	[2:0] [2:0]
	// R56 Fine Gamma KN3 - KN2 	[2:0] [2:0]
	// R57 Fine Gamma KN5 - KN4 	[2:0] [2:0]
	// R60 Gradient RN1 - RN0 		[2:0] [2:0]
	// R61 Amplitude VRP1 - VRP0	[5:0] [5:0]
}

void trackTouch(u8 options) {
	u16 const minX = 0x10;
	u16 const maxX = 0xF1;
	u16 const minY = 0x10;
	u16 const maxY = 0xF1;
	char val[4];
	const short mX = (240 << 8) / (maxX - minX);
	const short mY = (320 << 8) / (maxY - minY);
	u16 valX, valBisX;
	u16 valY, valBisY;
	u16 posX;
	u16 posY;
	static u16 dmaxX = 0;
	static u16 dmaxY = 0;
	static u16 lastX = 0;
	static u16 lastY = 0;

	while (1) {
		TC_set_interrupt(0);
		Read_Ads7846_filter();
		Convert_Pos();
		valX = Pen_Point.X >> 3;
		valY = Pen_Point.Y >> 3;

		//rc = Read_Ads7846();
		//valX = Pen_Point.X >> 3;
		//valY = Pen_Point.Y >> 3;

		if (valX > dmaxX)
			dmaxX = valX;
		if (valY > dmaxY)
			dmaxY = valY;

		if (options & TrackTouch_ShowXY) {
			LCD_CharSize(24);
			LCD_SetTextColor(TextR, TextG, TextB);
			LCD_SetBackColor(WindowR, WindowG, WindowB);
			val[0] = digitToAscii[(valX & 0x0F00) >> 8];
			val[1] = digitToAscii[(valX & 0x00F0) >> 4];
			val[2] = digitToAscii[valX & 0x000F];
			val[3] = 0;
			LCD_StringLine(120 - 16, 100, val);
			val[0] = digitToAscii[(dmaxX & 0x0F00) >> 8];
			val[1] = digitToAscii[(dmaxX & 0x00F0) >> 4];
			val[2] = digitToAscii[dmaxX & 0x000F];
			val[3] = 0;
			LCD_StringLine(120 - 16, 120, val);

			val[0] = digitToAscii[(valY & 0x0F00) >> 8];
			val[1] = digitToAscii[(valY & 0x00F0) >> 4];
			val[2] = digitToAscii[valY & 0x000F];
			val[3] = 0;
			LCD_StringLine(120 - 16, 200, val);
			val[0] = digitToAscii[(dmaxY & 0x0F00) >> 8];
			val[1] = digitToAscii[(dmaxY & 0x00F0) >> 4];
			val[2] = digitToAscii[dmaxY & 0x000F];
			val[3] = 0;
			LCD_StringLine(120 - 16, 220, val);
		}

		//posX = 240 - (((valX - minX) * mX) >> 8);
		//posY = ((valY - minY) * mY) >> 8;

		posX = Pen_Point.X0;
		posY = Pen_Point.Y0;

		if (options & TrackTouch_Cursor) {
			if (lastX != posX || lastY != posY) {
				LCD_SetTextColor(WindowR, WindowG, WindowB);
				LCD_DrawFullCircle(lastX, lastY, 2);
				LCD_SetTextColor(TextR, TextG, TextB);
				LCD_DrawFullCircle(posX, posY, 2);
				lastX = posX;
				lastY = posY;
			}
		}

		if (options & TrackTouch_Pen) {
			if (lastX != posX || lastY != posY) {
				LCD_SetTextColor(TextR, TextG, TextB);
				LCD_DrawFullCircle(posX, posY, 1);
				lastX = posX;
				lastY = posY;
			}
		}

		if (options & TrackTouch_ShowBars) {
			LCD_SetTextColor(0xFF, 0xFF, 0);

			if (valX > 0)
				LCD_DrawFullRect(0, 0, posX, 10);
			if (valY > 0)
				LCD_DrawFullRect(0, 0, 10, posY);

			LCD_SetTextColor(WindowR, WindowG, WindowB);

			if (valX > 0)
				LCD_DrawFullRect(posX, 0, 240 - posX, 10);

			if (valY > 0)
				LCD_DrawFullRect(0, posY, 10, 320 - posY);

			LCD_SetTextColor(TextR, TextG, TextB);
		}

		TC_set_interrupt(1);

		if (valX < minX || valY < minY) {
			touch_done = 0;
			break;
		}

	}
}

void drawGrid(u8 xScale, u8 yScale) {
	short pos = 0;
	LCD_Clear(0, 0, 0);
	LCD_SetTextColor(0xff, 0xff, 0xff);
	while (pos < 320) {
		LCD_DrawLine(0, pos, 240, Horizontal);
		pos += yScale;
	}
	pos = 0;
	while (pos < 240) {
		LCD_DrawLine(pos, 0, 320, Vertical);
		pos += xScale;
	}
}

void initMenu() {
	int textIndex = 0;
	LCD_Clear(WindowR, WindowG, WindowB);
	char * text[] = { "Menu1", "Menu2", "Menu3", "Menu4" };
	for (textIndex = 0; textIndex < 4; textIndex++) {
		LCD_SetTextColor(MenuColorR, MenuColorG, MenuColorB);
		LCD_SetBackColor(MenuColorR, MenuColorG, MenuColorB);
		LCD_DrawFullRect(MenuWidth * textIndex, 0, MenuWidth, MenuHeight);
		LCD_SetTextColor(MenuBorderR, MenuBorderG, MenuBorderB);
		LCD_DrawRect(MenuWidth * textIndex, 0, MenuWidth, MenuHeight);
		LCD_CharSize(16);
		int pos = (MenuWidth * textIndex)
				+ ((MenuWidth - (strlen(text[textIndex])) * 8) >> 1);
		LCD_SetTextColor(0, 0, 0);
		LCD_StringLine(pos, 4, text[textIndex]);
		initStatusBar("Ready...");
	}
	TC_set_interrupt(1);
	//Delay(1000);
}

void initStatusBar(char info[]) {
	LCD_SetTextColor(MenuColorR, MenuColorG, MenuColorB);
	LCD_DrawFullRect(0, 320 - MenuHeight, 240, MenuHeight);
	LCD_SetTextColor(MenuBorderR, MenuBorderG, MenuBorderB);
	LCD_DrawLine(0, 320 - MenuHeight, 240, Horizontal);
	writeStatus(info);
}

void writeStatus(char info[]) {
	LCD_CharSize(16);
	LCD_SetTextColor(0, 0, 0);
	LCD_SetBackColor(MenuColorR, MenuColorG, MenuColorB);
	LCD_StringLine(0, 320 - MenuHeight + 4, info);
}

void dispWelcome(void) {
	LCD_Clear(0, 0, 0);
	uint32_t time = GetTicks();
	const int height = 299;
	const int baseY = height / 2 - 44;
	int radius = 40;
	u16 chipType = LCD_ReadReg(R0);

	LCD_SetTextColor(0xFF, 0xFF, 0xFF);
	LCD_SetBackColor(0, 0, 0);
	LCD_CharSize(24);
	LCD_StringLine(120 - (11 * 16) / 2, baseY, "Cortex m4");

	char text[] = "Test of 2.8 \" TFT 262K panel\0";
	LCD_CharSize(16);
	LCD_StringLine(120 - ((sizeof text - 1) * 8) / 2, baseY + 24, text);

	char text1[17] = "Chip type : xxxx";
	char chipText[5];
	getAsciiFromShort(chipText, chipType);
	memcpy(&text1[12], &chipText, 5);
	LCD_StringLine(120 - ((sizeof text1 - 1) * 8) / 2, baseY + 24 + 16, text1);
	char text2[] = "and powered by STM32F4";
	LCD_StringLine(120 - ((sizeof text2 - 1) * 8) / 2, baseY + 24 + 16 * 2,
			text2);
	char text3[] = "discovery board";
	LCD_StringLine(120 - ((sizeof text3 - 1) * 8) / 2, baseY + 24 + 16 * 3,
			text3);
	//Delay(1000);
	LCD_SetTextColor(0xFF, 0, 0);
	LCD_DrawFullCircle(radius, radius, radius);
	LCD_SetTextColor(0, 0xFF, 0);
	LCD_DrawFullCircle(239 - radius, radius, radius);
	LCD_SetTextColor(0, 0, 0xFF);
	LCD_DrawFullCircle(radius, height - radius, radius);
	LCD_SetTextColor(0xFF, 0xFF, 0);
	LCD_DrawFullCircle(239 - radius, height - radius, radius);
	time = (GetTicks() - time) / 10;
	displayTime(170, 304, time, 0xffffff, 0x00);
	Delay_ms(imageDelay);
}

void testReadRam(void) {
	int i;
	int j;
	int k;
	u32 val;
	u8 red;
	u8 green;
	u8 blue;
	const u8 maxCol = 52;
	Counter = TimeCounter;
	LCD_Clear(0, 0, 0);
	LCD_SetCursor(0, 0);
	LCD_WriteRAM_Prepare();
	red = maxCol;
	green = 0;
	blue = 0;
	for (i = 0; i < 150; i++) {
		for (j = 0; j < 240; j++) {
			LCD_WriteRAM((red << 2) * 63.0F / maxCol,
					(green << 2) * 63.0F / maxCol,
					(blue << 2) * 63.0F / maxCol);
		}
		if (red == maxCol && green < maxCol && blue == 0) {
			green += 2;
		} else if (green >= maxCol && red > 0) {
			red -= 2;
		} else if (green == maxCol && blue < maxCol) {
			blue += 2;
		} else if (blue == maxCol && green > 0) {
			green -= 2;
		} else if (blue == maxCol && red < maxCol) {
			red += 2;
		} else if (red == maxCol && blue > 0) {
			blue -= 2;
		}
	}

	for (k = 0; k < 150; k++) {
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 8; j++) {
				LCD_SetCursor(i * 8 + j, k);
				val = LCD_ReadRAM();
				red = (val >> 16);
				green = (val >> 8);
				blue = val;
				LCD_SetCursor(i * 8 + j, k + 160);
				LCD_WriteRAM_Prepare();
				LCD_WriteRAM(red, green, blue);
			}
		}
	}
	Counter = (TimeCounter - Counter) / 10;
	displayTime(170, 304, Counter, 0xffffff, 0x00);
	Delay_ms(imageDelay);
}
/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in milliseconds.
 * @retval None
 */
void Delay_ms(__IO short nTime) {
	TimingDelay = nTime * 10;
	while (TimingDelay != 0)
		;
}

/**
 * @brief  Decrements the TimingDelay variable.
 * @param  None
 * @retval None
 */
void TimingDelay_Decrement(void) {
	if (TimingDelay != 0x00) {
		TimingDelay--;
	}
	TimeCounter++;
}

/**
 * @brief  Get number of milliseconds since start
 * @param  None
 * @retval Number of ms elapsed since reset
 */
unsigned long GetTicks(void) {
	return TimeCounter;
}

void initSystick(void) {
	if (SysTick_Config(SystemCoreClock / 10000))
		while (1)
			;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_SetPriority(SysTick_IRQn,
			NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
}

void displayTime(uint16_t posX, uint16_t posY, uint16_t time, uint32_t fcolor,
		uint32_t bcolor) {
	char * TextTime[10];
	memcpy(TextTime, "xxxxx ms \0", 10);
	LCD_SetTextColor(fcolor >> 16, fcolor >> 8, fcolor);
	LCD_SetBackColor(bcolor >> 16, bcolor >> 8, bcolor);
	LCD_CharSize(16);
	getDecimalFromShort((char*) TextTime, (unsigned short) time);
	LCD_StringLine(posX, posY, (char *) TextTime);
}
