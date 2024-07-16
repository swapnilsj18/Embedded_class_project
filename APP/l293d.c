#include "L293d.h"
void motor_forward()
{
    IN3 = 1;
    IN4 = 0;
    relayPin = 1;
}
void motor_reverse()
{
    IN3 = 0;
    IN4 = 1;
    relayPin = 1;
}
void motor_off()
{
    IN3 = 0;
    IN4 = 0;
    relayPin = 0;
}
