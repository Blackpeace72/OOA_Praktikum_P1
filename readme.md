<h2>Dokumentation</h2>

Die Idee ist es das erste Praktikum mit einer Doppelt verketteten Liste zu lösen.
Der Vorteil der doppelt verketteten Liste ist es das Elemente sortiert eingefügt werden können.
Unteranderem muss nicht darauf geachtet werden Speicher zu vergrößern. Ein Nachteil der 
doppelt verketteten Liste ist es allerdings das das eingeben großer Datenmengen sehr lange dauert.
Dafür ist das herausnehmen des Elements mit der höchsten Priorität sehr schnell.

<b>Static Funktionen werden hier dazu benutzt um das "private" in der Objektorientierten
Programmierung zu simulieren.</b>

<b>Folgende Funktionen wurden implementiert:</b> 
````c
pqueue_t *pqueue_create();
````
Diese Funktion erzeugt eine neue Prioritätswarteschlange.
````c
static pqentry_t *pqentry_create(char *value, float p);
````
Diese Funktion erzeugt ein neues Element für die Wartschlange und initialisiert die Werte value und p.
````c
void pqueue_insert(pqueue_t *pq, char *value, float p);
````
Diese Funktion trägt ein neues Element gemäß seiner Priorität in die Liste ein. 
Dabei wird auf darauf geachtet ob die Liste leer ist, ob das neue Element am Anfang,
am Ende oder in der Mitte eingefügt werden muss.
````c
char *pqueue_extractMin(pqueue_t *pq);
````
Diese Funktion liefert die Value des Elements mit der höchsten Priorität zurück und entfernt es
anschließend aus der Liste. 
````c
static void pqueue_decreaseKey(pqueue_t *pq, char *value, float p);
````
Diese Funktion verändert die Priorität. Dazu löscht sie zuerst das gesuchte Element aus der Warteschlange und erzeugt
danach ein neues Element mit der neuen Priorität und fügt es anschließend in die Warteschlange
wieder ein. 
````c
static void pqueue_remove(pqueue_t *pq, char *value);
````
Diese Funktion sucht anhand der Value das Element in der Liste welches gelöscht werden soll.
````c
void pqueue_destroy(pqueue_t *pq);
````
Diese Funktion zerstört die Warteschlange und entfernt alle Objekte die sich noch in der 
Warteschlange befinden.
````c
void printList(pqueue_t *list);
````
Diese Funktion ist eine Kontrollfunktion und gibt die Liste vorwärts und rückwärts aus und 
soll somit als Kontrolle gelten ob das Einfügen der Elemente funktioniert hat. 

<b>Es wurden außerdem einige Testfunktionen implementiert um die einzelenen Funktionen zu 
testen.</b> 
````c
void testCreateQueue();
````
Diese Funktion test ob eine Warteschlange erzeugt wurden konnte.
````c
void testCreateEntry();
````
Diese Funktion teste ob eine Element für die Liste erzeugt werden konnte.
````c
void testInsert();
````
Es werden Dummy Elemente in die Liste eingefügt umd zu überprüfen ob diese korrekt eingefügt
wurden.
````c
void testRemove();
````
Es werden Dummy Elemente in die Liste eingefügt und danach gezielt anhand des Strings gesucht und 
entfernt.
````c
void testExtractMin();
````
Es werden Dummy Elemente in die Liste eingefügt und danach wird das Element mit der höchsten 
Priorität entfernt. 
````c
void testDecreaseKey();
````
Es werden Dummy Elemente in die Liste eingefügt und danach wird gezielt ein Element ausgesucht dessen
Priorität verändert werden soll.
````c
void testDestroyQueue();
````
Es wird eine Liste erzeugt danach werden Elemente in die Liste eingefügt und dann wird die 
Liste zerstört um zu testen ob dies einwandfrei funktionert hat. 

<h3>Laufzeiten</h3>
</p>Es wurde mit einem i7 2.8Ghz und 8Gb Ram getestet</p>
<table>
    <tr>
        <th>Anzahl der Elemente</th>
        <th>Zeit einfügen in Sekunden</th>
        <th>Zeit herausnehmen in Sekunden</th>
    </tr>
    <tr>
        <td>10.000</td>
        <td>0.20</td>
        <td>0.00</td>
    </tr>
    <tr>
        <td>20.000</td>
        <td>0.98</td>
        <td>0.00</td>
    </tr>
    <tr>
        <td>30.000</td>
        <td>2.53</td>
        <td>0.00</td>
    </tr>
    <tr>
        <td>40.000</td>
        <td>4.32</td>
        <td>0.00</td>
    </tr>
    <tr>
        <td>50.000</td>
        <td>6.96</td>
        <td>0.00</td>
    </tr>
    <tr>
        <td>60.000</td>
        <td>10.31</td>
        <td>0.01</td>
    </tr>
    <tr>
        <td>70.000</td>
        <td>14.21</td>
        <td>0.01</td>
    </tr>
    <tr>
        <td>80.000</td>
        <td>19.64</td>
        <td>0.01</td>
    </tr>
    <tr>
       <td>90.000</td>
       <td>24.74</td>
       <td>0.01</td>
    </tr>
    <tr>
        <td>100.000</td>
        <td>29.98</td>
        <td>0.01</td>
    </tr>
</table>