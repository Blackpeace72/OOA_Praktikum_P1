//
// Created by Felix Häner on 2019-04-06.
//

#include "priorityqueue_t.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct pqentry {
    char *value;
    float priority;
    pqentry_t *p_next;
    pqentry_t *p_prev;

};

struct pqueue {
    pqentry_t *p_head;
    pqentry_t *p_tail;
};

/* Vorrangwarteschlange Funktionalität */

pqueue_t *pqueue_create() {

    pqueue_t *liste;

    liste = (pqueue_t *) malloc(sizeof(pqueue_t));
    if (liste == NULL) {
        exit(42);
    }

    liste->p_tail = NULL;
    liste->p_head = NULL;


    return liste;


}

static pqentry_t *pqentry_create(char *value, float p) {

    pqentry_t *elem;

    elem = (pqentry_t *) malloc(sizeof(pqentry_t));
    if (elem == NULL) {
        exit(42);

    }
    elem->value = (char*) malloc(sizeof(char));
    if(elem->value == NULL) {
        exit(42);
    }
    elem->value = value;
    elem->priority = p;
    elem->p_next = NULL;
    elem->p_prev = NULL;

    return elem;
}

void pqueue_insert(pqueue_t *pq, char *value, float p) {

    //Erzeuge neues Element
    pqentry_t *elem = pqentry_create(value, p);


    //Leere Liste
    if (pq->p_head == NULL) {
        pq->p_head = elem;
        pq->p_tail = elem;
        elem->p_next = NULL;
        elem->p_prev = NULL;
        return;
    }

    //Anfang der Liste
    if (pq->p_head->priority >= elem->priority) {
        elem->p_next = pq->p_head;
        elem->p_prev = NULL;
        pq->p_head->p_prev = elem;
        pq->p_head = elem;
        return;
    }

    //Ende der Liste
    if (pq->p_tail->priority <= elem->priority) {
        elem->p_prev = pq->p_tail;
        elem->p_next = NULL;
        pq->p_tail->p_next = elem;
        pq->p_tail = elem;
        return;
    }

    //Mitte der Liste
    pqentry_t *search;
    search = pq->p_head;
    while (search != NULL) {
        if (elem->priority <= search->priority) {
            elem->p_next = search;
            elem->p_prev = search->p_prev;
            search->p_prev->p_next = elem;
            search->p_prev = elem;
            return;
        }
        search = search->p_next;
    }
}

char *pqueue_extractMin(pqueue_t *pq) {
    if(pq->p_head == NULL) {
        return "Liste ist leer!\n";
    }
    char *value = pq->p_head->value;
    pqueue_remove(pq, value);
    return value;

}

static void pqueue_decreaseKey(pqueue_t *pq, char *value, float p) {
    pqueue_remove(pq, value);
    pqueue_insert(pq, value, p);
}

static void pqueue_remove(pqueue_t *pq, char *value) {

    int stringVal;

    if (pq->p_head == NULL) {
        return;
    }

    //letztes Element oder ein Element
    if (pq->p_head->p_next == NULL) {
        free(pq->p_head);
        pq->p_head = NULL;
        return;
    }

    //Entferne Element am Anfang
    stringVal = strcmp(pq->p_head->value, value);
    if (stringVal == 0) {
        pqentry_t *nextHead = pq->p_head->p_next;
        pq->p_head->p_next->p_prev = NULL;
        free(pq->p_head);
        pq->p_head = nextHead;
        return;
    }

    //Entferne Element am Ende
    stringVal = strcmp(pq->p_tail->value, value);
    if (stringVal == 0) {
        pq->p_tail->p_prev->p_next = NULL;
        pqentry_t *nextTail = pq->p_tail->p_prev;
        free(pq->p_tail);
        pq->p_head = nextTail;
        return;
    }

    //Entferne Element in der Mitte
    pqentry_t *search;
    search = pq->p_head;
    while (search != NULL) {
        stringVal = strcmp(search->value, value);
        if (stringVal == 0) {
            search->p_prev->p_next = search->p_next;
            search->p_next->p_prev = search->p_prev;
            free(search);
            return;
        }
        search = search->p_next;
    }

}

void pqueue_destroy(pqueue_t *pq) {
    if (pq->p_head == NULL) {
        free(pq);
        return;
    }
    while (pq->p_head != NULL) {
        pqueue_extractMin(pq);
    }
    free(pq);
}

void printList(pqueue_t *list) {
    if (list->p_head == NULL) {
        printf("\nDie Liste ist leer!\n");
        return;
    }

    pqentry_t *forward = list->p_head;
    pqentry_t *backward = list->p_tail;


    printf("Liste:\n");
    while (forward != NULL) {
        printf("Value: %s\n", forward->value);
        printf("Priority: %f\n", forward->priority);
        forward = forward->p_next;
    }

//    printf("\nListe Rueckwaertz\n");
//    while (backward != NULL) {
//        printf("Value: %s\n", backward->value);
//        printf("Priority: %f\n", backward->priority);
//        backward = backward->p_prev;
//}
}


