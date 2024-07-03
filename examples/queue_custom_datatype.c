#include <stdio.h>
#include "../include/ctl.h"

typedef struct {
    int x;
    int y;
} Point;

// Define a queue for Points
CTL_DEFINE_QUEUE_TYPE(Point, Point)
CTL_DEFINE_QUEUE_FUNCTIONS(Point, Point)

int main() {
    Queue_Point* queue = Queue_Point_create();

    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 6};

    Queue_Point_enqueue(queue, p1);
    Queue_Point_enqueue(queue, p2);
    Queue_Point_enqueue(queue, p3);

    Point p = Queue_Point_dequeue(queue);
    printf("Dequeued Point(%d, %d)\n", p.x, p.y);

    p = Queue_Point_dequeue(queue);
    printf("Dequeued Point(%d, %d)\n", p.x, p.y);

    Queue_Point_destroy(queue);

    return 0;
}
