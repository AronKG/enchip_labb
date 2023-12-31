/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "quad_sseg.h"
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
// Function prototypes
void updateClock();
void updateDisplay();
void handleRollovers();

uint16_t button_exti_count;
uint16_t button_debounced_count;
uint16_t unhandled_exti;

uint8_t hours = 23;
uint8_t minutes = 59;
uint8_t seconds = 23;

int display_hours_minutes = 0; // Flag for display mode (0: MM:SS, 1 HH:MM)

//Time counter
//uint16_t timeCounter = 0;

//Flag for colon blinking
uint8_t colonOn = 0;
uint8_t hoursTens ;       // Hours (24-hour format)
uint8_t hoursOnes;
uint8_t minutesTens ;   // Minutes (modulo 60)
uint8_t minutesOnes ;
uint8_t secondsTens;   // Seconds (modulo 60)
uint8_t secondsOnes ;



TIM_HandleTypeDef htm;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


void uart_print_menu(){
	    char menu_str[100];

	    sprintf(menu_str,
            "Choose the menu:\r\n"
	    	"1. Clock mode:\r\n"
	        "2. Button mode:\r\n");

	    HAL_UART_Transmit(&huart2, (uint8_t*) menu_str, strlen(menu_str), HAL_MAX_DELAY);
}

int uart_get_menu_choice()
{
	char str[1];
	uint16_t str_len = 1;
	HAL_UART_Receive(&huart2,(uint8_t *) str, str_len,HAL_MAX_DELAY);
	int ret = -1;
	sscanf(str, "%d", &ret);


	return ret;
}

void uart_print_bad_choice()
{
	char bad_choice_str[]="Felaktig inmatning. Vänligen välj ett giltigt alternativ 1 eller 2.\r\n";
	HAL_UART_Transmit(&huart2, (uint8_t*)bad_choice_str, sizeof(bad_choice_str) - 1, HAL_MAX_DELAY);
}

void clock_mode()
{
	/*** init segment ***/
	/*** main loop ***/
	HAL_TIM_Base_Start_IT(&htim3);

	 hours = 23;
	 minutes = 59;
	 seconds = 45;

	while (1)
	{
		 // Update your clock variables based on TIM3 interrupts
		        // ...

		// Check if the blue button is held down to switch display mode
		if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)){
			display_hours_minutes = 1;   //Swithch to HH:MM
		}
		else{
			display_hours_minutes = 0; // Back to MM:SS mode
		}
		updateDisplay();


	}
}


void button_mode()
{
	/*** init segment ***/

	/*** main loop ***/

	int b1_pressed;
	int pressed;
	while (1)
	{
		/* deal with debouncing the button... */

		// check b1 button (on board, active low)
		b1_pressed = GPIO_PIN_RESET== HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);


		if (unhandled_exti) // was set in interrupt
		{
			uint16_t BOUNCE_DELAY_MS = 10;
			HAL_Delay(BOUNCE_DELAY_MS); // value measured by probing
			pressed = GPIO_PIN_RESET == HAL_GPIO_ReadPin(MY_BTN_GPIO_Port, MY_BTN_Pin);
				if (pressed)
				{
					button_debounced_count++;

				}
			unhandled_exti = 0;
		}

		if(b1_pressed){
			qs_put_big_num(button_exti_count, 0);


		}
		else{
			qs_put_big_num(button_debounced_count, 0);

		}
	}

}



//#define MY_BTN_Pin GPIO_PIN_2
//#define MY_BTN_GPIO_Port GPIOC

void HAL_GPIO_EXTI_Callback( uint16_t GPIO_Pin )
{
	if(GPIO_Pin ==  MY_BTN_Pin)
	{
		button_exti_count++;
		unhandled_exti = 1;
	}

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if(htim->Instance == TIM3){
		//This function will be called every half-second
		// Update your clock variables here
		//...
		colonOn = !colonOn;
		if(colonOn == 1){
		seconds++;
		}
	}
}

void updateClock(){
	//seconds++;        //Incriment seconds
	handleRollovers();  // Handle rollovers
}

//Function to hanle rollovers

void handleRollovers()
{
	if(seconds >= 60)
	{
		seconds = 0;
		minutes++;
		if(minutes >= 60)
		{
			minutes = 0;
			hours++;
			if(hours >= 24)
			{
				hours = 0;
			}
		}
	}
}

void updateDisplay()
{
	// Toggle colon every half seconde


	// Detrmain whether to diplay HH:MM or MM:SS
	updateClock();

	 hoursTens = (hours % 24) / 10;       // Hours (24-hour format)
	 hoursOnes = (hours % 24) % 10;
	 minutesTens = (minutes % 60) / 10;   // Minutes (modulo 60)
	 minutesOnes = (minutes % 60) % 10;
	 secondsTens = (seconds % 60) / 10;   // Seconds (modulo 60)
	 secondsOnes = (seconds % 60) % 10;

	if(display_hours_minutes)
	{
		//qs_put_big_num((uint16_t)(hours * 100 + minutes), colonOn);
        qs_put_digits(hoursTens, hoursOnes, minutesTens, minutesOnes, colonOn);
	}
	else
	{
		//qs_put_big_num((uint16_t)(hours * 100 + minutes), colonOn);
        qs_put_digits(minutesTens, minutesOnes, secondsTens, secondsOnes, colonOn);
	}
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


	  uart_print_menu();
	  int menu_choice = uart_get_menu_choice();
	  {
		  switch (menu_choice)
			  {
			  case 1:
				  clock_mode();
			  break;
			  case 2:
				  button_mode();
			  break;
			  default: uart_print_bad_choice();
			  break;
			  }
	    }


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 1000-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 42000-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, SEG_DIO_Pin|SEG_CLK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : B1_Pin MY_BTN_Pin */
  GPIO_InitStruct.Pin = B1_Pin|MY_BTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_DIO_Pin SEG_CLK_Pin */
  GPIO_InitStruct.Pin = SEG_DIO_Pin|SEG_CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
