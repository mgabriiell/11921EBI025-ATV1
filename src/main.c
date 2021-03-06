#include<stdlib.h>
#define STM32_RCC_BASE0x40023800

#define STM32_GPIOC_BASE     0x48000800U
#define STM32_RCC_AHB1ENR_OFFSET  0x0030
#define STM32_GPIO_MODER_OFFSET   0x0000
#define STM32_GPIO_OTYPER_OFFSET  0x0004
#define STM32_GPIO_PUPDR_OFFSET   0x000c
#define STM32_GPIO_BSRR_OFFSET    0x0018

#define STM32_RCC_AHB1ENR
#define STM32_GPIOC_MODER
#define STM32_GPIOC_OTYPER
#define STM32_GPIOC_PUPDR
#define STM32_GPIOC_BSRR

#define GPIO_BSRR_SET(n)(1 << (n))
#define GPIO_BSRR_RST(n)(1 << (n + 16))
int main(int argc,char *argv[])
{
uint32_t reg;
uint32_t *pRCC_AHB1ENR  = (uint32_t*)STM32_RCC_AHB1ENR;
uint32_t *pGPIOC_MODER  = (uint32_t*)STM32_GPIOC_MODER;
uint32_t *pGPIOC_OTYPER = (uint32_t*)STM32_GPIOC_OTYPER;
uint32_t *pGPIOC_PUPDR  = (uint32_t*)STM32_GPIOC_PUPDR;
uint32_t *pGPIOC_BSRR   = (uint32_t*)STM32_GPIOC_BSRR;
while(1)
{
   *pGPIOC_BSRR = GPIO_BSRR_SET(13);
    for(uint32_t i =0; i < LED_DELAY; i++);
    *pGPIOC_BSRR = GPIO_BSRR_RST(13);
    for(uint32_t i =0; i < LED_DELAY; i++);  
};
return EXIT_SUCCESS;
}
