#include <stdio.h>

int main(void)
{
    int num1, num2, num3;
    int avarage;

    int avarage_more = 0;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("Digite o terceiro número: ");
    scanf("%d", &num3);

    avarage = ((num1 + num2 + num3) / 3);

    if (num1 > avarage)
    {
        avarage_more++;
    }

    if (num2 > avarage)
    {
        avarage_more++;
    }

    if (num3 > avarage)
    {
        avarage_more++;
    }

    printf("%d estão acima da média: \n", avarage_more);
}