//
// Created by 29568 on 2026/3/26.
//

#ifndef SHOOT_TASK_H
#define SHOOT_TASK_H
#include "dev_motor_dji.h"
#include "dev_motor_dm.h"
typedef enum
{
    WHEEL_OFF = 0,
    WHEEL_ON = 1,
} FRICTION_WHEEL_e;
typedef enum
{
    CLAW_DISABLE = 0,
    CLAW_ENABLE = 1,
}CLAW_e;
typedef  struct
{
    FRICTION_WHEEL_e state;
    float target_speed;
    DjiMotorInstance_s *motor[3];
}SHOOT_WHEEL_s;

typedef struct
{
    CLAW_e state;
    DmMotorInstance_s *motor;
}SHOOT_CLAW_s;

typedef struct
{
    SHOOT_WHEEL_s wheel;
    SHOOT_CLAW_s claw;
}SHOOT_s;
#endif //SHOOT_TASK_H