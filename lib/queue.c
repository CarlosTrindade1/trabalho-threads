#include <stdlib.h>
#include <queue.h>

/*
  This   file    contains   a    function   definitions    for   queue
  manipulation. You  are free to  choose your own  implementation. You
  may need to define additional functions if you want to implement the
  extra-point functionality.
*/

/*
  @params: queue_t* queue: it's a pointer to the queue
  @description: This function initializes a queue
  @return: void
*/
void queue_init(queue_t** queue) {
  *queue = (queue_t*)malloc(sizeof(queue_t));

  // Check if it was possible to alloc memory
  if (*queue == NULL) {
    exit(EXIT_FAILURE);
  }

  (*queue)->first = NULL;
  (*queue)->size = 0;
}

/*
  @params: queue_t* queue: it's a pointer to the queue
  @description: This function returns the first element in the queue
  @return: node_t* first node: it returns the first node in the queue
*/
node_t* dequeue(queue_t* queue) {
  // The queue is empty
  if (queue->first == NULL) return NULL;

  node_t* first_node = queue->first;

  queue->first = first_node->next;

  queue->size--;

	return first_node;
}

/*
  @params: 
    queue_t* queue: it's a ponter to the queue
    node_t* item: it's an element that will be added to the queue
  @decription: This function adds an element to the end of the queue
  @return: void
*/
void enqueue(queue_t* queue, node_t* item) {
  if (queue->size == 0) {
    queue->first = item;
  } else {
    node_t* node;

    for (node = queue->first; node->next != NULL; node = node->next)
      ;
  
    node->next = item;
  }

  queue->size++;
}

// TODO: checks if a queue is empty
int is_empty(queue_t* queue) {
	return queue->size == 0;
}



