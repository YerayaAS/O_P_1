// obtiene fabricante y modelo dispo. de dispositivo ubicado en
// bus 0, ranura 0 y función 0 de un bus PCI; http://wiki.osdev.org/PCI
#include <sys/io.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CONF_DIR 0xCF8
/* en CONF_DIR se especifica dir. a leer/escribir: bus|ranura|func|registro con el formato:
|    31    |(30-24) |(23-16)|(15-11)  |(10-8)     |(7-2)      |(1-0)| 
|Enable Bit|Reserved|BusNum |DeviceNum|FunctionNum|RegisterNum| 0 0 |    */

#define CONF_DAT 0xCFC
// Si se lee de CONF_DAT se obtiene contenido de registro especificado en CONF_DIR
// Si se escribe en CONF_DAT se modifica contenido de registro especificado en CONF_DIR

int main(int argc, char *argv[]) {
    if (ioperm(CONF_DIR, 8, 1) < 0) { // permiso para acceso a los 2 puertos modo usuario
        perror("ioperm"); return 1;
    }
    uint32_t dir, dat; uint16_t vend, prod;

    /* el formato es

    |    31    |(30-24) |(23-16)|(15-11)  |(10-8)     |(7-2)      |(1-0)|
    |Enable Bit|Reserved|BusNum |DeviceNum|FunctionNum|RegisterNum| 0 0 |

    Al ser bus 0, ranura 0, función 0 y registro 0 basta con especificar el "enable" bit
   */
    dir = (uint32_t) 0x80000000;

    outl (dir, CONF_DIR); dat = inl(CONF_DAT);

    if (dat == 0xFFFFFFFF) {
        fprintf(stderr, "no existe ese dispositivo\n"); return 1; }

    vend = dat & 0x0000FFFF; prod = dat >> 16; // extrae vendedor y producto

    printf("Bus 0 Slot 0 Function 0: Vendor ID %x Device ID %x\n", vend, prod);
    return 0;
} 
