#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/list.h>
#include <linux/slab.h>

struct birthday{
    int day;
    int month;
    int year;
    struct list_head list;
};

struct birthday *tmp;
struct list_head *pos, *q;
struct birthday mylist;

/* This function is called when the module is loaded. */
int simple_init(void){
    int i, d=13, m=1, y=1997;

    /* LIST_HEAD(mylist) */
    INIT_LIST_HEAD(&mylist.list);
    
    printk(KERN_INFO "Loading Module\n");
    printk(KERN_INFO "Initializing list..\n");
    /* adding elements to mylist */
    for(i=0; i<5; i++){
        tmp = (struct birthday *)kmalloc(sizeof(struct birthday), GFP_KERNEL);
        tmp->day = d++;
        tmp->month = m++;
        tmp->year = y++;
        list_add_tail(&tmp->list, &mylist.list);      
    }
    printk(KERN_INFO "List Initialized.\n");

    /* traversing list */
    i = 1;
    printk(KERN_INFO "Traversing list..\n");
    list_for_each(pos, &mylist.list){
        tmp = list_entry(pos, struct birthday, list);
        printk(KERN_INFO "Birthday: %d\n", i++);
        printk(KERN_INFO "%d/%d/%d\n", tmp->day, tmp->month, tmp->year);
    }
    printk(KERN_INFO "List Traversed. Total elements:%d\n\n", --i);

    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Deleting Birthday List.\n");
    list_for_each_safe(pos, q, &mylist.list){
        tmp = list_entry(pos, struct birthday, list);
        printk(KERN_INFO "Element Deleted.\n");
        list_del(pos);
        kfree(tmp);
    }
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

