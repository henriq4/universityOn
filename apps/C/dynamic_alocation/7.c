#include <stdio.h>
#include <stdlib.h>

#define LEN 2

struct Book {
  int code;
  char title[50];
  char author[50];
  char grade[150];
};

int search_book(struct Book *book1, struct Book *book2) {
  if (book1->code == book2->code) {
    return 1;
  }

  return 0;
}

int main() {
  int num_books = LEN;

  struct Book *books;

  books = (struct Book *)malloc(num_books * sizeof(struct Book));

  for (int i = 0; i < LEN; i++) {
    printf("Digite o código: ");
    scanf("%d", &(books + i)->code);

    printf("Digite o título: ");
    fgets((books + i)->title, 50, stdin);

    printf("Digite o autor: ");
    fgets((books + i)->author, 50, stdin);

    printf("Digite o assunto: ");
    fgets((books + i)->grade, 150, stdin);

    printf("**\n");
  }

  int result = search_book(books, books + 1);

  if (result == 1) {
    printf("Os livros são iguais\n");

    return 0;
  }

  printf("Os livros são diferentes\n");

  return 0;
}
