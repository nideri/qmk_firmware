#include "ws2812.h"
#include "quantum.h"
#include "hal.h"
#include "oled_driver.h"

/*
 ~/kbrd/qmk_firmware/lib/chibios/os/hal/ports/STM32/LLD/TIMv1/stm32_tim.h
Compiling: lib/chibios/os/hal/ports/STM32/STM32F3xx/hal_lld.c                                       [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/ADCv3/hal_adc_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/CANv1/hal_can_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/DACv1/hal_dac_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/DMAv1/stm32_dma.c                                     [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/EXTIv1/stm32_exti.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/GPIOv2/hal_pal_lld.c                                  [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/I2Cv2/hal_i2c_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/RTCv2/hal_rtc_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/SPIv2/hal_i2s_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/SPIv2/hal_spi_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/TIMv1/hal_st_lld.c                                    [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/TIMv1/hal_gpt_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/TIMv1/hal_icu_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/TIMv1/hal_pwm_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/USARTv2/hal_serial_lld.c                              [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/USARTv2/hal_uart_lld.c                                [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/USBv1/hal_usb_lld.c                                   [OK]
Compiling: lib/chibios/os/hal/ports/STM32/LLD/xWDGv1/hal_wdg_lld.c                                  [OK]
*/

// from stm32f3xx_hal_gpio.h
#define  GPIO_MODE_AF_PP                        (0x00000002U)   /*!< Alternate Function Push Pull Mode     */
#define  GPIO_PULLDOWN      (0x00000002U)   /*!< Pull-down activation                */
// stm32f3xx_hal_gpio_ex.h
/*---------------------------------- STM32F303xE ------------------------------*/
/** 
  * @brief   AF 1 selection  
  */ 
#define GPIO_AF1_TIM2           ((uint8_t)0x01U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF1_TIM15          ((uint8_t)0x01U)  /* TIM15 Alternate Function mapping */
#define GPIO_AF1_TIM16          ((uint8_t)0x01U)  /* TIM16 Alternate Function mapping */
#define GPIO_AF1_TIM17          ((uint8_t)0x01U)  /* TIM17 Alternate Function mapping */

/** 
  * @brief   AF 2 selection  
  */ 
#define GPIO_AF2_TIM1           ((uint8_t)0x02U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2           ((uint8_t)0x02U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF2_TIM3           ((uint8_t)0x02U)  /* TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)  /* TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM8           ((uint8_t)0x02U)  /* TIM8 Alternate Function mapping */
#define GPIO_AF2_TIM15          ((uint8_t)0x02U)  /* TIM15 Alternate Function mapping */
#define GPIO_AF2_TIM20          ((uint8_t)0x02U)  /* TIM20 Alternate Function mapping */

/** 
  * @brief   AF 3 selection  
  */ 
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)  /* TIM8 Alternate Function mapping  */
#define GPIO_AF3_TIM15         ((uint8_t)0x03U)  /* TIM15 Alternate Function mapping */
#define GPIO_AF3_TIM20         ((uint8_t)0x03U)  /* TIM20 Alternate Function mapping */

/** 
  * @brief   AF 4 selection  
  */ 
#define GPIO_AF4_TIM1          ((uint8_t)0x04U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF4_TIM8          ((uint8_t)0x04U)  /* TIM8 Alternate Function mapping */
#define GPIO_AF4_TIM16         ((uint8_t)0x04U)  /* TIM16 Alternate Function mapping */
#define GPIO_AF4_TIM17         ((uint8_t)0x04U)  /* TIM17 Alternate Function mapping */

/** 
  * @brief   AF 5 selection  
  */ 
#define GPIO_AF5_TIM8          ((uint8_t)0x05U)  /* TIM8 Alternate Function mapping */

/** 
  * @brief   AF 6 selection  
  */ 
#define GPIO_AF6_TIM1          ((uint8_t)0x06U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF6_TIM8          ((uint8_t)0x06U)  /* TIM8 Alternate Function mapping */
#define GPIO_AF6_TIM20         ((uint8_t)0x06U)  /* TIM20 Alternate Function mapping */
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  /* SPI3/I2S3 Alternate Function mapping */

/** 
  * @brief   AF 9 selection 
  */ 
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF9_TIM8          ((uint8_t)0x09U)  /* TIM8 Alternate Function mapping */
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)  /* TIM15 Alternate Function mapping */

/** 
  * @brief   AF 10 selection  
  */ 
