#ifndef DCMI_DMA_GPIO_H_
#define DCMI_DMA_GPIO_H_

#include "../system/include/cmsis/stm32f4xx.h"
#include "./color.h"

#define IMG_ROWS 120
#define IMG_COLS 100

uint8_t image_state = 0x00;

extern uint32_t img[(IMG_ROWS * IMG_COLS)];

void DCMI_init();
void DCMI_GPIO_init();
void DCMI_DMA_init();

void DCMI_init() {
    DCMI_GPIO_init();
    DCMI_DMA_init();
}

void DCMI_GPIO_init() {
    /* GPIO */
    RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN);

    // VSY | VSYNC
    GPIOB->MODER |= GPIO_MODER_MODER7_1;
    GPIOB->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR7_1 | GPIO_OSPEEDER_OSPEEDR7_0); // del
    GPIOB->PUPDR |= GPIO_PUPDR_PUPDR7_0;// убрать..
    GPIOB->AFR[0] |= (0xD << 28);

    // HRE | HSYNC
    GPIOA->MODER |= GPIO_MODER_MODER4_1;
    GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR4_1 | GPIO_OSPEEDER_OSPEEDR4_0);
    GPIOA->PUPDR |= GPIO_PUPDR_PUPDR4_0;
    GPIOA->AFR[0] |= (0xD << 16);

    // PCLK
    GPIOA->MODER |= GPIO_MODER_MODER6_1;
    GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR6_1 | GPIO_OSPEEDER_OSPEEDR6_0);
    GPIOA->AFR[0] |= (0xD << 24);

    // D0
    GPIOA->MODER |= GPIO_MODER_MODER9_1;
    GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9_1 | GPIO_OSPEEDER_OSPEEDR9_0);
    GPIOA->PUPDR |= GPIO_PUPDR_PUPDR9_0;
    GPIOA->AFR[1] |= (0xD << 4);

    // D1
    GPIOA->MODER |= GPIO_MODER_MODER10_1;
    GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10_1 | GPIO_OSPEEDER_OSPEEDR10_0);
    GPIOA->PUPDR |= GPIO_PUPDR_PUPDR10_0;
    GPIOA->AFR[1] |= (0xD << 8);

    // D2
    GPIOC->MODER |= GPIO_MODER_MODER8_1;
    GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8_1 | GPIO_OSPEEDER_OSPEEDR8_0);
    GPIOC->PUPDR |= GPIO_PUPDR_PUPDR8_0;
    GPIOC->AFR[1] |= (0xD << 0);

    // D3
    GPIOC->MODER |= GPIO_MODER_MODER9_1;
    GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9_1 | GPIO_OSPEEDER_OSPEEDR9_0);
    GPIOC->PUPDR |= GPIO_PUPDR_PUPDR9_0;
    GPIOC->AFR[1] |= (0xD << 4);

    // D4
    GPIOC->MODER |= GPIO_MODER_MODER11_1;
    GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR11_1 | GPIO_OSPEEDER_OSPEEDR11_0);
    GPIOC->PUPDR |= GPIO_PUPDR_PUPDR11_0;
    GPIOC->AFR[1] |= (0xD << 12);

    // D5
    GPIOB->MODER |= GPIO_MODER_MODER6_1;
    GPIOB->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR6_1 | GPIO_OSPEEDER_OSPEEDR6_0);
    GPIOB->PUPDR |= GPIO_PUPDR_PUPDR6_0;
    GPIOB->AFR[0] |= (0xD << 24);

    // D6
    GPIOB->MODER |= GPIO_MODER_MODER8_1;
    GPIOB->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8_1 | GPIO_OSPEEDER_OSPEEDR8_0);
    GPIOB->PUPDR |= GPIO_PUPDR_PUPDR8_0;
    GPIOB->AFR[1] |= (0xD << 0);

    // D7
    GPIOB->MODER |= GPIO_MODER_MODER9_1;
    GPIOB->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9_1 | GPIO_OSPEEDER_OSPEEDR9_0);
    GPIOB->PUPDR |= GPIO_PUPDR_PUPDR9_0;
    GPIOB->AFR[1] |= (0xD << 4);

    // D8
    GPIOC->MODER |= GPIO_MODER_MODER10_1;
    GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10_1 | GPIO_OSPEEDER_OSPEEDR10_0);
    GPIOC->PUPDR |= GPIO_PUPDR_PUPDR10_0;
    GPIOC->AFR[1] |= (0xD << 8);

    // D9
    GPIOC->MODER |= GPIO_MODER_MODER12_1;
    GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR12_1 | GPIO_OSPEEDER_OSPEEDR12_0);
    GPIOC->PUPDR |= GPIO_PUPDR_PUPDR12_0;
    GPIOC->AFR[1] |= (0xD << 16);
}

