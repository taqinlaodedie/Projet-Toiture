#include "mbed.h"
#include "Sigfox.h"

DigitalOut myled(LED1);
Serial at(D1, D0);
Sigfox sigfox(&at);

int main() {
	wait(2);
	sigfox.send(258, 852, 106, 902, 154, 255, 255, 255);
    while(1) {
        myled = 1; // LED is ON
        wait(2.0); // 200 ms
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
    }
}