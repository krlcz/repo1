#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktura reprezentująca studenta
struct Student {
    char imie[50];
    char nazwisko[50];
    int rok_urodzenia;
};

// Struktura reprezentująca element kolejki
struct Node {
    struct Student student;
    struct Node* next;
};

// Struktura reprezentująca kolejkę FIFO
struct Queue {
    struct Node* front;
    struct Node* rear;
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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Blad alokacji pamieci.\n");
        return;
    }

    printf("Podaj imie studenta: ");
    scanf_s(" %s", newNode->student.imie,sizeof(newNode->student.imie));

    printf("Podaj nazwisko studenta: ");
    scanf_s(" %s", newNode->student.nazwisko,sizeof(newNode->student.nazwisko));

    printf("Podaj rok urodzenia studenta: ");
    scanf_s(" %d", &newNode->student.rok_urodzenia);

    newNode->next = NULL;

    if (queue->rear == NULL) {
        // Kolejka jest pusta
        queue->front = queue->rear = newNode;
    }
    else {
        // Dodaj na koniec kolejki
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Dodano studenta do kolejki.\n");
}

// Funkcja do pobierania elementu z kolejki
void pobierz_element(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kolejka jest pusta.\n");
        return;
    }

    struct Node* temp = queue->front;
    queue->front = temp->next;

    free(temp);

    printf("Pobrano studenta z kolejki.\n");
}

// Funkcja do wyszukiwania elementu po nazwisku
void wyszukaj_element(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kolejka jest pusta.\n");
        return;
    }

    char szukane_nazwisko[50];
    printf("Podaj nazwisko do wyszukania: ");
    scanf_s("%s", szukane_nazwisko,sizeof(szukane_nazwisko));

    struct Node* current = queue->front;
    while (current != NULL) {
        if (strcmp(current->student.nazwisko, szukane_nazwisko) == 0) {
            printf("Znaleziono studenta: Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
                current->student.imie, current->student.nazwisko, current->student.rok_urodzenia);
            return;
        }
        current = current->next;
    }

    printf("Nie znaleziono studenta o nazwisku %s.\n", szukane_nazwisko);
}

// Funkcja do wypisywania wszystkich elementów kolejki
void wypisz_elementy(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kolejka jest pusta.\n");
        return;
    }

    struct Node* current = queue->front;
    while (current != NULL) {
        printf("Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
            current->student.imie, current->student.nazwisko, current->student.rok_urodzenia);
        current = current->next;
    }
}

// Funkcja do sprawdzania liczby elementów w kolejce
void sprawdz_liczbe_elementow(struct Queue* queue) {
    int liczba_elementow = 0;
    struct Node* current = queue->front;
    while (current != NULL) {
        liczba_elementow++;
        current = current->next;
    }
    printf("Liczba elementow w kolejce: %d\n", liczba_elementow);
}

// Funkcja do usuwania całej struktury (zwolnienie pamięci)
void usun_cala_strukture(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    queue->front = queue->rear = NULL;

    printf("Usunieto cala strukture (wszystkie elementy).\n");
}

int main() {
    struct Queue kolejka = { NULL, NULL };
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
