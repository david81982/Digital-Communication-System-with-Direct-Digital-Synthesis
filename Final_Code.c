//------------------------------------------------------------------------------------
//  Company: Texas Tech University
//  Engineer: David Gomez and William Tolson
//
//  Course:  TTU Digital Communications Project Lab (ECE-3334-302)
//
//  Project description: Digital Communication System with Direct Digital Synthesis:
//      Design and construct a wireless communication system that takes an ASCII
//      alpha-numeric input and produces a modulated RF signal using DDS.
//      Amplify the modulated carrier signal and transmit the signal wirelessly.
//
//  Version: 2.8
//
//  Additional comments: Code has been reviewed and fully tested before demo 
//      presentation.
//------------------------------------------------------------------------------------

#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; //Stop watchdog timer

//Initalize all the Input pins
    P1DIR &= ~BIT2; //Making P1.2 as Input
    P1REN = BIT2;   //Enable Pullup/down
    P1OUT = BIT2;   //Select Pullup

    P1DIR &= ~BIT3; //Making P1.3 as Input
    P1REN = BIT3;   //Enable Pullup/down
    P1OUT = BIT3;   //Select Pullup

    P2DIR &= ~BIT4; //Making P2.4 as Input
    P2REN = BIT4;   //Enable Pullup/down
    P2OUT = BIT4;   //Select Pullup

    P2DIR &= ~BIT6; //Making P2.6 as Input
    P2REN = BIT6;   //Enable Pullup/down
    P2OUT = BIT6;   //Select Pullup

    P3DIR &= ~BIT1; //Making P3.1 as Input
    P3REN = BIT1;   //Enable Pullup/down
    P3OUT = BIT1;   //Select Pullup

    P3DIR &= ~BIT7; //Making P3.7 as Input
    P3REN = BIT7;   //Enable Pullup/down
    P3OUT = BIT7;   //Select Pullup

    P7DIR &= ~BIT0; //Making P7.0 as Input
    P7REN = BIT0;   //Enable Pullup/down
    P7OUT = BIT0;   //Select Pullup

    P7DIR &= ~BIT4; //Making P7.4 as Input
    P7REN = BIT4;   //Enable Pullup/down
    P7OUT = BIT4;   //Select Pullup

    P8DIR &= ~BIT1; //Making P8.1 as Input
    P8REN = BIT1;   //Enable Pullup/down
    P8OUT = BIT1;   //Select Pullup

    P8DIR &= ~BIT2; //Making P8.2 as Input
    P8REN = BIT2;   //Enable Pullup/down
    P8OUT = BIT2;   //Select Pullup

//Initialize all the Output pins
    P1DIR |= BIT6;  //Making P1.6 as Output
    P3DIR |= BIT4;  //Making P3.4 as Output
    P3DIR |= BIT3;  //Making P3.3 as Output
    P6DIR |= BIT5;  //Making P6.5 as Output

//Initialize all the variables
    int num, c, d;
    num = 0;        //Default case

//Infinite loop
    while(1)
    {

        //Check if there is an Input with the buttons
        if( !(P1IN & BIT2) )         //Evaluates to True for a 'LOW' on P1.2
        {
            num = 1;                 //Case 1
            while( !(P1IN & BIT2) ); //wait until button is released
        }

        else if( !(P1IN & BIT3) )    //Evaluates to True for a 'LOW' on P1.3
        {
            num = 2;                 //Case 2
            while( !(P1IN & BIT3) ); //wait until button is released
        }

        else if( !(P2IN & BIT4) )    //Evaluates to True for a 'LOW' on P2.4
        {
            num = 3;                 //Case 3
            while( !(P2IN & BIT4) ); //wait until button is released
        }

        else if( !(P3IN & BIT7) )    //Evaluates to True for a 'LOW' on P3.7
        {
            num = 4;                 //Case 4
            while( !(P3IN & BIT7) ); //wait until button is released
        }

        else if( !(P8IN & BIT2) )    //Evaluates to True for a 'LOW' on P8.2
        {
            num = 5;                 //Case 5
            while( !(P8IN & BIT2) ); //wait until button is released
        }

        else if( !(P8IN & BIT1) )    //Evaluates to True for a 'LOW' on P8.1
        {
            num = 6;                 //Case 6
            while( !(P8IN & BIT1) ); //wait until button is released
        }

        else if( !(P2IN & BIT6) )    //Evaluates to True for a 'LOW' on P2.6
        {
            num = 7;                 //Case 7
            while( !(P2IN & BIT6) ); //wait until button is released
        }

        else if( !(P7IN & BIT4) )    //Evaluates to True for a 'LOW' on P7.4
        {
            num = 8;                 //Case 8
            while( !(P7IN & BIT4) ); //wait until button is released
        }

        else if( !(P3IN & BIT1) )    //Evaluates to True for a 'LOW' on P3.1
        {
            num = 9;                 //Case 9
            while( !(P3IN & BIT1) ); //wait until button is released
        }

        else if( !(P7IN & BIT0) )    //Evaluates to True for a 'LOW' on P7.0
        {
            num = 10;                //Case 10
            while( !(P7IN & BIT0) ); //wait until button is released
        }

        //Based on the Input produce their respective binary
        switch (num) {

        case 1:
            P6OUT &= ~BIT5;
            P3OUT |= BIT4;
            P3OUT |= BIT3;
            P1OUT &= ~BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        case 2:
            P6OUT |= BIT5;
            P3OUT |= BIT4;
            P3OUT |= BIT3;
            P1OUT &= ~BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        case 3:
            P6OUT &= ~BIT5;
            P3OUT &= ~BIT4;
            P3OUT &= ~BIT3;
            P1OUT |= BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        case 4:
            P6OUT |= BIT5;
            P3OUT &= ~BIT4;
            P3OUT &= ~BIT3;
            P1OUT |= BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        case 5:
            P6OUT &= ~BIT5;
            P3OUT |= BIT4;
            P3OUT &= ~BIT3;
            P1OUT |= BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        case 6:
            P6OUT |= BIT5;
            P3OUT |= BIT4;
            P3OUT &= ~BIT3;
            P1OUT |= BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        case 7:
            P6OUT &= ~BIT5;
            P3OUT &= ~BIT4;
            P3OUT |= BIT3;
            P1OUT |= BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        case 8:
            P6OUT |= BIT5;
            P3OUT &= ~BIT4;
            P3OUT |= BIT3;
            P1OUT |= BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        case 9:
            P6OUT &= ~BIT5;
            P3OUT |= BIT4;
            P3OUT |= BIT3;
            P1OUT |= BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        case 10:
            P6OUT |= BIT5;
            P3OUT |= BIT4;
            P3OUT |= BIT3;
            P1OUT |= BIT6;
            
            //Manuel time delay
            for (c = 1; c <= 300; c++)
               for (d = 1; d <= 300; d++)
               {}
            break;

        default:
            //Do nothing
            break;
        }

        //Set all to Low so that the loop creates a wave
        P6OUT &= ~BIT5;
        P3OUT &= ~BIT4;
        P3OUT &= ~BIT3;
        P1OUT &= ~BIT6;
        
        //Manuel time delay
        for (c = 1; c <= 250; c++)
           for (d = 1; d <= 250; d++)
           {}
    }
    return 0;   //This will never run
}
