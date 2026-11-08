#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_AUTHOR("Fernando Pérez Costoya");
MODULE_DESCRIPTION("Módulo mínimo");
MODULE_LICENSE("GPL");

MODULE_PARM_DESC(entero, "UN ENTERO");
static int entero = 666;
// parámetro accesible en sysfs: root puede leerlo y modificarlo
module_param(entero, int, S_IRUSR|S_IWUSR);

static int __init mod_init(void) {
	printk("Inicio de mod: parámetro %d\n", entero);
	return 0;
}
static void __exit mod_exit(void) {
	printk("Fin de mod\n");
}
module_init(mod_init); // función de entrada del módulo
module_exit(mod_exit); // función de salida del módulo
