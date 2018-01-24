#include <stdio.h>
#include <stdlib.h>

struct list_node_s{
  int data;
  struct list_node_s *next;
};

int member(int value, struct list_node_s *head_p){
  struct list_node_s *current = head_p;
    while (current != NULL && current->data < value)
        current = current->next;

    if (current == NULL || current->data > value) {
        return 0;
    } else {
        return 1;
    }
}

void insert(int value, struct list_node_s *head_p) {
    struct list_node_s *current = head_p;
    struct list_node_s *pred = NULL;
    struct list_node_s *temp;
    while (current != NULL && current->data < value) {
        pred = current;
        current = current->next;
    }
    if (current == NULL || current->data > value) {
        temp = malloc(sizeof(struct list_node_s));
        temp->data = value;
        temp->next = current;
        if (pred == NULL){
          head_p = temp;
        }else{
          pred->next = temp;
        }
    }
}

void delete(int value, struct list_node_s *head_p) {
  struct list_node_s *current = head_p;
    struct list_node_s *pred = NULL;
    while (current != NULL && current->data < value) {
        pred = current;
        current = current->next;
    }
    if (current != NULL && current->data == value) {
        if (pred == NULL) {
            head_p = current->next;
            free(current);
        } else {
            pred->next = current->next;
            free(current);
        }
    }
}

void printList(struct list_node_s *head_p){
  struct list_node_s *curr_p = head_p;
  while (curr_p != NULL) {
    printf("%d, ", curr_p -> data);
    curr_p = curr_p -> next;
  }
  printf("\n");
}
