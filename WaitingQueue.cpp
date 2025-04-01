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
        if (!queue) return;
    
        QueueNode* newNode = new QueueNode;
        newNode->client = client;
        newNode->next = nullptr;
        newNode->previous = nullptr;
    
        // Se a fila está vazia
        if (!queue->head) {
            queue->head = queue->tail = newNode;
        } else {
            QueueNode* current = queue->tail;
    
            // Regras de intercalamento
            int elderlyBefore = 0;
            int generalBefore = 0;
            while (current) {
                if (current->client.priority == 1) elderlyBefore++;
                else generalBefore++;
    
                if (client.priority == 1 && generalBefore >= 1) break;
                if (client.priority == 0 && elderlyBefore >= 2) break;
    
                current = current->previous;
            }
    
            if (!current) {
                // Adicionar no início
                newNode->next = queue->head;
                queue->head->previous = newNode;
                queue->head = newNode;
            } else {
                // Inserir após current
                newNode->next = current->next;
                newNode->previous = current;
                if (current->next) {
                    current->next->previous = newNode;
                } else {
                    queue->tail = newNode;
                }
                current->next = newNode;
            }
        }
    
        // Atualiza contadores
        if (client.priority == 1) queue->elderlyCount++;
        else queue->generalCount++;
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

    int removeClient(WaitingQueue* queue, char* name) {
        if (!queue || !queue->head) {
            return 0; // Fila vazia ou inválida
        }
    
        QueueNode* current = queue->head;
        while (current) {
            if (strcmp(current->client.name, name) == 0) {
                // Ajusta os ponteiros
                if (current->previous) {
                    current->previous->next = current->next;
                } else {
                    queue->head = current->next; // Se for o primeiro nó
                }
    
                if (current->next) {
                    current->next->previous = current->previous;
                } else {
                    queue->tail = current->previous; // Se for o último nó
                }
    
                // Atualiza contadores
                if (current->client.priority == 1) {
                    queue->elderlyCount--;
                } else {
                    queue->generalCount--;
                }
                queue->size--;
    
                // Libera memória
                delete current;
                return 1; // Removido com sucesso
            }
            current = current->next;
        }
        return 0; // Cliente não encontrado
    }
   
    // Obeter ordem da fila
    Client* getQueueOrder(const WaitingQueue* queue, int* numClients) {
        if (!queue || queue->head == nullptr) {
            *numClients = 0;
            return 0; // Fila vazia ou inváliada
        }

        QueueNode* current = queue->head;        
        *numClients = queue->size;
        Client* order = new Client[*numClients];
        int elderlyCount = 0;
        int generalCount = 0;
        int index = 0;

        while (current) {
            if (current->client.priority == 1) {
                if ((elderlyCount < 2) || (generalCount = 0))
                    order[index++] = current->client;
                    elderlyCount++;
            } else {
                if ((elderlyCount <= 2) || (generalCount = 1))
                order[index++] = current->client;
                generalCount++;
                elderlyCount = 0;
            }
            current = current->next;
        }
               
        return order;

    } 

    void deleteQueue(WaitingQueue* queue) {
        if (!queue) return; // Verifica se a fila existe
    
        QueueNode* temp;
        while (queue->head) {  // Enquanto houver elementos na fila
            temp = queue->head;
            queue->head = queue->head->next; // Avança o ponteiro head
            delete temp;  // Libera o nó atual
        }
    
        queue->tail = nullptr; // Evita ponteiro solto
        queue->size = 0;
        queue->generalCount = 0;
        queue->elderlyCount = 0;
    }
 
    
    void printQueue(const WaitingQueue* queue) {
        if (!queue || queue->head == nullptr) {
            std::cout << "Fila vazia." << std::endl;
            return;
        }
    
        QueueNode* current = queue->head;
        std::cout << "Fila atual:" << std::endl;
        while (current) {
            std::cout << "Nome: " << current->client.name << ", Prioridade: " << current->client.priority << std::endl;
            current = current->next;
        }
    }
    
}