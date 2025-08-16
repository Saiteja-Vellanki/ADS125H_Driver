
#ifndef ADS125H_H
#define ADS125H_H


#include<stdint.h>


enum{
    DEVICE_ID = 0x00,
    REVISION_ID,
    STATUS_MSB,
    STATUS_LSB,
    ADC_REF_STATUS,
    DIGITAL_STATUS,
    RESERVED_1,
    GPIO_DATA_INPUT,
    FIFO_SEQ_STATUS,
    FIFO_DEPTH_MSB,
    FIFO_DEPTH_LSB,
    CONVERSION_CTRL,
    RESET,
    ADC_CFG,
    REFERENCE_CFG,
    CLK_DIGITAL_CFG,
    RESERVED_2,
    RESERVED_3,
    GPIO_CFG,
    SPARE_CFG,
    SEQUENCER_CFG = 0x20,
    SEQUENCER_STEP_EN0,
    SEQUENCER_STEP_EN1,
    SEQUENCER_STEP_EN2,
    SEQUENCER_STEP_EN3,
    FIFO_CFG,
    FIFO_THRES_A_MSB,
    FIFO_THRES_A_LSB,
    FIFO_THRES_B_MSB,
    FIFO_THRES_B_LSB,
    DIAG_MONITOR_CFG,
    CS_FWD_CFG  = 0x30, 
    AGPIO_FWD_CFG,
    GPIO_FWD_CFG,
    REG_MAP_CRC = 0x3D,
    PAGE_INDICATOR,
    PAGE_POINTER
};

typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t dev_id : 4;
        uint8_t ch_cnt : 2;
        uint8_t res    : 2;

    }bits;
}Dev_id_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t drdy            : 1;
        uint8_t resetn          : 1;
        uint8_t adc_ref_faultn  : 1;
        uint8_t step_indicator  : 5;

    }bits;
}Staus_Msb_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t spi_crc_faultn    : 1;
        uint8_t reg_write_faultn  : 1;
        uint8_t internal_faultn   : 1;
        uint8_t fifo_faultn       : 1;
        uint8_t conv_count        : 4;

    }bits;
}Staus_Lsb_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t bufn_uvn         : 1;
        uint8_t bufn_ovn         : 1;
        uint8_t bufp_uvn         : 1;
        uint8_t bufp_ovn         : 1;
        uint8_t mode_over_faultn : 1;
        uint8_t ref_uvn          : 1;
        uint8_t avdd_uvn         : 1;
        uint8_t res              : 1;
    }bits;
}Adc_Ref_Status_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t reg_map_crc_faultn  : 1;
        uint8_t mem_internal_faultn : 1;
        uint8_t crc_fault_page      : 6;
    }bits;
}Digital_Status_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t gpio_0_dat_in : 1;
        uint8_t gpio_1_dat_in : 1;
        uint8_t gpio_2_dat_in : 1;
        uint8_t gpio_3_dat_in : 1;
        uint8_t res           : 4;
    }bits;
}Gpio_Data_Input_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t fifo_crc_faultn : 1;
        uint8_t fifo_ufn        : 1;
        uint8_t fifo_ofn        : 1;
        uint8_t seq_count       : 4;
        uint8_t seq_active      : 1;
    }bits;
}Fifo_Seq_Status_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t fifo_depth : 1;
        uint8_t res        : 7;
    }bits;
}Fifo_Depth_Msb_reg;

typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t stop      : 1;
        uint8_t res       : 1;
        uint8_t step_init : 5;
        uint8_t start     : 1;
    }bits;
}Conversion_Ctrl_reg;

typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t pwdn         : 1;
        uint8_t stby_mode    : 1;
        uint8_t speed_mode   : 2;
        uint8_t res          : 2;
        uint8_t fifo_test_en : 1;
        uint8_t res          : 1;
    }bits;
}Adc_Cfg_reg;

typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t refp_buf_en : 1;
        uint8_t ref_val     : 1;
        uint8_t res         : 6;
    }bits;
}Reference_Cfg_reg;

typedef union 
{ 
    uint8_t all;
    struct 
    {
        uint8_t cont_read_en : 1;
        uint8_t sdo_mode     : 1;
        uint8_t out_drv      : 1;
        uint8_t clk_sel      : 1;
        uint8_t clk_div      : 2;
        uint8_t res          : 2;

    }bits;
}Clk_Digital_Cfg_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t gpio_0_cfg : 2;
       uint8_t gpio_1_cfg : 2;
       uint8_t gpio_2_cfg : 2;
       uint8_t gpio_3_cfg : 2;
    }bits;
}Gpio_Cfg_reg;

typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t spare_0 : 1;
       uint8_t spare_1 : 1;
       uint8_t spare_2 : 1;
       uint8_t spare_3 : 1;
       uint8_t spare_4 : 1;
       uint8_t spare_5 : 1;
       uint8_t spare_6 : 1;
       uint8_t spare_7 : 1;
    }bits;
}Spare_Cfg_reg;

typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t drdy_cfg      : 2;
       uint8_t res           : 2;
       uint8_t stop_behavior : 2;
       uint8_t seq_mode      : 2;
    }bits;
}Sequencer_Cfg_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t seq_step_0_en : 1;
       uint8_t seq_step_1_en : 1;
       uint8_t seq_step_2_en : 1;
       uint8_t seq_step_3_en : 1;
       uint8_t seq_step_4_en : 1;
       uint8_t seq_step_5_en : 1;
       uint8_t seq_step_6_en : 1;
       uint8_t seq_step_7_en : 1;
    }bits;
}Sequencer_Stepen0_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t seq_step_8_en  : 1;
       uint8_t seq_step_9_en  : 1;
       uint8_t seq_step_10_en : 1;
       uint8_t seq_step_11_en : 1;
       uint8_t seq_step_12_en : 1;
       uint8_t seq_step_13_en : 1;
       uint8_t seq_step_14_en : 1;
       uint8_t seq_step_15_en : 1;
    }bits;
}Sequencer_Stepen1_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t seq_step_16_en : 1;
       uint8_t seq_step_17_en : 1;
       uint8_t seq_step_18_en : 1;
       uint8_t seq_step_19_en : 1;
       uint8_t seq_step_20_en : 1;
       uint8_t seq_step_21_en : 1;
       uint8_t seq_step_22_en : 1;
       uint8_t seq_step_23_en : 1;
    }bits;
}Sequencer_Stepen2_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t seq_step_24_en : 1;
       uint8_t seq_step_25_en : 1;
       uint8_t seq_step_26_en : 1;
       uint8_t seq_step_27_en : 1;
       uint8_t seq_step_28_en : 1;
       uint8_t seq_step_29_en : 1;
       uint8_t seq_step_30_en : 1;
       uint8_t seq_step_31_en : 1;
    }bits;
}Sequencer_Stepen3_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t fifo_en : 1;
       uint8_t res     : 7;
    }bits;
}Fifo_Cfg_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t fifo_thres_a : 1;
       uint8_t res          : 7;
    }bits;
}Fifo_Thres_A_MSB_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t fifo_thres_a : 1;
       uint8_t res          : 7;
    }bits;
}Fifo_Thres_B_MSB_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t spi_crc_en         : 1;
       uint8_t status_en          : 1;
       uint8_t ref_uv_en          : 1;
       uint8_t buf_oor_en         : 1;
       uint8_t reg_map_crc_en     : 1;
       uint8_t fault_pin_behavior : 1;
       uint8_t tdac_range         : 1;
       uint8_t res                : 1;
    }bits;
}Diag_Monitor_Cfg_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t timeout_sel    : 2;
       uint8_t cs_fwd_en_code : 6;
    }bits;
}Cs_Fwd_Cfg_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t agpio0_fwd_en : 1;
       uint8_t agpio1_fwd_en : 1;
       uint8_t agpio2_fwd_en : 1;
       uint8_t agpio3_fwd_en : 1;
       uint8_t agpio4_fwd_en : 1;
       uint8_t agpio5_fwd_en : 1;
       uint8_t agpio6_fwd_en : 1;
       uint8_t agpio7_fwd_en : 1;
    }bits;
}AGpio_Fwd_Cfg_reg;


typedef union 
{ 
    uint8_t all;
    struct 
    {
       uint8_t gpio0_fwd_en : 1;
       uint8_t gpio1_fwd_en : 1;
       uint8_t gpio2_fwd_en : 1;
       uint8_t gpio3_fwd_en : 1;
       uint8_t res          : 4;
    }bits;
}Gpio_Fwd_Cfg_reg;

void Read_dev_id(void);
uint32_t Adc_Read(uint8_t reg_add);
uint32_t Adc_Write(uint8_t reg_add, uint32_t data);

#endif