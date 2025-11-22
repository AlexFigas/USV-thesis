void Led::update()
{
    if (!isBlinking)
        return;

    unsigned long now = millis();

    if ((now - blinkStart) >= blinkDuration)
    {
        isBlinking = false;
        if (lastState == State::ON)
        {
            on();
        }
        else
        {
            off();
        }
        return;
    }

    if (state == State::BLINK_ON && (now - lastToggle) >= blinkInterval)
    {
        expander.setPWM(pin, 0);
        state = State::BLINK_OFF;
        lastToggle = now;
    }
    else if (state == State::BLINK_OFF && (now - lastToggle) >= blinkInterval)
    {
        expander.setPWM(pin, 4095);
        state = State::BLINK_ON;
        lastToggle = now;
    }
}