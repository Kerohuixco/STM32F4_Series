/*=====================================================================================================================================
 * Begin of header
=====================================================================================================================================*/
#ifndef __SYSTEMDEFINITION_H__
#define __SYSTEMDEFINITION_H__
/*=====================================================================================================================================*/

/*===========================================================================================
 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Definitions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
=============================================================================================*/

#define STM32F401RE

#define SIMULATION_PROTEUS_ON
//#define SIMULATION_PROTEUS_OFF

#define RELE_1      GPIOA_ODR._GPIO_PIN_14
#define RELE_2      GPIOA_ODR._GPIO_PIN_15
#define RELE_3      GPIOB_ODR._GPIO_PIN_0
#define RELE_4      GPIOB_ODR._GPIO_PIN_1
#define RELE_5      GPIOB_ODR._GPIO_PIN_2
#define RELE_6      GPIOB_ODR._GPIO_PIN_3
#define RELE_7      GPIOB_ODR._GPIO_PIN_4
#define RELE_8      GPIOB_ODR._GPIO_PIN_5

#define OPTO_1      GPIOB_IDR._GPIO_PIN_12
#define OPTO_2      GPIOB_IDR._GPIO_PIN_13
#define OPTO_3      GPIOB_IDR._GPIO_PIN_14
#define OPTO_4      GPIOB_IDR._GPIO_PIN_15
#define OPTO_5      GPIOC_IDR._GPIO_PIN_0
#define OPTO_6      GPIOC_IDR._GPIO_PIN_1
#define OPTO_7      GPIOC_IDR._GPIO_PIN_2
#define OPTO_8      GPIOC_IDR._GPIO_PIN_3

#define NULL ( ( void * )0 )



/*===========================================================================================
 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Definitions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
=============================================================================================*/
typedef struct{
    uint8_t Major;  ///<MAJOR version when you make incompatible API changes
    uint8_t Minor;  ///<MINOR version when you add functionality in a backwards compatible manner
    uint8_t Build;  ///<PATCH version when you make backwards compatible bug fixes
    uint8_t Day;
    uint8_t Month;
    uint16_t Year;
    uint8_t Name[15];
} FirmwareVersion_t; ///< Semantic Version Fields


void Load_Data_From_Device( void );

/*=====================================================================================================================================*/
#endif
/*=====================================================================================================================================
 * End header
=====================================================================================================================================*/