#define GPIO_AF10_TIM2           ((uint8_t)0xAU)  /* TIM2 Alternate Function mapping */
#define GPIO_AF10_TIM3           ((uint8_t)0xAU)  /* TIM3 Alternate Function mapping */
#define GPIO_AF10_TIM4           ((uint8_t)0xAU)  /* TIM4 Alternate Function mapping */
#define GPIO_AF10_TIM8           ((uint8_t)0xAU)  /* TIM8 Alternate Function mapping */
#define GPIO_AF10_TIM17          ((uint8_t)0xAU)  /* TIM17 Alternate Function mapping */
/** 
  * @brief   AF 11 selection  
  */ 
#define GPIO_AF11_TIM1           ((uint8_t)0x0BU)  /* TIM1 Alternate Function mapping */
#define GPIO_AF11_TIM8           ((uint8_t)0x0BU)  /* TIM8 Alternate Function mapping */

/** 
  * @brief   AF 12 selection  
  */ 
#define GPIO_AF12_TIM1            ((uint8_t)0xCU)  /* TIM1 Alternate Function mapping */

/*******************************************************************************/

#define T0H_OUT_PORT (GPIOC) /* timN_ch1 */
#define T1H_OUT_PORT (GPIOC) /* timN_ch3 */
#define SPI_SCK_PORT (GPIOC) /* spiN_sck */
#define SPI_MISO_PORT (GPIOC) /* spiN_mosi */

#define T0H_OUT_PIN (0) /* timN_ch1 */
#define T1H_OUT_PIN (2) /* timN_ch3 */
#define SPI_SCK_PIN (10) /* spiN_sck */
#define SPI_MISO_PIN (11) /* spiN_mosi */

/* ref man: Table 14. STM32F303xD/E alternate function mapping (continued) */
#define T0H_AF (GPIO_AF2_TIM1) /* timN_ch1 */
#define T1H_AF (GPIO_AF2_TIM1) /* timN_ch3 */
#define SPI_SCK_AF (GPIO_AF6_SPI3) /* spiN_sck */
#define SPI_MISO_AF (GPIO_AF6_SPI3) /* spiN_mosi */

#define MSTR_TMR (TIM4) /* can be TIM 1/8/4/15 when SLV_TMR = TIM20, MSTR must be able to trigger SLV, see reference manual table 31 "Timer synchronization" */
#define SLV_TMR (TIM1) /* can be TIM1/8/20, need 16 bit RCR and "combined pwm mode" */

#define MSTR_TMR_CR2 (0x00000020)
#define MSTR_TMR_START (0x00000001) /* cr1 cen: counter enable */

#define SLV_TMR_SMCR_TS (0b011) /* itr3 */
#define SLV_TMR_CR1  (0x00000008)
#define SLV_TMR_SMCR (0x00010000 | (SLV_TMR_SMCR_TS << 4))
#define SLV_TMR_CCMR1 (0x00016858)
#define SLV_TMR_CCMR2 (0x00016858)
#define SLV_TMR_BDTR (0x02002000)
#define SLV_TMR_EN_CH1_3_OUT (0x00000101) /* enable slave timer output on ch1 and ch3 (when configuration is done) */
#define SLV_TMR_MOE  (0x00008000) /* slave timer master output enable */

#define WS2812_SPI (SPI3)
#define WS2812_SPI_CR1 (0x00000200)
#define WS2812_SPI_CR2 (0x00001700)
#define WS2812_SPI_START_TX_CR1 (0x00000040) /* spi enable */
#define WS2812_SPI_START_TX_CR2 (0x00000022) /* errie | txdmaen */

//#define TIM_DMA (DMA2_Channel1)
#define SPI_DMA (DMA2_Channel2) /* Table 80. STM32F303xB/C/D/E, STM32F358xC and STM32F398xE summary of DMA2 requests
for each channel */
#define SPI_DMA_CCR (0x000000be)

#define NOF_LEDS (RGBLED_NUM)
#define SLV_RCR_VAL (NOF_LEDS*8*3 - 1)
#define SYS_FRQ (72e6)
#define WS2812B_FREQ (800e3)
#define SLV_TOP (SYS_FRQ/WS2812B_FREQ - 1)
#define SLV_PHASE_SHIFT (1)
#define WS2812B_T0H (SYS_FRQ*(400e-9) - 1 + SLV_PHASE_SHIFT)
#define WS2812B_T1H (SYS_FRQ*(800e-9) - 1 + SLV_PHASE_SHIFT)
#define MSTR_PERIOD (NOF_LEDS + WS2812B_TRESET*SYS_FRQ/MSTR_PRESCALER)
#define WS2812B_TRESET (50e-6)
#define MSTR_PRESCALER ((SLV_TOP+1)*8*3)

