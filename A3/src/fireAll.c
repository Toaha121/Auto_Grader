#include "../include/headerA3.h"

// function 9
void fireAll(a3Emp **headLL) {
  char answer;
  printf("\nAre you sure you want to fire everyone? (y/n):");
  scanf(" %c", &answer);

  if (answer == 'y') {
    a3Emp *emp = *headLL;
    while (emp != NULL) {
      a3Emp *temp = emp;
      emp = emp->nextEmployee;
      free(temp->dependents);
      free(temp);
    }
    *headLL = NULL;
    printf("All fired. Linked list is now empty.\n\n");
  }
}
