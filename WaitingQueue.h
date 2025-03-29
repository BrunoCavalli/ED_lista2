#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H

#include <iostream>
#include <string>

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