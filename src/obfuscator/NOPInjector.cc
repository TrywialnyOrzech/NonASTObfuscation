#include "NOPInjector.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int NOPInjector::getRandomValues( bool choice ) {
  if( choice )
    return randomX;
  else
    return randomY;
}