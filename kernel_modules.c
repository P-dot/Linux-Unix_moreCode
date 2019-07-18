#include <linux/init.h>
#include <linux/module.h>

static int hello_init(void){
	printk(KERN_ALERT "TEST: Hello world, Polymath is already in the kernel\n");



	return 0;
}

static void hello_exit(void){
	 printk(KERN_ALERT "Test: Good byte, from Polymath");
}

module_init(hello_init);
module_exit(hello_exit);