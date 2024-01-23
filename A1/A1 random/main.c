#include "given.h"

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

  if (fptr == NULL) {

    printf("Error! File was not created!");
    return 1;
  }

  while (!feof(fptr)) {
    fgets(name, MAX_STR, fptr);
    numLines++;
  }

  if (numLines != (2 * NUMBER_COURSES)) {
    printf("not found");
    return -1;
  }

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
    return 1;
  }

  for (int i = 0; i < NUMBER_PROFS; i++) {

    fscanf(fptr, "%s", pname);
    strcpy(profInfo[i].profName, pname);
  }

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
  fclose(fptr);

  return 0;
}

/* Task 4 */
int nCourses(int n, struct profStruct profInfo[NUMBER_PROFS],
             char profsNCourses[NUMBER_PROFS][MAX_STR]) {

  int num;
  int f = 0;

  for (int i = 0; i < NUMBER_PROFS; i++) {

    num = 0;

    for (int j = 0; j < NUMBER_COURSES; j++) {
      if (profInfo[i].coursesTaught[j] != -1) {
        num++;
      }
    }

    if (num >= n) {

      strcpy(profsNCourses[f], profInfo[i].profName);
      ++f;
    }
  }
  for (int i = f; i < NUMBER_PROFS; i++) {
    strcpy(profsNCourses[i], "\0");
  }
  printf("%d", f);

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
      cNumFound = &courseInfo[i].courseID;
      return 1;
    }
  }
  return 0;
}

/* Task 7 */
int profsTeachingCourse(int courseNum, struct profStruct profInfo[NUMBER_PROFS],
                        char taughtBy[NUMBER_PROFS][MAX_STR]) {
  int num = 0;
  for (int i = 0; i < NUMBER_PROFS; i++) {
    for (int j = 0; j < NUMBER_COURSES; j++) {
      if (profInfo[i].coursesTaught[j] == courseNum) {
        strcpy(taughtBy[num], profInfo[i].profName);
        num++;
      }
    }
  }
  for (int i = num; i < NUMBER_PROFS; i++) {
    strcpy(taughtBy[i], "\0");
  }
  printf("%d", num);
  return 0;
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

  printf("%d\n", num);
  average = (num / NUMBER_PROFS);
  roundOff = (num % NUMBER_PROFS);
  if (roundOff >= NUMBER_PROFS / 2) {
    roundedVal = average + 1;
  } else {
    roundedVal = average;
  }

  printf("%.1f", roundedVal);

  return roundedVal;
}
