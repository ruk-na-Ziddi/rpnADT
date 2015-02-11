#include "expr_assert.h"
#include "rpn.h"
#include <string.h>
#include <stdlib.h>

void test_isOperator_gives_1_for_plus_sign(){
	assertEqual(isOperator('+'), 1);
}

void test_isOperator_gives_1_for_minus_sign(){
	assertEqual(isOperator('-'), 1);
}

void test_isOperator_gives_1_for_multiply_sign(){
	assertEqual(isOperator('*'), 1);
}

void test_isOperator_gives_1_for_devision_sign(){
	assertEqual(isOperator('/'), 1);
}

void test_isOperator_gives_0_for_a(){
	assertEqual(isOperator('a'), 0);
}

void test_isOperator_gives_0_for_A(){
	assertEqual(isOperator('A'), 0);
}

void test_isOperator_gives_0_for_add_the_rate_sign(){
	assertEqual(isOperator('@'), 0);
}

void test_isOperator_gives_0_for_1(){
	assertEqual(isOperator('1'), 0);
}

void test_isOperator_gives_0_for_0(){
	assertEqual(isOperator('0'), 0);
}

void test_isOprand_gives_1_for_0(){
	assertEqual(isOprand('0'), 1);
}

void test_isOprand_gives_1_for_1(){
	assertEqual(isOprand('1'), 1);
}

void test_isOprand_gives_1_for_2(){
	assertEqual(isOprand('2'), 1);
}

void test_isOprand_gives_1_for_3(){
	assertEqual(isOprand('3'), 1);
}

void test_isOprand_gives_1_for_4(){
	assertEqual(isOprand('4'), 1);
}

void test_isOprand_gives_1_for_5(){
	assertEqual(isOprand('5'), 1);
}

void test_isOprand_gives_1_for_6(){
	assertEqual(isOprand('6'), 1);
}

void test_isOprand_gives_1_for_7(){
	assertEqual(isOprand('7'), 1);
}

void test_isOprand_gives_1_for_8(){
	assertEqual(isOprand('8'), 1);
}

void test_isOprand_gives_1_for_9(){
	assertEqual(isOprand('9'), 1);
}

void test_isOprand_gives_0_for_plus_sign(){
	assertEqual(isOprand('+'), 0);
}

void test_isOprand_gives_0_for_minus_sign(){
	assertEqual(isOprand('-'), 0);
}

void test_isOprand_gives_0_for_multiply_sign(){
	assertEqual(isOprand('*'), 0);
}

void test_isOprand_gives_0_for_devision_sign(){
	assertEqual(isOprand('/'), 0);
}

void test_isOprand_gives_0_for_a(){
	assertEqual(isOprand('a'), 0);
}

void test_isOprand_gives_0_for_A(){
	assertEqual(isOprand('A'), 0);
}

void test_isOprand_gives_0_for_ampersand_sign(){
	assertEqual(isOprand('&'), 0);
}

void test_operation_gives_8_for_6_2_and_plus_sign(){
	assertEqual(operation(6, 2, '+'), 8);
}

void test_operation_gives_4_for_6_2_and_minus_sign(){
	assertEqual(operation(6, 2, '-'), 4);
}

void test_operation_gives_12_for_6_2_and_multiply_sign(){
	assertEqual(operation(6, 2, '*'), 12);
}

void test_operation_gives_3_for_6_2_and_devision_sign(){
	assertEqual(operation(6, 2, '/'), 3);
}

void test_operation_gives_30_for_20_10_and_plus_sign(){
	assertEqual(operation(20, 10, '+'), 30);
}

void test_operation_gives_10_for_20_10_and_minus_sign(){
	assertEqual(operation(20, 10, '-'), 10);
}

void test_operation_gives_200_for_20_10_and_multiply_sign(){
	assertEqual(operation(20, 10, '*'), 200);
}

void test_operation_gives_2_for_20_10_and_devision_sign(){
	assertEqual(operation(20, 10, '/'), 2);
}

void test_operation_gives_0_for_6_2_and_ampersand_sign(){
	assertEqual(operation(6, 2, '&'), 0);
}

