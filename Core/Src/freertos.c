/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId SHOOT_TaskHandle;
osThreadId GIMBAL_TaskHandle;
osThreadId CHASSIS_TaskHandle;
osThreadId WATCHDOG_TaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void SHOOT_start_task(void const * argument);
void GIMBAL_start_task(void const * argument);
void CHASSIS_start_task(void const * argument);
void WATCHDOG_start_task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of SHOOT_Task */
  osThreadDef(SHOOT_Task, SHOOT_start_task, osPriorityIdle, 0, 128);
  SHOOT_TaskHandle = osThreadCreate(osThread(SHOOT_Task), NULL);

  /* definition and creation of GIMBAL_Task */
  osThreadDef(GIMBAL_Task, GIMBAL_start_task, osPriorityIdle, 0, 128);
  GIMBAL_TaskHandle = osThreadCreate(osThread(GIMBAL_Task), NULL);

  /* definition and creation of CHASSIS_Task */
  osThreadDef(CHASSIS_Task, CHASSIS_start_task, osPriorityIdle, 0, 128);
  CHASSIS_TaskHandle = osThreadCreate(osThread(CHASSIS_Task), NULL);

  /* definition and creation of WATCHDOG_Task */
  osThreadDef(WATCHDOG_Task, WATCHDOG_start_task, osPriorityIdle, 0, 128);
  WATCHDOG_TaskHandle = osThreadCreate(osThread(WATCHDOG_Task), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_SHOOT_start_task */
/**
* @brief Function implementing the SHOOT_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_SHOOT_start_task */
__weak void SHOOT_start_task(void const * argument)
{
  /* USER CODE BEGIN SHOOT_start_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END SHOOT_start_task */
}

/* USER CODE BEGIN Header_GIMBAL_start_task */
/**
* @brief Function implementing the GIMBAL_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_GIMBAL_start_task */
__weak void GIMBAL_start_task(void const * argument)
{
  /* USER CODE BEGIN GIMBAL_start_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END GIMBAL_start_task */
}

/* USER CODE BEGIN Header_CHASSIS_start_task */
/**
* @brief Function implementing the CHASSIS_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_CHASSIS_start_task */
__weak void CHASSIS_start_task(void const * argument)
{
  /* USER CODE BEGIN CHASSIS_start_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END CHASSIS_start_task */
}

/* USER CODE BEGIN Header_WATCHDOG_start_task */
/**
* @brief Function implementing the WATCHDOG_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_WATCHDOG_start_task */
__weak void WATCHDOG_start_task(void const * argument)
{
  /* USER CODE BEGIN WATCHDOG_start_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END WATCHDOG_start_task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
