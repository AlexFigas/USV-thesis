void Thruster::setDirection(bool clockwise)
{
    if (clockwise)
    {
        _expander.setMinPwmOn(pulseToTicks(controller.PWM_STOP_PULSE));
        _expander.setMaxPwmOn(pulseToTicks(controller.PWM_MIN_PULSE));
    }
    else
    {
        _expander.setMinPwmOn(pulseToTicks(controller.PWM_STOP_PULSE));
        _expander.setMaxPwmOn(pulseToTicks(controller.PWM_MAX_PULSE));
    }
}

uint16_t Thruster::pulseToTicks(int microseconds)
{
    return (uint16_t)((microseconds * 4096L) / (1000000 / controller.PWM_FREQ));
}