void test_operation_gives_0_for_6_2_and_add_the_rate_sign(){
	assertEqual(operation(6, 2, '@'), 0);
}

void test_intToStr_gives_0_as_string(){
	char *result=intToStr(0);
	assertEqual(strcmp(result, "0"), 0);
}

void test_intToStr_gives_1_as_string(){
	char *result=intToStr(1);
	assertEqual(strcmp(result, "1"), 0);
}

void test_intToStr_gives_12_as_string(){
	char *result=intToStr(12);
	assertEqual(strcmp(result, "12"), 0);
}

void test_intToStr_gives_123_as_string(){
	char *result=intToStr(123);
	assertEqual(strcmp(result, "123"), 0);
}

void test_intToStr_gives_1234_as_string(){
	char *result=intToStr(1234);
	assertEqual(strcmp(result, "1234"), 0);
}

void test_intToStr_gives_12345_as_string(){
	char *result=intToStr(12345);
	assertEqual(strcmp(result, "12345"), 0);
}

void test_intToStr_gives_123456_as_string(){
	char *result=intToStr(123456);
	assertEqual(strcmp(result, "123456"), 0);
}

void test_intToStr_gives_1234567_as_string(){
	char *result=intToStr(1234567);
	assertEqual(strcmp(result, "1234567"), 0);
}

void test_intToStr_gives_12345678_as_string(){
	char *result=intToStr(12345678);
	assertEqual(strcmp(result, "12345678"), 0);
}

void test_intToStr_gives_123456789_as_string(){
	char *result=intToStr(123456789);
	assertEqual(strcmp(result, "123456789"), 0);
}

void test_intToStr_gives_1234567890_as_string(){
	char *result=intToStr(1234567890);
	assertEqual(strcmp(result, "1234567890"), 0);
}

void test_makeOneNumber_concates_b_to_a_and_gives_ab(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),2);
	strcpy(str,"a");
	result=makeOneNumber(str,'b',1);
	assertEqual(strcmp(result.num, "ab"), 0);
	free(str);
}

void test_makeOneNumber_concates_c_to_ab_and_gives_abc(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),2);
	strcpy(str,"ab");
	result=makeOneNumber(str,'c',2);
	assertEqual(strcmp(result.num, "abc"), 0);
	free(str);
}

void test_makeOneNumber_concates_d_to_abc_and_gives_abcd(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),5);
	strcpy(str,"abc");
	result=makeOneNumber(str,'d',3);
	assertEqual(strcmp(result.num, "abcd"), 0);
	free(str);
}

void test_makeOneNumber_concates_e_to_abcd_and_gives_abcde(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),10);
	strcpy(str,"abcd");
	result=makeOneNumber(str,'e',4);
	assertEqual(strcmp(result.num, "abcde"), 0);
	free(str);
}

void test_makeOneNumber_concates_2_to_1_and_gives_12(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),3);
	strcpy(str,"1");
	result=makeOneNumber(str,'2',1);
	assertEqual(strcmp(result.num, "12"), 0);
	free(str);
}

void test_makeOneNumber_concates_3_to_12_and_gives_12(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),3);
	strcpy(str,"12");
	result=makeOneNumber(str,'3',2);
	assertEqual(strcmp(result.num, "123"), 0);
	free(str);
}

void test_makeOneNumber_concates_4_to_123_and_gives_1234(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),5);
	strcpy(str,"123");
	result=makeOneNumber(str,'4',3);
	assertEqual(strcmp(result.num, "1234"), 0);
	free(str);
}

void test_makeOneNumber_concates_5_to_1234_and_gives_12345(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),5);
	strcpy(str,"1234");
	result=makeOneNumber(str,'5',4);
	assertEqual(strcmp(result.num, "12345"), 0);
	free(str);
}

void test_makeOneNumber_concates_6_to_12345_and_gives_123456(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),10);
	strcpy(str,"12345");
	result=makeOneNumber(str,'6',5);
	assertEqual(strcmp(result.num, "123456"), 0);
	free(str);
}

