#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktura reprezentująca studenta
struct Student {
    char imie[50];
    char nazwisko[50];
    int rok_urodzenia;
};

// Struktura reprezentująca element stosu
struct Node {
    struct Student student;
    struct Node* next;
};

// Struktura reprezentująca stos (LIFO) z głową
struct Stack {
    struct Node* top;
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

// Funkcja do dodawania elementu na stos
void dodaj_element(struct Stack* stack) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Blad alokacji pamieci.\n");
        return;
    }

    printf("Podaj imie studenta: ");
    scanf_s("%s", newNode->student.imie,sizeof(newNode->student.imie));

    printf("Podaj nazwisko studenta: ");
    scanf_s("%s", newNode->student.nazwisko,sizeof(newNode->student.nazwisko));

    printf("Podaj rok urodzenia studenta: ");
    scanf_s("%d", &newNode->student.rok_urodzenia);

    newNode->next = stack->top;
    stack->top = newNode;

    printf("Dodano studenta na stos.\n");
}

// Funkcja do pobierania elementu ze stosu
void pobierz_element(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stos jest pusty.\n");
        return;
    }

    struct Node* temp = stack->top;
    stack->top = temp->next;

    printf("Pobrano studenta ze stosu: Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
        temp->student.imie,
        temp->student.nazwisko,
        temp->student.rok_urodzenia);

    free(temp);

    if (stack->top == NULL) {
        printf("Stos jest teraz pusty.\n");
    }
}

// Funkcja do wyszukiwania elementu po nazwisku na stosie
void wyszukaj_element(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stos jest pusty.\n");
        return;
    }

    char szukane_nazwisko[50];
    printf("Podaj nazwisko do wyszukania: ");
    scanf_s("%s", szukane_nazwisko,sizeof(szukane_nazwisko));

    struct Node* current = stack->top;
    while (current != NULL) {
        if (strcmp(current->student.nazwisko, szukane_nazwisko) == 0) {
            printf("Znaleziono studenta: Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
                current->student.imie,
                current->student.nazwisko,
                current->student.rok_urodzenia);
            return;
        }
        current = current->next;
    }

    printf("Nie znaleziono studenta o nazwisku %s.\n", szukane_nazwisko);
}

// Funkcja do wypisywania wszystkich elementów na stosie
void wypisz_elementy(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stos jest pusty.\n");
        return;
    }

    struct Node* current = stack->top;
    printf("Elementy na stosie:\n");
    while (current != NULL) {
        printf("Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
            current->student.imie,
            current->student.nazwisko,
            current->student.rok_urodzenia);
        current = current->next;
    }
}

// Funkcja do sprawdzania liczby elementów na stosie
void sprawdz_liczbe_elementow(struct Stack* stack) {
    int liczba_elementow = 0;
    struct Node* current = stack->top;
    while (current != NULL) {
        liczba_elementow++;
        current = current->next;
    }
    printf("Liczba elementow na stosie: %d\n", liczba_elementow);
}

// Funkcja do usuwania całej struktury (zwolnienie pamięci)
void usun_cala_strukture(struct Stack* stack) {
    struct Node* current = stack->top;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;

    printf("Usunieto cala strukture (wszystkie elementy).\n");
}

int main() {
    struct Stack stos = { NULL };
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
        scanf_s("%d", &wybor);

        switch (wybor) {
        case DODAJ_ELEMENT:
            dodaj_element(&stos);
            break;
        case POBIERZ_ELEMENT:
            pobierz_element(&stos);
            break;
        case WYSZUKAJ_ELEMENT:
            wyszukaj_element(&stos);
            break;
        case WYPISZ_ELEMENTY:
            wypisz_elementy(&stos);
            break;
        case SPRAWDZ_LICZBE_ELEMENTOW:
            sprawdz_liczbe_elementow(&stos);
            break;
        case USUN_CALA_STRUKTURE:
            usun_cala_strukture(&stos);
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
