# MCP23017_Driver
Simple MCP23017 GPIO Expander Driver

Files of Interest:

MCP23017.h: Device specific header file - Shouldn't need modification
MCP23017.c: Device specific source file - Shouldn't need modification
MCP23017_Hardware.h: Hardware specific header file - Should not need modification beyond the exported low level driver
MCP23017_Hardware.c: Hardware specific source file - User must implement this file for their board/project needs

To Use:

0. Include MCP23017.h
1. Create an MCP23017_Init_Struct_t with desired user settings.
2. Create an MCP23017_IO_Drv_t with necessary low level IO functions (I2C/SPI, GPIO Communication functions).
3. Create a MCP23017_Handle_t
4. Pass the init struct, IO Driver, and device handle to MCP23017_Init()
5. Functions listed in MCP23017.h can now be used by passing the initialized device handle as a function arguement
Above example was implemented on an STM32F4 processor (STM32 BlackPill WeAct)

Logging functions may be removed and replaced with user code.