uint8_t frame_buf[NOF_LEDS*3];

void ws2812_init(LED_TYPE* ledarray, uint16_t leds) {
	
  
	  // init frame buf
	  for (uint16_t i=0; i<NOF_LEDS*3; i++) {
		  frame_buf[i]=0;
	  }
	  /*
	  // led beim stecker

	  frame_buf[0]=0x0f; // g
	  frame_buf[1]=0x00; // r
	  frame_buf[2]=0x00; // b

	  frame_buf[3]=0x00; // g
	  frame_buf[4]=0x0f; // r
	  frame_buf[5]=0x00; // b

	  frame_buf[6]=0x00; // g
	  frame_buf[7]=0x00; // r
	  frame_buf[8]=0x0f; // b

	  frame_buf[12]=0xff; // g
	  frame_buf[13]=0xff; // r
	  frame_buf[14]=0x00; // b
  */
	  RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	  RCC->AHBENR |= RCC_AHBENR_DMA2EN;
	  RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	  RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	  RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;
	  
	  /*
	    init gpio stuff
	   */

	  T0H_OUT_PORT->MODER |= (GPIO_MODE_AF_PP << (T0H_OUT_PIN*2));
	  T1H_OUT_PORT->MODER |= (GPIO_MODE_AF_PP << (T1H_OUT_PIN*2));
	  SPI_SCK_PORT->MODER |= (GPIO_MODE_AF_PP << (SPI_SCK_PIN*2));
	  SPI_MISO_PORT->MODER |= (GPIO_MODE_AF_PP << (SPI_MISO_PIN*2));

	  SPI_SCK_PORT->PUPDR |= (GPIO_PULLDOWN << (SPI_SCK_PIN*2));

	  /*
	    switch between AFRL and AFRH. Pin numbers < 16 will go to AFRL, numbers >= 16 to AFRH
	   */
	# if T0H_OUT_PIN*4/32 == 0
	    T0H_OUT_PORT->AFRL |= (T0H_AF << (T0H_OUT_PIN*4U));
	# else
	    T0H_OUT_PORT->AFRH |= (T0H_AF << (T0H_OUT_PIN*4U-32U));
	# endif

	# if T1H_OUT_PIN*4/32 == 0
	    T1H_OUT_PORT->AFRL |= (T1H_AF << (T1H_OUT_PIN*4U));
	# else
	    T1H_OUT_PORT->AFRH |= (T1H_AF << (T1H_OUT_PIN*4U-32U));
	# endif

	# if SPI_SCK_PIN*4/32 == 0
	    SPI_SCK_PORT->AFRL |= (SPI_SCK_AF << (SPI_SCK_PIN*4U));
	# else
	    SPI_SCK_PORT->AFRH |= (SPI_SCK_AF << (SPI_SCK_PIN*4U-32U));
	# endif

	# if SPI_MISO_PIN*4/32 == 0
	    SPI_MISO_PORT->AFRL |= (SPI_MISO_AF << (SPI_MISO_PIN*4U));
	# else
	    SPI_MISO_PORT->AFRH |= (SPI_MISO_AF << (SPI_MISO_PIN*4U-32U));
	# endif

	    /* 
init master timer 
*/
	    MSTR_TMR->CR2 = MSTR_TMR_CR2;
	    MSTR_TMR->PSC = MSTR_PRESCALER;
	    MSTR_TMR->ARR = MSTR_PERIOD;

	    /* 
init slave timer 
*/
	    SLV_TMR->CR1 = SLV_TMR_CR1;
	    SLV_TMR->SMCR = SLV_TMR_SMCR;
	    SLV_TMR->CCMR1 = SLV_TMR_CCMR1;
	    SLV_TMR->CCMR2 = SLV_TMR_CCMR2;
	    SLV_TMR->ARR = SLV_TOP;
	    SLV_TMR->RCR = SLV_RCR_VAL;
	    SLV_TMR->CCR1 = SLV_PHASE_SHIFT;
	    SLV_TMR->CCR2 = WS2812B_T0H;
	    SLV_TMR->CCR3 = SLV_PHASE_SHIFT;
	    SLV_TMR->CCR4 = WS2812B_T1H;
	    SLV_TMR->BDTR = SLV_TMR_BDTR;

	    /* 
init spi 
*/
	    WS2812_SPI->CR1 = WS2812_SPI_CR1;
	    WS2812_SPI->CR2 = WS2812_SPI_CR2;

	    /*
init dma
	    */
	    SPI_DMA->CCR = SPI_DMA_CCR;
	    SPI_DMA->CNDTR = NOF_LEDS*3;//sizeof(frame_buf); // 0x9;
	    SPI_DMA->CPAR = (uint32_t)&(WS2812_SPI->DR); // adr of spi tx buf
	    SPI_DMA->CMAR = (uint32_t)frame_buf;//ledarray;//frame_buf;
	    SPI_DMA->CCR |= 0x00000001; /* set enable */
/*
	    uint32_t adr = &(WS2812_SPI->DR);
		  frame_buf[12]=adr & 0xff; // g
		  frame_buf[13]=(adr >> 8) & 0xff; // r
		  frame_buf[14]=(adr >> 16) & 0xff; // b
*/
	    /*
enable slave timer output
	    */
	    SLV_TMR->CCER |= SLV_TMR_EN_CH1_3_OUT;
//	    HAL_Delay(1);
	    SLV_TMR->BDTR |= SLV_TMR_MOE;

	    /*
start spi transmit with dma transfers
	    */
	    WS2812_SPI->CR2 |= WS2812_SPI_START_TX_CR2;
	    WS2812_SPI->CR1 |= WS2812_SPI_START_TX_CR1;

	    /*
everyting is armed, start master timer
	    */
	    MSTR_TMR->CR1 |= MSTR_TMR_START;


  
  return;
}

