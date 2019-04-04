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

#if __FPU_USED == 1
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
	uint32_t count = 60000;
	char text[] = "Test of FPU unit\0";
	char text1[] = "       computations\0";
	uint16_t posY = 20;
	LCD_Clear(0xff, 0xff, 0xff);
	LCD_SetTextColor(0x00, 0x00, 0x00);
	LCD_SetBackColor(0xff, 0xff, 0xff);
	LCD_CharSize(16);
	LCD_StringLine(120 - ((sizeof text - 1) * 8) / 2, posY, text);
	posY += 20;
	getDecimalFromShort((char*) text1, (unsigned short) (count));
	LCD_StringLine(120 - ((sizeof text1 - 1) * 8) / 2, posY, text1);
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

float testFPUCosf(uint32_t count) {
	float resultat1=0;
	volatile float i;
	for (i = 0; i < count; i++) {
		resultat1 += cosf(i);
	}
	return resultat1;
}

float testFPUSinf(uint32_t count) {
	float resultat1=0;
	volatile float i;
	for (i = 0; i < count; i++) {
		resultat1 += sinf(i);
	}
	return resultat1;
}

float testFPUMult(uint32_t count) {
	float resultat1=0, resultat2=0, resultat3=0, resultat4=0, resultat5=0;
	volatile float i;
	for (i = 0; i < count; i++) {
		resultat1 = i;
		resultat2 += resultat1 * resultat1;
		resultat3 += resultat1 * resultat2;
		resultat4 += resultat2 * resultat3;
		resultat5 += resultat3 * resultat4;
	}
	return resultat5;
}

float testFPUDiv(uint32_t count) {
	float resultat1=0, resultat2=0, resultat3=0, resultat4=0, resultat5=0;
	volatile float i;
	for (i = 0; i < count; i++) {
		resultat1 = i;
		resultat2 += (i + resultat1) / resultat1;
		resultat3 += resultat1 / resultat2;
		resultat4 += resultat2 / resultat3;
		resultat5 += resultat3 / resultat4;
	}
	return resultat5;
}

float testFPUVsqrtf(uint32_t count) {
	float resultat1=0, resultat2=0, resultat3=0, resultat4=0, resultat5=0;
	volatile float i;
	for (i = 0; i < count; i++) {
		resultat1 += vsqrtf(i);
		resultat2 += vsqrtf(resultat1);
		resultat3 += vsqrtf(resultat2);
		resultat4 += vsqrtf(resultat3);
		resultat5 += vsqrtf(resultat4);
	}
	return resultat5;
}

float testFPUSqrtf(uint32_t count) {
	float resultat1=0, resultat2=0, resultat3=0, resultat4=0, resultat5=0;
	volatile float i;
	for (i = 0; i < count; i++) {
		resultat1 += sqrtf(i);
		resultat2 += sqrtf(resultat1);
		resultat3 += sqrtf(resultat2);
		resultat4 += sqrtf(resultat3);
		resultat5 += sqrtf(resultat4);
	}
	return resultat5;
}

float testFPUAdd(uint32_t count) {
	float resultat1=0, resultat2=0, resultat3=0, resultat4=0, resultat5=0;
	volatile float i;
	for (i = 0; i < count; i++) {
		resultat1 += i;
		resultat2 += resultat1;
		resultat3 += resultat1 + resultat2;
		resultat4 += resultat1 + resultat2 + resultat3;
		resultat5 += resultat1 + resultat2 + resultat3 + resultat4;
	}
	return resultat5;
}

float testFPULogf(uint32_t count) {
	float resultat1=0, resultat2=0, resultat3=0, resultat4=0, resultat5=0;
	volatile float i;
	for (i = 0; i < count; i++) {
		resultat1 += log10f(i);
		resultat2 += log10f(resultat1);
		resultat3 += log10f(resultat2);
		resultat4 += log10f(resultat3);
		resultat5 += log10f(resultat4);
	}
	return resultat5;
}

float testFPULnf(uint32_t count) {
	float resultat1=0, resultat2=0, resultat3=0, resultat4=0, resultat5=0;
	volatile float i;
	for (i = 0; i < count; i++) {
		resultat1 += logf((float) i);
		resultat2 += logf(resultat1);
		resultat3 += logf(resultat2);
		resultat4 += logf(resultat3);
		resultat5 += logf(resultat4);
	}
	return resultat5;
}

float testFPUAbsf(uint32_t count) {
	volatile float i;
	volatile float counter = -count;
	float resultat=0;
	for (i = 0; i > counter; i--) {
		resultat += fabsf(i++);
		resultat += fabsf(i--);
		resultat += fabsf(i++);
		resultat += fabsf(i--);
		resultat += fabsf(i++);
		resultat += fabsf(i--);
		resultat += fabsf(i++);
		resultat += fabsf(i--);
		resultat += fabsf(i++);
		resultat += fabsf(i--);
	}
	return resultat;
}

float testFPUVabsf(uint32_t count) {
	volatile float i;
	volatile float counter = -count;
	float resultat=0;
	for (i = 0; i > counter; i--) {
		resultat += vabsf((float) i++);
		resultat += vabsf((float) i--);
		resultat += vabsf((float) i++);
		resultat += vabsf((float) i--);
		resultat += vabsf((float) i++);
		resultat += vabsf((float) i--);
		resultat += vabsf((float) i++);
		resultat += vabsf((float) i--);
		resultat += vabsf((float) i++);
		resultat += vabsf((float) i--);
	}
	return resultat;
}
