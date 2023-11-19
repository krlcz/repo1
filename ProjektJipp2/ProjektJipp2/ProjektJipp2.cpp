
#include <stdio.h>
#include <string.h>



int main() {
    char tekst[500]; 
    char znak;
    char pozycje[500];
    int i = 0;
    int j=0;
    printf("Podaj przykladowy tekst: \n");
    
    fgets(tekst, sizeof(tekst), stdin);
    tekst[strlen(tekst) - 1] = 0;

    
    
    printf("Podaj znak ktorego chcesz znac pozycje: \n");
    scanf_s("%c", &znak);
    
    while (tekst[i] != '\0') {
        if (tekst[i] == znak) {
            pozycje[j] = i;
            j++;
        }
        i++;
    }
    int decyzja;
    printf("Podaj 1 jesli chcesz pierwsze wystapienie znaku lub -1 jesli ostatnie: \n");
    scanf_s("%d", &decyzja);
    




    if (j == 0) {
        printf("Znak '%c' nie zostal znaleziony w tekscie.\n", znak);
    }
    else if (decyzja == 1) {
        printf("pierwsze wystapienie znaku '%c' to %d\n", znak,pozycje[0]);

    }
    else if (decyzja == -1) {
        printf("ostatnie wystapienie znaku '%c' to %d\n", znak, pozycje[j - 1]);
    }

    return 0;
}