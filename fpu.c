/**
 ******************************************************************************
 * @file    Test01/fpu.c
 * @author  Goofie 31
 * @version V1.0.0
 * @date    03-December-2011
 * @brief   FPU test
 ******************************************************************************
 */
#include "fpu.h"
#include "main.h"
#include "ILI9325.h"
#include "AsciiLib.h"

#ifdef __FPU_USED
__attribute__((always_inline)) static float inline vsqrtf(float op1) {
	float result;
	__asm volatile ("vsqrt.f32 %0, %1" : "=w" (result) : "w" (op1) );
	return (result);
}
__attribute__((always_inline)) static float inline vabsf(float op1) {
	float result;
	__asm volatile ("vabs.f32 %0, %1" : "=w" (result) : "w" (op1) );
	return (result);
}
#endif

void testFPU(void) {
	uint32_t time;
	uint32_t count = 10000;
	char text[] = "Test of FPU unit\0";
	char text1[] = "xxxxx0 computations\0";
	char textRepl[22];
	uint16_t posY = 20;
	LCD_Clear(0xff, 0xff, 0xff);
	LCD_SetTextColor(0x00, 0x00, 0x00);
	LCD_SetBackColor(0xff, 0xff, 0xff);
	LCD_CharSize(16);
	LCD_StringLine(120 - ((sizeof text - 1) * 8) / 2, posY, text);
	posY += 20;
	memcpy(textRepl, text1, 30);
	getDecimalFromShort((char*) textRepl, (unsigned short) (count));
	LCD_StringLine(120 - ((sizeof textRepl - 1) * 8) / 2, posY, textRepl);
	posY += 20;
#if __FPU_USED == 1
	LCD_StringLine(120 - (8 * 8) / 2, posY, "With FPU\0");
#else
	LCD_StringLine(120 - (6 * 8) / 2, posY, "No FPU\0");
#endif
	posY += 40;

	time = GetTicks();
	testFPUAdd(count);
	time = (GetTicks() - time) / 10;
	LCD_StringLine(20, posY, "Add : ");
	displayTime(150, posY, time, 0x00, 0xffffff);

	time = GetTicks();
	testFPUMult(count);
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Multiply : ");
	displayTime(150, posY, time, 0x00, 0xffffff);

	time = GetTicks();
	testFPUDiv(count);
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Divide : ");
	displayTime(150, posY, time, 0x00, 0xffffff);

	time = GetTicks();
	testFPUSqrtf(count);
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Sqr : ");
	displayTime(150, posY, time, 0x00, 0xffffff);

	time = GetTicks();
#if __FPU_USED == 1
	testFPUVsqrtf(count);
#endif
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Sqr assembly  : ");
#if __FPU_USED == 1
	displayTime(150, posY, time, 0x00, 0xffffff);
#else
	LCD_StringLine(150, posY, "     N/A\0");
#endif

	time = GetTicks();
	testFPUSinf(count);
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Sinus : ");
	displayTime(150, posY, time, 0x00, 0xffffff);

	time = GetTicks();
	testFPUCosf(count);
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Cosinus : ");
	displayTime(150, posY, time, 0x00, 0xffffff);

	time = GetTicks();
	testFPULogf(count);
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Log : ");
	displayTime(150, posY, time, 0x00, 0xffffff);

	time = GetTicks();
	testFPULnf(count);
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Ln : ");
	displayTime(150, posY, time, 0x00, 0xffffff);

	time = GetTicks();
#if __FPU_USED == 1
	testFPUVabsf(count);
#endif
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Abs assembly  : ");
#if __FPU_USED == 1
	displayTime(150, posY, time, 0x00, 0xffffff);
#else
	LCD_StringLine(150, posY, "     N/A\0");
#endif

	time = GetTicks();
	testFPUAbsf(count);
	time = (GetTicks() - time) / 10;
	posY += 20;
	LCD_StringLine(20, posY, "Abs : ");
	displayTime(150, posY, time, 0x00, 0xffffff);

	Delay_ms(imageDelay);
}

void testFPUCosf(uint32_t count) {
	float resultat1, resultat2, resultat3, resultat4, resultat5;
	long i;
	for (i = 0; i < count; i++) {
		resultat1 = cosf((float) i);
		resultat2 = cosf(resultat1);
		resultat3 = cosf(resultat2);
		resultat4 = cosf(resultat3);
		resultat5 = cosf(resultat4);
		resultat1 = cosf(resultat5);
		resultat2 = cosf(resultat1);
		resultat3 = cosf(resultat2);
		resultat4 = cosf(resultat3);
		resultat5 = cosf(resultat4);
	}
}

void testFPUSinf(uint32_t count) {
	float resultat1, resultat2, resultat3, resultat4, resultat5;
	long i;
	for (i = 0; i < count; i++) {
		resultat1 = sinf((float) i);
		resultat2 = sinf(resultat1);
		resultat3 = sinf(resultat2);
		resultat4 = sinf(resultat3);
		resultat5 = sinf(resultat4);
		resultat1 = sinf(resultat5);
		resultat2 = sinf(resultat1);
		resultat3 = sinf(resultat2);
		resultat4 = sinf(resultat3);
		resultat5 = sinf(resultat4);
	}
}

