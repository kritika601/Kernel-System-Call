#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ansh");
MODULE_DESCRIPTION("my_kernel_module");
MODULE_VERSION("1.0");

int counter(void){
    int count=0;
    struct task_struct *task;
    for_each_process(task){
        count+=1;
    }
    return count;
}

static int __init initfunc(void) {
    int val;
    printk(KERN_INFO "MODULE IS LOADED\n");
    val=counter();
    printk(KERN_INFO "Number of Running Processes: %d\n", val);
    return 0;
}

static void __exit exitfunc(void) {
    printk(KERN_INFO "MODULE IS UNLOADED\n");
}

module_init(initfunc);
module_exit(exitfunc);

