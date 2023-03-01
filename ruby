$ flex parser.l
$ bison -d parser.y
$ gcc -o parser parser.tab.c lex.yy.c
