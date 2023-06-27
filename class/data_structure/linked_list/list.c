#include "helpers.h"
#include <string.h>

// Define linked list struct
struct List{
    int info;
    struct List* next;
};

// starts/ creates the linked list
List* create_list(){
    return NULL;
}

// insert a value to the list
List* insert_list(List* list, int value){
    List* new = (List*) malloc(sizeof(List));
    new->info = value;
    new->next = list;
    return new;
}

// print each item of the list
void print_list(List* list){
    List* p;
    for(p = list; p != NULL; p = p->next){
        printf("info =  %d\n", p->info);
    }
}

// verifies if the list is empty
int empty_list(List* list){
    return (list == NULL);
}

// search for an element in the list
List* search(List* list, int v){
    List* p;
    for(p = list; p != NULL; p = p->next){
        if(p->info == v){
            return p;
        }
    }
    return NULL;
}

// remove item from the list
List* remove_item(List* list, int val){
    List* prev = NULL; //pointer to the previus element;
    List* p = list; // pointer to run thought the list
    // search for the item in the list
    while(p != NULL && p->info != val){
        prev = p;
        p = p->next;
    }
    //verifies if found the item
    if(p == NULL){
        return list;
        // if didnt find, returns the original list
    }
    if(prev == NULL){
        //removes the item in the start of the list
        list = p->next;
    }
    else{
        // removes the item in the middle of the list
        prev->next = p->next;
    }
    free(p);
    return list;
}

//liberate list
void liberate_list(List* list){
    List* t;
    List* p = list;
    while(p != NULL){
        t = p->next; // stores the reference to the next element
        free(p); // free the memory pointed to p
        p = t; // makes p point to the next
    }
}

// insert ordenate
List* ordenate_insert(List* list, int val){
    List* new;
    List* prev = NULL; // pointer to the previous item
    List* p = list; // pointer to run thought the list

    //search the position to insert the item
    while(p != NULL && p->info < val){
        prev = p;
        p = p->next;
    }
    // create new element
    new = (List*) malloc(sizeof(List));
    new->info = val;
    //link the new element
    if(prev == NULL){
        new->next = list;
        list = new;
    }
    else{
        //insert the element in the middle/ final of the list
        new->next = prev->next;
        prev->next = new;
    }
    return list;
}

int equality_lists(List* list1, List* list2){
    List* p1; // pointer to run thought the list 1
    List* p2; // pointer to run thought the list 2

    for(p1 = list1, p2 = list2;
        p1 != NULL && p2 != NULL;
        p1 = p1->next, p2 = p2->next){
            if(p1->info != p2->info){
                return 0;
            }
        }
    return p1 == p2;
}
