#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
static int major;
static ssize_t my_read(struct file *f, char __user *u, size_t l, loff_t *o){
     printk("Read is called\n");
     return 0;
}
static struct file_operations fops = {
    .read = my_read
};
static int __init hello_init(void) {
    major = register_chrdev(0,"hello_cdev",&fops);
    if(major < 0){
        printk(KERN_INFO "hello_cdev, Error registering character\n");
        return major;
    }
    printk("hello_cdev, Major device number %d\n",major);
    return 0;
}

static void __exit hello_exit(void) {
    unregister_chrdev(major,"hello_cdev");
    printk(KERN_INFO "Goodbye, kernel!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Duy Nguyen");
MODULE_DESCRIPTION("A sample driver for registering a character device");
