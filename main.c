#include <stdio.h>
#include "priorityqueue_t/priorityqueue_t.h"
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void testCase();

char *randomstring(int size) {
    char *str = (char *) malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; ++i) {
        str[i] = (rand() % 26) + 'A';
    }
    str[size] = '\0';
    return str;
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int prg;

    printf("\n\n");

    do {
        printf("Bitte wahlen Sie einen der Tests aus: \n");
        printf("1: Warteschlange erzeugen. \n");
        printf("2: Eintrag erzeugen. \n");
        printf("3: Einträge in Warteschlange ablegen. \n");
        printf("4: Einträge aus Warteschlange entfernen.\n");
        printf("5: Minimum aus der Schlange entfernen. \n");
        printf("6: Priorität ändern. \n");
        printf("7: Insertion und Removal Test aus der Aufgabe mit 100.000 Elementen. \n");
        printf("8: Programm beenden.\n");
        scanf("%d", &prg);

        switch (prg) {
            case 1:
                testCreateQueue();
                break;
            case 2:
                testCreateEntry();
                break;
            case 3:
                testInsert();
                break;
            case 4:
                testRemove();
                break;
            case 5:
                testExtractMin();
                break;
            case 6:
                testDecreaseKey();
                break;
            case 7:
                testCase();
                break;
            default:
                if(prg != 8) {
                    printf("Auswahl zwischen 1 und 8!\n");
                }
        }

    } while (prg != 8);

    return 0;
}

void testCase() {
    char *strings[MAX];
    clock_t tic, toc;

    for (int i = 0; i < MAX; ++i) {
        strings[i] = randomstring(8);
    }

    pqueue_t *pq = pqueue_create();

    tic = clock();
    for (int j = 0; j < MAX; ++j) {
        pqueue_insert(pq, strings[j], rand() % 100);
    }

    toc = clock();

    printf("insertion time: %.2f\n", (float) (toc - tic) / CLOCKS_PER_SEC);

    tic = clock();
    for (int k = 0; k < MAX; ++k) {
        pqueue_extractMin(pq);
    }
    toc = clock();

    printf("extract time: %.2f\n", (float) (toc - tic) / CLOCKS_PER_SEC);

    for (int l = 0; l < MAX; ++l) {
        free(strings[l]);
    }

    pqueue_destroy(pq);

    printf("\n\n");
}