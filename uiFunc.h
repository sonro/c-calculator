/***********************
 * c-calculator
 * uiFunc.h
 *
 * Command line User Interface functions
 ***********************/

#ifndef __UI_FUNC_H__
#define __UI_FUNC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Asks the user for an operand for part of an operation
 */
double getOperand(void);

/**
 * Asks the user for an operation to perform
 */
char *getOperator(void);

/**
 * Displays calculation and result to user
 */
void displayResult(double operand1, double operand2, char *operator, double result, bool binary);

/**
 * Display calculation history
 */
void displayHistory(void);

void clearHistory(void);

#endif
