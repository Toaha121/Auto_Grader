#include "a1.h"

int main(int argc, char argv) {

  struct courseStruct courseInfo[NUMBER_COURSES];
  struct profStruct profInfo[NUMBER_PROFS];

  FILE *fptr = penFileForReading(argv[1]); // better to call in task 2 instead of main

  int task2 = readCourse(argv[1], courseInfo);

  /*how to test

  printf("Course name reads:");
  for (int i = 0; i < NUMBER_COURSES; i++){

      printf("%s \n", courseInfo [i], courseName);
      printf("%d \n", courseInfo [i], courseID);

  }*/

  do {

    printf("4. task4 -....\n");
    printf("5. task4 -....\n");
    printf("6. task4 -....\n");
    printf("7. task4 -....\n");
    printf("8. task4 -....\n");

    printf("Enter your choice: ");
    scanf("%d", &whichTask);
  }

  return 0;
}
