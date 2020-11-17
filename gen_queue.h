/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//gen_queue.h contains the header file for, and the implementation of, the GenQueue class.
#ifndef GEN_QUEUE
#define GEN_QUEUE

#include "list_node.h"
#include "doubly_linked_list.h"

using namespace std;

//GenQueue is a template class for a standard DoublyLinkedList based Queue
template <class type> class GenQueue{
public:

  /* Default constructor: GenQueue
  * Instantiates an empty doubly linked list.
  */
  GenQueue();

  /* Destructor: ~GenQueue
  * Deletes the doubly linked list representing the queue.
  */
  ~GenQueue();

  /* Member function: Enqueue
  * Inserts data at the end of the queue.
  * Parameters:
  * data: a variable of a given type to be added to the queue
  */
  void Enqueue(type data);

  /* Member function: Dequeue
  * Removes data at the front of the queue.
  * Returns:
  * A variable of a given type that has been removed from the queue.
  */
  type Dequeue();

  /* Member function: Peek
  * Returns the data at the front of the queue without removing it.
  * Returns:
  * A variable of a given type that is at the front of the queue..
  */
  type Peek();

  /* Member function: IsEmpty
  * Returns whether or not the queue is empty.
  * Returns:
  * A bool indicating whether or not the queue is empty.
  */
  bool IsEmpty();

  /* Member function: GetLength
  * Returns the length of the queue.
  * Returns:
  An unsigned int representing the length of the queue.
  */
  unsigned int GetLength();

  /* Member Function: Print
  * Prints out the queue in it's current order.
  */
  void Print();

private:
  /* Member variable: queue
  * A pointer to a doubly linked list representing the queue.
  */
  DoublyLinkedList<type> *queue;

};

template<class type> GenQueue<type>::GenQueue(){
  queue = new DoublyLinkedList<type>();
}

template<class type> GenQueue<type>::~GenQueue(){
  delete queue;
}

template<class type> void GenQueue<type>::Enqueue(type data){
  queue->Append(data);
}

template<class type> type GenQueue<type>::Dequeue(){
  type temp;
  if(!IsEmpty())
    temp = queue->RemoveFront();
  return temp;
}

template<class type> type GenQueue<type>::Peek(){
  type temp;
  if(!IsEmpty()){
    ListNode<type> *temp_node = queue->GetNodeFromPosition(0);
    temp = temp_node->data;
  }
  return temp;
}

template<class type> bool GenQueue<type>::IsEmpty(){
  return queue->IsEmpty();
}

template<class type> unsigned int GenQueue<type>::GetLength(){
  return queue->GetLength();
}

template<class type> void GenQueue<type>::Print(){
  queue->Print();
}


#endif
