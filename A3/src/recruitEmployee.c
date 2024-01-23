#include "../include/headerA3.h"

// function 1
void recruitEmployee(struct employee **headLL) {

  int num;
  int lastSum;
  int empId;
  struct employee *newEmployee = malloc(sizeof(struct employee));
  struct employee *currEmployee = *headLL;
  struct employee *lastEmployee = *headLL;

  printf("\nEnter first name: ");
  scanf("%s", newEmployee->fname);

  printf("Enter last name: ");
  scanf("%s", newEmployee->lname);

  // Calculate the employee's ID
  num = 0;
  for (int i = 0; i < strlen(newEmployee->fname); i++) {
    num = num + (int)newEmployee->fname[i];
  }
  lastSum = strlen(newEmployee->lname);
  empId = num + lastSum;

  // checking if id exist
  while (currEmployee != NULL) {
    if (currEmployee->empId == empId) {
      empId = empId + rand() % 999 + 1; // add a random suffix to the ID
      currEmployee =
          *headLL; // restart the search from the beginning of the list
    }

    else {
      currEmployee = currEmployee->nextEmployee;
    }
  }
  newEmployee->empId = empId;

  // dependent
  newEmployee->numDependents = 0;
  char response = 'y';
  while (response == 'y') {

    printf("Enter name of dependent #%d: ", newEmployee->numDependents + 1);

    newEmployee->dependents = realloc(newEmployee->dependents, (newEmployee->numDependents + 1) * sizeof(char *));
    newEmployee->dependents[newEmployee->numDependents] = malloc(MAX_LENGTH * sizeof(char));
    scanf("%s", newEmployee->dependents[newEmployee->numDependents]);
    newEmployee->numDependents++;

    printf("Do you have any more dependents? ");
    scanf(" %c", &response);
  }
  printf("Number of dependents:%d\n", newEmployee->numDependents);

  // Adding the new employee to the end of the linked list
  newEmployee->nextEmployee = NULL;
  if (*headLL == NULL) {
    *headLL = newEmployee;
  } else {
    while (lastEmployee->nextEmployee != NULL) {
      lastEmployee = lastEmployee->nextEmployee;
    }
    lastEmployee->nextEmployee = newEmployee;
  }

  printf("Your computer generated Id is:%d\n", empId);
}

