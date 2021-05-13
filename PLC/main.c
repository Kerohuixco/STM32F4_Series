/*=====================================================================================================================================
 * File: UART1Handler.c 
 * Author: J. Angel Perez M.
 * Editor: Visual Studio Code     
 * Project: PLC    
 * Version: 1.0.0    
 * 
 * Compiler: MikroC ARM v6.2   
 * IDE: MikroC ARM v6.2         
 * Kernel:      
 * 
 * Notes: Template based in Standar MISRA C 2004
=====================================================================================================================================*/
#include "main.h"

#include "/Configuration/SystemConfig.c"

#include "../Library/UART1Handler.c"


void main( void ) {

     GPIO_Digital_Output( &GPIOA_BASE, _GPIO_PINMASK_14 );
     GPIO_Digital_Output( &GPIOA_BASE, _GPIO_PINMASK_15 );
     GPIO_Digital_Output( &GPIOB_BASE, _GPIO_PINMASK_0 );
     GPIO_Digital_Output( &GPIOB_BASE, _GPIO_PINMASK_5 );
     GPIO_Digital_Output( &GPIOB_BASE, _GPIO_PINMASK_2 );
     GPIO_Digital_Output( &GPIOB_BASE, _GPIO_PINMASK_3 );
     GPIO_Digital_Output( &GPIOB_BASE, _GPIO_PINMASK_4 );
     GPIO_Digital_Output( &GPIOB_BASE, _GPIO_PINMASK_5 );
     
     GPIO_Digital_Input( &GPIOB_BASE, _GPIO_PINMASK_12 );
     GPIO_Digital_Input( &GPIOB_BASE, _GPIO_PINMASK_13 );
     GPIO_Digital_Input( &GPIOB_BASE, _GPIO_PINMASK_14 );
     GPIO_Digital_Input( &GPIOB_BASE, _GPIO_PINMASK_15 );
     GPIO_Digital_Input( &GPIOC_BASE, _GPIO_PINMASK_0 );
     GPIO_Digital_Input( &GPIOC_BASE, _GPIO_PINMASK_1 );
     GPIO_Digital_Input( &GPIOC_BASE, _GPIO_PINMASK_2 );
     GPIO_Digital_Input( &GPIOC_BASE, _GPIO_PINMASK_3 );
     
     v_UART1_Tx_Init( void );

     Load_Data_From_Device( void );
     
     while(1){
              RELE_1 = ~ RELE_1;
              Delay_ms(1000);
              RELE_2 = ~ RELE_1;
              UART1_Write_Text("Hola nuevo mundo\r\n");
     }

}