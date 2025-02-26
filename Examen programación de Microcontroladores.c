// Configuración de fuses para PIC16F877A
#pragma config FOSC = HS     // Oscilador de alta velocidad con cristal externo
#pragma config WDTE = OFF    // Desactivar el Watchdog Timer
#pragma config PWRTE = OFF   // Desactivar el Power-up Timer
#pragma config BOREN = OFF   // Desactivar Brown-out Reset
#pragma config LVP = OFF     // Desactivar Low Voltage Programming
#pragma config CPD = OFF     // Desactivar protección de datos EEPROM
#pragma config WRT = OFF     // Desactivar protección de escritura en memoria de programa
#pragma config CP = OFF      // Desactivar protección del código

#include <xc.h>   // Librería para el PIC
#define _XTAL_FREQ 20000000  // Definir la frecuencia del oscilador (20MHz)

void main() {
    // Configuración de pines como salida
    TRISA = 0x00; // RA0 y RA1 como salida (puerto A)
    TRISB = 0x00; // RB0 como salida (puerto B)
    TRISC = 0x00; // RC0 como salida (puerto C)

    // Apaga todos los LEDs inicialmente
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;

    // Bucle principal
    while (1) {
        // Enciende todos los LEDs al mismo tiempo
        PORTA = 0x03;  // Enciende RA0 y RA1
        PORTB = 0x01;  // Enciende RB0
        PORTC = 0x01;  // Enciende RC0
        __delay_ms(500);  // Espera 500 ms

        // Apaga todos los LEDs al mismo tiempo
        PORTA = 0x00;  // Apaga RA0 y RA1
        PORTB = 0x00;  // Apaga RB0
        PORTC = 0x00;  // Apaga RC0
        __delay_ms(500);  // Espera 500 ms
    }
}