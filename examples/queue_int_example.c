#include <stdio.h>
#include "../include/ctl.h"

// Define a queue for integers
CTL_DEFINE_QUEUE_TYPE(int, int)
CTL_DEFINE_QUEUE_FUNCTIONS(int, int)

int main() {
    Queue_int* queue = Queue_int_create();

    Queue_int_enqueue(queue, 10);
    Queue_int_enqueue(queue, 20);
    Queue_int_enqueue(queue, 30);

    printf("Dequeued %d\n", Queue_int_dequeue(queue));
    printf("Dequeued %d\n", Queue_int_dequeue(queue));
    printf("Dequeued %d\n", Queue_int_dequeue(queue));

    Queue_int_destroy(queue);

    return 0;
}
