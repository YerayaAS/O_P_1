/* Ejemplo de MMIO: acceso a registros del Local-APIC ID y versión
 *      https://wiki.osdev.org/APIC#Local_APIC_registers
 *      https://www.intel.la/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-vol-3a-part-1-manual.pdf
 *              Tabla 10.1 y secciones 10.4.6 y 10.4.8 */

#include <linux/init.h>
#include <linux/module.h>
#include <asm/io.h>
MODULE_LICENSE("GPL");

//#define xAPIC2 // elimine esta definición si xAPIC
#define LOCAL_APIC_BASE_ADDRESS 0xfee00000
struct lapic_info {
	uint32_t reservado[8];
	uint32_t id;
	uint32_t relleno[3];
	uint32_t version; // nº versión: 8 bits de menor peso
	// ... no usados por el programa
};
static int lAPIC_init(void) {
	int tam=4096, desp=0;
	struct lapic_info __iomem *lapic; // __iomem indica que es MMIO
#ifndef xAPIC2
        desp=24;
#endif
	// obtiene rango dir. lógicas sistema asociadas a dir. físicas dispositivo
	if ((lapic = ioremap(LOCAL_APIC_BASE_ADDRESS, tam))==NULL) {
                printk("Error en ioremap\n");
                return -1;
        }
	// en x86 puede usarse directamente la dirección MMIO
	printk("Uso directo: Local APIC ID: %d Versión %d\n", lapic->id>>desp, lapic->version&0xFF);
	// pero buenas prácticas recomiendan uso de funciones de acceso a MMIO
	printk("Uso ioread32: Local APIC ID: %d Versión %d\n", ioread32(&lapic->id)>>desp,
		ioread32(&lapic->version)&0xFF);
	iounmap(lapic);
	return 0;
} 
static void lAPIC_exit(void) {}
module_init(lAPIC_init); 
module_exit(lAPIC_exit); 
