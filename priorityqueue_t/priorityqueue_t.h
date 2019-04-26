//
// Created by Felix Häner on 2019-04-06.
//

#ifndef PRAKTIKUM_1_PRIORITYQUEUE_T_H
#define PRAKTIKUM_1_PRIORITYQUEUE_T_H

// Interface Warteschlange
typedef struct pqueue pqueue_t;

typedef struct pqentry pqentry_t;

pqueue_t *pqueue_create();

void pqueue_insert(pqueue_t *pq, char *value, float p);

char *pqueue_extractMin(pqueue_t *pq);

static void pqueue_decreaseKey(pqueue_t *pq, char *value, float p);

static void pqueue_remove(pqueue_t *pq, char *value);

static pqentry_t *pqentry_create(char *value, float p);

void pqueue_destroy(pqueue_t *pq);

void printList(pqueue_t *list);

// Interface Test Funktionen
void testCreateQueue();

void testCreateEntry();

void testInsert();

void testRemove();

void testExtractMin();

void testDestroyQueue();

void testDecreaseKey();

#endif //PRAKTIKUM_1_PRIORITYQUEUE_T_H
