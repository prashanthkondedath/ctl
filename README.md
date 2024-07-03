# CTL: C Template Library

CTL (C Template Library) is a lightweight header-only library that provides generic stack, queue, and priority queue implementations in C. The library allows you to define and use these data structures for any data type, including custom structures.

## Features

- Generic Stack
- Generic Queue
- Generic Priority Queue (Min-Heap and Max-Heap)
- Easy integration with your C projects
- Header-only library

## Getting Started

To use the CTL library, include the `ctl.h` file in your project:

```c
#include "include/ctl.h"
Usage
Stack
Stack for int
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

// Define a stack for integers
CTL_DEFINE_STACK_TYPE(int, int)
CTL_DEFINE_STACK_FUNCTIONS(int, int)

int main() {
    Stack_int* stack = Stack_int_create();

    Stack_int_push(stack, 10);
    Stack_int_push(stack, 20);
    Stack_int_push(stack, 30);

    printf("Popped %d\n", Stack_int_pop(stack));
    printf("Popped %d\n", Stack_int_pop(stack));
    printf("Popped %d\n", Stack_int_pop(stack));

    Stack_int_destroy(stack);

    return 0;
}
Stack for Custom Data Type
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

typedef struct {
    int x;
    int y;
} Point;

// Define a stack for Points
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

    Stack_Point_destroy(stack);

    return 0;
}
Queue
Queue for int
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

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
Queue for Custom Data Type
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

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
Priority Queue
Min-Heap for int
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

// Comparator function for integers (min-heap)
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
Max-Heap for int
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

// Comparator function for integers (max-heap)
int int_compare_max(int a, int b) {
    return b - a;
}

// Define a priority queue for integers (max-heap)
CTL_DEFINE_PRIORITY_QUEUE_TYPE(int, int_max, int_compare_max)
CTL_DEFINE_PRIORITY_QUEUE_FUNCTIONS(int, int_max, int_compare_max)

int main() {
    PriorityQueue_int_max* pq = PriorityQueue_int_max_create(4, int_compare_max);

    PriorityQueue_int_max_enqueue(pq, 30);
    PriorityQueue_int_max_enqueue(pq, 10);
    PriorityQueue_int_max_enqueue(pq, 20);

    printf("Dequeued %d\n", PriorityQueue_int_max_dequeue(pq));
    printf("Dequeued %d\n", PriorityQueue_int_max_dequeue(pq));
    printf("Dequeued %d\n", PriorityQueue_int_max_dequeue(pq));

    PriorityQueue_int_max_destroy(pq);

    return 0;
}
Min-Heap for Custom Data Type
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

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
Max-Heap for Custom Data Type
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

typedef struct {
    int x;
    int y;
} Point;

// Comparator function for Points based on x value (max-heap)
int point_compare_max(Point a, Point b) {
    return b.x - a.x;
}

// Define a priority queue for Points (max-heap)
CTL_DEFINE_PRIORITY_QUEUE_TYPE(Point, Point_max, point_compare_max)
CTL_DEFINE_PRIORITY_QUEUE_FUNCTIONS(Point, Point_max, point_compare_max)

int main() {
    PriorityQueue_Point_max* pq = PriorityQueue_Point_max_create(4, point_compare_max);

    Point p1 = {3, 2};
    Point p2 = {1, 4};
    Point p3 = {5, 6};

    PriorityQueue_Point_max_enqueue(pq, p1);
    PriorityQueue_Point_max_enqueue(pq, p2);
    PriorityQueue_Point_max_enqueue(pq, p3);

    Point p = PriorityQueue_Point_max_dequeue(pq);
    printf("Dequeued Point(%d, %d)\n", p.x, p.y);

    p = PriorityQueue_Point_max_dequeue(pq);
    printf("Dequeued Point(%d, %d)\n", p.x, p.y);

    PriorityQueue_Point_max_destroy(pq);

    return 0;
}
Examples
Example usage files are included in the examples directory:

stack_int_example.c - Example of using stack with int data type.
queue_int_example.c - Example of using queue with int data type.
stack_custom_datatype.c - Example of using stack with custom data type Point.
queue_custom_datatype.c - Example of using queue with custom data type Point.
pqueue_int_example.c - Example of using priority queue with int data type (min-heap).
pqueue_int_max_example.c - Example of using priority queue with int data type (max-heap).
pqueue_custom_datatype.c - Example of using priority queue with custom data type Point (min-heap).
pqueue_custom_datatype_max.c - Example of using priority queue with custom data type
Mention that you could use in your projects or for any interviews where you dont need to implement stack, queue and priority queue from scratch since c doesnt support standard libraries
ChatGPT
Sure, here is the updated README.md with the additional information about using this library in projects and for interviews.

README.md
markdown
Copy code
# CTL: C Template Library

CTL (C Template Library) is a lightweight header-only library that provides generic stack, queue, and priority queue implementations in C. The library allows you to define and use these data structures for any data type, including custom structures.

## Features

- Generic Stack
- Generic Queue
- Generic Priority Queue (Min-Heap and Max-Heap)
- Easy integration with your C projects
- Header-only library

## Getting Started

To use the CTL library, include the `ctl.h` file in your project:

```c
#include "include/ctl.h"
Usage
Stack
Stack for int
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

