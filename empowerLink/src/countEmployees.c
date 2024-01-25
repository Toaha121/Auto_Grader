#include "../include/headerA3.h"


// function 6
int countEmployees(struct employee *headLL) {
  int count = 0;
  struct employee *emp = headLL;
  while (emp != NULL) {
    count++;
    emp = emp->nextEmployee;
  }

  printf("\nTotal Number of Employees: %d\n\n", count);
  return count;
}
