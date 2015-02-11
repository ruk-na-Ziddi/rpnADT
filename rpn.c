#include "rpn.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isOperator(char c){
	int i;
	char *operatorSet="+-*/";
	for(i=0;i<strlen(operatorSet);++i){
		if(c==operatorSet[i]) return 1;
	}
	return 0;
}

int isOprand(char c){
	int i;
	char *operandSet="0123456789";
	for(i=0;i<strlen(operandSet);++i){
		if(c==operandSet[i]) return 1;
	}
	return 0;
}

int operation(int a,int b,char c){
	int res;
	switch(c){
		case '+': res=a+b; break;
		case '-': res=a-b; break;
		case '*': res=a*b; break;
		case '/': res=a/b; break;
		default: res=0; break;
	}
	return res;
}

char* intToStr(int num){ 
    int size = log10(num) + 1;
    char *str = malloc(size);
    sprintf(str, "%d", num);
    return str;
}

NUM makeOneNumber(char* strNum,char c,int j) {
	NUM n;
	strNum=realloc(strNum, sizeof(char)*(j+1));
	strNum[j]=c;
	n = (NUM){j+1,strNum};
	return n;
}

void popTopTwoElePushRes(Stack stack,int i,char *expression){
	char *a,*b,*strRes=NULL;
	int *result;
	int x,y;
	a=pop(stack); b=pop(stack);
	x=atoi(a); y=atoi(b);
	result=(int *)malloc(sizeof(int));
	*result=operation(y, x, expression[i]);
	strRes=intToStr(*result);
	push(stack, strRes);
	free(a); free(b);
	free(result);
}

int evaluation(char *expression){
	NUM n;
	int i,indexStrNum=0,length=strlen(expression),return_value;
	char *strNum=NULL;
	Stack stack=createStack();
	for (i = 0; i < length; ++i){
		if(isOprand(expression[i])){
			n=makeOneNumber(strNum, expression[i], indexStrNum); 
			indexStrNum=n.position; strNum=n.num;
			if(expression[i+1]==' '){
				indexStrNum=0; push(stack, strNum);
				strNum=calloc(0,0);
			}
		}
		if(isOperator(expression[i]))
			(popTopTwoElePushRes(stack,i,expression));
	}
	return_value=atoi((char *)(*stack.top)->data);
	free(stack.list); free(strNum);
	return return_value;
}

int noOFOprands(char *expression){
	int i,oprands=0;
	for(i=0;i<strlen(expression);++i){
		if(isOprand(expression[i]) && (expression[i+1]==' ' || expression[i+1]==0))
			++oprands;
	}
	return oprands;
}

int noOFOperators(char *expression){
	int i,operators=0;
	for(i=0;i<strlen(expression);++i){
		if(isOperator(expression[i])) ++operators;
	}
	return operators;
}

Result evaluate(char *expression){
	int evaluated_value,oprands,operators;
	Result result;
	oprands=noOFOprands(expression);
	operators=noOFOperators(expression);
	result=(oprands==(operators+1))?(Result){0,evaluation(expression)}:(Result){1,-1};
	return result;
}

int priorty(char c){
	switch(c){
		case '(': return 1;
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 3;
	}
	return 4;
}

int isOpenParanthesis(char c){
	return (c=='(');
}

int isCloseParanthesis(char c){
	return (c==')');
}

void pushOperatorOrOpenParanthesis(Stack stack, char *c){
	if(isOperator(*c) || isOpenParanthesis(*c)){
		push(stack, (c));
	}
}

void MorePriortyOperatorIsOnTop(Stack stack, char c, int * j,char * strNum){
	if((*stack.top)!=NULL && isOperator(c) && (priorty(*(char*)(*stack.top)->data) >= priorty(c)) ){
        strNum[(*j)++]=*(char*)pop(stack);
    	strNum[(*j)++]=' ';
	}
}

void closeParanthesisIsFound(Stack stack,char c,int * j,char *strNum){
	if(isCloseParanthesis(c)){
		while(*(char*)(*stack.top)->data!='('){
			strNum[(*j)-1]!=' '&&(strNum[(*j)++]=' ');
			strNum[(*j)++]=*(char*)pop(stack);
		}
		strNum[(*j)-1]!=' '&&(strNum[(*j)++]=' ');
		pop(stack);
	}
}

void emptyingOperatorStack(Stack stack, int * j,char *strNum){
	while(stack.list->count!=0){
		if(strNum[((*j)-1)]==' '){
			strNum[(*j)++]=*(char*)pop(stack);
		}else{
			strNum[(*j)++]=' ';
			strNum[(*j)++]=*(char*)pop(stack);
		}
	}
}

void AfterOprandOperatorFound(char c,int * i,int * j,char * strNum,char * expression){
	if(isOprand(c)){
		strNum[(*j)++]=c;
		if(isOperator(expression[(*i)+1])){
			strNum[(*j)++]=' ';
		}
	}
}

char * infixToPostfix(char * expression){
	int i,j=0,lenght=strlen(expression);
	char *strNum=NULL;
	Stack stack=createStack();
	strNum=calloc(sizeof(char), lenght*3);
	for(i=0; i<lenght; ++i){
		AfterOprandOperatorFound(expression[i], &i, &j, strNum, expression);
		MorePriortyOperatorIsOnTop(stack, expression[i], &j, strNum);
		closeParanthesisIsFound(stack, expression[i], &j, strNum);
		pushOperatorOrOpenParanthesis(stack, &expression[i]);
	}
	emptyingOperatorStack(stack, &j, strNum);
	free(stack.list);
	return strNum;
}