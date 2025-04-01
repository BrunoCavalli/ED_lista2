#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H

#include <iostream>
#include <string>

/**
 * @namespace WaitingQueueTAD
 * A namespace containing data structures and functions for managing a waiting queue.
 */

/**
 * @struct Client
 * Represents a client in the waiting queue.
 * 
 * @var Client::name
 * A character array storing the name of the client (maximum 50 characters).
 * 
 * @var Client::priority
 * The priority level of the client. 
 * 0 = general; 1 = priority.
 */

/**
 * @struct QueueNode
 * Represents a node in the waiting queue.
 * 
 * @var QueueNode::client
 * The client data stored in the node.
 * 
 * @var QueueNode::next
 * A pointer to the next node in the queue.
 * 
 * @var QueueNode::previous
 * A pointer to the previous node in the queue.
 */

/**
 * @struct WaitingQueue
 * Represents the waiting queue.
 * 
 * @var WaitingQueue::generalCount
 * The count of general (non-priority) clients in the queue.
 * 
 * @var WaitingQueue::elderlyCount
 * The count of priority clients in the queue.
 * 
 * @var WaitingQueue::head
 * A pointer to the first node in the queue.
 * 
 * @var WaitingQueue::tail
 * A pointer to the last node in the queue.
 * 
 * @var WaitingQueue::size
 * The total number of clients in the queue.
 */

/**
 * @function createQueue
 * Initializes and returns a new waiting queue.
 * 
 * @return A pointer to the newly created WaitingQueue.
 */

/**
 * @function enqueue
 * Adds a client to the waiting queue.
 * 
 * @param queue A pointer to the WaitingQueue.
 * @param client The client to be added to the queue.
 */

/**
 * @function peek
 * Retrieves the next client to be served without removing them from the queue.
 * 
 * @param queue A pointer to the WaitingQueue.
 * @param client A pointer to a Client structure to store the next client.
 * @return 0 if the queue is empty, 1 otherwise.
 */

/**
 * @function dequeue
 * Removes and retrieves the next client to be served from the queue.
 * 
 * @param queue A pointer to the WaitingQueue.
 * @param returnclient A pointer to a Client structure to store the removed client.
 * @return 0 if the queue is empty, 1 otherwise.
 */

/**
 * @function removeClient
 * Removes a specific client from the queue by their name.
 * 
 * @param queue A pointer to the WaitingQueue.
 * @param name The name of the client to be removed.
 * @return 0 if the client was not found, 1 if the client was successfully removed.
 */

/**
 * @function getQueueOrder
 * Retrieves the current order of clients in the queue.
 * 
 * @param queue A pointer to the WaitingQueue.
 * @param numClients A pointer to an integer to store the number of clients in the queue.
 * @return A dynamically allocated array of Client structures representing the queue order.
 *         The caller is responsible for freeing the memory.
 */

/**
 * @function deleteQueue
 * Deletes the waiting queue and frees all associated memory.
 * 
 * @param queue A pointer to the WaitingQueue to be deleted.
 */

/**
 * @function printQueue
 * Prints the current state of the queue to the standard output.
 * 
 * @param queue A pointer to the WaitingQueue.
 */
namespace WaitingQueueTAD {

    struct Client {
        char name[50];
        int priority; // 0 = geral; 1 = prioridade
    };

    struct QueueNode {
        Client client;
        QueueNode* next;
        QueueNode* previous;

    };

    struct WaitingQueue {
        int generalCount;
        int elderlyCount;
        QueueNode* head;
        QueueNode* tail;
        int size;
    };

    WaitingQueue* createQueue(); // Inicializar a fila
    void enqueue(WaitingQueue* queue, Client client); // inserir cliente na fila
    int peek(const WaitingQueue* queue, Client* client); // Proximo a ser atendido
    int dequeue(WaitingQueue* queue, Client* returnclient); // Remover o proximo da fila
    int removeClient(WaitingQueue* queue, char* name); // Remover cliente especifico da fila
    Client* getQueueOrder(const WaitingQueue* queue, int* numClients); // Obeter ordem da fila
    void deleteQueue(WaitingQueue* queue); // Deletar a fila e liberar memoria
    void printQueue(const WaitingQueue* queue);
}



#endif // WAITINGQUEUE_H