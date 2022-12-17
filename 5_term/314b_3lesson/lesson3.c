#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Robert W. Oliver II");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

static int __init lkm_example_init(void) {
 printk(KERN_INFO "Hello, World!\n");
 return 0;
}

static void __exit lkm_example_exit(void) {
 printk(KERN_INFO "Goodbye, World!\n");
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);

int init_module(void)
{
 Major = register_chrdev(0, DEVICE_NAME, &fops);
 if (Major < 0) {
  printk(KERN_ALERT "Registering char device failed with %d\n", Major);
 return Major;
}
printk(KERN_INFO "I was assigned major number %d. To talk to\n", Major);
printk(KERN_INFO "the driver, create a dev file with\n");
printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, Major)
return 0;
}

static int device_open(struct inode *inode, struct file *file){
static int counter = 0;
if (Device_Open)
return -EBUSY;
Device_Open++;
sprintf(msg, "I already told you %d times Hello world!\n", counter++);
msg_Ptr = msg;
try_module_get(THIS_MODULE);
return 0;

}
static int device_release(struct inode *inode, struct file *file){
Device_Open--; /* We're now ready for our next caller */
/** Decrement the usage count, or else once you opened the file, you'll
never get get rid of the module. */
module_put(THIS_MODULE);
return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, /* buffer to fill with data */
size_t length, /* length of the buffer */ loff_t * offset)
{
int bytes_read = 0; /* Number of bytes actually written to the buffer*/
/* If we're at the end of the message, * return 0 signifying end of file */
if (*msg_Ptr == 0) return 0;
/* Actually put the data into the buffer */
while (length && *msg_Ptr) {
/** The buffer is in the user data segment, not the kernel
* segment so "*" assignment won't work. We have to use
* put_user which copies data from the kernel data segment to
* the user data segment. */
put_user(*(msg_Ptr++), buffer++);
length--;
bytes_read++;
}
/* Most read functions return the number of bytes put into the buffer */
return bytes_read;
}
