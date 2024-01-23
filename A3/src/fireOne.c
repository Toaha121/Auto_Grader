#include "../include/headerA3.h"

void fireOne(a3Emp **headLL, int whichOne) {
  if (*headLL == NULL) {
    printf("List empty\n\n");
    return;
  }

  a3Emp *current = *headLL;
  a3Emp *previous = NULL;
  int pos = 0;

  for (int i = 1; i != whichOne; i++) {
    if (current->nextEmployee == NULL) {
      return;
    }
    previous = current;
    current = current->nextEmployee;
  }

  if (previous == NULL) {
    *headLL = current->nextEmployee;
  }

  else {
    previous->nextEmployee = current->nextEmployee;
  }

  printf("Employee [Id: %d] fired.\n", current->empId);
  free(current);
}

