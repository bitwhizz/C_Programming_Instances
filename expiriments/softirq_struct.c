/*
Why does the function take itself as an argument?

Passing a pointer to the structure itself into the function is a classic C design pattern (often used to mimic object-oriented behavior).

Because the function receives struct softirq_action *, you can embed this structure inside a larger custom structure.
 When the function executes, it can use a macro like container_of() in Linux to look backward,
 find the larger structure wrapping it, and access other context data it needs to do its job.
*/

#include <stdio.h>
#include <stddef.h> // Gives us 'offsetof' to find the parent data

struct softirq_action {
    void (*action)(struct softirq_action *);
};

// A bigger structure that wraps around the generic slip
struct detailed_order {
    int quantity;               // Extra data
    struct softirq_action slip; // Embedded generic slip
};

void cook_multiple_burgers(struct softirq_action *slip_ptr) {
    // The trick: Look backward from the slip pointer to find the whole detailed order
    struct detailed_order *full_order = (struct detailed_order *)(
        (char *)slip_ptr - offsetof(struct detailed_order, slip)
    );

    // Now we can read the extra data!
    printf("Cooking %d burgers now!\n", full_order->quantity);
}

int main(void) {
    struct detailed_order order1;
    order1.quantity = 5;                           // We want 5 burgers
    order1.slip.action = cook_multiple_burgers;    // Assign the function

    // The execution engine (the chef) only sees the generic slip
    struct softirq_action *generic_slip = &order1.slip;

    // The chef executes it. Because the slip is passed in, 
    // the function can find the 'quantity' of 5!
    generic_slip->action(generic_slip);

    return 0;
}
