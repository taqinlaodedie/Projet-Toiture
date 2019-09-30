#include "Sigfox.h"

Sigfox::Sigfox(Serial *at) {
	_at = at;
}

/**
  * @brief  Tester si le module sigfox est pret
  * @param  
  * @retval 1 si OK, 0 sinon
  */
bool Sigfox::ready() {
	_at->printf("AT");
	char c = _at->getc();
	if(c == 'O')
		return 1;
	else
		return 0;
}

/**
  * @brief  Envoyer les parametres recuperees par les capteurs
  * @param  Les valeurs detectees par les capteurs
  * @retval 
  */
void Sigfox::send(s16 temp_air, u16 hum_air, s16 temp_sol, u16 hum_sol, u8 lum, u8 val_r, u8 val_g, u8 val_b) {
	_at->printf("AT$SF=%04x%04x%04x%04x%02x%02x%02x%02x\r", temp_air, hum_air, temp_sol, hum_sol, lum, val_r, val_g, val_b);
}