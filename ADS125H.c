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
#define ADDRESS_SIXBITS        0x3F


uint32_t Adc_Read(uint8_t reg_add)
{
    uint32_t tx_buf = 0;
    uint32_t rx_buf = 0;

    tx_buf = ((READ_REG_COMMAND | (reg_add & ADDRESS_SIXBITS)) <<16) | (0x00 << 8) | (0x00);    
                                             

    //Do: SPI Transfer
    //DO: SPI Read
  return;
}

uint32_t Adc_Write(uint8_t reg_add, uint32_t data)
{
    uint32_t tx_buf = 0;
    uint32_t rx_buf = 0;

    tx_buf = ((WRITE_REG_COMMAND | (reg_add & ADDRESS_SIXBITS)) << 16) | (0x00 << 8) |(data);
    //Do: SPI Transfer

    return;
}

void Read_dev_id(void)
{
    uint32_t reg_value = 0;
    Dev_id_reg devid;

   reg_value =  Adc_Read(DEVICE_ID);
   devid.all = (uint8_t)(reg_value) & 0xFF;
   printf("Device id: %d",devid.bits.dev_id);

}