/*********************
 * c-calculator
 * brain.h
 *
 * Calculator Brain
 ********************/

#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <math.h>
#include <string.h>

#include "types.h"

// known operations
extern Op operations[];

// failstate
extern Op fail;

// function prototypes

/**
 * Performs operation on inputed operand/s
 */
double evaluate(double operand1, double operand2, Op operate);

/**
 * Returns an Op by matching inputed symbol with known operations
 */
Op checkOperator(char *symbol);

#endif
