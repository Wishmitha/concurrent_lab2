#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>
#include "linkedlist.h"
#include "timer.h"
#include "shuffler.h"

long t_count = 0;
pthread_rwlock_t rwlock;
struct list_node_s *head = NULL;

int n, m;
float member_percentage, insert_percentage, delete_percentage;
int * operations;

void *pthread_execution(void *t_id) {

    long my_tid = (long)t_id;
    int op_per_theread = m/t_count;
    srand(clock());

    for (int i = my_tid*op_per_theread; i < (my_tid+1)*op_per_theread; i++) {
      int value = rand() % 65536;
      if(operations[i] == 0){
        pthread_rwlock_rdlock(&rwlock);
        member(value, head);
        pthread_rwlock_unlock(&rwlock);
      } else if(operations[i] == 1) {
        pthread_rwlock_wrlock(&rwlock);
        insert(value, head);
        pthread_rwlock_unlock(&rwlock);
      } else {
        pthread_rwlock_wrlock(&rwlock);
        delete(value, head);
        pthread_rwlock_unlock(&rwlock);
      }
    }
    return NULL;
}

float lock_execution(int argc, char *argv[]) {
  long t_id;
  pthread_t *t_handler;

  struct list_node_s *head = malloc(sizeof(struct list_node_s));

  srand(clock());
  for (int i=0; i < n; i++) {
      int value = rand() % 65536;
      insert(value, head);
  }

  operations = malloc (m* sizeof(int));

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
  t_handler = (pthread_t *) malloc(t_count * sizeof(pthread_t));
  clock_t init = clock();

  pthread_rwlock_init(&rwlock, NULL);

  for (t_id = 0; t_id < t_count; t_id++) {
      pthread_create(&t_handler[t_id], NULL, pthread_execution, (void*)t_id);
  }
  for (t_id = 0; t_id < t_count; t_id++) {
      pthread_join(t_handler[t_id], NULL);
  }

  pthread_rwlock_destroy(&rwlock);

  clock_t end = clock();
  return (double)(end - init) / CLOCKS_PER_SEC;
}

int main(int argc, char *argv[]) {

    const int no_of_tests = 15;

    if(argc == 7){
      t_count = (int) strtol(argv[1], (char **) NULL, 10);
      n = (int) strtol(argv[2], (char **) NULL, 10);
      m = (int) strtol(argv[3], (char **) NULL, 10);

      member_percentage = (float) atof(argv[4]);
      insert_percentage = (float) atof(argv[5]);
      delete_percentage = (float) atof(argv[6]);

      for (int i = 0; i < no_of_tests; i++) {
          float time = lock_execution(argc, argv);
          printf("%.10f\n", time);
      }

    }else{
      printf("Error : Insufficient Number Parameters.\n");
    }

    return 0;

}
