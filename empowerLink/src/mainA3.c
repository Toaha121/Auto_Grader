#include "../include/headerA3.h"


int main() {

  int code;
  char ans = 'y';
  char fullName[100];
  int whichone;
  int whichone1;
  int ID;
  struct employee *headLL = NULL; // Initialize headLL to NULL

  while (ans == 'y') {

    char ans1 = 'y';

    printf("1. Add a new employee\n");
    printf("2. Print data of all employees\n");
    printf("3. Print data of the nth employee\n");
    printf("4. Search for employee based on empId\n");
    printf("5. Search for employee based on full name\n");
    printf("6. Count the total number of employees\n");
    printf("7. Sort the employees based on their empId\n");
    printf("8. Remove the nth employee in the current LL\n");
    printf("9. Remove all employees in the current LL\n");
    printf("10. Exit\n");
    printf("Enter 1 to 10: ");
    scanf(" %d", &code);

    switch (code) {

    case 1:

      // struct employee *headLL = NULL; // Initialize headLL to NULL

      while (ans1 == 'y') {
        recruitEmployee(&headLL);
        printf("Do you wish to continue: ");
        scanf(" %c", &ans1); // Add a space before %c to discard any leftover
                             // newline characters
        printf("\n");
      }
      break;

    case 2:
      printf("\n\n");
      printAll(headLL);
      break;

    case 3:
      printf("\n\n");
      printf("Which one do you want to print: ");
      scanf("%d", &whichone);
      printOne(headLL, whichone);
      break;

    case 4:

      printf("Enter an Employee Id:");
      scanf("%d", &ID);
      lookOnId(headLL, ID);
      break;

    case 5:
      printf("Enter the full name of the employee: ");
      scanf("%s", fullName);
      lookOnFullName(headLL, fullName);
      break;

    case 6:
      countEmployees(headLL);
      break;

    case 7:
       sortEmployeesId (headLL);
       break;

    case 8:

       countEmployees(headLL);
       printf("Which Employee do you wish to fire? Enter number between 1 and %d: ", countEmployees(headLL));
       scanf("%d", &whichone1);
       fireOne(&headLL, whichone1);
       countEmployees(headLL);
       break;


    case 9:
      fireAll(&headLL);
      break;

    case 10:
      ans = 'n';
      break;
    }
  }

  return 0;
}