void test_makeOneNumber_concates_7_to_123456_and_gives_1234567(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),10);
	strcpy(str,"123456");
	result=makeOneNumber(str,'7',6);
	assertEqual(strcmp(result.num, "1234567"), 0);
	free(str);
}

void test_makeOneNumber_concates_8_to_1234567_and_gives_12345678(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),10);
	strcpy(str,"1234567");
	result=makeOneNumber(str,'8',7);
	assertEqual(strcmp(result.num, "12345678"), 0);
	free(str);
}

void test_makeOneNumber_concates_9_to_12345678_and_gives_123456789(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),10);
	strcpy(str,"12345678");
	result=makeOneNumber(str,'9',8);
	assertEqual(strcmp(result.num, "123456789"), 0);
	free(str);
}

void test_makeOneNumber_concates_0_to_123456789_and_gives_1234567890(){
	NUM result;
	char *str=(char *)calloc(sizeof(char),10);
	strcpy(str,"123456789");
	result=makeOneNumber(str,'0',9);
	assertEqual(strcmp(result.num, "1234567890"), 0);
	free(str);
}

void test_evaluation_evaluates_the_expression_2_3_p_and_gives_5(){
	assertEqual(evaluation("2 3 +"), 5);
}

void test_evaluation_evaluates_the_expression_2_3_n_and_gives_n_1(){
	assertEqual(evaluation("2 3 -"), -1);
}

void test_evaluation_evaluates_the_expression_2_3_m_and_gives_6(){
	assertEqual(evaluation("2 3 *"), 6);
}

void test_evaluation_evaluates_the_expression_6_2_d_and_gives_3(){
	assertEqual(evaluation("6 2 /"), 3);
}

void test_evaluation_evaluates_the_expression_2_3_4_p_p_and_gives_10(){
	assertEqual(evaluation("2 3 5 + +"), 10);
}

void test_evaluation_evaluates_the_expression_22_3_4_p_p_and_gives_30(){
	assertEqual(evaluation("22 3 5 + +"), 30);
}

void test_evaluation_evaluates_the_expression_22_3_4_p_n_and_gives_14(){
	assertEqual(evaluation("22 3 5 + -"), 14);
}

void test_evaluation_evaluates_the_expression_22_3_4_n_p_and_gives_20(){
	assertEqual(evaluation("22 3 5 - +"), 20);
}

void test_evaluation_evaluates_the_expression_2_3_4_m_m_and_gives_30(){
	assertEqual(evaluation("2 3 5 * *"), 30);
}

void test_evaluation_evaluates_the_expression_2_2_2_p_2_p_p_and_gives_8(){
	assertEqual(evaluation("2 2 2 + 2 + +"), 8);
}

void test_evaluation_evaluates_the_expression_2_2_n_2_2_2_m_2_n_n_n_and_gives_4(){
	assertEqual(evaluation("2 2 + 2 2 2 * 2 - - -"), 4);
}

void test_noOFOprands_gives_1_for_1_p(){
	assertEqual(noOFOprands("1 +"), 1);
}

void test_noOFOprands_gives_2_for_1_1_p(){
	assertEqual(noOFOprands("1 1 +"), 2);
}

void test_noOFOprands_gives_3_for_1_1_1(){
	assertEqual(noOFOprands("1 1 1"), 3);
}

void test_noOFOprands_gives_1_for_1_p_n_p(){
	assertEqual(noOFOprands("1 + - +"), 1);
}

void test_noOFOprands_gives_5_for_1_1_1_n_1_1_p_m_d(){
	assertEqual(noOFOprands("1 1 1 - 1 1 + * /"), 5);
}

void test_noOFOprands_gives_4_for_1_1_n_1_1_p_m(){
	assertEqual(noOFOprands("1 1 - 1 1 + *"), 4);
}

void test_noOFOprands_gives_2_for_1_p_d_n_m_1_p_m_d(){
	assertEqual(noOFOprands("1 + / - * 1 + * /"), 2);
}

void test_noOFOprands_gives_6_for_1_2_3_4_5_6_p_p_n_p_n(){
	assertEqual(noOFOprands("1 2 3 4 5 6 + + - + -"), 6);
}

