#include <stdio.h>
#include "../include/ctl.h"

typedef struct {
    int x;
    int y;
} Point;

// Comparator function for Points based on x value (min-heap)
int point_compare(Point a, Point b) {
    return a.x - b.x;
}

// Define a priority queue for Points
CTL_DEFINE_PRIORITY_QUEUE_TYPE(Point, Point, point_compare)
CTL_DEFINE_PRIORITY_QUEUE_FUNCTIONS(Point, Point, point_compare)

int main() {
    PriorityQueue_Point* pq = PriorityQueue_Point_create(4, point_compare);

    Point p1 = {3, 2};
    Point p2 = {1, 4};
    Point p3 = {5, 6};

    PriorityQueue_Point_enqueue(pq, p1);
    PriorityQueue_Point_enqueue(pq, p2);
    PriorityQueue_Point_enqueue(pq, p3);

    Point p = PriorityQueue_Point_dequeue(pq);
    printf("Dequeued Point(%d, %d)\n", p.x, p.y);

    p = PriorityQueue_Point_dequeue(pq);
    printf("Dequeued Point(%d, %d)\n", p.x, p.y);

    PriorityQueue_Point_destroy(pq);

    return 0;
}