// Define a stack for integers
CTL_DEFINE_STACK_TYPE(int, int)
CTL_DEFINE_STACK_FUNCTIONS(int, int)

int main() {
    Stack_int* stack = Stack_int_create();

    Stack_int_push(stack, 10);
    Stack_int_push(stack, 20);
    Stack_int_push(stack, 30);

    printf("Popped %d\n", Stack_int_pop(stack));
    printf("Popped %d\n", Stack_int_pop(stack));
    printf("Popped %d\n", Stack_int_pop(stack));

    Stack_int_destroy(stack);

    return 0;
}
Stack for Custom Data Type
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

typedef struct {
    int x;
    int y;
} Point;

// Define a stack for Points
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

    Stack_Point_destroy(stack);

    return 0;
}
Queue
Queue for int
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

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
Queue for Custom Data Type
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

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
Priority Queue
Min-Heap for int
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

// Comparator function for integers (min-heap)
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
Max-Heap for int
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

// Comparator function for integers (max-heap)
int int_compare_max(int a, int b) {
    return b - a;
}

// Define a priority queue for integers (max-heap)
CTL_DEFINE_PRIORITY_QUEUE_TYPE(int, int_max, int_compare_max)
CTL_DEFINE_PRIORITY_QUEUE_FUNCTIONS(int, int_max, int_compare_max)

int main() {
    PriorityQueue_int_max* pq = PriorityQueue_int_max_create(4, int_compare_max);

    PriorityQueue_int_max_enqueue(pq, 30);
    PriorityQueue_int_max_enqueue(pq, 10);
    PriorityQueue_int_max_enqueue(pq, 20);

    printf("Dequeued %d\n", PriorityQueue_int_max_dequeue(pq));
    printf("Dequeued %d\n", PriorityQueue_int_max_dequeue(pq));
    printf("Dequeued %d\n", PriorityQueue_int_max_dequeue(pq));

    PriorityQueue_int_max_destroy(pq);

    return 0;
}
Min-Heap for Custom Data Type
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

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
Max-Heap for Custom Data Type
c
Copy code
#include <stdio.h>
#include "include/ctl.h"

typedef struct {
    int x;
    int y;
} Point;

// Comparator function for Points based on x value (max-heap)
int point_compare_max(Point a, Point b) {
    return b.x - a.x;
}

// Define a priority queue for Points (max-heap)
CTL_DEFINE_PRIORITY_QUEUE_TYPE(Point, Point_max, point_compare_max)
CTL_DEFINE_PRIORITY_QUEUE_FUNCTIONS(Point, Point_max, point_compare_max)

int main() {
    PriorityQueue_Point_max* pq = PriorityQueue_Point_max_create(4, point_compare_max);

    Point p1 = {3, 2};
    Point p2 = {1, 4};
    Point p3 = {5, 6};

    PriorityQueue_Point_max_enqueue(pq, p1);
    PriorityQueue_Point_max_enqueue(pq, p2);
    PriorityQueue_Point_max_enqueue(pq, p3);

    Point p = PriorityQueue_Point_max_dequeue(pq);
    printf("Dequeued Point(%d, %d)\n", p.x, p.y);

    p = PriorityQueue_Point_max_dequeue(pq);
    printf("Dequeued Point(%d, %d)\n", p.x, p.y);

    PriorityQueue_Point_max_destroy(pq);

    return 0;
}
Examples
Example usage files are included in the examples directory:

stack_int_example.c - Example of using stack with int data type.
queue_int_example.c - Example of using queue with int data type.
stack_custom_datatype.c - Example of using stack with custom data type Point.
queue_custom_datatype.c - Example of using queue with custom data type Point.
pqueue_int_example.c - Example of using priority queue with int data type (min-heap).
pqueue_int_max_example.c - Example of using priority queue with int data type (max-heap).
pqueue_custom_datatype.c - Example of using priority queue with custom data type Point (min-heap).
pqueue_custom_datatype_max.c - Example of using priority queue with custom data type Point (max-heap).
Integration
You can use CTL in your projects or for any interviews where you don't need to implement stack, queue, and priority queue from scratch since C doesn't support these standard libraries out of the box.

Simply include the ctl.h file and use the provided macros to define and create the desired data structures for your specific data types.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Author
Prashanth Kondedath

