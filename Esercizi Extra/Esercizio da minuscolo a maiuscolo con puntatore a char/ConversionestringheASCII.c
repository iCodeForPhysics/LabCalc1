#include <stdio.h>
#include <string.h>

void press_key()
{
    double c;
    printf("\nPremi un tasto per continuare...\n");
    getchar();
    while ((c = getchar()) != '\n');
}

int main(void)
{
    int choice;
    char *p;
    char frase[280];
    do
    {
        printf("Benvenuto nel programma di conversione di una frase!\nPremi 1 per convertire da minuscolo a maiuscolo.\nPremi 2 per convertire da maiuscolo a minuscolo.\n");
        scanf("%d", &choice);
        if (choice != 1 && choice != 2)
        {
            printf("\nSei sicuro di quello che stai facendo?\n");
        }
        while ((getchar()) != '\n');
    } while (choice != 1 && choice != 2);

    press_key();

    printf("Adesso inserisci la frase che vuoi convertire . Hai a disposizione un massimo di %ld caratteri(spazi inclusi), come se fosse Twitter.\nSe supererai il limite, i caratteri dopo il 280esimo non verranno considerati.\n", sizeof(frase));
    scanf("%280[^\n]", frase);
    size_t lunghezza = strlen(frase);

    if (choice == 1) // da minuscolo a maiuscolo
    {
        printf("\nEcco la tua frase convertita:\n");
        for (int i = 0; i < lunghezza; i++)
        {
            p = &frase[i];
            *p = (*p >= 'a' && *p <= 'z') ? (*p) - 32 : *p;
        }
        printf("%s\n", frase);
    }

    if (choice == 2) // da maiuscolo a minuscolo
    {
        printf("\nEcco la tua frase convertita:\n");
        for (int i = 0; i < lunghezza; i++)
        {
            p = &frase[i];
            *p = (*p >= 'A' && *p <= 'Z') ? (*p) + 32 : *p;
        }
        printf("%s\n", frase);
    }
}
