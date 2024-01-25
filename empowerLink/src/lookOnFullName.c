#include "../include/headerA3.h"

// function 5
int lookOnFullName(struct employee *headLL, char whichName[100]) {
  struct employee *emp = headLL;
  int position = 0;
  while (emp != NULL) {
    if (strcmp(emp->fname, whichName) == 0) {
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
  printf("Employee not found.\n");
  return -1;
}
