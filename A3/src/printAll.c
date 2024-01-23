#include "../include/headerA3.h"


// function 2
void printAll(struct employee *headLL) {

  struct employee *emp = headLL;
  int count = 1;

  if (headLL == NULL) {
    printf("There are no employees to print.\n");
  }

  while (emp != NULL) {
    printf("\nEmployee # %d:\n", count);
    printf("Employee id: %d\n", emp->empId);
    printf("First name: %s\n", emp->fname);
    printf("Last name: %s\n", emp->lname);
    printf("Dependents [%d]: ", emp->numDependents);
    for (int i = 0; i < emp->numDependents; i++) {
      printf("%s", emp->dependents[i]);
      if (i < emp->numDependents - 1) {
        printf(", ");
      }
    }
    printf("\n\n");
    emp = emp->nextEmployee;
    count++;
  }
  printf("Currently, there are %d employees.\n\n", count - 1);
}



