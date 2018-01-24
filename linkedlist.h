#include <stdio.h>
#include <stdlib.h>

struct list_node_s{
  int data;
  struct list_node_s *next;
};

int member(int value, struct list_node_s *head_p){
  struct list_node_s *curr_p = head_p;

  while (curr_p != NULL && curr_p -> data != value) {
    curr_p = curr_p -> next;
  }

  if(curr_p != NULL){
    return 0;
  }else{
    return 1;
  }
}

void insert(int value, struct list_node_s *head_p) {
  struct list_node_s *curr_p = head_p;

  if(curr_p == NULL){
    curr_p = malloc(sizeof(struct list_node_s));
    curr_p -> data = value;
    return;
  }

  while (curr_p -> next != NULL) {
    curr_p = curr_p -> next;
  }

  struct list_node_s *new_node = malloc(sizeof(struct list_node_s));
  new_node -> data = value;
  new_node -> next = NULL;
  curr_p -> next = new_node;

}

void delete(int value, struct list_node_s *head_p) {
  struct list_node_s *curr_p = head_p;
  struct list_node_s *pre_p;

  while (curr_p != NULL && curr_p -> data != value) {
    pre_p = curr_p;
    curr_p = curr_p -> next;
  }
  if(curr_p != NULL) {
    pre_p -> next = curr_p -> next;
    free(curr_p);
  }
}

void printList(struct list_node_s *head_p){
  struct list_node_s *curr_p = head_p;
  printf("start \n");
  while (curr_p != NULL) {
    printf("%d, ", curr_p -> data);
    curr_p = curr_p -> next;
  }
  printf("\n");
}
