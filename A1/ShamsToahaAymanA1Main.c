#include "givenA1.h"

int main(int argc, char * argv[]) {


//Declaring variables
  struct courseStruct courseInfo[NUMBER_COURSES];
  struct profStruct profInfo[NUMBER_PROFS];
  char profsNCourses[NUMBER_PROFS][MAX_STR];
  char taughtBy[NUMBER_PROFS][MAX_STR];


  int choice;
  int n;
  char courseName [MAX_STR];
  int  cNumFound;
  int value;
  float average;

  char cNameFound[MAX_STR];

//Reading from the files from command prompt using argv[]
  openFileForReading(argv[1]);
  openFileForReading(argv[2]);

  readCourse(argv[1], courseInfo);

  readProfAndCoursesTaught(argv[2], profInfo, courseInfo);



//loop to choose again if you want
  for (int i = 0; i<100; i++){

    printf("Enter choice between 4 to 7:");
    scanf("%d", &choice);

    switch(choice){

      case 4:
        printf("Enter the number of courses:");
        scanf("%d", &n);
        value = nCourses(n, profInfo, profsNCourses);

        printf("%d", value);
        printf("\n");
        break;

      case 5:
        printf("Enter the course number:");
        scanf("%d", &n);
        value = getCourseName(n, cNameFound, courseInfo);
        if(value != 0){
          printf("Course Found: %d", value);
        }
        else{
          printf("Course not found:");
        }

        printf("\n");
        break;


      case 6:
        printf("Enter the course name:");
        getchar();

        fgets(courseName, MAX_STR, stdin);
        courseName[strlen(courseName) - 1] = '\0';
        value = getCourseNum(courseName, &cNumFound, courseInfo);


        if (value == 1){

          printf("Course ID Found: %d\n", value);
       }

        if (value == 0){
          printf("Course ID  was not found");
        }


        break;

      case 7:
        printf("Enter the course number:");
        scanf("%d", &n);
        value = profsTeachingCourse(n, profInfo, taughtBy);


        if(value > 0){
         printf("%d", value);
        }
        else {
         printf("not founf");
        }


        printf("\n");
        break;
        }



//a way for the loop to end
  if ((choice > 7) || (choice < 4)){

    i = 1000;
  }

  }

  average = avgNumCourses(profInfo);
  printf("Average: %.1f", average);

  return 0;

}
