/*
 * NvM_EEPROM.h
 *
 *  Created on: 12-Oct-2026
 *      Author: acer
 */
#ifndef NVM_H
#define NVM_H

#include <stdint.h>
#include "sdk_project_config.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* ================= Configuration ================= */

#define NVM_BLOCK_COUNT       3U
#define BLOCK_LENGTH          3U
#define CRC_SIZE              1U
#define RECORD_SIZE           (BLOCK_LENGTH + CRC_SIZE)

#define LPI2C_INSTANCE        0U

#define BLOCK1_ADDRESS        0x000U
#define BLOCK2_ADDRESS        0x010U
#define BLOCK3_ADDRESS        0x020U

/* ================= Private configuration ================= */

#define EEPROM_I2C_ADDRESS    0x50U
#define EEPROM_CAPACITY       512U
#define EEPROM_PAGE_SIZE      16U
#define I2C_TIMEOUT           1000U
#define UART_TIMEOUT          1000U

/* ================= NvM Variables ================= */

static uint16_t failedBlocks[NVM_BLOCK_COUNT];
static uint8_t  failedBlockCount = 0U;

static uint8_t ramMirror1[BLOCK_LENGTH];
static uint8_t ramMirror2[BLOCK_LENGTH];
static uint8_t ramMirror3[BLOCK_LENGTH];

/* ================= Block Registration ================= */


/*
 * Set to 1 for the initial write-and-read test.
 * After successful verification, change to 0
 * to read existing EEPROM contents without rewriting.
 */
#define WRITE_INITIAL_DATA    1U

/* ================= Public API ================= */

/* Initialize clocks, pins, UART and I2C, then print the banner */
void NvM_Init(void);

/* Run the full startup sequence:
 * optional initial write -> ReadAll -> print pass/fail log */
void NvM_Run(void);

#endif /* NVM_H */
