#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "shuffler.h"

int n, m;
float member_percentage, insert_percentage, delete_percentage;

long i;
long my_m;

float serial_execution() {

    struct list_node_s *head = malloc(sizeof(struct list_node_s));
    srand(clock());
    for (int i=0; i < n; i++) {
        int value = rand() % 65536;
        insert(value, head);
    }
    int operations[m];

    for (int i = 0; i < m; i++) {
      if(i < (int)m*member_percentage) {
        operations[i] = 0;
      } else if (i < (int)m*(member_percentage + insert_percentage)) {
        operations[i] = 1;
      } else {
        operations[i] = 2;
      }
    }

    //
    // printf("%f, %f, %f \n", member_percentage, insert_percentage, delete_percentage);
    // int n =  sizeof(operations)/ sizeof(operations[0]);
    shuffle(operations, m);
    // printArray(operations, m);
    // printList(head);
    clock_t init = clock();

    srand(clock());

    for (int i = 0; i < m; i++) {
        int value = rand() % 65536;
        if(operations[i] == 0){
          member(value, head);
        } else if(operations[i] == 1) {
          insert(value, head);
        } else {
          delete(value, head);
        }
    }

    printf("end :");
    // printList(head);

    clock_t end = clock();

    //printf("%d\n", head -> data);
    // printList(head);

    return (double)(end - init) / CLOCKS_PER_SEC;
}


int main(int argc, char *argv[]) {
    const int no_of_tests = 15;

    if(argc == 6){
      n = (int) strtol(argv[1], (char **) NULL, 10);
      m = (int) strtol(argv[2], (char **) NULL, 10);

      member_percentage = (float) atof(argv[3]);
      insert_percentage = (float) atof(argv[4]);
      delete_percentage = (float) atof(argv[5]);

      for (int i = 0; i < no_of_tests; i++) {
          float time = serial_execution();
          printf("%.10f\n", time);
      }

    }else{
      printf("Error : Insufficient Number Parameters.\n");
    }


    // int a[10] = {1,2,3,4,6,7,8,9,0};
    // int z =  sizeof(a)/ sizeof(a[0]);
    // shuffle(a, z);
    // printArray(a, z);
    // printf("end \n");
    //


    // struct list_node_s *head = malloc(sizeof(struct list_node_s));
    //
    //
    // for (int i=0; i < 10; i++) {
    //     int value = rand() % 65536;
    //     insert(value, head);
    // }
    // printList(head);
    return 0;
}
