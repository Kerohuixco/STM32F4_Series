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

#include "UART1Handler.h"


/**********************************************************************************************
 * Local Variables
**********************************************************************************************/
 static uint8_t ucTempByteUART = 0;

 static uint8_t pcRxUARTBuffer[ UART1_MAX_BUFFER_LENGTH ]; 
 static uint16_t usUARTMessageLength = 0;

 static uint8_t UART1_DataReady = 0;

/**********************************************************************************************
 * Instances
**********************************************************************************************/

/**********************************************************************************************
 * IRQ Handlers
**********************************************************************************************/
#ifdef STM32F401RE  
void vUSART_ISRCallback( void ) iv IVT_INT_USART1 ics ICS_AUTO{
    
    if( USART1_SRbits.RXNE == 1 ){
        ucTempByteUART = USART1_DR;
        if( ucTempByteUART == '\n' ){
            pcRxUARTBuffer[ usUARTMessageLength++ ] = ucTempByteUART;
            UART1_DataReady = 1;
            ucTempByteUART = 0;
        }else{
                pcRxUARTBuffer[ usUARTMessageLength++ ] = ucTempByteUART;
                ucTempByteUART = 0;
            }
    }

    if( USART1_SRbits.ORE == 1 ){
        UART1_Text( "[ IRQ ] UART Overrun\r\n", NULL );
        ucTempByteUART = USART1_SR;
        ucTempByteUART = USART1_DR;
    }

}
#else

#endif
/*===========================================================================================
 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Build Functions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
=============================================================================================*/
/*================ v_UART1_Tx_Init( void ) ================
* Description:
* Parameters [in]: void
* return: void    
==========================================================*/
void v_UART1_Tx_Init( void ){

#if defined( SIMULATION_PROTEUS_ON )
    UART1_Init_Advanced( 57600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART1_PA9_10 );
#elif defined( SIMULATION_PROTEUS_OFF )
    UART1_Init_Advanced( 115200, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART1_PA9_10 );
#endif
}

/*================ v_UART1_Rx_Init( void ) ================
* Description:
* Parameters [in]: void
* return: void    
==========================================================*/
void v_UART1_Rx_Init( void ){
#ifdef STM32F401RE 
    USART1_CR1bits.RE       = 1;
    USART1_CR1bits.RXNEIE   = 1;
    NVIC_IntEnable( IVT_INT_USART1 );
#else

#endif
}

/*============= v_UART1_Write( uint8_t ucData ) ===========
* Description:
* Parameters [in]: uint8_t ucData
* return: void    
==========================================================*/
void v_UART1_Write( uint8_t ucData ){
#ifdef STM32F401RE 
    if( USART1_CR1bits.UE == 1 ){
        USART1_DR = ucData;
        while( !USART1_SRbits.TXE );
    }
#else

#endif
}

/*============ v_UART1_Write_Text( *pcBuffer ); ===========
* Description:
* Parameters [in]: uint8_t * pcBuffer
* return: void    
==========================================================*/
void v_UART1_Write_Text( uint8_t * pcBuffer ){
    uint32_t ulCounter = 0;
    uint32_t ulSize = 0;

    ulSize = strlen( pcBuffer );

#ifdef STM32F401RE 
    if( USART1_CR1bits.UE == 1 ){
        for( ulCounter = 0; ulCounter < ulSize; ulCounter++ ){
            USART1_DR = pcBuffer[ ulCounter ];
            while( !USART1_SRbits.TXE );
        }
    }
#else

#endif
}

/*================ UART1_Text( *text, a); ================
* Description:
* Parameters [in]:  const uint8_t *text
*                   uint32_t a
* return: void    
==========================================================*/
void UART1_Text( const uint8_t *text, uint32_t a){
    uint8_t ul8txt[127];
    sprintf(ul8txt, text, a );
    UART1_Write_Text( ul8txt );
}

/*================ UART1_TextF( *text, a); ================
* Description:
* Parameters [in]:  const uint8_t *text
*                   float a
* return: void    
==========================================================*/
void UART1_TextF( const uint8_t *text, float a){
    uint8_t ul8txt[127];
    sprintf(ul8txt, text, a );
    UART1_Write_Text( ul8txt );
    //PrintOut( PrintHandler, text, a);
}

/*================ UART1_TextC( *text, *a) ================
* Description:
* Parameters [in]:  const uint8_t *text
*                   uint8_t *a
* return: void    
==========================================================*/
void UART1_TextC( const uint8_t *text, uint8_t *a){
    uint8_t ul8txt[127];
    sprintf(ul8txt, text, a );
    UART1_Write_Text( ul8txt );
    //PrintOut( PrintHandler, text, a);
}

/*=============== UART1_Text2( *text, a, b) ===============
* Description:
* Parameters [in]:  uint8_t *text
*                   uint16_t a
*                   uint16_t b
* return: void    
==========================================================*/
void UART1_Text2( uint8_t *text, uint16_t a, uint16_t b){
    uint8_t ul8txt[127];
    sprintf(ul8txt, text, a, b );
    UART1_Write_Text( ul8txt );
    //PrintOut( PrintHandler, text, a, b);
}

/*=========== UART1_Text4( *text, a, b, c, d) ============
* Description: 
* Parameters [in]:  uint8_t *text
*                   uint16_t a
*                   uint16_t b
*                   uint16_t c
*                   uint16_t d
* return: void    
==========================================================*/
void UART1_Text4( uint8_t *text, uint16_t a, uint16_t b, uint16_t c, uint16_t d){
        uint8_t ul8txt[127];
    sprintf(ul8txt, text, a, b, c, d );
    UART1_Write_Text( ul8txt );
    //PrintOut( PrintHandler, text, a, b, c, d);
}



/*===========================================================================================
 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Setters and Getters <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
=============================================================================================*/

/*========== uint8_t v_UART1_Data_Ready( void ) ===========
* Description:
* Parameters [in]: void
* return: uint8_t UART1_DataReady     
==========================================================*/
uint8_t v_UART1_Data_Ready( void ){
    return UART1_DataReady;
}
/*=====================================================================================================================================
 * End file
=====================================================================================================================================*/