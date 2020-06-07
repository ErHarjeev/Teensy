// FSM Stop Watch Example
#include <Arduino.h>
void S_IDLE_Actions();
void S_PAUSED_Actions();
void S_RUNNING_Actions();
uint32_t counter = 0; //time
//Event
bool SS_pressed = false;
bool R_pressed = false;
//States IDLE, RUNNING, PAUSED
// enum type -> new datatype
enum states
{
    S_IDLE,
    S_RUNNING,
    S_PAUSED,
};
states current_state = S_IDLE; //initial transition
void setup()
{
}
void loop()
{
    //FSM
    switch (current_state)
    {
    case S_IDLE:
        //check events -> do transitions
        if (SS_pressed)
        {
            current_state = S_RUNNING;
        }                 //stay in state if reset is pressed
        S_IDLE_Actions(); //Actions
        break;
    case S_RUNNING:
        if (SS_pressed)
        {
            current_state = S_PAUSED;
        }
        else if (R_pressed)
        {
            current_state = S_IDLE;
        }
        S_RUNNING_Actions(); //Action
        break;
    case S_PAUSED:
        if (SS_pressed)
        {
            current_state = S_RUNNING;
        }
        else if (R_pressed)
        {
            current_state = S_IDLE;
        }
        S_PAUSED_Actions(); //Action -> nothing here
        break;
    default:
        //error
        break;
    }
}
void S_IDLE_Actions()
{
    counter = 0; //Actions
}
void S_RUNNING_Actions()
{
    counter++;
}
void S_PAUSED_Actions()
{
}