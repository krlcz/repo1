#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Struktura reprezentująca studenta
struct Student {
    char imie[50];
    char nazwisko[50];
    int rok_urodzenia;
};

// Struktura reprezentująca stos (LIFO)
struct Stack {
    struct Student elements[MAX_STACK_SIZE];
    int top;
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
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stos jest pelny. Nie mozna dodac elementu.\n");
        return;
    }

    printf("Podaj imie studenta: ");
    scanf_s("%s", stack->elements[++stack->top].imie, 50*sizeof(char));

    printf("Podaj nazwisko studenta: ");
    scanf_s("%s", stack->elements[stack->top].nazwisko, 50 * sizeof(char));

    printf("Podaj rok urodzenia studenta: ");
    scanf_s("%d", &stack->elements[stack->top].rok_urodzenia);

    printf("Dodano studenta na stos.\n");
}

// Funkcja do pobierania elementu ze stosu
void pobierz_element(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stos jest pusty.\n");
        return;
    }

    printf("Pobrano studenta ze stosu: Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
        stack->elements[stack->top].imie,
        stack->elements[stack->top].nazwisko,
        stack->elements[stack->top].rok_urodzenia);

    stack->top--;

    if (stack->top == -1) {
        printf("Stos jest teraz pusty.\n");
    }
}

// Funkcja do wyszukiwania elementu po nazwisku na stosie
void wyszukaj_element(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stos jest pusty.\n");
        return;
    }

    char szukane_nazwisko[50];
    printf("Podaj nazwisko do wyszukania: ");
    scanf_s(" %s", szukane_nazwisko,sizeof(szukane_nazwisko));

    for (int i = stack->top; i >= 0; i--) {
        if (strcmp(stack->elements[i].nazwisko, szukane_nazwisko) == 0) {
            printf("Znaleziono studenta: Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
                stack->elements[i].imie,
                stack->elements[i].nazwisko,
                stack->elements[i].rok_urodzenia);
            return;
        }
    }

    printf("Nie znaleziono studenta o nazwisku %s.\n", szukane_nazwisko);
}

// Funkcja do wypisywania wszystkich elementów na stosie
void wypisz_elementy(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stos jest pusty.\n");
        return;
    }

    printf("Elementy na stosie:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("Imie: %s, Nazwisko: %s, Rok urodzenia: %d\n",
            stack->elements[i].imie,
            stack->elements[i].nazwisko,
            stack->elements[i].rok_urodzenia);
    }
}

// Funkcja do sprawdzania liczby elementów na stosie
void sprawdz_liczbe_elementow(struct Stack* stack) {
    printf("Liczba elementow na stosie: %d\n", stack->top + 1);
}

// Funkcja do usuwania całej struktury (zwolnienie pamięci)
void usun_cala_strukture(struct Stack* stack) {
    stack->top = -1;

    printf("Usunieto cala strukture (wszystkie elementy).\n");
}

int main() {
    struct Stack stos = {.top = -1 };
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
