#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

struct c {
    int saldo;
};

typedef struct c conta;

conta from, to;
int valor;

// Semáforos para garantir a sincronização
sem_t from_sem;
sem_t to_sem;

// A thread irá executar esta função
void *transferencia(void *arg) {
    sem_wait(&from_sem);  // Espera até que a conta 'from' esteja disponível
    if (from.saldo >= valor) {
        from.saldo -= valor;
        to.saldo += valor;
    }
    sem_post(&from_sem);  // Libera a conta 'from'
    
    printf("Transferência concluída com sucesso!\n");
    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);

    return NULL;
}

int main() {
    pthread_t thread;
    int i;

    // Inicializa os semáforos
    sem_init(&from_sem, 0, 1);
    sem_init(&to_sem, 0, 1);

    // Todas as contas começam com saldo 100
    from.saldo = 100;
    to.saldo = 100;
  
    printf("Transferindo 10 para a conta c2\n");
    valor = 10;

    for (i = 0; i < 10; i++) {
        if (pthread_create(&thread, NULL, transferencia, NULL) != 0) {
            perror("pthread_create");
            exit(1);
        }
        pthread_join(thread, NULL); // Espera pelo término da thread
    }

    // Zera o saldo de 'from'
    from.saldo = 0;

    // Destruir os semáforos
    sem_destroy(&from_sem);
    sem_destroy(&to_sem);

    printf("Transferências concluídas.\n");
    return 0;
}# PROJ1SO
# PROJ1SO
