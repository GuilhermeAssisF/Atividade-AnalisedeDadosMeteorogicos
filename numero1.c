#include <stdio.h>
#include <stdlib.h>
#include "matrizLib.h"

int main()
{
    int m[100][100], i, j, linhas = 30, cols = 2, medMax = 0, medMin = 0, ampl = 0, amplMax = 0, dia = 0, ampldia = 0, tempMin = 0;

    srand(time(NULL));

    // temperatura maxima
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < 1; j++)
        {
            m[i][j] = (rand() % 10) + 30;
            medMax += m[i][j];
        }
    }

    // temperatura minima
    for (i = 0; i < linhas; i++)
    {
        for (j = 1; j < 2; j++)
        {
            m[i][j] = rand() % (m[i][j - 1]);
            medMin = medMin + m[i][j];
            if (m[i][j] < 10)
            {
                tempMin += 1;
            }
        }
    }

    printf("        Max| Min|\n");
    for (i = 0; i < linhas; i++)
    {
        printf("Dia %d -", i + 1);
        for (j = 0; j < cols; j++)
            printf("%3d |", m[i][j]);
        printf("\n");
    } // fim for i
    printf("\n");

    printf("A media da temperatura maxima este mes e de %d graus celsius.\n", medMax / linhas);
    printf("\nA media da temperatura minima este mes e de %d graus celsius.\n", medMin / linhas);

    for (i = 0; i < linhas; i++)
    {
        dia = i;
        for (j = 0; j < 1; j++)
        {
            ampl = m[i][0] - m[i][1];
            if (ampl > amplMax)
            {
                amplMax = ampl;
                ampldia = dia + 1;
            }
        }
    }

    printf("\nNo dia %d foi registrada a maior amplitude termica que alcancou os %d graus celsius.\n", ampldia, amplMax);
    printf("\nA temperatura minima ficou abaixo dos 10 graus celsius %d dias do mes.\n", tempMin);
    return 0;
}
