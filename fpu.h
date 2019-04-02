#ifndef __FPU_H
#define __FPU_H
#include "math.h"
#include "stm32f4xx_conf.h"
void testFPU(void);
void testFPUMult(uint32_t count);
void testFPUDiv(uint32_t count);
void testFPUSinf(uint32_t count);
void testFPUCosf(uint32_t count);
void testFPUSqrtf(uint32_t count);
void testFPUVsqrtf(uint32_t count);
void testFPULogf(uint32_t count);
void testFPUAdd(uint32_t count);
void testFPULnf(uint32_t count);
void testFPUAbsf(uint32_t count);
void testFPUVabsf(uint32_t count);

#endif
