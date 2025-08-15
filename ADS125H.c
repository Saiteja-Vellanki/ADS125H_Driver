#include "ADS125H.h"

/*
ADS125H SPI Command Summary
-------------------------------------------------------------------------------------------------------------
Command Description               Byte 1 (Command)            Byte 2             Byte 3 (Optional CRC-IN)
-------------------------------------------------------------------------------------------------------------
No Operation (Read Conversion)    0x00                        0x00               CRC-IN of Byte 1 and Byte 2
Read Register                     0x40 + (address[5:0])       Don't care         CRC-IN of Byte 1 and Byte 2
Write Register                    0x80 + (address[5:0])       Register data      CRC-IN of Byte 1 and Byte 2
Read FIFO Buffer                  0x0F                        Don't care         CRC-IN of Byte 1 and Byte 2
--------------------------------------------------------------------------------------------------------------
*/

#define READ_CONV_NOP_COMMAND  0x00
#define READ_REG_COMMAND       0x40
#define WRITE_REG_COMMAND      0x80
#define READ_FIFO_BUFF_COMMAND 0x0F


