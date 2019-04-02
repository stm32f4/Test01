/**
 ******************************************************************************
 * @file    SysTick/main.h
 * @author  MCD Application Team
 * @version V1.0.0
 * @date    19-September-2011
 * @brief   Header for main.c module
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#define MenuHeight	20
#define MenuWidth 60
#define MenuColorR  153
#define MenuColorG  217
#define MenuColorB  234
#define MenuBorderR 112
#define MenuBorderG 146
#define MenuBorderB 190
#define MenuIColorR  255
#define MenuIColorG  255
#define MenuIColorB  255
#define MenuTextHeight 16
#define WindowR 0xFF
#define WindowG 0xD0
#define WindowB 0x80
#define PopupR 0xFF
#define PopupG 0x80
#define PopupB 0x80
#define TextR 0
#define TextG 0
#define TextB 0

#define TrackTouch_NoShow 1
#define TrackTouch_ShowXY 2
#define TrackTouch_ShowBars 4
#define TrackTouch_Cursor 8
#define TrackTouch_Pen 16

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
extern unsigned short imageDelay;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void TimingDelay_Decrement(void);
void Delay_ms(volatile short nTime);
void trackTouch(unsigned char options);
unsigned long GetTicks(void);
void displayTime(unsigned short posX, unsigned short posY, unsigned short time,
		unsigned long fcolor, unsigned long bcolor);

#endif /* __MAIN_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
