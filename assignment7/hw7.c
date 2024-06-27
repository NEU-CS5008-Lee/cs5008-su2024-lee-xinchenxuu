//name: Xinchen Xu
//email: xu.xinc@northeastern.edu
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXSTRING 200

// finite state machine states
#define STARTSTATE 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define ACCEPTSTATE 10
#define ERRORSTATE 11

// check if a character c is a digit
bool isDigit(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  } else {
    return false;
  }
}

// append character c to string s
void appendChar(char* s, char c) {
  char charToStr[2];           // convert char to string
  charToStr[0] = c;
  charToStr[1] = '\0';          // put NUL to terminate string of one character
  strcat(s, charToStr);
}

int main () {
  char inputLine[MAXSTRING];   // temporary string to hold input line
  char cityStr[MAXSTRING];     // city name
  int  lineNum;                // line number (city rank)
  int  popInt;                 // population
  int  state;                  // FSM state
  int  nextChar;               // index of next character in input string
  char temp[MAXSTRING];        // temp string to build up extracted strings from input characters

  FILE* fp;
  fp = fopen("pop.csv","r");

  if (fp != NULL) {
    fgets(inputLine, MAXSTRING, fp); // prime the pump for the first line

    // ***** BEGIN FINITE STATE MACHINE *****

    while (feof(fp) == 0){
      nextChar = 0;
      state = STARTSTATE; 
      strcpy(temp,"");       // temp = ""
      strcpy(cityStr,"");    // cityStr = ""
      popInt = 0;            // Initialize popInt to 0

      if (nextChar >= strlen(inputLine)){
        // if no input string then go to ERRORSTATE
        state = ERRORSTATE;
      } 

      while ((state != ERRORSTATE) && (state != ACCEPTSTATE)) {
        switch (state) {
          case STARTSTATE:
            // look a digit to confirm a valid line
            if (isDigit(inputLine[nextChar])) {
              state = S1;
            } else {
              state = ERRORSTATE;
            }  
            break;

          case S1:
            if (isDigit(inputLine[nextChar])) {
              // Stay in S1 if still reading digits
              state = S1;
            } else if (inputLine[nextChar] == ',') {
              state = S2;
            } else {
              state = ERRORSTATE;
            }
            break;

          case S2:
            if (inputLine[nextChar] == '"') {
              state = S3;
            } else {
              state = ERRORSTATE;
            }
            break;

          case S3:
            if (inputLine[nextChar] != '"') {
              appendChar(cityStr, inputLine[nextChar]);
              state = S3;
            } else if (inputLine[nextChar] == '"') {
              state = S4;
            } else {
              state = ERRORSTATE;
            }
            break;

          case S4:
            if (inputLine[nextChar] == ',') {
              state = S5;
            } else {
              state = ERRORSTATE;
            }
            break;

          case S5:
            if (inputLine[nextChar] == '"') {
              state = S6;
            } else if (inputLine[nextChar] == '(') {
              popInt = 0;
              state = ACCEPTSTATE;
            } else {
              state = ERRORSTATE;
            }
            break;

          case S6:
            if (isDigit(inputLine[nextChar])) {
              appendChar(temp, inputLine[nextChar]);
              state = S6;
            } else if (inputLine[nextChar] == ',' || inputLine[nextChar] == '"') {
              if (inputLine[nextChar] == '"') {
                temp[strlen(temp)] = '\0'; // Ensure the temp string is null-terminated
                // Remove commas from the temp string
                char *src = temp, *dst = temp;
                while (*src) {
                  if (*src != ',') {
                    *dst++ = *src;
                  }
                  src++;
                }
                *dst = '\0';
                popInt = atoi(temp);
                state = ACCEPTSTATE;
              }
              state = S6;
            } else {
              state = ERRORSTATE;
            }
            break;

          case ACCEPTSTATE:
            // nothing to do - we are done!
            break;

          default:
            state = ERRORSTATE;
            break;
        } // end switch

        // advance input
        nextChar++;

      }	// end while state machine loop

      // ***** END FINITE STATE MACHINE *****

      // process the line - print out raw line and the parsed fields
      printf("> %.60s\n", inputLine);
      printf("[%.30s]: %d\n", cityStr, popInt);

      // get next line
      fgets(inputLine, MAXSTRING, fp);

    } // end while file input loop

    fclose(fp);

  } else {
    printf("File not found!\n");
  }

  return 0;
}

