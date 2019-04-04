#ifndef __FPU_H
#define __FPU_H
#include "math.h"
#include "stm32f4xx_conf.h"
void testFPU(void);
float testFPUMult(uint32_t count);
float testFPUDiv(uint32_t count);
float testFPUSinf(uint32_t count);
float testFPUCosf(uint32_t count);
float testFPUSqrtf(uint32_t count);
float testFPUVsqrtf(uint32_t count);
float testFPULogf(uint32_t count);
float testFPUAdd(uint32_t count);
float testFPULnf(uint32_t count);
float testFPUAbsf(uint32_t count);
float testFPUVabsf(uint32_t count);

#endif
