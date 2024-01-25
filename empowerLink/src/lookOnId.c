#include "../include/headerA3.h"


// function 4
int lookOnId(struct employee *headLL, int whichEmpId) {
  int position = 1;
  struct employee *emp = headLL;
  while (emp != NULL) {
    if (emp->empId == whichEmpId) {
      printf("Employee id: %d\n", emp->empId);
      printf("First name: %s\n", emp->fname);
      printf("Last name: %s\n", emp->lname);
      printf("Dependents: ");
      for (int i = 0; i < emp->numDependents; i++) {
        printf("%s", emp->dependents[i]);
        if (i != emp->numDependents - 1) {
          printf(", ");
        }
      }
      printf("\n\n");
      return position;
    }
    emp = emp->nextEmployee;
    position++;
  }
  printf("Employee with id %d not found.\n", whichEmpId);
  return -1;
}

