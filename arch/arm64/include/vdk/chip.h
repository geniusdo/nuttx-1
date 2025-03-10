/****************************************************************************
 * arch/arm64/include/vdk/chip.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM64_INCLUDE_VDK_CHIP_H
#define __ARCH_ARM64_INCLUDE_VDK_CHIP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Number of bytes in x kibibytes/mebibytes/gibibytes */

#define KB(x)           ((x) << 10)
#define MB(x)           (KB(x) << 10)
#define GB(x)           (MB(UINT64_C(x)) << 10)

#if defined(CONFIG_ARCH_CHIP_VDK)

#if CONFIG_ARM64_GIC_VERSION == 3 || CONFIG_ARM64_GIC_VERSION == 4

#define CONFIG_GICD_BASE          0xe5a00000
#define CONFIG_GICR_BASE          0xe5a40000
#define CONFIG_GICR_OFFSET        0x20000

#else

#error CONFIG_ARM64_GIC_VERSION should be 3 or 4

#endif /* CONFIG_ARM64_GIC_VERSION */

#define CONFIG_RAMBANK_ADDR      0x80000000
#define CONFIG_RAMBANK_SIZE      MB(128)
#define CONFIG_RAMBANK_END       \
        (CONFIG_RAMBANK_ADDR + CONFIG_RAMBANK_SIZE)

#define CONFIG_DEVICEIO1_BASEADDR  0xe0000000
#define CONFIG_DEVICEIO1_SIZE      MB(128)
#define CONFIG_DEVICEIO1_END       \
        (CONFIG_DEVICEIO1_BASEADDR + CONFIG_DEVICEIO1_SIZE)

#define CONFIG_SRAM_BASEADDR       0xf0000000
#define CONFIG_SRAM_SIZE           0x40000
#define CONFIG_SRAM_END       \
        (CONFIG_SRAM_BASEADDR + CONFIG_SRAM_SIZE)

#define CONFIG_LOAD_BASE          0x80000000

#define MPID_TO_CLUSTER_ID(mpid)  ((mpid) & ~0xff)

#endif

/****************************************************************************
 * Assembly Macros
 ****************************************************************************/

#ifdef __ASSEMBLY__

.macro  get_cpu_id xreg0
  mrs    \xreg0, mpidr_el1
  ubfx   \xreg0, \xreg0, #8, #8
.endm

#endif /* __ASSEMBLY__ */

#endif /* __ARCH_ARM64_INCLUDE_VDK_CHIP_H */
