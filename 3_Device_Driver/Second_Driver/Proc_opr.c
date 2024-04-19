#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define BUFFER_SIZE 1024

static char proc_buffer[BUFFER_SIZE];
static unsigned long proc_buffer_size = 0;

static ssize_t my_read(struct file *file, char __user *buf, size_t count, loff_t *offset)
{
   printk("Here I write\n");
    return count; // Return the number of bytes written
}

static ssize_t my_write(struct file *file, const char __user *buf, size_t count, loff_t *offset)
{
    copy_to_user(buf, proc_buffer + *offset, count);
    printk("Here I read\n");
    return 0; // Return 0 to indicate end of file
}

static const struct proc_ops my_fops = {
    .proc_read = my_read,
    .proc_write = my_write,
};

struct proc_dir_entry *proc_file_entry = NULL;

/* Meta Information */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MARCO");
MODULE_DESCRIPTION("A Proc_fs device driver");

static int __init mod_init(void)
{
    proc_file_entry = proc_create("First_proc", 0666, NULL, &my_fops);
    if (!proc_file_entry) {
        printk(KERN_ERR "Failed to create proc entry\n");
        return -ENOMEM;
    }
    return 0;
}

static void __exit mod_exit(void)
{
    if (proc_file_entry)
        remove_proc_entry("First_proc", NULL);
}

module_init(mod_init);
module_exit(mod_exit);