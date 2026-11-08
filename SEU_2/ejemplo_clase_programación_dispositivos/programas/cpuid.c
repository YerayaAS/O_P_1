 // Obtiene el nombre del fabricante del procesador mediante intrucción CPUID
#include <sys/uio.h>
#include <stdio.h>
#define tam_trozo 4

int main(int argc, char *argv[]) {
    int op=0; // tipo de operación
    char nombre_tr1[tam_trozo], nombre_tr2[tam_trozo], nombre_tr3[tam_trozo];
    /* Instrucción CPUID:
     *     - entrada EAX: tipo de información solicitada
     *     - salida EAX,EBX,ECX,EDX: información retornada
     *
     * Ejemplo de uso:
     *     - entrada EAX = 0
     *     - salida EBX, EDX, ECX: nombre del fabricante
     */
    asm ("cpuid"
        // salida: EBX a nombre_tr1; ECX a nombre_tr3; EDX a nombre_tr2
            : "=b" (nombre_tr1), "=c" (nombre_tr3), "=d" (nombre_tr2)
        // entrada: EAX tipo de información solicitada (nombre fabricante)
        : "a" (op) );

    printf("%.*s%.*s%.*s\n", tam_trozo, nombre_tr1, tam_trozo, nombre_tr2,
		    tam_trozo, nombre_tr3);
    return 0;
}
