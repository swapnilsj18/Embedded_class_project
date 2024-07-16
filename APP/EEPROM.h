/* 
 * File:   EEPROM.h
 * Author: Dell
 *
 * Created on June 20, 2024, 3:37 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#include "../projectsdefines.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
    uint8_t read_from_eeprom(uint8_t address);
    void write_to_eeprom(uint8_t address, uint8_t data);




#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

