int Expander::setDutyCycle(byte channel, float duty_cycle)
{
    int pwm = map(duty_cycle, _MIN_DUTY_CYCLE, _MAX_DUTY_CYCLE, _MIN_PWM_ON, _MAX_PWM_ON);
    _board.setPWM(channel, _PWM_OFF_POINT, pwm);
    return pwm;
}