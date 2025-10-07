void Control::control()
{
    if (state == StateMessage_State_AUTOMATIC)
    {
        if (lastState != state)
        {
            automaticLed.on();
            manualLed.off();
            lastState = state;
        }

        automaticControl();
    }
    else if (state == StateMessage_State_MANUAL)
    {
        if (lastState != state)
        {
            automaticLed.off();
            manualLed.on();
            lastState = state;
        }

        manualControl(manualState);
    }
}

void Control::automaticControl()
{
    if (currentWaypoint >= waypoints.size() && waypoints.size() > 0)
    {
        automaticLed.blink(2000, 100);
        movement.stop();
        return;
    }
    setCourse(lastBearingError);
}

void Control::setCourse(int bearingError)
{
    if (bearingError > 0)
    {
        movement.right(100, 0, bearingError);
    }
    else if (bearingError < 0)
    {
        movement.left(100, 0, -bearingError);
    }
    else
    {
        movement.front(100, 0);
    }
}
