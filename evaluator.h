
#ifndef EVALUATOR
#define EVALUATOR

// conscell data type
struct cell {
    char symbol[20];
    struct cell *first;
    struct cell *rest;
};


typedef struct cell conscell;
typedef conscell *List;

List false;  // #f conscell
List true;  // #t conscell

List newList();  // new list


// returns first element of list
List car(List list);


// returns everything in list expect the first element
List cdr(List list);


// returns list where first element is the list list1 and the rest
// of the list is the elements in list 2
List cons(List list1, List list2);

// returns 0 or 1 depending on whether it is a conscell structure
int isConsCell(List list);

// global environment
List globalList;


 // prevents evaluation of the contents of the list
List quote(List list);


 // returns #t if the list is a symbol and () otherwise
List symbol(List list);



 // returns a list where the elements of list2 are inserted at the end of list1
List append(List list1, List list2);


 // returns #t if list is null and () otherwise
List null(List list);


 // returns #t if the lists are equal and () otherwise
List equal(List list1, List list2);


 // returns the pair associated with the symbol in list1, () otherwise
 // list1 must be a symbol and list2 must be assoc list
List assoc(List list1, List list2);


 // operates as an if statement equivalent in scheme
List cond(List list);


 // associates symbol in list1 with the expression in list2, returns list1
List define(List list1, List list2);


 // returns #t if expression is a list, () otherwise
List isList(List list);


 // returns #t if the expression is a defined function, () otherwise
List isFunction(List list);


 //  Evaluates the given list based on the above defined functions and returns it.
List eval(List list);

#endif //EVAL
