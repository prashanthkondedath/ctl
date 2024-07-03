/*
MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Author: Prashanth Kondedath
*/

#ifndef CTL_H
#define CTL_H

#include <stdlib.h>
#include <string.h>

// Macro to define a default return value for complex types
#define CTL_DEFAULT_RETURN(type) (type) {0}

// Macro to define a new queue type and its functions
#define CTL_DEFINE_QUEUE_TYPE(type, name) \
    typedef struct QueueNode_##name { \
        type data; \
        struct QueueNode_##name* next; \
    } QueueNode_##name; \
    \
    typedef struct { \
        QueueNode_##name* front; \
        QueueNode_##name* back; \
    } Queue_##name; \
    \
    Queue_##name* Queue_##name##_create(); \
    void Queue_##name##_destroy(Queue_##name* queue); \
    void Queue_##name##_enqueue(Queue_##name* queue, type value); \
    type Queue_##name##_dequeue(Queue_##name* queue); \
    type Queue_##name##_peek(Queue_##name* queue); \
    int Queue_##name##_is_empty(Queue_##name* queue);

// Macro to define functions for a queue type
#define CTL_DEFINE_QUEUE_FUNCTIONS(type, name) \
    Queue_##name* Queue_##name##_create() { \
        Queue_##name* queue = (Queue_##name*)malloc(sizeof(Queue_##name)); \
        queue->front = NULL; \
        queue->back = NULL; \
        return queue; \
    } \
    \
    void Queue_##name##_destroy(Queue_##name* queue) { \
        QueueNode_##name* current = queue->front; \
        QueueNode_##name* next; \
        while (current != NULL) { \
            next = current->next; \
            free(current); \
            current = next; \
        } \
        free(queue); \
    } \
    \
    void Queue_##name##_enqueue(Queue_##name* queue, type value) { \
        QueueNode_##name* new_node = (QueueNode_##name*)malloc(sizeof(QueueNode_##name)); \
        new_node->data = value; \
        new_node->next = NULL; \
        if (queue->back == NULL) { \
            queue->front = new_node; \
            queue->back = new_node; \
        } else { \
            queue->back->next = new_node; \
            queue->back = new_node; \
        } \
    } \
    \
    type Queue_##name##_dequeue(Queue_##name* queue) { \
        if (queue->front != NULL) { \
            QueueNode_##name* old_front = queue->front; \
            type value = old_front->data; \
            queue->front = old_front->next; \
            if (queue->front == NULL) { \
                queue->back = NULL; \
            } \
            free(old_front); \
            return value; \
        } \
        return CTL_DEFAULT_RETURN(type); /* Add error handling as needed */ \
    } \
    \
    type Queue_##name##_peek(Queue_##name* queue) { \
        if (queue->front != NULL) { \
            return queue->front->data; \
        } \
        return CTL_DEFAULT_RETURN(type); /* Add error handling as needed */ \
    } \
    \
    int Queue_##name##_is_empty(Queue_##name* queue) { \
        return queue->front == NULL; \
    }

// Macro to define a new stack type and its functions
#define CTL_DEFINE_STACK_TYPE(type, name) \
    typedef struct StackNode_##name { \
        type data; \
        struct StackNode_##name* next; \
    } StackNode_##name; \
    \
    typedef struct { \
        StackNode_##name* top; \
    } Stack_##name; \
    \
    Stack_##name* Stack_##name##_create(); \
    void Stack_##name##_destroy(Stack_##name* stack); \
    void Stack_##name##_push(Stack_##name* stack, type value); \
    type Stack_##name##_pop(Stack_##name* stack); \
    type Stack_##name##_peek(Stack_##name* stack); \
    int Stack_##name##_is_empty(Stack_##name* stack);

// Macro to define functions for a stack type
#define CTL_DEFINE_STACK_FUNCTIONS(type, name) \
    Stack_##name* Stack_##name##_create() { \
        Stack_##name* stack = (Stack_##name*)malloc(sizeof(Stack_##name)); \
        stack->top = NULL; \
        return stack; \
    } \
    \
    void Stack_##name##_destroy(Stack_##name* stack) { \
        StackNode_##name* current = stack->top; \
        StackNode_##name* next; \
        while (current != NULL) { \
            next = current->next; \
            free(current); \
            current = next; \
        } \
        free(stack); \
    } \
    \
    void Stack_##name##_push(Stack_##name* stack, type value) { \
        StackNode_##name* new_node = (StackNode_##name*)malloc(sizeof(StackNode_##name)); \
        new_node->data = value; \
        new_node->next = stack->top; \
        stack->top = new_node; \
    } \
    \
    type Stack_##name##_pop(Stack_##name* stack) { \
        if (stack->top != NULL) { \
            StackNode_##name* old_top = stack->top; \
            type value = old_top->data; \
            stack->top = old_top->next; \
            free(old_top); \
            return value; \
        } \
        return CTL_DEFAULT_RETURN(type); /* Add error handling as needed */ \
    } \
    \
    type Stack_##name##_peek(Stack_##name* stack) { \
        if (stack->top != NULL) { \
            return stack->top->data; \
        } \
        return CTL_DEFAULT_RETURN(type); /* Add error handling as needed */ \
    } \
    \
    int Stack_##name##_is_empty(Stack_##name* stack) { \
        return stack->top == NULL; \
    }

