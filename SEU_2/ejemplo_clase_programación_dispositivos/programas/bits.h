// devuelven el resultado de la operación pero sin modificar el dato
#define bit_es_igual_uno(dato, nbit) (dato & (1<<nbit))
#define bit_es_igual_cero(dato, nbit) (~dato & (1<<nbit))
#define bit_fija_a_uno(dato, nbit) (dato | (1<<nbit))
#define bit_fija_a_cero(dato, nbit) (dato & ~(1<<nbit))
#define bit_invierte_bit(dato, nbit) (dato ^ (1<<nbit))
#define bits_extrae(dato, nbit, tam_bits) ((dato>>nbit) & ((1<<tam_bits)-1))
#define bits_inserta(dato, nbit, tam_bits, inserto) ((dato & ~(((1<<tam_bits)-1) << nbit)) | ((inserto & ((1<<tam_bits)-1)) << nbit)) 

// modifican el dato y devuelven el resultado de la modificación
#define bit_fija_a_uno_insitu(dato, nbit) (dato |= (1<<nbit))
#define bit_fija_a_cero_insitu(dato, nbit) (dato &= ~(1<<nbit))
#define bit_invierte_bit_insitu(dato, nbit) (dato ^= (1<<nbit))
#define bits_inserta_insitu(dato, nbit, tam_bits, inserto) (dato = ((dato & ~(((1<<tam_bits)-1) << nbit)) | ((inserto & ((1<<tam_bits)-1)) << nbit)))
