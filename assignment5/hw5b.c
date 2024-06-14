// name: Xinchen Xu
// email: xu.xinc@northeastern.edu
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 200
#define RAND_RANGE 95  // 95 printing characters x20-x7E

// return random character
char randChar() {
  // 0 -> x20 -> ' '
  // 1 -> x21 -> '!'
  // ,,,
  // 94 -> x7E -> '~'
  // see https://ascii.cl
  return ((char)((rand() % RAND_RANGE) + 0x20));
}

// return the value of a char unless it is lower case
// in which case return the upper case of the character
char upperChar(char c){
  if ((c<'a') || (c>'z')){
    return(c);
  } else {
    // if you forget the displacement of lower to upper case
    // just let the computer figure it out for you!
    return(c-('a'-'A'));
  }
}

// function to swap two characters
void swap(char* a, char* b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

// partition function for quicksort
int partition(char* data, int left, int right) {
  char pivot = data[right];
  int i = left - 1;
  
  for (int j = left; j < right; j++) {
    if (upperChar(data[j]) <= upperChar(pivot)) {
      i++;
      swap(&data[i], &data[j]);
    }
  }
  swap(&data[i + 1], &data[right]);
  return i + 1;
}

// quicksort function
void quicky(char* data, int left, int right) {
  if (left < right) {
    int pi = partition(data, left, right);
    quicky(data, left, pi - 1);
    quicky(data, pi + 1, right);
  }
}

int main() {
  char source[LIMIT]; // array to hold input data values

  int i;             // loop variable
  int j;             // loop variable

  // seed random numbers
  srand((unsigned)time(NULL));

  // initialize source array with random characters
  for (i = 0; i < LIMIT; i++) {
    source[i] = randChar();
  }

  // print out source array in rows of 20 elements
  printf("Source array:\n");
  for (i = 0; i < ((LIMIT / 20) + 1); i++) {
    for (j = 0; j < 20; j++) {
      if (i * 20 + j < LIMIT) {
        printf("%c ", source[i * 20 + j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  // do the sorting
  quicky(source, 0, LIMIT - 1);

  // print out sorted array in rows of 10 elements
  printf("Destination array:\n");
  for (i = 0; i < ((LIMIT / 10) + 1); i++) {
    for (j = 0; j < 10; j++) {
      if (i * 10 + j < LIMIT) {
        printf("%c ", source[i * 10 + j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}