// Macro to define a new priority queue type and its functions
#define CTL_DEFINE_PRIORITY_QUEUE_TYPE(type, name, compare) \
    typedef struct { \
        type* data; \
        size_t size; \
        size_t capacity; \
        int (*compare)(type, type); \
    } PriorityQueue_##name; \
    \
    PriorityQueue_##name* PriorityQueue_##name##_create(size_t initial_capacity, int (*compare)(type, type)); \
    void PriorityQueue_##name##_destroy(PriorityQueue_##name* pq); \
    void PriorityQueue_##name##_enqueue(PriorityQueue_##name* pq, type value); \
    type PriorityQueue_##name##_dequeue(PriorityQueue_##name* pq); \
    type PriorityQueue_##name##_peek(PriorityQueue_##name* pq); \
    int PriorityQueue_##name##_is_empty(PriorityQueue_##name* pq);

// Macro to define functions for a priority queue type
#define CTL_DEFINE_PRIORITY_QUEUE_FUNCTIONS(type, name, compare) \
    static void PriorityQueue_##name##_heapify_up(PriorityQueue_##name* pq, size_t index) { \
        if (index == 0) return; \
        size_t parent_index = (index - 1) / 2; \
        if (pq->compare(pq->data[index], pq->data[parent_index]) < 0) { \
            type temp = pq->data[index]; \
            pq->data[index] = pq->data[parent_index]; \
            pq->data[parent_index] = temp; \
            PriorityQueue_##name##_heapify_up(pq, parent_index); \
        } \
    } \
    \
    static void PriorityQueue_##name##_heapify_down(PriorityQueue_##name* pq, size_t index) { \
        size_t left_child_index = 2 * index + 1; \
        size_t right_child_index = 2 * index + 2; \
        size_t smallest = index; \
        if (left_child_index < pq->size && pq->compare(pq->data[left_child_index], pq->data[smallest]) < 0) { \
            smallest = left_child_index; \
        } \
        if (right_child_index < pq->size && pq->compare(pq->data[right_child_index], pq->data[smallest]) < 0) { \
            smallest = right_child_index; \
        } \
        if (smallest != index) { \
            type temp = pq->data[index]; \
            pq->data[index] = pq->data[smallest]; \
            pq->data[smallest] = temp; \
            PriorityQueue_##name##_heapify_down(pq, smallest); \
        } \
    } \
    \
    PriorityQueue_##name* PriorityQueue_##name##_create(size_t initial_capacity, int (*compare)(type, type)) { \
        PriorityQueue_##name* pq = (PriorityQueue_##name*)malloc(sizeof(PriorityQueue_##name)); \
        pq->data = (type*)malloc(initial_capacity * sizeof(type)); \
        pq->size = 0; \
        pq->capacity = initial_capacity; \
        pq->compare = compare; \
        return pq; \
    } \
    \
    void PriorityQueue_##name##_destroy(PriorityQueue_##name* pq) { \
        free(pq->data); \
        free(pq); \
    } \
    \
    void PriorityQueue_##name##_enqueue(PriorityQueue_##name* pq, type value) { \
        if (pq->size == pq->capacity) { \
            pq->capacity *= 2; \
            pq->data = (type*)realloc(pq->data, pq->capacity * sizeof(type)); \
        } \
        pq->data[pq->size++] = value; \
        PriorityQueue_##name##_heapify_up(pq, pq->size - 1); \
    } \
    \
    type PriorityQueue_##name##_dequeue(PriorityQueue_##name* pq) { \
        if (pq->size == 0) { \
            return CTL_DEFAULT_RETURN(type); /* Add error handling as needed */ \
        } \
        type value = pq->data[0]; \
        pq->data[0] = pq->data[--pq->size]; \
        PriorityQueue_##name##_heapify_down(pq, 0); \
        return value; \
    } \
    \
    type PriorityQueue_##name##_peek(PriorityQueue_##name* pq) { \
        if (pq->size == 0) { \
            return CTL_DEFAULT_RETURN(type); /* Add error handling as needed */ \
        } \
        return pq->data[0]; \
    } \
    \
    int PriorityQueue_##name##_is_empty(PriorityQueue_##name* pq) { \
        return pq->size == 0; \
    }

#endif // CTL_H
