#include "WaitingQueue.h"
#include <iostream>
#include <cstring>

using namespace WaitingQueueTAD;

int main() {
    // Criação da fila
    WaitingQueue* queue = createQueue();

    // Adicionando clientes à fila
    Client client1 = {"Alice", 1}; // Prioridade
    Client client2 = {"Bob", 0};   // Geral
    Client client3 = {"Charlie", 1}; // Prioridade
    Client client4 = {"David", 0};   // Geral

    enqueue(queue, client1);
    enqueue(queue, client2);
    enqueue(queue, client3);
    enqueue(queue, client4);

    // Imprimindo a fila
    std::cout << "Estado inicial da fila:" << std::endl;
    printQueue(queue);

    // Verificando o próximo cliente a ser atendido
    Client nextClient;
    if (peek(queue, &nextClient)) {
        std::cout << "\nPróximo cliente a ser atendido: " << nextClient.name << std::endl;
    } else {
        std::cout << "\nA fila está vazia." << std::endl;
    }

    // Removendo o próximo cliente da fila
    if (dequeue(queue, &nextClient)) {
        std::cout << "\nCliente atendido e removido da fila: " << nextClient.name << std::endl;
    } else {
        std::cout << "\nA fila está vazia." << std::endl;
    }

    // Imprimindo a fila após a remoção
    std::cout << "\nEstado da fila após a remoção:" << std::endl;
    printQueue(queue);

    // Removendo um cliente específico
    char nameToRemove[] = "Charlie";
    if (removeClient(queue, nameToRemove)) {
        std::cout << "\nCliente " << nameToRemove << " removido da fila." << std::endl;
    } else {
        std::cout << "\nCliente " << nameToRemove << " não encontrado na fila." << std::endl;
    }

    // Imprimindo a fila após a remoção específica
    std::cout << "\nEstado da fila após a remoção específica:" << std::endl;
    printQueue(queue);

    // Obtendo a ordem atual da fila
    int numClients;
    Client* queueOrder = getQueueOrder(queue, &numClients);
    if (queueOrder) {
        std::cout << "\nOrdem atual da fila:" << std::endl;
        for (int i = 0; i < numClients; ++i) {
            std::cout << "Nome: " << queueOrder[i].name << ", Prioridade: " << queueOrder[i].priority << std::endl;
        }
        delete[] queueOrder; // Liberando memória alocada
    } else {
        std::cout << "\nA fila está vazia." << std::endl;
    }

    // Deletando a fila
    deleteQueue(queue);
    delete queue;

    return 0;
}