
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

#include "SystemDefinition.h"

FirmwareVersion_t Device_version;


void Load_Data_From_Device( void ){
    Device_version.Major = 1;
    Device_version.Minor = 0;
    Device_version.Build = 0;
    Device_version.Day = 12;
    Device_version.Month = 5;
    Device_version.Year = 2022;
    strcpy(Device_version.Name,"PLC");
}
/*=====================================================================================================================================
 * End file
=====================================================================================================================================*/
