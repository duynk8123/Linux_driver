#include <linux/init.h>
#include <linux/module.h>

static int __init hello_init(void) {
    printk(KERN_INFO "Log level, This is an info!\n"); 
    printk(KERN_WARNING "Log level, This is an warning!\n"); 
    printk(KERN_ALERT "Log level, This is an alert!\n"); 
    
    return 0;
}

static void __exit hello_exit(void) {
    pr_emerg("log level,Module is unloaded: \n");
    pr_err("log level, Error\n");
    pr_info("log level - the last info, ... \n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Duy Nguyen");
MODULE_DESCRIPTION("A simple hello world module");