extern volatile uint8_t key_led[MATRIX_ROWS*MATRIX_COLS];

void ws2812_setleds(LED_TYPE* ledarray, uint16_t leds) {
    static bool s_init = false;
    if (!s_init) {
        ws2812_init( ledarray,  leds);
        s_init = true;
    }

#define I_STDBY_IN_uA (919L)
#define I_DIGIT_IN_uA (52L)
#define I_MAX_IN_uA (200000L) /* max. current in uA (target) */

#define I_MAX_IN_uA_MEASURED (I_MAX_IN_uA) /* max. current in uA measured) */
#define I_ERROR ((float)I_MAX_IN_uA_MEASURED/(float)I_MAX_IN_uA) /* relative error */
#define I_MAX_IN_uA_WITH_ERROR ((uint32_t)((float)I_MAX_IN_uA/I_ERROR))

    
    uint32_t current = I_STDBY_IN_uA*leds;
    uint16_t i=0;
    while (i<leds) {

#ifdef QMK_RGB      
      current += (ledarray[i].g+ledarray[i].r+ledarray[i].b+3)*I_DIGIT_IN_uA;
#else
      current += ( ((key_led[i]>>0) & 0x01)
		  +((key_led[i]>>1) & 0x01)
		  +((key_led[i]>>2) & 0x01)
		 )*I_DIGIT_IN_uA;
#endif

      // always do led 0 ("alive led"), not sure why is_oled_active() == false is needed... otherwhise it won't work
      // "main loop" might run faster when oled_active = false...
      if (((i==0) && (is_oled_active() == false)) || ((current < I_MAX_IN_uA_WITH_ERROR) && (is_oled_active() == true))) { //_uA_WITH_ERROR) {
#ifdef QMK_RGB	
	frame_buf[i*3+0] = ledarray[i].g;
	frame_buf[i*3+1] = ledarray[i].r;
	frame_buf[i*3+2] = ledarray[i].b;
#else
	if (i < MATRIX_ROWS*MATRIX_COLS) {
	  frame_buf[i*3+1] = (key_led[i] >> 0) & 0x01; // r
	  frame_buf[i*3+0] = (key_led[i] >> 1) & 0x01; // g
	  frame_buf[i*3+2] = (key_led[i] >> 2) & 0x01; // b
	}
#endif	
      } else {
	frame_buf[i*3+0] = 0;
	frame_buf[i*3+1] = 0;
	frame_buf[i*3+2] = 0;	
      }

      i++;
    }
    /*
    for (uint16_t i = 0; i < leds && i < NOF_LEDS; i++) {
      frame_buf[i*3+0] = ledarray[i].g;
      frame_buf[i*3+1] = ledarray[i].r;
      frame_buf[i*3+2] = ledarray[i].b;
      //ws2812_write_led(i, ledarray[i].r, ledarray[i].g, ledarray[i].b);
    }
    */
}







