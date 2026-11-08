// hace parpadear LED conectado a pin 13 sin bibliotecas usando MMIO
// corresponde a pin PB5: pin 5 de registros B
const int pinLED= 5;
void setup()
{
  // definir pin 13 como salida  
  // lee registro y lo escribe actualizando solo ese pin
  DDRB |= (1 << pinLED);
}
void loop() {
  // encender LED
  // lee registro y lo escribe actualizando solo ese pin
  PORTB |= (1 << pinLED);
  delay(1000);                  // esperar un segundo
  // apagar LED
  // lee registro y lo escribe actualizando solo ese pin
  PORTB &= ~(1 << pinLED);
  delay(1000);                  // esperar un segundo
}

