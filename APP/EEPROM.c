#include "EEPROM.h"


uint8_t read_from_eeprom(uint8_t address) 
{
    while (EECON1bits.WR || EECON1bits.RD);  // Wait until any previous write or read operation is complete
    
    EEADR = address;  // Set EEPROM address
    EECON1bits.EEPGD = 0;  // Select EEPROM memory
    EECON1bits.CFGS = 0;  // Access EEPROM memory
    EECON1bits.RD = 1;  // Start read cycle
    
    while (EECON1bits.RD);  // Wait for read operation to complete
    
    return EEDATA;  // Return data read from EEPROM
}

void write_to_eeprom(uint8_t address, uint8_t data) {
    while (EECON1bits.WR || EECON1bits.RD);  // Wait until any previous write or read operation is complete
    
    EEADR = address;  // Set EEPROM address
    EEDATA = data;  // Set data to write
    EECON1bits.EEPGD = 0;  // Select EEPROM memory
    EECON1bits.CFGS = 0;  // Access EEPROM memory
    EECON1bits.WREN = 1;  // Enable write to EEPROM
    
    // Required sequence to initiate write
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;  // Start write cycle
    
    while (EECON1bits.WR);  // Wait for write operation to complete
    EECON1bits.WREN = 0;  // Disable write to EEPROM
}
