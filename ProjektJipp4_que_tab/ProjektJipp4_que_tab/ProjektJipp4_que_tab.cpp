#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

// Struktura reprezentująca studenta
struct Student {
    char imie[50];
    char nazwisko[50];
    int rok_urodzenia;
};

// Struktura reprezentująca kolejkę FIFO
struct Queue {
    struct Student elements[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

// Typ wyliczeniowy dla menu
enum MenuOption {
    DODAJ_ELEMENT = 1,
    POBIERZ_ELEMENT,
    WYSZUKAJ_ELEMENT,
    WYPISZ_ELEMENTY,
    SPRAWDZ_LICZBE_ELEMENTOW,
    USUN_CALA_STRUKTURE,
    ZAKONCZ_PROGRAM
};

// Funkcja do dodawania elementu do kolejki
void dodaj_element(struct Queue* queue) {
    if ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front) {
        printf("Kolejka jest pelna. Nie mozna dodac elementu.\n");
        return;
    }

    printf("Podaj imie studenta: ");
    scanf_s(" %s", queue->elements[queue->rear].imie,sizeof(queue->elements[queue->rear].imie));

    printf("Podaj nazwisko studenta: ");
    scanf_s(" %s", queue->elements[queue->rear].nazwisko,sizeof(queue->elements[queue->rear].nazwisko));

    printf("Podaj rok urodzenia studenta: ");
    scanf_s(" %d", &queue->elements[queue->rear].rok_urodzenia);

    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;

    printf("Dodano studenta do kolejki.\n");
}

// Funkcja do pobierania elementu z kolejki
void pobierz_element(struct Queue* queue) {
    if (queue->front == queue->rear) {
        printf("Kolejka jest pusta.\n");
        return;
    }

    printf("Pobrano studenta z kolejki: Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
        queue->elements[queue->front].imie,
        queue->elements[queue->front].nazwisko,
        queue->elements[queue->front].rok_urodzenia);

    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
}

// Funkcja do wyszukiwania elementu po nazwisku
void wyszukaj_element(struct Queue* queue) {
    if (queue->front == queue->rear) {
        printf("Kolejka jest pusta.\n");
        return;
    }

    char szukane_nazwisko[50];
    printf("Podaj nazwisko do wyszukania: ");
    scanf_s(" %s", szukane_nazwisko,sizeof(szukane_nazwisko));

    int current = queue->front;
    while (current != queue->rear) {
        if (strcmp(queue->elements[current].nazwisko, szukane_nazwisko) == 0) {
            printf("Znaleziono studenta: Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
                queue->elements[current].imie,
                queue->elements[current].nazwisko,
                queue->elements[current].rok_urodzenia);
            return;
        }
        current = (current + 1) % MAX_QUEUE_SIZE;
    }

    printf("Nie znaleziono studenta o nazwisku %s.\n", szukane_nazwisko);
}

// Funkcja do wypisywania wszystkich elementów kolejki
void wypisz_elementy(struct Queue* queue) {
    if (queue->front == queue->rear) {
        printf("Kolejka jest pusta.\n");
        return;
    }

    int current = queue->front;
    while (current != queue->rear) {
        printf("Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
            queue->elements[current].imie,
            queue->elements[current].nazwisko,
            queue->elements[current].rok_urodzenia);
        current = (current + 1) % MAX_QUEUE_SIZE;
    }
}

// Funkcja do sprawdzania liczby elementów w kolejce
void sprawdz_liczbe_elementow(struct Queue* queue) {
    int liczba_elementow = (queue->rear - queue->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    printf("Liczba elementow w kolejce: %d\n", liczba_elementow);
}

// Funkcja do usuwania całej struktury (zwolnienie pamięci)
void usun_cala_strukture(struct Queue* queue) {
    queue->front = queue->rear = 0;

    printf("Usunieto cala strukture (wszystkie elementy).\n");
}

int main() {
    struct Queue kolejka = {  0, 0 };
    int wybor;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Dodaj element\n");
        printf("2. Pobierz element\n");
        printf("3. Wyszukaj element\n");
        printf("4. Wypisz elementy\n");
        printf("5. Sprawdz liczbe elementow\n");
        printf("6. Usun cala strukture\n");
        printf("7. Zakoncz program\n");

        printf("Wybierz opcje: ");
        scanf_s(" %d", &wybor);

        switch (wybor) {
        case DODAJ_ELEMENT:
            dodaj_element(&kolejka);
            break;
        case POBIERZ_ELEMENT:
            pobierz_element(&kolejka);
            break;
        case WYSZUKAJ_ELEMENT:
            wyszukaj_element(&kolejka);
            break;
        case WYPISZ_ELEMENTY:
            wypisz_elementy(&kolejka);
            break;
        case SPRAWDZ_LICZBE_ELEMENTOW:
            sprawdz_liczbe_elementow(&kolejka);
            break;
        case USUN_CALA_STRUKTURE:
            usun_cala_strukture(&kolejka);
            break;
        case ZAKONCZ_PROGRAM:
            printf("Zakonczono program.\n");
            return 0;
        default:
            printf("Nieprawidlowy wybor. Wybierz ponownie.\n");
        }
    }

    return 0;
}
