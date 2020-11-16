/*
* Implementação das operações sobre o TAD lista encadeada e duplamente encadeada.
*/

#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void lst_init(lst_ptr * l)
{
    if((*l = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
    }
    (*l)->prox = *l;
}

void lst_ins(lst_ptr l, lst_info val)
{
    lst_ptr n;
    if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
    }
    n->dado = val;
    if (l->prox == l) {
       l->prox = n;
       n->ant = l;
    }
    else {
        l->ant->prox = n;
        n->ant = l->ant;
    }
     n->prox = l;
     l->ant = n;
}

void lst_print(lst_ptr l)
{
    lst_ptr p = l->prox;
    while (p != l) {
        if(p->dado->dado != 25 && p->dado->dado != 12) {
            printf("%d.[%d,%d],",
                p->dado->dado,
                p->dado-> linha,
                p->dado->col);
            p = p->prox;
            printf("\n");
        }else {
             printf("[%d].[%d,%d],",
                p->dado->dado,
                p->dado-> linha,
                p->dado->col);
                p = p->prox;
                printf("\n");
        }
    }
}

void lst_kill(lst_ptr l)
{
	lst_ptr p, q = l->prox;
	while (l != q) {
		p = q;
		q = q->prox;
		free(p);
	}
}

int lst_occurs(lst_ptr l, lst_info x)
{
	int cont = 0;
	while (l != NULL && l->dado < x) {
		l = l->prox;
	}
	while (l != NULL && l->dado == x) {
		cont++;
		l = l->prox;
	}
	return cont;
}

int lst_size(lst_ptr l)
{
	int cont = 0;
	while (l != NULL) {
		cont++;
		l = l->prox;
	}
	return cont;
}

lst_info lst_pop_get(lst_ptr l)
{
    return l->ant->dado;
}
