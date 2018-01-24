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

    shuffle(operations, m);
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

    clock_t end = clock();

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

    return 0;
}
