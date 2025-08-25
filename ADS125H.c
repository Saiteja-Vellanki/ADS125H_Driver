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

void RSPI0_Init(void)
{
    SYSTEM.PRCR.WORD = 0xA50B;   // Unlock
    MSTP(RSPI0) = 0;             // Cancel module stop
    SYSTEM.PRCR.WORD = 0xA500;   // Lock

  
    MPC.P20PFS.BYTE = 0x0D;      // RSPCKA
    MPC.P21PFS.BYTE = 0x0D;      // MISOA
    MPC.P22PFS.BYTE = 0x0D;      // MOSIA

    PORT2.PMR.BIT.B0 = 1;        // Peripheral
    PORT2.PMR.BIT.B1 = 1;
    PORT2.PMR.BIT.B2 = 1;

    MPC.P23PFS.BYTE = 0x00;      // GPIO function
    PORT2.PDR.BIT.B3 = 1;        // Output
    PORT2.PODR.BIT.B3 = 1;       // Drive high (deselect)

    RSPI0.SPCR.BYTE = 0x00;      // Disable during config
    RSPI0.SPPCR.BYTE = 0x00;     // MOSI idle low
    RSPI0.SPSCR.BYTE = 0x00;     // Single transfer
    RSPI0.SPDCR.BYTE = 0x20;     // 24-bit (long word)
    RSPI0.SPDCR2.BYTE = 0x00;

    RSPI0.SPBR = 23;

    RSPI0.SPCMD0.WORD = 0;
    RSPI0.SPCMD0.BIT.CPHA = 1;   // CPHA=1
    RSPI0.SPCMD0.BIT.CPOL = 0;   // CPOL=0
    RSPI0.SPCMD0.BIT.BRDV = 0;
    RSPI0.SPCMD0.BIT.SPB  = 23;  // 24-bit transfer
    RSPI0.SPCMD0.BIT.LSBF = 0;   // MSB first

    RSPI0.SSLP.BYTE = 0x00;      // Not used (manual CS)

    // Enable RSPI as master
    RSPI0.SPCR.BIT.MSTR = 1;
    RSPI0.SPCR.BIT.SPE  = 1;
}

uint32_t RSPI0_Transfer(uint32_t data)
{
    while(RSPI0.SPSR.BIT.IDLNF);   // Wait if busy

    PORT2.PODR.BIT.B3 = 1;         // CS high

    RSPI0.SPDR.LONG = data;        // Write 24-bit frame

    while(!RSPI0.SPSR.BIT.SPRF);   // Wait for complete
    uint32_t rx = RSPI0.SPDR.LONG;

    PORT2.PODR.BIT.B3 = 0;         // CS low

    return rx;
}

void Adc_clk_init(void)
{
    Clk_Digital_Cfg_reg clk_config;
    
    clk_config.all =0;
    clk_config.bits.clk_sel = 0;
    clk_config.bits.clk_div = 2;

    Adc_Write(CLK_DIGITAL_CFG, clk_config.all);

    
}

uint32_t Adc_Read(uint8_t reg_add)
{
    uint32_t tx_buf = 0;
    uint32_t rx_buf = 0;

    tx_buf = ((READ_REG_COMMAND | (reg_add & ADDRESS_SIXBITS)) <<16) | (0x00 << 8) | (0x00);    
                                             

    rx_buf = RSPI0_Transfer24(tx_buf);
  return (uint8_t)(rx_buf & 0xFF);;
}

void Adc_Write(uint8_t reg_add, uint8_t data)
{
    uint32_t tx_buf = 0;
    uint32_t rx_buf = 0;

    tx_buf = ((WRITE_REG_COMMAND | (reg_add & ADDRESS_SIXBITS)) << 16) | (0x00 << 8) |(data);
    rx_buf = RSPI0_Transfer24(tx_buf);
 
   
}

void Read_dev_id(void)
{
    uint8_t reg_value = 0;
    Dev_id_reg devid;

   reg_value =  Adc_Read(DEVICE_ID);
   devid.all = reg_value;
   printf("Device id: %d",devid.bits.dev_id);

}