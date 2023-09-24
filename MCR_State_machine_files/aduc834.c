
/* a header with definitions of symbols for ADuC834 */
#include <aduc834.h>
#include <lab2_board.h>
#include <lcd_comm.h>
/* a millisecond system timer */
volatile long int system_timer;

extern void LCD_DelayMs (uint16_t ms_cnt);



void IsrTimer2 (void) interrupt 5
{
 system_timer++;
 TF2 = 0;
}

/*Listing 2*/
void Timer2Init (void)
{
/******************************************** 
TODO:
 configure the Timer 2 to overflow each 1 ms, 
 use the mode with automatic reload
*********************************************/
	TL2 = 0xF0;
	TH2 = 0xD1;
	ET2=1;
	EA=1;
	TR2=1;

}

void StateInitialize(void);
void StateIdle(void);
void StateSetTimeout(void);
void StateCountdown(void);


/* an array of pointers to state functions */
void (*state_array[])() = {StateInitialize, StateIdle,
StateSetTimeout, StateCountdown};
/* a definition of an enumerated type 
 used for indexing the state_array */
typedef enum {ST_INITIALIZE, ST_IDLE, ST_SET_TIMEOUT, ST_COUNTDOWN}
state_name_t;
/* a variable specifying the current state */
state_name_t current_state;

/* timeout for the countdown value in milliseconds */
static long int timeout_set;
void StateInitialize (void)
{
/* set the LCD backlight to violet */ 
PORT_LCD_LED &= ~((1 << LCD_RED) | (1 << LCD_BLUE)); 
Timer2Init();
/*InterruptsInit();
LCD_Init();
/******************************************** 
TODO:
1. call the ADC initialization function
2. display a message that the application is initializing
3. wait 3 seconds
*********************************************/
 /* transition to the next state occurs after calling
 its function for the first time */
	LCD_SendString("Hang tight! Initializing State Machine... ");
if (P2&(1<<1))==0{
 StateIdle();
}

}


void StateIdle (void)
{ 
 /* check for entry */
 if (current_state != ST_IDLE)
 {
 current_state = ST_IDLE;
 
/******************************************** 
TODO:
1. display the menu
2. set the LCD backlight to green
*********************************************/
PORT_LCD_LED &= ~((1 << LCD_GREEN)
LCD_SendString("Menu\nA. Start Timer\n B. Set Timer");
	
 return;
 }
 
 if (BUTTON1_CHK)
 {
 StateSetTimeout();
 
 } else if (BUTTON2_CHK)
 {
 StateCountdown();
 }
}


void StateCountdown (void)
{
 static long int time_start, time_1s_ref;
 
 /* check for entry */
 if (current_state != ST_COUNTDOWN)
 {
 current_state = ST_COUNTDOWN;
 
 /* store the value of the system timer 
 from which the countdown begins */
 time_start = system_timer;
 /* a reference for 1-sec timeouts */
 time_1s_ref = time_start;
 return;
 } 
/******************************************** 
TODO:
1. conditionally transit to the idle state
 when the button C is pressed
2. display the information on how to return to the menu
3. set the LCD backlight to turquoise
*********************************************/ 
 /* check if a 1-sec timeout expired 
 (used for 1 Hz display update) */
 if (system_timer - time_1s_ref > 1000)
 { 
 time_1s_ref += 1000;
/******************************************** 
TODO:
 display the remaining time (after each 1 second)
*********************************************/ 
 }
 /* check if the timeout expired */
 if (system_timer - time_start > timeout_set)
 { 
 StateIdle(); 
 }
} 
void StateSetTimeout (void)
{
/********************************************
	TODO: 
Implement the timeout adjustment:
1. on entry, set the current state to ST_SET_TIMEOUT
2. change the „timeout_set” variable value in the range 
 from 1000 to 20000 milliseconds based on the readings 
 from the ADC channel connected to the potentiometer
3. when the user presses the C button,
 transit to the idle state
*********************************************/
}

int main (void)
{
 current_state = ST_INITIALIZE;
 while (1)
 {
 /* current state function is executed from the 
 state function array */
 state_array[current_state]();
 }
}


