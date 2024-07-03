#include <stdio.h>
#include "../include/ctl.h"

// Comparator function for integers (min-heap)
// For a max heap, you can modify the comparator function to reverse the comparison.
// int int_compare(int a, int b) {
//    return a - b;
// }
//

int int_compare(int a, int b) {
    return a - b;
}

// Define a priority queue for integers
CTL_DEFINE_PRIORITY_QUEUE_TYPE(int, int, int_compare)
CTL_DEFINE_PRIORITY_QUEUE_FUNCTIONS(int, int, int_compare)

int main() {
    PriorityQueue_int* pq = PriorityQueue_int_create(4, int_compare);

    PriorityQueue_int_enqueue(pq, 30);
    PriorityQueue_int_enqueue(pq, 10);
    PriorityQueue_int_enqueue(pq, 20);

    printf("Dequeued %d\n", PriorityQueue_int_dequeue(pq));
    printf("Dequeued %d\n", PriorityQueue_int_dequeue(pq));
    printf("Dequeued %d\n", PriorityQueue_int_dequeue(pq));

    PriorityQueue_int_destroy(pq);

    return 0;
}
