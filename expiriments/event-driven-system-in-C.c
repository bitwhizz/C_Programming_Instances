/*
In C, event-driven programming is a paradigm where the flow of the program is determined by external events—such as user inputs, sensor data, network packets, or hardware interrupts—rather than a pre-defined, sequential execution of code.

Instead of actively waiting (polling) for something to happen, an event-driven program sits in a blocked state until an event occurs, at which point it triggers a specific function called a callback.

An event-driven system in C typically relies on three main components:

    The Event Queue: A buffer that collects incoming events from the operating system or hardware.

    The Event Loop: A continuous loop that monitors the queue, fetches events as they arrive, and dispatches them.

    Callbacks (Event Handlers): Functions registered by the programmer that execute in response to specific events.

+-------------+     Event     +------------+     Dispatch     +-------------------+
| Event Source| ------------> | Event Loop | ---------------> | Callback Function |
+-------------+               +------------+                  +-------------------+

*/


#include <stdio.h>
#include <stdbool.h>

// 1. Define the types of events
typedef enum {
    EVENT_KEY_PRESS,
    EVENT_MOUSE_CLICK,
    EVENT_QUIT
} EventType;

// 2. Define the Callback function signature
typedef void (*EventHandler)(void);

// 3. Application Callback Functions
void onKeyPress(void) {
    printf("Key press detected! Processing input...\n");
}

void onMouseClick(void) {
    printf("Mouse click detected! Updating UI...\n");
}

// 4. The Event Loop Engine
void runEventLoop(EventHandler key_cb, EventHandler mouse_cb) {
    bool running = true;
    EventType current_event;

    printf("Event loop started. Simulated inputs...\n");

    // Simulated event queue/stream
    EventType simulated_events[] = {EVENT_KEY_PRESS, EVENT_MOUSE_CLICK, EVENT_QUIT};
    int event_index = 0;

    while (running) {
        // Fetch next event
        current_event = simulated_events[event_index++];

        // Dispatch based on event type
        switch (current_event) {
            case EVENT_KEY_PRESS:
                if (key_cb) key_cb(); // Trigger callback
                break;
            case EVENT_MOUSE_CLICK:
                if (mouse_cb) mouse_cb(); // Trigger callback
                break;
            case EVENT_QUIT:
                printf("Quit event received. Exiting loop.\n");
                running = false;
                break;
        }
    }
}

int main(void) {
    // Register the callbacks and run the loop
    runEventLoop(onKeyPress, onMouseClick);
    return 0;
}
