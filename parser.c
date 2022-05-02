
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "lexer.h"
#include "evaluator.h"


// S_Expr parses the inputted Scheme expression into a conscell structure.
List s_expr(char token[]) {
    List local, temp;
    if(!strcmp(token, "(")) {
        local = newList();
        strcpy(local->symbol, "");
        local->first = newList();
        strcpy(token, getToken());
        local->first = s_expr(token);
        temp = local;
        strcpy(token, getToken());
        while(strcmp(token, ")") != 0) {
            temp->rest = newList();
            temp = cdr(temp);
            temp->first = newList();
            temp->first = s_expr(token);
            strcpy(token, getToken());
        }
        temp->rest = NULL;
    } else {
        if (!strcmp(token, "#f")) {
            local = false;
        } else if (!strcmp(token, "#t")) {
            local = true;
        } else if (!strcmp(token, "'")) {
            local = newList();
            strcpy(local->symbol, "");
            local->first = newList();
            strcpy(token, "quote");
            local->first = s_expr(token);
            strcpy(token, getToken());
            local->rest = newList();
            local->rest->first = s_expr(token);
        } else {
            local = newList();
            strcpy(local->symbol, token);
            local->first = NULL;
            local->rest = NULL;
        }
    }
    return local;
}

//converts the given list in conscell structure to a standard output
 //that would be expected from Scheme. To determine the top-most
 //layer of recursion, the first integer variable is used.
void printHelper(List list, int first) {
    if (list == NULL) {
        if (first == 0) {
            printf(" ()");
        } else {
            printf("()");
        }
    } else if (isConsCell(list)) {
        if (first == 0) {
            printf(" (");
        }
        if (car(list) != NULL) {
            if (!strcmp(car(list)->symbol, "")) {
                printf("(");
            }
            printHelper(car(list), 1);
            if (cdr(list) != NULL) {
                printf(" ");
            } else {
                printf(")");
            }
        }
        if (cdr(list) != NULL) {
            printHelper(cdr(list), 1);
        }
    } else {
        if (first == 0) {
            printf(" ");
        }
        printf("%s", list->symbol);
    }
}

void printList(List list) {
    printHelper(list, 0);
}
