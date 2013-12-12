/**
  ******************************************************************************
  * @file    main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    02-October-2013
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


void RCC_Config(void) {
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    
}

void NVIC_Config(void) {
    NVIC_InitTypeDef NVIC_InitStructure;
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_UP_TRG_COM_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        
    NVIC_Init(&NVIC_InitStructure);
}

void TIM_Config(void) {
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    
    TIM_TimeBaseInitStructure.TIM_Prescaler = 10000 - 1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 4800 - 1;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
    
    TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM1, ENABLE);
}

void GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;            //引脚
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;        //模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;  //速度
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;       //输出类型
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void) {
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f0xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f0xx.c file
     */
    RCC_Config();
    NVIC_Config();
    TIM_Config();
    GPIO_Config();

    //RCC->CR &= 0xfffffffe;
    while (1) {
	  //GPIO_SetBits(GPIOA, GPIO_Pin_6);
    }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