void DCMI_DMA_init() {
        RCC->AHB2ENR |= RCC_AHB2ENR_DCMIEN;
    DCMI->CR |= (DCMI_CR_CM | DCMI_CR_VSPOL | DCMI_CR_HSPOL | DCMI_CR_PCKPOL | DCMI_CR_EDM_0);

    /* DMA */
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
    DMA2_Stream1->CR |= (0x1 << 25);

	DMA2_Stream1->PAR |= (uint32_t) (&DCMI->DR);
	DMA2_Stream1->M0AR |= (uint32_t)&img[0];
	DMA2_Stream1->NDTR = (IMG_ROWS * IMG_COLS) / 2;

    // 3. Настройка
    // 3.1 DMA_SxCR_CIRC - Включаем круговой режим работы
    // 3.2 DMA_SxCR_MINC - Режим увеличения объема памяти
    // 3.3 DMA_SxCR_PSIZE_1 - Длина 32-bit
    // 3.4 DMA_SxCR_MSIZE_1 - Длина 32-bit
    // 3.5 DMA_SxCR_PL_1 - Высокий уровень приоритета, не обезательная скорее всего настройка,
    //                     добавить если несколько будеь
    // 3.6 DMA_SxCR_TCIE - Прерывания
    DMA2_Stream1->CR = (DMA_SxCR_CIRC | DMA_SxCR_MINC | DMA_SxCR_PSIZE_1 | DMA_SxCR_MSIZE_1 | DMA_SxCR_TCIE | DMA_SxCR_TEIE);
    //DMA2_Stream1->FCR |= (0x3 << 0);
    DMA2->LIFCR |= (DMA_LIFCR_CTCIF1 | DMA_LIFCR_CTEIF1);
    // 4. Прерывания
    NVIC_EnableIRQ(DMA2_Stream1_IRQn);
    NVIC_SetPriority(DMA2_Stream1_IRQn, 2);

    // 5. Запуск
//    DMA2_Stream1->CR |= DMA_SxCR_EN;

    /* DCMI */

    DCMI->CR |= DCMI_CR_ENABLE;
//    DCMI->IER |= (DCMI_IER_FRAME_IE | DCMI_IER_OVF_IE | DCMI_IER_ERR_IE);
//    NVIC_EnableIRQ(DCMI_IRQn);
//    NVIC_SetPriority(DCMI_IRQn, 1);
}

void DMA2_Stream1_IRQHandler(void) {
	if((DMA2->LISR & DMA_LISR_TCIF1) == DMA_LISR_TCIF1) {
		DMA2->LIFCR |= DMA_LIFCR_CTCIF1;
        DMA2_Stream1->CR &= ~DMA_SxCR_EN;
    	image_state = 0x01;
	}

    if ((DMA2->LISR & DMA_LISR_TEIF1) == DMA_LISR_TEIF1) {
        DMA2->LIFCR |= DMA_LIFCR_CTEIF1;
        image_state = 0x02;
        DMA2_Stream1->CR &= ~DMA_SxCR_EN;
    }
}

#if 0  // Прерываний нету
void DCMI_IRQHandler(void) {
    if ((DCMI->RISR & DCMI_RIS_FRAME_RIS) == DCMI_RIS_FRAME_RIS) {
        //DCMI->ICR |= DCMI_ICR_FRAME_ISC;
        // disable DMA
    }
    if ((DCMI->RISR & DCMI_RIS_OVR_RIS) == DCMI_RIS_OVR_RIS) {
        //
    }
    if ((DCMI->RISR & DCMI_RIS_ERR_RIS) == DCMI_RIS_ERR_RIS) {

    }
}
#endif