void test_noOFOprands_gives_1_for_11_p_n_p(){
	assertEqual(noOFOprands("11 + - +"), 1);
}

void test_noOFOprands_gives_3_for_11_22_45_p_n(){
	assertEqual(noOFOprands("11 22 45 + -"), 3);
}

void test_noOFOprands_gives_2_for_11_22_p(){
	assertEqual(noOFOprands("11 22 +"), 2);
}

void test_noOFOperators_gives_1_for_1_p(){
	assertEqual(noOFOperators("1 +"), 1);
}

void test_noOFOperators_gives_1_for_1_1_p(){
	assertEqual(noOFOperators("1 1 +"), 1);
}

void test_noOFOperators_gives_0_for_1_1_1(){
	assertEqual(noOFOperators("1 1 1"), 0);
}

void test_noOFOperators_gives_3_for_1_p_n_p(){
	assertEqual(noOFOperators("1 + - +"), 3);
}

void test_noOFOperators_gives_4_for_1_1_1_n_1_1_p_m_d(){
	assertEqual(noOFOperators("1 1 1 - 1 1 + * /"), 4);
}

void test_noOFOperators_gives_3_for_1_1_n_1_1_p_m(){
	assertEqual(noOFOperators("1 1 - 1 1 + *"), 3);
}

void test_noOFOperators_gives_7_for_1_p_d_n_m_1_p_m_d(){
	assertEqual(noOFOperators("1 + / - * 1 + * /"), 7);
}

void test_noOFOperators_gives_5_for_1_2_3_4_5_6_p_p_n_p_n(){
	assertEqual(noOFOperators("1 2 3 4 5 6 + + - + -"), 5);
}

void test_evaluate_evaluates_the_expression_2_3_p_and_gives_5_as_status_and_0_as_error(){
	int status, error;
	Result evaluated=evaluate("2 3 +");
	status=evaluated.status;
	error=evaluated.error;
	assertEqual(status, 5);
	assertEqual(error, 0);
}

void test_evaluate_evaluates_the_expression_2_3_2_3_p_p_and_gives_neg_1_as_status_and_1_as_error(){
	int status, error;
	Result evaluated=evaluate("2 3 2 3 + +");
	status=evaluated.status;
	error=evaluated.error;
	assertEqual(status, -1);
	assertEqual(error, 1);
}

void test_evaluate_evaluates_the_expression_2_3_p_p_and_gives_neg_1_as_status_and_1_as_error(){
	int status, error;
	Result evaluated=evaluate("2 3 + +");
	status=evaluated.status;
	error=evaluated.error;
	assertEqual(status, -1);
	assertEqual(error, 1);
}

void test_evaluate_evaluates_the_expression_2_3_5_p_p_and_gives_10_as_status_and_0_as_error(){
	int status, error;
	Result evaluated=evaluate("2 3 5 + +");
	status=evaluated.status;
	error=evaluated.error;
	assertEqual(status, 10);
	assertEqual(error, 0);
}

void test_evaluate_evaluates_the_expression_2_3_5_4_p_p_n_and_gives_10_as_status_and_0_as_error(){
	int status, error;
	Result evaluated=evaluate("2 3 5 4 + + -");
	status=evaluated.status;
	error=evaluated.error;
	assertEqual(status, -10);
	assertEqual(error, 0);
}

void test_popTopTwoElePushRes_pops_top_two_datas_and_pushes_their_added_value(){
	char *first_node_data, *second_node_data;
	Stack stack=createStack();
	first_node_data=calloc(sizeof(char), 5);
	second_node_data=calloc(sizeof(char), 5);
	strcpy(first_node_data,"10"); strcpy(second_node_data, "10");
	push(stack,first_node_data);
	push(stack,second_node_data);
	popTopTwoElePushRes(stack,4,"5 5 +");	
	assertEqual(strcmp((*stack.top)->data, "20"), 0);
}

