#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct No {
    int info;
    struct No* proximo;
};

struct No* criarNo(char info) {
    struct No* novoNo = (struct No*) malloc(sizeof(struct No));
    novoNo->info = info;
    novoNo->proximo = NULL;

    return novoNo;
}

void inserirNoInicio(struct No** cabeca, int info) {
    struct No* novoNo = criarNo(info);

    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }

    struct No* temporario = novoNo;
    temporario->proximo = *cabeca;
    *cabeca = temporario;
}

void inserirNoFinal(struct No** cabeca, int info) {
    struct No* novoNo = criarNo(info);

    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }

    struct No* atual = *cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novoNo;
}

void imprimirLista(struct No* cabeca) {
    struct No* atual = cabeca;
    printf("[");
    while (atual != NULL) {
        printf(" %d ", atual->info);
        atual = atual->proximo;
    }
    printf("]");
}

int main() {
    struct No* cabeca = NULL;

    inserirNoInicio(&cabeca, 11);
    inserirNoInicio(&cabeca, 12);
    inserirNoFinal(&cabeca, 13);
    inserirNoFinal(&cabeca, 14);
    imprimirLista(cabeca);

    return 0;
}

