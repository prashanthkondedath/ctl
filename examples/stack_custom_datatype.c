#include <stdio.h>
#include "../include/ctl.h"

// Custom Datatype
typedef struct {
    int x;
    int y;
} Point;

CTL_DEFINE_STACK_TYPE(Point, Point)
CTL_DEFINE_STACK_FUNCTIONS(Point, Point)

int main() {
    Stack_Point* stack = Stack_Point_create();

    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 6};

    Stack_Point_push(stack, p1);
    Stack_Point_push(stack, p2);
    Stack_Point_push(stack, p3);

    Point p = Stack_Point_pop(stack);
    printf("Popped Point(%d, %d)\n", p.x, p.y);

    p = Stack_Point_pop(stack);
    printf("Popped Point(%d, %d)\n", p.x, p.y);
    
    p = Stack_Point_pop(stack);
    printf("Popped Point(%d, %d)\n", p.x, p.y);

    Stack_Point_destroy(stack);

    return 0;
}
