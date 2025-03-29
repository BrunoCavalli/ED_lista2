#include "WaitingQueue.h"
#include <iostream>
#include <cstring>
#include <string>


namespace WaitingQueueTAD {

    WaitingQueue* createQueue() {
        WaitingQueue* queue = new WaitingQueue;
        queue->generalCount = 0;
        queue->elderlyCount = 0;
        queue->head = nullptr;
        queue->tail = nullptr;
        queue->size = 0;
        return queue;
    }

    void enqueue(WaitingQueue* queue, Client client) {
        QueueNode* newNode = new QueueNode{};
        newNode->client = client;
        newNode->next = queue->head;
        newNode->previous = nullptr;

        if (queue->head != nullptr) {
            queue->head->previous = newNode;
        }
        queue->head = newNode;

        if (queue->tail == nullptr) {
            queue->tail = newNode;
        }

        queue->size++;
    }

    int peek(const WaitingQueue* queue, Client* returnClient) {
        if (queue->head == nullptr) {
            return 0; // Fila vazia
        }
        *returnClient = queue->head->client;
        return 1; // Sucesso
    }

    int dequeue(WaitingQueue* queue, Client* returnClient) {
        if (queue->head == nullptr) {
            return 0; // Fila vazia
        }

        QueueNode* nodeToRemove = queue->head;
        *returnClient = nodeToRemove->client;

        queue->head = queue->head->next;
        if (queue->head != nullptr) {
            queue->head->previous = nullptr;
        } else {
            queue->tail = nullptr; // Se a fila ficou vazia, atualiza o tail
        }

        delete nodeToRemove;
        queue->size--;

        return 1; // Sucesso
    }
}