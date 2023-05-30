#include "givenA1.h"
#include <math.h>
int main(int argc, char * argv[]){
    //vars
    struct courseStruct courseInfo[NUMBER_COURSES];
    struct profStruct profInfo [NUMBER_PROFS];
    int whichTask;
    int courseNumber;
    char profsNCourses [NUMBER_PROFS][MAX_STR];
    int courseCode;
    char cNameFound [MAX_STR];
    char cName[MAX_STR];
    char dummy = '\0';
    int cNumFound;
    int courseNum;
    char taughtBy [NUMBER_PROFS][MAX_STR];
    int task6;
    float task8;


    int task2 = readCourse(argv[1], courseInfo);
    if(task2 != 1){
      printf("There was an error in populating the course information");
    }
    //printf("%d", task2);//for testing

    //printf("Course Info\n");
    //for(int i = 0; i< NUMBER_COURSES; i++){
      //printf("%s", courseInfo[i].courseName);
      //printf("%d\n", courseInfo[i].courseID);


    //}

    int task3 = readProfAndCoursesTaught(argv[2], profInfo, courseInfo);
    if(task3 != 1){
      printf("There was an error in populating the course information");
    }
    //printf("%d", task3);//for testing
    //printf("Prof Info\n");
    //for(int i = 0; i< NUMBER_PROFS; i++){
      //printf("%s", profInfo[i].profName);
      //printf("%d %d %d %d %d %d %d %d %d %d\n", profInfo[i].coursesTaught[0], profInfo[i].coursesTaught[1], profInfo[i].coursesTaught[2], profInfo[i].coursesTaught[3], profInfo[i].coursesTaught[4], profInfo[i].coursesTaught[5], profInfo[i].coursesTaught[6], profInfo[i].coursesTaught[7], profInfo[i].coursesTaught[8], profInfo[i].coursesTaught[9]);


    //}


    //menu
    do{
      printf ("\nHere is the menu \n\n");
      printf("4. Task4 - returns the total number of professors who teach n or more number of courses.\n");
      printf("5. Task5 - takes course code, returns 1 if the course is found, 0 otherwise.\n");
      printf("6. Task6 - takes course name, returns 1 if the course is found, 0 otherwise.\n");
      printf("7. Task7 - takes course code,  returns the total number of profs teaching the course if the course is found, 0 otherwise.\n");
      printf("8. Task 8 - returns the average number of courses taught by a professor.\n");
      printf ("Exit: any other number\n");
      printf ("Enter your choice: ");
      scanf("%d", &whichTask);

      switch(whichTask){

        case 4:
          //asks user for the value of n
          printf("Enter the value of n: ");
          scanf("%d", &courseNumber);
          //uses n to call function and save it under task4
          int task4 = nCourses(courseNumber, profInfo, profsNCourses);
          //displayed number of profs that teach n or more courses and their names if at least one prof teaches that amount
          printf("%d Prof(s) teach %d or more courses\n", task4, courseNumber);
          if (task4>0){
            printf("Name(s):");
            for(int i = 0; i<task4; i++){

              printf("\n%s",profsNCourses[i]);

            }
          }
          break;

        case 5:
          //asks user for course id
          printf("Enter the course code you wish to search for: ");
          scanf("%d", &courseCode);
          //uses given info to call function that searches for that course and tell you if its name was found
          int task5 = getCourseName(courseCode, cNameFound, courseInfo);
          //displays results
          if(task5 == 1){
            printf("Course name found!\n");
          }
          else{
            printf("Course name not found\n");
          }
          break;

        case 6:
          //asks user for a course name
          printf("Enter a course name: ");
          //reads in with spaces and removes newline character
          fgetc(stdin);
          fgets(cName, MAX_STR, stdin);
          cName[strlen(cName)-1] = dummy;
          task6 = getCourseNum(cName, &cNumFound, courseInfo);

          //results after function call
          if(task6 == 1){
            printf("Course number found! %d\n");
          }
          else{
            printf("Course number not found\n");
          }
          break;

        case 7:
          //asks user for course code and function indicates how many professors teach that course
          printf("Enter a course code: ");
          scanf("%d", &courseNum);
          int task7 = profsTeachingCourse(courseNum, profInfo, taughtBy);
          printf("%d profs teach this course.",task7);
          break;

        case 8:
          //displays average number of courses taught by professors
          task8 = avgNumCourses(profInfo);
          printf("The average number of courses taught is %.2f", task8);
          break;

        default: printf ("\nYou have exited\n");

      }

    }while (whichTask>=4 && whichTask<9);

    return 0;
}