#if 0  /* Инициализация через какую то библиотеку */
void OV2640_Init() {
    DCMI_GPIO_init();
    DCMI_DMA_Interrupts();

    DCMI_InitTypeDef DCMI_InitStructure;
    DMA_InitTypeDef  DMA_InitStructure;

    /*** Configures the DCMI to interface with the OV2640 camera module ***/
    /* Enable DCMI clock */

//    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_DCMI, ENABLE);
    RCC->AHB2ENR |= RCC_AHB2ENR_DCMIEN;

    /* DCMI configuration */
    DCMI_InitStructure.DCMI_CaptureMode = DCMI_CaptureMode_Continuous;
    DCMI_InitStructure.DCMI_SynchroMode = DCMI_SynchroMode_Hardware;
    DCMI_InitStructure.DCMI_PCKPolarity = DCMI_PCKPolarity_Rising;
    DCMI_InitStructure.DCMI_VSPolarity = DCMI_VSPolarity_Low;
    DCMI_InitStructure.DCMI_HSPolarity = DCMI_HSPolarity_Low;
    DCMI_InitStructure.DCMI_CaptureRate = DCMI_CaptureRate_All_Frame;
    DCMI_InitStructure.DCMI_ExtendedDataMode = DCMI_ExtendedDataMode_8b;

    /* Configures the DMA2 to transfer Data from DCMI */
    /* Enable DMA2 clock */
//    RCC_AHB1PeriphResetCmd(RCC_AHB1Periph_DMA2, ENABLE);
//    RCC_AHB1PeriphResetCmd(RCC_AHB1Periph_DMA2, DISABLE);
//    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

    /* DMA2 Stream1 Configuration */
    DMA_DeInit(DMA2_Stream1);

    DMA_InitStructure.DMA_Channel = DMA_Channel_1;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&(DCMI->DR);
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Targetbuffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_InitStructure.DMA_BufferSize = 160*120/2;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

    /* DCMI configuration */
    DCMI_InitStructure.DCMI_VSPolarity = DCMI_VSPolarity_High;
    DCMI_Init(&DCMI_InitStructure);

    DMA_Cmd(DMA2_Stream1, DISABLE);
    while ( DMA_GetCmdStatus(DMA2_Stream1) != DISABLE );

    /* DMA2 IRQ channel Configuration */
    DMA_Init(DMA2_Stream1, &DMA_InitStructure);
}
#endif

#if 0  /* Прерывания для того, что выше */
void DCMI_DMA_Interrupts() {
    NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = DCMI_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
	DCMI_ClearITPendingBit(DCMI_IT_FRAME | DCMI_IT_OVF | DCMI_IT_ERR);
	DCMI_ITConfig(DCMI_IT_FRAME | DCMI_IT_OVF | DCMI_IT_ERR, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
	DMA_ClearITPendingBit(DMA2_Stream1, DMA_IT_TCIF1 | DMA_IT_TEIF1);
	DMA_ITConfig(DMA2_Stream1, DMA_IT_TC | DMA_IT_FE | DMA_IT_TE | DMA_IT_DME, ENABLE);
}
#endif

#if 0  /* Прерывания с избытком для того, что выше */
void DCMI_IRQHandler(void) {
	if ( DCMI_GetITStatus(DCMI_IT_OVF) != RESET) { // Overflow interrupt mask
		DCMI_ClearITPendingBit(DCMI_IT_OVF);
	}

	if ( DCMI_GetITStatus(DCMI_IT_FRAME) != RESET) { // Frame capture complete interrupt mask
		DCMI_ClearITPendingBit(DCMI_IT_FRAME);
	}

	if ( DCMI_GetITStatus(DCMI_IT_ERR) != RESET) { // Synchronization error interrupt mask
		DCMI_ClearITPendingBit(DCMI_IT_ERR);
	}

	if ( DCMI_GetITStatus(DCMI_IT_LINE) != RESET) { // Line interrupt mask
		DCMI_ClearITPendingBit(DCMI_IT_LINE);
	}

	if ( DCMI_GetITStatus(DCMI_IT_VSYNC) != RESET) { // Line interrupt mask
		DCMI_ClearITPendingBit(DCMI_IT_VSYNC);
	}
}

void DMA2_Stream1_IRQHandler(void) {
	if ( DMA_GetITStatus(DMA2_Stream1, DMA_IT_DMEIF1) != RESET) { // direct mode error interrupt
		DMA_ClearITPendingBit(DMA2_Stream1, DMA_IT_DMEIF1);
	}

	if ( DMA_GetITStatus(DMA2_Stream1, DMA_IT_FEIF1) != RESET) { // FIFO error interrupt
		DMA_ClearITPendingBit(DMA2_Stream1, DMA_IT_FEIF1);
	}

	if ( DMA_GetITStatus(DMA2_Stream1, DMA_IT_HTIF1) != RESET) { // half transfer complete interrupt

		DMA_ClearITPendingBit(DMA2_Stream1, DMA_IT_HTIF1);
	}

	if ( DMA_GetITStatus(DMA2_Stream1, DMA_IT_TCIF1) != RESET) { // transfer complete interrupt

		DMA_ClearITPendingBit(DMA2_Stream1, DMA_IT_TCIF1);
	}

	if ( DMA_GetITStatus(DMA2_Stream1, DMA_IT_TEIF1) != RESET) { // transfer error interrupt
		DMA_ClearITPendingBit(DMA2_Stream1, DMA_IT_TEIF1);
	}
}
#endif

#endif  // DCMI_DMA_GPIO_H_
