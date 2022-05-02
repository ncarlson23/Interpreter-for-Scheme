

#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "lexer.h"
#include "evaluator.h"

int main() {
    printf("A prototype evaluator for Scheme.\n"
            "Type Scheme expressions using quote,\n"
            "car, cdr, cons and symbol?.\n"
            "The function call (exit) quits.\n");
    char token[20];
    startTokens(20);
    globalList = false;
    while (1) {
        printf("\nscheme> ");
        strcpy(token, getToken());
        List input = s_expr(token);
        List output = eval(input);
        printList(output);
        printf("\n");
    }
    return 0;
}