void testFPUMult(uint32_t count) {
	float resultat1, resultat2, resultat3, resultat4, resultat5;
	long i;
	for (i = 0; i < count; i++) {
		resultat1 = (1.14159265358979323846f * (float) i);
		resultat2 = resultat1 * resultat1;
		resultat3 = resultat1 * resultat2;
		resultat4 = resultat2 * resultat3;
		resultat5 = resultat3 * resultat4;
		resultat1 = resultat5 * resultat1;
		resultat2 = resultat1 * resultat3;
		resultat3 = resultat2 * resultat4;
		resultat4 = resultat3 * resultat5;
		resultat5 = resultat3 * resultat4;
	}
}

void testFPUDiv(uint32_t count) {
	float resultat1, resultat2, resultat3, resultat4, resultat5;
	long i;
	for (i = 0; i < count; i++) {
		resultat1 = (1.14159265358979323846f / (float) i);
		resultat2 = resultat1 / resultat1;
		resultat3 = resultat1 / resultat2;
		resultat4 = resultat2 / resultat3;
		resultat5 = resultat3 / resultat4;
		resultat1 = resultat5 / resultat1;
		resultat2 = resultat1 / resultat3;
		resultat3 = resultat2 / resultat4;
		resultat4 = resultat3 / resultat5;
		resultat5 = resultat3 / resultat4;
	}
}

void testFPUVsqrtf(uint32_t count) {
	float resultat1, resultat2, resultat3, resultat4, resultat5;
	long i;
	for (i = 0; i < count; i++) {
		resultat1 = vsqrtf((float) i);
		resultat2 = vsqrtf(resultat1);
		resultat3 = vsqrtf(resultat2);
		resultat4 = vsqrtf(resultat3);
		resultat5 = vsqrtf(resultat4);
		resultat1 = vsqrtf(resultat5);
		resultat2 = vsqrtf(resultat1);
		resultat3 = vsqrtf(resultat2);
		resultat4 = vsqrtf(resultat3);
		resultat5 = vsqrtf(resultat4);
	}
}

void testFPUSqrtf(uint32_t count) {
	float resultat1, resultat2, resultat3, resultat4, resultat5;
	long i;
	for (i = 0; i < count; i++) {
		resultat1 = sqrtf((float) i);
		resultat2 = sqrtf(resultat1);
		resultat3 = sqrtf(resultat2);
		resultat4 = sqrtf(resultat3);
		resultat5 = sqrtf(resultat4);
		resultat1 = sqrtf(resultat5);
		resultat2 = sqrtf(resultat1);
		resultat3 = sqrtf(resultat2);
		resultat4 = sqrtf(resultat3);
		resultat5 = sqrtf(resultat4);
	}
}

void testFPUAdd(uint32_t count) {
	float resultat1, resultat2, resultat3, resultat4, resultat5;
	long i;
	for (i = 0; i < count; i++) {
		resultat1 = ((float) i + 1234.76443686765543465487f);
		resultat2 = (float) i + resultat1;
		resultat3 = resultat1 + resultat2;
		resultat4 = resultat2 + resultat3;
		resultat5 = resultat3 + resultat4;
		resultat1 = resultat4 + resultat5;
		resultat2 = resultat5 + resultat1;
		resultat3 = resultat1 + resultat2;
		resultat4 = resultat2 + resultat3;
		resultat5 = resultat3 + resultat4;
	}
}

void testFPULogf(uint32_t count) {
	float resultat1, resultat2, resultat3, resultat4, resultat5;
	long i;
	for (i = 0; i < count; i++) {
		resultat1 = log10f((float) i);
		resultat2 = log10f(resultat1);
		resultat3 = log10f(resultat2);
		resultat4 = log10f(resultat3);
		resultat5 = log10f(resultat4);
		resultat1 = log10f(resultat5);
		resultat2 = log10f(resultat1);
		resultat3 = log10f(resultat2);
		resultat4 = log10f(resultat3);
		resultat5 = log10f(resultat4);
	}
}

void testFPULnf(uint32_t count) {
	float resultat1, resultat2, resultat3, resultat4, resultat5;
	long i;
	for (i = 0; i < count; i++) {
		resultat1 = logf((float) i);
		resultat2 = logf(resultat1);
		resultat3 = logf(resultat2);
		resultat4 = logf(resultat3);
		resultat5 = logf(resultat4);
		resultat1 = logf(resultat5);
		resultat2 = logf(resultat1);
		resultat3 = logf(resultat2);
		resultat4 = logf(resultat3);
		resultat5 = logf(resultat4);
	}
}

void testFPUAbsf(uint32_t count) {
	signed long i;
	signed long counter = -count;
	for (i = 0; i > counter; i--) {
		fabsf((float) i++);
		fabsf((float) i--);
		fabsf((float) i++);
		fabsf((float) i--);
		fabsf((float) i++);
		fabsf((float) i--);
		fabsf((float) i++);
		fabsf((float) i--);
		fabsf((float) i++);
		fabsf((float) i--);
	}
}

void testFPUVabsf(uint32_t count) {
	signed long i;
	signed long counter = -count;
	for (i = 0; i > counter; i--) {
		vabsf((float) i++);
		vabsf((float) i--);
		vabsf((float) i++);
		vabsf((float) i--);
		vabsf((float) i++);
		vabsf((float) i--);
		vabsf((float) i++);
		vabsf((float) i--);
		vabsf((float) i++);
		vabsf((float) i--);
	}
}
