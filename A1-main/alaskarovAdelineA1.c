#include "givenA1.h"
#include <math.h>
FILE *openFileForReading(char fileName [MAX_STR]){
    //opens fileName for reading
    FILE * fptr = fopen(fileName,"r");

    if(fptr == NULL) {//error checking
      printf("ERROR, file does not exist.\n");
      return NULL;
    }
    return fptr;//returns file ptr if file was read
}

int readCourse (char filename [MAX_STR], struct courseStruct courseInfo [NUMBER_COURSES]){
    //initialize vars
    int i;

    int j;

    int c;

    int lineCount = 0;

    char courseName[MAX_STR];

    char dummy = '\0';

    FILE * fptr = openFileForReading(filename);
    if (fptr == NULL){//returns -1 if file can't be read
      return -1;
    }

    while ((c = fgetc(fptr)) != EOF) {

      if (c == '\n') {
            lineCount++;
      }

    }
    if (lineCount != (2*NUMBER_COURSES)){

      return -1;

    }
    //printf("Number of newlines: %d\n", lineCount);
    rewind(fptr);

    //populates courseNames with spaces but without newline character

    for (i = 0; i < NUMBER_COURSES; i++){

      fgets(courseName, MAX_STR, fptr);
      courseName[strlen(courseName)-1] = dummy;
      strcpy(courseInfo[i].courseName, courseName);

    }

    //populates courseIDs

    for (j = 0; j < NUMBER_COURSES; j++){

      fscanf(fptr, "%d", &courseInfo[j].courseID);

    }

    fclose(fptr);
    return 1;

}

int readProfAndCoursesTaught(char filename [MAX_STR], struct profStruct profInfo [NUMBER_PROFS], struct courseStruct courseInfo [NUMBER_COURSES]){
    //initialize vars

    int i;
    int j;
    int k;

    char yesAndNo[MAX_STR];

    FILE * fptr = openFileForReading(filename);
    if (fptr == NULL){//returns -1 if file can't be read
      return -1;
    }

    //populates profName in each struct list

    for (i = 0; i < NUMBER_PROFS; i++){

      fscanf(fptr, "%s", profInfo[i].profName);

    }

    //populates the courses taught by each prof

    for (j = 0; j < NUMBER_PROFS; j++){

      fscanf(fptr, "%s", yesAndNo);//takes in entire string of yes and no chars

      for (k = 0; k < NUMBER_COURSES; k++){

        if (tolower(yesAndNo[k]) == 'y'){//if yes, puts course id in list

          profInfo[j].coursesTaught[k] = courseInfo[k].courseID;

        }

        else if(tolower(yesAndNo[k]) == 'n'){//otherwise puts -1 as index of courses taught

          profInfo[j].coursesTaught[k] = -1;

        }

        else {//in case of unexpected characters

          printf("Error, neither yes or no.");

        }

      }

    }
    fclose(fptr);
    return 1;
}

int nCourses (int n, struct profStruct profInfo [NUMBER_PROFS], char profsNCourses [NUMBER_PROFS][MAX_STR]){
    //initialize vars
    int i, j;
    int count;
    int profCount = 0;

    //checks how many courses taught by each prof and compares it to n
    for (i = 0; i < NUMBER_PROFS; i++){
      count = 0;//count gets reset with each prof

      for(j = 0; j < NUMBER_COURSES; j++){

        if(profInfo[i].coursesTaught[j]!= -1){

          count++;

        }

      }

      //profs name gets added to the list and number of profs that teach n or more courses count gets updated
      if(count>=n){
        strcpy(profsNCourses[profCount], profInfo[i].profName);
        profCount++;

      }

    }

    return profCount;//returns number of profs that teach n or more courses

}

int getCourseName (int courseNum, char cNameFound [50], struct courseStruct courseInfo [NUMBER_COURSES]){
    //initialize variables
    int i;
    int retVal = 0;

    //looks for courseNum in struct list, if found then its course name stored in cNameFound and 1 is returned
    for(i = 0; i < NUMBER_COURSES; i++){

      if (courseNum == courseInfo[i].courseID){

        retVal = 1;
        strcpy(cNameFound, courseInfo[i].courseName);
        printf("%s!\n", cNameFound);//not necessary to print this
        return retVal;

      }

    }

    return retVal;//if courseNum does not match up with any IDs 0 is returned
}

int getCourseNum (char cName [50], int * cNumFound, struct courseStruct courseInfo [NUMBER_COURSES]){

    //initialize vars
    int i, compVal;
    int retVal = 0;
    //goes through course names and compares it to given name
    for (i = 0; i < NUMBER_COURSES; i++){
      compVal = strcmp(cName, courseInfo[i].courseName);
      if(compVal==0){//if names are the same
        cNumFound = &courseInfo[i].courseID;//courseID of particular courseName is saved
        retVal = 1;
        return retVal;//indicates success

      }

    }
    return retVal;//if no match found then 0 is returned
}

int profsTeachingCourse (int courseNum, struct profStruct profInfo [NUMBER_PROFS], char taughtBy [NUMBER_PROFS][MAX_STR]){
    //initialize vars
    int i, j;
    int count = 0;
    //populates taughtBy array with profs that teach the given course
    for(i = 0; i<NUMBER_PROFS; i++){
      for(j = 0; j<NUMBER_COURSES; j++){

        if (courseNum == profInfo[i].coursesTaught[j]){

          strcpy(taughtBy[i], profInfo[i].profName);
          count ++;//number of profs in list
        }
      }

    }

    return count;
}

float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]){
    //initialize vars
    float average;
    int i,j;
    float count = 0.0;

    //adds up all courses that are taught by each prof
    for(i = 0; i < NUMBER_PROFS; i++){

      for(j = 0; j < NUMBER_COURSES; j++){

        if(profInfo[i].coursesTaught[j]!= -1){

          count ++;

        }

      }


    }
    //divide by number of profs to get the average
    average = count / NUMBER_PROFS;

    return ceil(average);
}

