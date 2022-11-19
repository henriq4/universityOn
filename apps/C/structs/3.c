#include <stdio.h>

typedef struct {
  char name[30];
  int age;
  char sex;
  char civil_status;
  int quantity_friends;
  int quantity_pictures;
} user;

int main() {
  int quantity_users;

  printf("Deseja cadastrar quantos usuários? ");
  scanf("%d", &quantity_users);

  user users[quantity_users];

  for (int i = 0; i < quantity_users; i++) {
    printf("name: ");
    fgets(users[i].name, sizeof(users[i].name), stdin);

    printf("age: ");
    scanf("%d", &users[i].age);

    printf("sex: ");
    scanf(" %c", &users[i].sex);

    printf("civil status: ");
    scanf(" %c", &users[i].civil_status);

    printf("quantity friends: ");
    scanf("%d", &users[i].quantity_friends);

    printf("quantity pictures: ");
    scanf("%d", &users[i].quantity_pictures);

    printf("\n");
  }

  printf("Database: \n");

  for (int i = 0; i < quantity_users; i++) {
    printf("\tname: %s\n", users[i].name);

    printf("\tage: %d\n", &users[i].age);

    printf("\tsex: %c\n", &users[i].sex);

    printf("\tcivil status: %c\n", &users[i].civil_status);

    printf("\tquantity friends: %d\n", &users[i].quantity_friends);

    printf("\tquantity pictures: %d\n", &users[i].quantity_pictures);

    printf("\n");
  }
}
