/*
 * HardwareManager.c
 *
 *  Created on: May 27, 2020
 *      Author: PRG_C FS20
 */

#include "driverlib.h"
#include "HardwareManager.h"


// Backup Memory variables to track states through LPM3.5
volatile unsigned char * S1buttonDebounce = &BAKMEM2_L;       // S1 button debounce flag
volatile unsigned char * S2buttonDebounce = &BAKMEM2_H;       // S2 button debounce flag

ButtonSignal S1ButtonSignal = 0;
ButtonSignal S2ButtonSignal = 0;


Timer_A_initUpModeParam initUpParam_A0 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_1,          // SMCLK/1 = 2MHz
        30000,                                  // 15ms debounce period
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR,                       // Clear value
        true                                    // Start Timer
};

/*

Timer_B_initUpModeParam initUpParam_B0 =
{
        TIMER_B_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
        TIMER_B_CLOCKSOURCE_DIVIDER_1,          // SMCLK/1 = 2MHz
        30000,                                  // 15ms debounce period
        TIMER_B_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_B_DO_CLEAR,                       // Clear value
        true                                    // Start Timer
};

*/


/*
 * GPIO Initialization
 */
void Init_GPIO()
{
    // Set all GPIO pins to output low to prevent floating input and reduce power consumption
    GPIO_setOutputLowOnPin(
            GPIO_PORT_P1,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setOutputLowOnPin(
            GPIO_PORT_P2,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setOutputLowOnPin(
            GPIO_PORT_P3,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setOutputLowOnPin(
            GPIO_PORT_P4,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setOutputLowOnPin(
            GPIO_PORT_P5,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setOutputLowOnPin(
            GPIO_PORT_P6,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setOutputLowOnPin(
            GPIO_PORT_P7,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setOutputLowOnPin(
            GPIO_PORT_P8,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);

    GPIO_setAsOutputPin(
            GPIO_PORT_P1,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(
            GPIO_PORT_P2,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(
            GPIO_PORT_P3,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(
            GPIO_PORT_P4,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(
            GPIO_PORT_P5,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(
            GPIO_PORT_P6,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(
            GPIO_PORT_P7,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);
    GPIO_setAsOutputPin(
            GPIO_PORT_P8,
            GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN4
                    | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);

    GPIO_setAsInputPin(GPIO_PORT_P1, GPIO_PIN1);

    // Configure button S1 (P1.2) interrupt
    GPIO_selectInterruptEdge(GPIO_PORT_P1, GPIO_PIN2,
                             GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN2);

    // Configure button S2 (P2.6) interrupt
    GPIO_selectInterruptEdge(GPIO_PORT_P2, GPIO_PIN6,
                             GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_clearInterrupt(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_enableInterrupt(GPIO_PORT_P2, GPIO_PIN6);

    // Set P4.1 and P4.2 as Secondary Module Function Input, LFXT.
    GPIO_setAsPeripheralModuleFunctionInputPin(
    GPIO_PORT_P4,
                                               GPIO_PIN1 + GPIO_PIN2,
                                               GPIO_PRIMARY_MODULE_FUNCTION);

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PMM_unlockLPM5();
}

/*
 * Clock System Initialization
 */
void Init_Clock()
{
    // Initializes the XT1 crystal oscillator
    CS_turnOnXT1(CS_XT1_DRIVE_1);
}


#if 0
/*
 * Real Time Clock counter Initialization
 */
void Init_RTC()
{
    // Set RTC modulo to 327-1 to trigger interrupt every ~10 ms
    RTC_setModulo(RTC_BASE, 326);
    RTC_enableInterrupt(RTC_BASE, RTC_OVERFLOW_INTERRUPT);
}
#endif

/*
 * PORT1 Interrupt Service Routine
 * Handles S1 button press interrupt
 */
#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
    P1OUT |= BIT0;    // Turn LED1 On
    switch (__even_in_range(P1IV, P1IV_P1IFG7))
    {
    case P1IV_NONE:
        break;
    case P1IV_P1IFG0:
        break;
    case P1IV_P1IFG1:
        break;
    case P1IV_P1IFG2:
        if ((*S1buttonDebounce) == 0)
        {
            *S1buttonDebounce = 1;               // First high to low transition
            S1ButtonSignal = 1;
#if 0
            holdCount = 0;
            if (*mode == STOPWATCH_MODE)
            {
                // Start/Pause stopwatch
                *stopWatchRunning ^= 0x1;
                if (*stopWatchRunning)
                    RTC_start(RTC_BASE, RTC_CLOCKSOURCE_XT1CLK);
                else
                    RTC_stop(RTC_BASE);
            }
            if (*mode == TEMPSENSOR_MODE)
            {
                // Start/Pause temp sensor
                *tempSensorRunning ^= 0x1;
            }
#endif

            // Start debounce timer
            Timer_A_initUpMode(TIMER_A0_BASE, &initUpParam_A0);
        }
        break;
    case P1IV_P1IFG3:
        break;
    case P1IV_P1IFG4:
        break;
    case P1IV_P1IFG5:
        break;
    case P1IV_P1IFG6:
        break;
    case P1IV_P1IFG7:
        break;
    }
}

/*
 * PORT2 Interrupt Service Routine
 * Handles S2 button press interrupt
 */
#pragma vector = PORT2_VECTOR
__interrupt void PORT2_ISR(void)
{
    P4OUT |= BIT0;    // Turn LED2 On
    switch (__even_in_range(P2IV, P2IV_P2IFG7))
    {
    case P2IV_NONE:
        break;
    case P2IV_P2IFG0:
        break;
    case P2IV_P2IFG1:
        break;
    case P2IV_P2IFG2:
        break;
    case P2IV_P2IFG3:
        break;
    case P2IV_P2IFG4:
        break;
    case P2IV_P2IFG5:
        break;
    case P2IV_P2IFG6:

        if ((*S2buttonDebounce) == 0)
        {
            *S2buttonDebounce = 1;               // First high to low transition
            S2ButtonSignal = 1;
#if 0
            holdCount = 0;
            switch (*mode)
            {
            case STOPWATCH_MODE:
                // Reset stopwatch if stopped; Split if running
                if (!(*stopWatchRunning))
                {
                    if (LCDMEMCTL & LCDDISP)
                        LCDMEMCTL &= ~LCDDISP;
                    else
                        resetStopWatch();
                }
                else
                {
                    // Use LCD Blink memory to pause/resume stopwatch at split time
                    LCDBMEMW[pos1 / 2] = LCDMEMW[pos1 / 2];
                    LCDBMEMW[pos2 / 2] = LCDMEMW[pos2 / 2];
                    LCDBMEMW[pos3 / 2] = LCDMEMW[pos3 / 2];
                    LCDBMEMW[pos4 / 2] = LCDMEMW[pos4 / 2];
                    LCDBMEMW[pos5 / 2] = LCDMEMW[pos5 / 2];
                    LCDBMEMW[pos6 / 2] = LCDMEMW[pos6 / 2];
                    LCDBMEMW[12 / 2] = LCDMEMW[12 / 2];

                    // Toggle between LCD Normal/Blink memory
                    LCDMEMCTL ^= LCDDISP;
                }
                break;
            case TEMPSENSOR_MODE:
                // Toggle temperature unit flag
                *tempUnit ^= 0x01;
                // Update LCD when temp sensor is not running
                if (!*tempSensorRunning)
                    displayTemp();
                break;
            }
#endif

            // Start debounce timer
            Timer_A_initUpMode(TIMER_A0_BASE, &initUpParam_A0);
        }
        break;

    case P2IV_P2IFG7:
        break;
    }
}

/*
 * Timer A0 Interrupt Service Routine
 * Used as button debounce timer
 */
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR (void)
{
#if 0
    // Both button S1 & S2 held down
    if (!(P1IN & BIT2) && !(P2IN & BIT6))
    {
        holdCount++;
        if (holdCount == 40)
        {
            // Stop Timer A0
            Timer_A_stop(TIMER_A0_BASE);

            // Change mode
            if (*mode == STARTUP_MODE)
            (*mode) = STOPWATCH_MODE;
            else if (*mode == STOPWATCH_MODE)
            {
                (*mode) = TEMPSENSOR_MODE;
                *stopWatchRunning = 0;
                RTC_stop(RTC_BASE);
            }
            else if (*mode == TEMPSENSOR_MODE)
            {
                (*mode) = STOPWATCH_MODE;
                *tempSensorRunning = 0;
            }
            __bic_SR_register_on_exit(LPM3_bits);                // exit LPM3
        }
    }
#endif

    // Button S1 released
    if (P1IN & BIT2)
    {
        *S1buttonDebounce = 0;                          // Clear button debounce
        P1OUT &= ~BIT0;
    }

    // Button S2 released
    if (P2IN & BIT6)
    {
        *S2buttonDebounce = 0;                          // Clear button debounce
        P4OUT &= ~BIT0;
    }
    // Both button S1 & S2 released
    if ((P1IN & BIT2) && (P2IN & BIT6))
    {
        // Stop timer A0
        Timer_A_stop(TIMER_A0_BASE);
        /*
        if (*mode == STOPWATCH_MODE)
        if (!(*stopWatchRunning))
        __bic_SR_register_on_exit(LPM3_bits);// exit LPM3
        if (*mode == TEMPSENSOR_MODE)
        __bic_SR_register_on_exit(LPM3_bits);// exit LPM3
        */
    }
}


#if 0

/*
 * Timer B0 Interrupt Service Routine
 * Used as button debounce timer
 */
#pragma vector = TIMER0_B0_VECTOR
__interrupt void TIMER0_B0_ISR (void)
{
    // Both button S1 & S2 held down
    if (!(P1IN & BIT2) && !(P2IN & BIT6))
    {
        holdCount++;
        if (holdCount == 40)
        {
            // Stop Timer A0
            Timer_A_stop(TIMER_A0_BASE);

            // Change mode
            if (*mode == STARTUP_MODE)
            (*mode) = STOPWATCH_MODE;
            else if (*mode == STOPWATCH_MODE)
            {
                (*mode) = TEMPSENSOR_MODE;
                *stopWatchRunning = 0;
                RTC_stop(RTC_BASE);
            }
            else if (*mode == TEMPSENSOR_MODE)
            {
                (*mode) = STOPWATCH_MODE;
                *tempSensorRunning = 0;
            }
            __bic_SR_register_on_exit(LPM3_bits);                // exit LPM3
        }
    }

    // Button S1 released
    if (P1IN & BIT2)
    {
        *S1buttonDebounce = 0;                          // Clear button debounce
        P1OUT &= ~BIT0;
    }

    // Button S2 released
    if (P2IN & BIT6)
    {
        *S2buttonDebounce = 0;                          // Clear button debounce
        P4OUT &= ~BIT0;
    }
    // Both button S1 & S2 released
    if ((P1IN & BIT2) && (P2IN & BIT6))
    {
        // Stop timer A0
        Timer_B_stop(TIMER_B0_BASE);
        /*
        if (*mode == STOPWATCH_MODE)
        if (!(*stopWatchRunning))
        __bic_SR_register_on_exit(LPM3_bits);// exit LPM3
        if (*mode == TEMPSENSOR_MODE)
        __bic_SR_register_on_exit(LPM3_bits);// exit LPM3
        */
    }
}
#endif


#if 0
/*
 * RTC Interrupt Service Routine
 * Wakes up every ~10 milliseconds to update stowatch
 */
#pragma vector = RTC_VECTOR
__interrupt void RTC_ISR(void)
{
    switch (__even_in_range(RTCIV, RTCIV_RTCIF))
    {
    case RTCIV_NONE:
        break;
    case RTCIV_RTCIF:
#if 0
        if (*mode == STARTUP_MODE)
        {
            __bic_SR_register_on_exit(LPM3_bits);            // exit LPM3
        }
        if (*mode == STOPWATCH_MODE)
        {
            // Since RTC runs at 32768 Hz and isn't fast enough to count 10 ms exactly
            // offset RTC counter every 100 10ms intervals to add up to 1s
            // (327 * 32) + (328 * 68) = 32768
            if((*count)==31)
            {
                // Set RTC to interrupt after 328 XT1 cycles
                RTC_setModulo(RTC_BASE, 327);
            }
            else if((*count)==99)
            {
                // Set RTC to interrupt after 327 XT1 cycles
                RTC_setModulo(RTC_BASE, 326);
                (*count)=0;
            }
            (*count)++;
            __bic_SR_register_on_exit(LPM3_bits);            // exit LPM3
        }
        if (*mode == TEMPSENSOR_MODE)
        __bic_SR_register_on_exit(LPM3_bits);            // exit LPM3
#endif
        break;
    }
}

/*
 * ADC Interrupt Service Routine
 * Wake up from LPM3 when ADC conversion completes
 */
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC_VECTOR
__interrupt void ADC_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC_VECTOR))) ADC_ISR (void)
#else
#error Compiler not supported!
#endif
{
    switch (__even_in_range(ADCIV, ADCIV_ADCIFG))
    {
    case ADCIV_NONE:
        break;
    case ADCIV_ADCOVIFG:
        break;
    case ADCIV_ADCTOVIFG:
        break;
    case ADCIV_ADCHIIFG:
        break;
    case ADCIV_ADCLOIFG:
        break;
    case ADCIV_ADCINIFG:
        break;
    case ADCIV_ADCIFG:
        // Clear interrupt flag
        ADC_clearInterrupt(ADC_BASE, ADC_COMPLETED_INTERRUPT_FLAG);
        __bic_SR_register_on_exit(LPM3_bits);                // Exit LPM3
        break;
    default:
        break;
    }
}
#endif
