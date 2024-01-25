#include "givenA1.h"




// part 1
FILE *openFileForReading(char fileName[MAX_STR]) {

  FILE *fptr;
  fptr = fopen(fileName, "r");

  if (fptr == NULL) {

    printf("Error! File not found!");
    return NULL;
  }

  return fptr;
}





// part 2
int readCourse(char filename[MAX_STR],
               struct courseStruct courseInfo[NUMBER_COURSES]) {

  int id;
  int i = 0;
  int j;
  int numLines = 0;
  char name[MAX_STR];

  FILE *fptr;
  fptr = fopen(filename, "r");

//checking if a file exist
  if (fptr == NULL) {

    printf("Error! File was not created!");
    return 1;
  }

//reading through the files to find total number of lines
  while (!feof(fptr)) {
    fgets(name, MAX_STR, fptr);
    numLines++;
  }

//total line number cannot be more than 20 or less than 20
  if (numLines != (2 * NUMBER_COURSES)) {
    printf("not found");
    return -1;
  }


//taking pointer back to start of the line from the end
  fseek(fptr, 0, SEEK_SET);
  if (numLines == (2 * NUMBER_COURSES)) {

    for (j = 0; j < 10; j++) {

      fgets(name, MAX_STR, fptr);
      name[strlen(name) - 1] = '\0';
      strcpy(courseInfo[j].courseName, name);
    }

    while (!feof(fptr)) {

      fscanf(fptr, "%d", &id);
      courseInfo[i].courseID = id;
      i++;
    }
  }
  return 1;
}






// part 3
int readProfAndCoursesTaught(char filename[MAX_STR],
                             struct profStruct profInfo[NUMBER_PROFS],
                             struct courseStruct courseInfo[NUMBER_COURSES]) {

  char pname[MAX_STR];
  char courseAvailable[NUMBER_COURSES];
  int i;

  FILE *fptr;
  fptr = fopen(filename, "r");

  if (fptr == NULL) {

    printf("Error! File was not created!");
    return -1;
  }


//reading names from the files
  for (int i = 0; i < NUMBER_PROFS; i++) {

    fscanf(fptr, "%s", pname);
    strcpy(profInfo[i].profName, pname);
  }


// if the courses in text file has a yes the course number is saved in the file
  for (i = 0; i < NUMBER_PROFS; i++) {

    fscanf(fptr, "%s", courseAvailable);

    for (int j = 0; j < NUMBER_COURSES; j++) {

      if (tolower(courseAvailable[j]) == 'y') {
        profInfo[i].coursesTaught[j] = courseInfo[j].courseID;
      }
      if (tolower(courseAvailable[j]) == 'n') {
        profInfo[i].coursesTaught[j] = -1;
      }
    }
  }
  fclose(fptr);// closing file

  return 1;
}



/* Task 4 */
int nCourses(int n, struct profStruct profInfo[NUMBER_PROFS],
             char profsNCourses[NUMBER_PROFS][MAX_STR]) {

  int num;
  int f = 0;


//loping through coursesTaught to see which has -1 indicating it is not taught
  for (int i = 0; i < NUMBER_PROFS; i++) {

    num = 0;

    for (int j = 0; j < NUMBER_COURSES; j++) {
      if (profInfo[i].coursesTaught[j] != -1) {
        num++;
      }
    }

    if (num >= n) {//if n is greater than num or equal is gives the name of the professors who teaches n or more
                   //n is a number input we take from user
      strcpy(profsNCourses[f], profInfo[i].profName);
      ++f;// to loop through the names and check data
    }
  }
  for (int i = f; i < NUMBER_PROFS; i++) {
    strcpy(profsNCourses[i], "\0");
  }

  return f;
}





/* Task 5 */
int getCourseName(int courseNum, char cNameFound[50],
                  struct courseStruct courseInfo[NUMBER_COURSES]) {

  for (int i = 0; i < NUMBER_COURSES; i++) {
    if (courseNum == courseInfo[i].courseID) {
      strcpy(cNameFound, courseInfo[i].courseName);
      return 1;
    }
  }
  return 0;
}




/* Task 6 */
int getCourseNum(char cName[50], int *cNumFound,
                 struct courseStruct courseInfo[NUMBER_COURSES]) {




  for (int i = 0; i < NUMBER_COURSES; i++) {
    if (strcmp(courseInfo[i].courseName, cName) == 0) {
      *cNumFound = courseInfo[i].courseID;
      return 1;
    }
  }

  return 0;


}





/* Task 7 */
int profsTeachingCourse(int courseNum, struct profStruct profInfo[NUMBER_PROFS],
                        char taughtBy[NUMBER_PROFS][MAX_STR]) {
  int num = 0;

//looping through coursesTaught to see if value inputed matches with courseNum
  for (int i = 0; i < NUMBER_PROFS; i++) {
    for (int j = 0; j < NUMBER_COURSES; j++) {

//if value matches, professor name added to array
      if (profInfo[i].coursesTaught[j] == courseNum) {
        strcpy(taughtBy[num], profInfo[i].profName);
        num++;
      }
    }
  }

//so that the professor names are in all one after another in the string
  for (int i = num; i < NUMBER_PROFS; i++) {
    strcpy(taughtBy[i], "\0");
  }


  return num;
}






/*Task 8 */
float avgNumCourses(struct profStruct profInfo[NUMBER_PROFS]) {

  int num = 0;
  float average;
  float roundOff;
  float roundedVal;


  for (int i = 0; i < NUMBER_PROFS; i++) {
    for (int j = 0; j < NUMBER_COURSES; j++) {
      if (profInfo[i].coursesTaught[j] != -1) {
        num++;
      }
    }
  }


//formula to find the rounded figure
  average = (num / NUMBER_PROFS);
  roundOff = (num % NUMBER_PROFS);
  if (roundOff >= NUMBER_PROFS / 2) {
    roundedVal = average + 1;
  } else {
    roundedVal = average;
  }


  return roundedVal;
}
