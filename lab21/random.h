#include "lab21.h"

int randomNumber() {
   srand(time(0));
   return (rand() % 10) + 1;
}