#include <stdio.h>

#define MAX_PEOPLE 100

struct People {
  char hair_color; // l - loiro, p - preto, c - castanho, r - ruivo
  char eye_color;  // a - azul, v - verde, c - castanho, p - preto
  char sex;        // m - masculino, f - feminino
  int age;
} peoples[MAX_PEOPLE];

void main() {
  int yougest_people_pos = 0;
  int women_bet_18_35_blonde_hair_green_eyes_count = 0;

  for (int i = 0; i < MAX_PEOPLE; i++) {
    printf("Digite o cabelo da pessoa %d: ", i + 1);
    scanf("%c", &peoples[i].hair_color);

    printf("Digite os olhos da pessoa %d: ", i + 1);
    scanf("%c", &peoples[i].eye_color);

    printf("Digite o sexo da pessoa %d: ", i + 1);
    scanf("%c", peoples[i].sex);

    printf("Digite a idade da pessoa %d: ", i + 1);
    scanf("%d", &peoples[i].age);

    if (peoples[i].age < peoples[yougest_people_pos].age) {
      yougest_people_pos = i;
    }
  }

  for (int i = 0; i < MAX_PEOPLE; i++) {
    if (peoples[i].sex == "f") {
      if (peoples[i].hair_color == "l") {
        if (peoples[i].eye_color == "v") {
          if (peoples[i].age >= 18 && peoples[i].age <= 35) {
            women_bet_18_35_blonde_hair_green_eyes_count++;
          }
        }
      }
    }
  }

  float avarage_w =
      (float)women_bet_18_35_blonde_hair_green_eyes_count / (float)MAX_PEOPLE;
  printf("A percentagem de mulheres com cabelo loiro, olhos verdes e com idade "
         "entre 18 e 35 anos é de %.2f\n",
         avarage_w);

  printf("A pessoa mais nova tem %d anos de idade\n",
         peoples[yougest_people_pos].age);
}
