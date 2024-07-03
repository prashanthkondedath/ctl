# CTL: C Template Library

CTL (C Template Library) is a lightweight header-only library that provides generic stack, queue, and priority queue implementations in C. 
The library allows you to define and use these data structures for any data type, including custom structures.

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


