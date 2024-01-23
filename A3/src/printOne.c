#include "../include/headerA3.h"


// function 3
void printOne(struct employee *headLL, int whichOne) {
  if (headLL == NULL) {
    printf("There are no employees to print.\n");
  }
  int count = 1;
  struct employee *emp = headLL;
  while (emp != NULL) {
    if (count == whichOne) {
      printf("\nEmployee id: %d\n", emp->empId);
      printf("First name: %s\n", emp->fname);
      printf("Last name: %s\n", emp->lname);
      printf("Dependents: ");
      for (int i = 0; i < emp->numDependents; i++) {
        printf("%s", emp->dependents[i]);
        if (i < emp->numDependents - 1) {
          printf(", ");
        }
      }
      printf("\n\n");
      return;
    }
    emp = emp->nextEmployee;
    count++;
  }
  printf("Position doesn't exist.\n\n");
}