void test_popTopTwoElePushRes_pops_top_two_datas_and_pushes_their_added_value_when_stack_has_three_datas(){
	char *first_node_data, *second_node_data, *third_node_data;
	Stack stack=createStack();
	first_node_data=calloc(sizeof(char), 5);
	second_node_data=calloc(sizeof(char), 5);
	third_node_data=calloc(sizeof(char), 5);
	strcpy(first_node_data,"10"); strcpy(second_node_data, "10");
	strcpy(third_node_data,"20");
	push(stack,first_node_data); push(stack,second_node_data);
	push(stack, third_node_data);
	popTopTwoElePushRes(stack,4,"5 5 +");	
	assertEqual(strcmp((*stack.top)->data, "30"), 0);
}

void test_popTopTwoElePushRes_pops_top_two_datas_and_pushes_their_substacted_value(){
	char *first_node_data, *second_node_data, *third_node_data;
	Stack stack=createStack();
	first_node_data=calloc(sizeof(char), 5);
	second_node_data=calloc(sizeof(char), 5);
	third_node_data=calloc(sizeof(char), 5);
	strcpy(first_node_data,"10"); strcpy(second_node_data, "20");
	strcpy(third_node_data,"10");
	push(stack,first_node_data); push(stack,second_node_data);
	push(stack, third_node_data);
	popTopTwoElePushRes(stack,4,"5 5 -");
	assertEqual(strcmp((*stack.top)->data, "10"), 0);
}

void test_popTopTwoElePushRes_pops_top_two_datas_and_pushes_their_multiplied_value(){
	char *first_node_data, *second_node_data, *third_node_data;
	Stack stack=createStack();
	first_node_data=calloc(sizeof(char), 5);
	second_node_data=calloc(sizeof(char), 5);
	third_node_data=calloc(sizeof(char), 5);
	strcpy(first_node_data,"10"); strcpy(second_node_data, "20");
	strcpy(third_node_data,"10");
	push(stack,first_node_data); push(stack,second_node_data);
	push(stack, third_node_data);
	popTopTwoElePushRes(stack,4,"5 5 *");
	assertEqual(strcmp((*stack.top)->data, "200"), 0);
}

void test_popTopTwoElePushRes_pops_top_two_datas_and_pushes_their_devision_value(){
	char *first_node_data, *second_node_data, *third_node_data;
	Stack stack=createStack();
	first_node_data=calloc(sizeof(char), 5);
	second_node_data=calloc(sizeof(char), 5);
	third_node_data=calloc(sizeof(char), 5);
	strcpy(first_node_data,"10"); strcpy(second_node_data, "200");
	strcpy(third_node_data,"10");
	push(stack,first_node_data); push(stack,second_node_data);
	push(stack, third_node_data);
	popTopTwoElePushRes(stack,4,"5 5 /");
	assertEqual(strcmp((*stack.top)->data, "20"), 0);
}

void test_infixToPostfix_3_4_5_m_6_d_p_gives_3_p_4_m_5_d_6(){
	char *postFix=infixToPostfix("3+4*5/6");
	assertEqual(strcmp(postFix, "3 4 5 * 6 / +"), 0);
	free(postFix);
}

void test_infixToPostfix_gives_postfix_for_op_300_p_23_cp_m_op_43_m_21_cp_d_op_84_p_7cp(){
	char *postFix=infixToPostfix("(300+23)*(43-21)/(84+7)");
	assertEqual(strcmp(postFix, "300 23 + 43 21 - * 84 7 + /"), 0);
	free(postFix);
}

// void compare(char * s1,char*s2){
// 	int i ;
// 	for(i=0;i<strlen(s2);i++){
// 		if(s1[i]!=s2[i]){
// 			printf("%c != %c at %d\n",s1[i],s2[i],i );
// 		}
// 	}
// }

void test_infixToPostfix_gives_postFix_for_op_4_p_8_m_op_6_s_5_cp_d_op_op_3_s_2_cp_m_op_2_p_2_cp_cp(){
	char * expected="4 8 + 6 5 - * 3 2 - 2 2 + * /";
	char *postFix=infixToPostfix("(4+8)*(6-5)/((3-2)*(2+2))");
	assertEqual(strcmp(postFix,expected),0);
	free(postFix);
}