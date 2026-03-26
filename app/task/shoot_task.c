//
// Created by 29568 on 2026/3/26.
//

#include "shoot_task.h"

DmMotorInitConfig_s claw_config={
    .can_config = {
        .can_number = 2,
        .tx_id = 0x11,
        .rx_id = 0x21,
    },
    .parameters = {
        .pos_max = 3.14159f,
        .vel_max = 30.0f,
        .tor_max = 10.0f,
        .kp_max = 100.0f,
        .kd_max = 10.0f,
        .kp_int = 2.0f,
        .kd_int = 1.0f,
    },
    .control_mode = DM_POSITION,
    .topic_name = "1",
    .type = J4310,
    .velocity_pid_config = {
        .kp = 0.65f,
        .ki = 0.07f,
        .kd = 1.5f,
        .i_max = 2.0f,
        .out_max = 3.0f,
    },
    .angle_pid_config = {
        .kp = 30.0f,
        .ki = 0.0f,
        .kd = 5.0f,
        .i_max = 3.0f,
        .out_max = 8.0f,
        .angle_max =6.283186,
    },
};
DjiMotorInitConfig_s wheel_config[3] = {
    {
        .type = M3508,
        .control_mode = DJI_VELOCITY,
        .reduction_ratio = 1.0f,
        .topic_name = "1",
        .can_config = {
            .can_number = 1,
            .rx_id = 0x201,
            .tx_id = 0x200,
        },
        .velocity_pid_config = {
            .kp = 40.0f,
            .ki = 0.3f,
            .kd = 0.0f,
            .i_max = 1800.0f,
            .out_max = 10000.0f,
        },
    },
    {
        .type = M3508,
        .control_mode = DJI_VELOCITY,
        .reduction_ratio = 1.0f,
        .topic_name = "2",
        .can_config = {
            .can_number = 1,
            .rx_id = 0x202,
            .tx_id = 0x200,
        },
        .velocity_pid_config = {
            .kp = 40.0f,
            .ki = 0.3f,
            .kd = 0.0f,
            .i_max = 1800.0f,
            .out_max = 10000.0f,
        },
    },
    {
        .type = M3508,
        .control_mode = DJI_VELOCITY,
        .reduction_ratio = 1.0f,
        .topic_name = "3",
        .can_config = {
            .can_number = 1,
            .rx_id = 0x203,
            .tx_id = 0x200,
        },
        .velocity_pid_config = {
            .kp = 40.0f,
            .ki = 0.3f,
            .kd = 0.0f,
            .i_max = 1800.0f,
            .out_max = 10000.0f,
        },
    }
};
SHOOT_s shoot;

static void SHOOT_init(void)
{
    shoot.claw.motor = Motor_DM_Register(&claw_config);
    for(int i = 0; i < 3; i++)
    {
        shoot.wheel.motor[i] = Motor_Dji_Register(&wheel_config[i]);
    }
    shoot.claw.state = CLAW_DISABLE;
    shoot.wheel.state = WHEEL_OFF;
    shoot.wheel.target_speed = 4000.0f;
}

static void SHOOT_wheel_control(void)
{
    switch (shoot.wheel.state)
    {
    case WHEEL_OFF :
        {
            Pid_Disable(shoot.wheel.motor[0]->velocity_pid);
            Pid_Disable(shoot.wheel.motor[1]->velocity_pid);
            Pid_Disable(shoot.wheel.motor[2]->velocity_pid);
            if (Motor_Dji_Transmit(shoot.wheel.motor[0]) == false)
            {

            }
            break;
        }
    case WHEEL_ON :
        {
            Motor_Dji_Control(shoot.wheel.motor[0],shoot.wheel.target_speed);
            Motor_Dji_Control(shoot.wheel.motor[1],shoot.wheel.target_speed);
            Motor_Dji_Control(shoot.wheel.motor[2],shoot.wheel.target_speed);
            Motor_Dji_Transmit(shoot.wheel.motor[0]);
            break;
        }
    }
}

static void SHOOT_claw_control(void)
{
    switch (shoot.claw.state)
    {
    case CLAW_DISABLE :
        {
            Motor_Dm_Cmd(shoot.claw.motor,DM_CMD_MOTOR_DISABLE);
            Motor_Dm_Transmit(shoot.claw.motor);
            break;
        }
    case CLAW_ENABLE :
        {
            if (shoot.claw.motor->motor_state == DM_DISABLE)
            {
                Motor_Dm_Cmd(shoot.claw.motor,DM_CMD_MOTOR_ENABLE);
                Motor_Dm_Transmit(shoot.claw.motor);
            }
            break;
        }
    }
}

/* USER CODE BEGIN Header_SHOOT_start_task */
/**
* @brief Function implementing the SHOOT_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_SHOOT_start_task */
void SHOOT_start_task(void const * argument)
{
    /* USER CODE BEGIN SHOOT_start_task */
    SHOOT_init();
    /* Infinite loop */
    for(;;)
    {
        SHOOT_wheel_control();
        SHOOT_claw_control();
        osDelay(1);
    }
    /* USER CODE END SHOOT_start_task */
}