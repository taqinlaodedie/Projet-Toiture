#ifndef SIGFOX_H
#define SIGFOX_H

#include "mbed.h"

typedef uint8_t 	u8;
typedef uint16_t 	u16;
typedef int16_t 	s16;

class Sigfox: public Serial{
	public:
		Sigfox(PinName tx, PinName rx);
	
		/**
		* @brief  Tester si le module sigfox est pret
		* @param  
		* @retval 1 si OK, 0 sinon
		*/
		bool ready();
	
		/**
		* @brief  Envoyer les parametres recuperees par les capteurs
		* @param  Les valeurs detectees par les capteurs
		* @retval 
		*/
		void send(s16 temp_air, u16 hum_air, s16 temp_sol, u16 hum_sol, u8 lum, u8 val_r, u8 val_g, u8 val_b);
};

#endif