
#ifndef PARSER
#define PARSER
#include <stdlib.h>
#include "evaluator.h"


 // prints out given list on a new line
void printList(List list);

// Parses input from the command line into C and returns it in the List data type.
List s_expr(char token[]);

#endif //PARSER
