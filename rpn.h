#include "stack.h"

typedef struct result Result;
typedef struct num NUM;

struct result {
  int error;
  int status;
};

struct num{
	int position;
	char *num;
};

int isOperator(char c);
int isOprand(char c);
int operation(int a,int b,char c);
char* intToStr(int num);
NUM makeOneNumber(char* strNum,char c,int j);
int noOFOprands(char *expression);
int noOFOperators(char *expression);
void popTopTwoElePushRes(Stack stack,int i,char *expression);
int evaluation(char *expression);
Result evaluate(char *expression);
char * infixToPostfix(char * expression);