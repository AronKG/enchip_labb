/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define M1_HALL_H1_TIM3_CH1_Pin GPIO_PIN_2
#define M1_HALL_H1_TIM3_CH1_GPIO_Port GPIOE
#define M1_HALL_H2_TIM3_CH2_Pin GPIO_PIN_3
#define M1_HALL_H2_TIM3_CH2_GPIO_Port GPIOE
#define M1_HALL_H3_TIM3_CH3_Pin GPIO_PIN_4
#define M1_HALL_H3_TIM3_CH3_GPIO_Port GPIOE
#define M2_ENABLE1_GPIO_Pin GPIO_PIN_5
#define M2_ENABLE1_GPIO_GPIO_Port GPIOE
#define M3_PWM_WL_TIM20_CH3N_Pin GPIO_PIN_6
#define M3_PWM_WL_TIM20_CH3N_GPIO_Port GPIOE
#define USER_BUTTON_Pin GPIO_PIN_13
#define USER_BUTTON_GPIO_Port GPIOC
#define GPIO_OUT_LED_GREEN_Pin GPIO_PIN_3
#define GPIO_OUT_LED_GREEN_GPIO_Port GPIOF
#define M1_ENABLE1_GPIO_Pin GPIO_PIN_4
#define M1_ENABLE1_GPIO_GPIO_Port GPIOF
#define M1_ENABLE2_GPIO_Pin GPIO_PIN_5
#define M1_ENABLE2_GPIO_GPIO_Port GPIOF
#define M1_ENCB_TIM5_CH2_Pin GPIO_PIN_7
#define M1_ENCB_TIM5_CH2_GPIO_Port GPIOF
#define M1_ENCZ_TIM5_CH3_Pin GPIO_PIN_8
#define M1_ENCZ_TIM5_CH3_GPIO_Port GPIOF
#define M3_TIM20_BKIN_Pin GPIO_PIN_9
#define M3_TIM20_BKIN_GPIO_Port GPIOF
#define M3_TIM20_BKIN2_Pin GPIO_PIN_10
#define M3_TIM20_BKIN2_GPIO_Port GPIOF
#define ADC2_IN10_PFC_AC_V_Pin GPIO_PIN_1
#define ADC2_IN10_PFC_AC_V_GPIO_Port GPIOF
#define BUTTON_RESET_Pin GPIO_PIN_10
#define BUTTON_RESET_GPIO_Port GPIOG
#define M2_VBUS_ADC1_IN6_Pin GPIO_PIN_0
#define M2_VBUS_ADC1_IN6_GPIO_Port GPIOC
#define M2_RES_COS_ADC1_IN7_Pin GPIO_PIN_1
#define M2_RES_COS_ADC1_IN7_GPIO_Port GPIOC
#define M2_CURR_V_ADC12_IN8_Pin GPIO_PIN_2
#define M2_CURR_V_ADC12_IN8_GPIO_Port GPIOC
#define M2_CURR_W_ADC12_IN9_Pin GPIO_PIN_3
#define M2_CURR_W_ADC12_IN9_GPIO_Port GPIOC
#define M2_ENABLE2_GPIO_Pin GPIO_PIN_2
#define M2_ENABLE2_GPIO_GPIO_Port GPIOF
#define M1_TIM8_ETR_Pin GPIO_PIN_0
#define M1_TIM8_ETR_GPIO_Port GPIOA
#define M1_RES_SIN_ADC12_IN2_Pin GPIO_PIN_1
#define M1_RES_SIN_ADC12_IN2_GPIO_Port GPIOA
#define M1_RES_COS_ADC1_IN3_Pin GPIO_PIN_2
#define M1_RES_COS_ADC1_IN3_GPIO_Port GPIOA
#define M2_RES_SIN_ADC1_IN4_Pin GPIO_PIN_3
#define M2_RES_SIN_ADC1_IN4_GPIO_Port GPIOA
#define M1_RES_EX_DAC1_OUT1_Pin GPIO_PIN_4
#define M1_RES_EX_DAC1_OUT1_GPIO_Port GPIOA
#define M2_RES_EX_DAC1_OUT2_Pin GPIO_PIN_5
#define M2_RES_EX_DAC1_OUT2_GPIO_Port GPIOA
#define M3_TEMP_ID_ADC2IN3_Pin GPIO_PIN_6
#define M3_TEMP_ID_ADC2IN3_GPIO_Port GPIOA
#define M2_CURR_U_ADC2_IN4_Pin GPIO_PIN_7
#define M2_CURR_U_ADC2_IN4_GPIO_Port GPIOA
#define M2_TEMP_ID_ADC2_IN5_Pin GPIO_PIN_4
#define M2_TEMP_ID_ADC2_IN5_GPIO_Port GPIOC
#define PFC_AC_ZC_ADC2_IN11_Pin GPIO_PIN_5
#define PFC_AC_ZC_ADC2_IN11_GPIO_Port GPIOC
#define GPIO_OUT_INRUSH_Pin GPIO_PIN_11
#define GPIO_OUT_INRUSH_GPIO_Port GPIOF
#define M3_PWM_UH_TIM20_CH1_Pin GPIO_PIN_12
#define M3_PWM_UH_TIM20_CH1_GPIO_Port GPIOF
#define M3_PWM_VH_TIM20_CH2_Pin GPIO_PIN_13
#define M3_PWM_VH_TIM20_CH2_GPIO_Port GPIOF
#define M3_PWM_WH_TIM20_CH3_Pin GPIO_PIN_14
#define M3_PWM_WH_TIM20_CH3_GPIO_Port GPIOF
#define GPIO_OUT_ID_ENABLE_Pin GPIO_PIN_15
#define GPIO_OUT_ID_ENABLE_GPIO_Port GPIOF
#define M2_PWM_UH_TIM1_CH1_Pin GPIO_PIN_9
#define M2_PWM_UH_TIM1_CH1_GPIO_Port GPIOE
#define M2_PWM_VH_TIM1_CH2_Pin GPIO_PIN_11
#define M2_PWM_VH_TIM1_CH2_GPIO_Port GPIOE
#define M1_VOLT_V_ADC345_IN16_Pin GPIO_PIN_12
#define M1_VOLT_V_ADC345_IN16_GPIO_Port GPIOE
#define M2_PWM_WL_TIM1_CH3_Pin GPIO_PIN_13
#define M2_PWM_WL_TIM1_CH3_GPIO_Port GPIOE
#define ADC4_IN1_MORPHO_Pin GPIO_PIN_14
#define ADC4_IN1_MORPHO_GPIO_Port GPIOE
#define M1_TEMP_ID_ADC4_IN2_Pin GPIO_PIN_15
#define M1_TEMP_ID_ADC4_IN2_GPIO_Port GPIOE
#define M1_VBUS_ADC3_IN5_Pin GPIO_PIN_13
#define M1_VBUS_ADC3_IN5_GPIO_Port GPIOB
#define ADC45_IN12_PFC_Current1_Pin GPIO_PIN_8
#define ADC45_IN12_PFC_Current1_GPIO_Port GPIOD
#define ADC45_IN13_PFC_Current2_Pin GPIO_PIN_9
#define ADC45_IN13_PFC_Current2_GPIO_Port GPIOD
#define M1_VOLT_U_ADC345_IN7_Pin GPIO_PIN_10
#define M1_VOLT_U_ADC345_IN7_GPIO_Port GPIOD
#define M1_CURR_U_ADC345_IN8_Pin GPIO_PIN_11
#define M1_CURR_U_ADC345_IN8_GPIO_Port GPIOD
#define M1_CURR_V_ADC345_IN9_Pin GPIO_PIN_12
#define M1_CURR_V_ADC345_IN9_GPIO_Port GPIOD
#define M1_VOLT_W_ADC345_IN10_Pin GPIO_PIN_13
#define M1_VOLT_W_ADC345_IN10_GPIO_Port GPIOD
#define M1_CURR_W_ADC345_IN11_Pin GPIO_PIN_14
#define M1_CURR_W_ADC345_IN11_GPIO_Port GPIOD
#define M1_PWM_UH_TIM8_CH1_Pin GPIO_PIN_6
#define M1_PWM_UH_TIM8_CH1_GPIO_Port GPIOC
#define M1_PWM_VH_TIM8_CH2_Pin GPIO_PIN_7
#define M1_PWM_VH_TIM8_CH2_GPIO_Port GPIOC
#define M3_PWM_UL_TIM20_CH1N_Pin GPIO_PIN_0
#define M3_PWM_UL_TIM20_CH1N_GPIO_Port GPIOG
#define M3_PWM_VL_TIM20_CH2N_Pin GPIO_PIN_1
#define M3_PWM_VL_TIM20_CH2N_GPIO_Port GPIOG
#define M1_PWM_WH_TIM8_CH3_Pin GPIO_PIN_8
#define M1_PWM_WH_TIM8_CH3_GPIO_Port GPIOC
#define M3_ENABLE1_GPIO_Pin GPIO_PIN_9
#define M3_ENABLE1_GPIO_GPIO_Port GPIOC
#define M2_TIM1_BKIN2_Pin GPIO_PIN_11
#define M2_TIM1_BKIN2_GPIO_Port GPIOA
#define M2_HALL_H2_TIM4_CH2_Pin GPIO_PIN_12
#define M2_HALL_H2_TIM4_CH2_GPIO_Port GPIOA
#define M1_ENCA_TIM5_CH1_Pin GPIO_PIN_6
#define M1_ENCA_TIM5_CH1_GPIO_Port GPIOF
#define M1_PWM_UL_TIM8_CH1N_Pin GPIO_PIN_10
#define M1_PWM_UL_TIM8_CH1N_GPIO_Port GPIOC
#define M1_PWM_VL_TIM8_CH2N_Pin GPIO_PIN_11
#define M1_PWM_VL_TIM8_CH2N_GPIO_Port GPIOC
#define M1_PWM_WL_TIM8_CH3N_Pin GPIO_PIN_12
#define M1_PWM_WL_TIM8_CH3N_GPIO_Port GPIOC
#define GPIO_OUT_M2_ENABLE_Pin GPIO_PIN_6
#define GPIO_OUT_M2_ENABLE_GPIO_Port GPIOG
#define GPIO_OUT_M1_ENABLE_Pin GPIO_PIN_7
#define GPIO_OUT_M1_ENABLE_GPIO_Port GPIOG
#define GPIO_OUT_M1_BRAKE_Pin GPIO_PIN_8
#define GPIO_OUT_M1_BRAKE_GPIO_Port GPIOG
#define GPIO_OUT_M22_BRAKE_Pin GPIO_PIN_0
#define GPIO_OUT_M22_BRAKE_GPIO_Port GPIOD
#define M1_TIM8_BKIN2_Pin GPIO_PIN_1
#define M1_TIM8_BKIN2_GPIO_Port GPIOD
#define M3_ENABLE2_GPIO_Pin GPIO_PIN_2
#define M3_ENABLE2_GPIO_GPIO_Port GPIOD
#define M2_ENCA_TIM2_CH1_Pin GPIO_PIN_3
#define M2_ENCA_TIM2_CH1_GPIO_Port GPIOD
#define M2_ENCB_TIM2_CH2_Pin GPIO_PIN_4
#define M2_ENCB_TIM2_CH2_GPIO_Port GPIOD
#define GPIO_OUT_LED_YELLOW_Pin GPIO_PIN_5
#define GPIO_OUT_LED_YELLOW_GPIO_Port GPIOD
#define GPIO_OUT_LED_RED_Pin GPIO_PIN_6
#define GPIO_OUT_LED_RED_GPIO_Port GPIOD
#define M2_ENCZ_TIM2_CH3_Pin GPIO_PIN_7
#define M2_ENCZ_TIM2_CH3_GPIO_Port GPIOD
#define PFC_TIM17_BKIN_Pin GPIO_PIN_4
#define PFC_TIM17_BKIN_GPIO_Port GPIOB
#define PFC_TIM16_BKIN_Pin GPIO_PIN_5
#define PFC_TIM16_BKIN_GPIO_Port GPIOB
#define M2_HALL_H1_TIM4_CH1_Pin GPIO_PIN_6
#define M2_HALL_H1_TIM4_CH1_GPIO_Port GPIOB
#define M1_TIM8_BKIN_Pin GPIO_PIN_7
#define M1_TIM8_BKIN_GPIO_Port GPIOB
#define M2_HALL_H3_TIM4_CH3_Pin GPIO_PIN_8
#define M2_HALL_H3_TIM4_CH3_GPIO_Port GPIOB
#define M2_PWM_WL_TIM1_CH3N_Pin GPIO_PIN_9
#define M2_PWM_WL_TIM1_CH3N_GPIO_Port GPIOB
#define PFC_PWM1_TIM16_CH1_Pin GPIO_PIN_0
#define PFC_PWM1_TIM16_CH1_GPIO_Port GPIOE
#define PFC_PWM2_TIM17_CH1_Pin GPIO_PIN_1
#define PFC_PWM2_TIM17_CH1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
