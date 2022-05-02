scheme: evaltester.o lexer.o parser.o evaluator.o
	gcc -o scheme evaltester.o lexer.o  parser.o evaluator.o

evaltester.o: evaltester.c
	gcc -c evaltester.c

lexer.o: lexer.c
	gcc -c lexer.c

parser.o: parser.c
	gcc -c parser.c

evaluator.o: evaluator.c
	gcc -c evaluator.c

clean:
	rm -f *~ *.o *.a
#^this space must be a tab