/* Test Funktionen */

void testCreateQueue() {
    printf("Teste Warteschlange Erzeugen Funktion: \n\n");
    pqueue_t *liste;
    liste = pqueue_create();
    if (liste == NULL) {
        printf("Es trat ein Fehler auf!\n");
        return;
    }
    printf("Liste wurde erfolgreich erstellt\n");
    printf("\n\n");

    pqueue_destroy(liste);
}

void testCreateEntry() {
    printf("Teste Eintrag Erzeugen Funktion: \n\n");
    pqentry_t *elem;
    elem = pqentry_create("test", 2.0);
    if (elem == NULL) {
        printf("Es trat ein Fehler auf!\n");
        return;
    }
    printf("Element wurde erfolgreich erzeugt\n");
    printf("\n\n");
}

void testInsert() {
    printf("Teste Einfügen Funktion: \n\n");
    pqueue_t *list;
    list = pqueue_create();

    printf("Prüft ob ein Element erstellt und in die leere Liste eingefügt wurde\n");
    pqueue_insert(list, "obere mitte", 0.3);
    printList(list);
    printf("\n\n");

    printf("Prüft ob ein Element erstellt wurde und an das Ende der Liste eingefügt wurde\n");
    pqueue_insert(list, "ende", 7.0);
    printList(list);
    printf("\n\n");

    printf("Prüft ob ein Element erstellt wurde und an den Anfang der Liste eingefügt wurde\n");
    pqueue_insert(list, "anfang", 0.2);
    printList(list);
    printf("\n\n");

    printf("Prüft ob ein Element erstellt wurde und an die richtige Stelle in der Mitte der Liste eingefügt wurde\n");
    pqueue_insert(list, "untere mitte", 2.3);
    printList(list);
    printf("\n\n");

    pqueue_destroy(list);
}

void testRemove() {
    printf("Teste Loeschen Funktion: \n\n");
    pqueue_t *list;
    list = pqueue_create();

    // leere Liste
    pqueue_remove(list, "foo");

    printf("Leere Liste: \n\n");
    printList(list);
    printf("\n\n");

    //letztes oder ein Element
    pqueue_insert(list, "foo", 0.1);
    printList(list);
    pqueue_remove(list, "foo");

    printf("letztes oder ein Element: \n\n");
    printList(list);
    printf("\n\n");

    // Element am Anfang
    pqueue_insert(list, "foo1", 0.1);
    pqueue_insert(list, "foo2", 0.5);
    pqueue_remove(list, "foo1");
    printList(list);
    printf("Element am Anfang: \n\n");
    printList(list);
    printf("\n\n");

    // Element am Ende
    pqueue_insert(list, "foo1", 0.1);
    pqueue_insert(list, "foo2", 0.5);
    pqueue_remove(list, "foo2");

    printf("Element am Ende: \n\n");
    printList(list);
    printf("\n\n");

    // Element mitten in der Liste löschen
    pqueue_insert(list, "foo1", 0.1);
    pqueue_insert(list, "foo2", 0.5);
    pqueue_insert(list, "foo3", 0.6);
    pqueue_insert(list, "foo4", 0.7);
    pqueue_remove(list, "foo3");

    printf("Element mitten in der Liste löschen: \n\n");
    printList(list);
    printf("\n\n");

    pqueue_destroy(list);
}

void testExtractMin() {
    printf("Teste Extract Min Funktion: \n\n");

    pqueue_t *list;
    list = pqueue_create();
    pqueue_insert(list, "leere", 0.2);
    pqueue_insert(list, "ende", 5.0);
    pqueue_insert(list, "anfang", 0.1);
    pqueue_insert(list, "mitte", 2.0);
    printList(list);
    printf("\n\n");

    char *value = pqueue_extractMin(list);
    printf("Entfernter Eintrag: %s", value);

    printf("\n\n");

    pqueue_destroy(list);
}

//void testDestroyQueue() {
//    printf("Teste Destroy Queue Funktion: \n\n");
//
//    pqueue_t *list;
//    list = pqueue_create();
//    pqueue_insert(list, "leere", 0.2);
//    pqueue_insert(list, "ende", 5.0);
//    pqueue_insert(list, "anfang", 0.1);
//    pqueue_insert(list, "mitte", 2.0);
//    printList(list);
//    printf("\n\n");
//    pqueue_destroy(list);
//}

void testDecreaseKey() {
    printf("Teste DecreaseKey Funktion: \n\n");

    pqueue_t *list;
    list = pqueue_create();
    pqueue_insert(list, "leere", 0.2);
    pqueue_insert(list, "ende", 5.0);
    pqueue_insert(list, "anfang", 0.1);
    pqueue_insert(list, "mitte", 2.0);
    printList(list);
    printf("\n\n");

    pqueue_decreaseKey(list, "leere", 0.3);
    pqueue_decreaseKey(list, "ende", 0.4);
    pqueue_decreaseKey(list, "anfang", 0.5);
    pqueue_decreaseKey(list, "mitte", 1.0);
    pqueue_destroy(list);
}