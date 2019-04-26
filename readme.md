PRAKTIKUM 1 SEMESTER 2

Die Idee ist es das erste Praktikum mit einer Doppelten verketteten Liste zu lösen.
Die doppelt Verkettete Liste kann die Elemente sortiert einfügen. Es muss nicht drauf geachteet werden, wenn Speicher zu vergößern. Der Nachteil der Kette ist allerdings, dass große Datenmengen lange brauchen, um eingegeben zu werden. Das entfernen der Elemente nach Priorität ist dadurch aber extrem schnell.
Static Funktionen werden hier dazu benutzt um das "private" in der Objektorientierten Programmierung zu simulieren.

Folgende Funktionen wurden implementiert:
pqueue_t *pqueue_create();
Diese Funktion erzeugt eine neue Prioritätswarteschlange.

static pqentry_t *pqentry_create(char *value, float p);
Diese Funktion erzeugt ein neues Element für die Wartschlange und initialisiert die Werte value und p.

void pqueue_insert(pqueue_t *pq, char *value, float p);
Diese Funktion trägt ein neues Element gemäß seiner Priorität in die Liste ein.  Dabei wird auf darauf geachtet ob die Liste leer ist, ob das neue Element am Anfang, am Ende oder in der Mitte eingefügt werden muss.

char *pqueue_extractMin(pqueue_t *pq);
Diese Funktion liefert die Value des Elements mit der höchsten Priorität zurück und entfernt es anschließend aus der Liste. 

static void pqueue_decreaseKey(pqueue_t *pq, char *value, float p);
Diese Funktion verändert die Priorität. Dazu löscht sie zuerst das gesuchte Element aus der Warteschlange und erzeugt danach ein neues Element mit der neuen Priorität und fügt es anschließend in die Warteschlange wieder ein. 

static void pqueue_remove(pqueue_t *pq, char *value);
Diese Funktion sucht anhand der Value das Element in der Liste welches gelöscht werden soll.

void pqueue_destroy(pqueue_t *pq);
Diese Funktion zerstört die Warteschlange und entfernt alle Objekte die sich noch in der 
Warteschlange befinden.

void printList(pqueue_t *list);
Diese Funktion ist eine Kontrollfunktion und gibt die Liste vorwärts und rückwärts aus und 
soll somit als Kontrolle gelten ob das Einfügen der Elemente funktioniert hat. 

Es wurden außerdem einige Testfunktionen implementiert um die einzelnen Funktionen zu 
testen.

void testCreateQueue();
Diese Funktion testet ob eine Warteschlange erzeugt wurden konnte.

void testCreateEntry();
Diese Funktion testet ob eine Element für die Liste erzeugt werden konnte.

void testInsert();
Es werden Dummy Elemente in die Liste eingefügt und zu überprüfen ob diese korrekt eingefügt
wurden.

void testRemove();
Es werden Dummy Elemente in die Liste eingefügt und danach gezielt anhand des Strings gesucht und 
entfernt.



void testExtractMin();
Es werden Dummy Elemente in die Liste eingefügt und danach wird das Element mit der höchsten 
Priorität entfernt. 

void testDecreaseKey();
Es werden Dummy Elemente in die Liste eingefügt und danach wird gezielt ein Element ausgesucht dessen
Priorität verändert werden soll.

void testDestroyQueue();
Es wird eine Liste erzeugt danach werden Elemente in die Liste eingefügt und dann wird die 
Liste zerstört um zu testen ob dies einwandfrei funktionert hat. 

Laufzeiten
i7 2.8Ghz
8 GB

        Anzahl der Elemente
        Zeit einfügen in Sekunden
        Zeit herausnehmen in Sekunden


10000	20000	30000	40000	50000	60000	70000	80000	90000	100000
0,18	0,94	2,23	4,02	6,66	10,01	13,81	19,14	24,04	29,01
0,00	0,00	0,00	0,00	0,00	0,00	0,01	0,01	0,01	0,01

