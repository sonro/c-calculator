/*************************
 * c-calculator
 * types.h
 *
 * Defines new types for calculator brain to use
 */

#ifndef __TYPES_H__
#define __TYPES_H__

// OpType - Unary or Binary style calculator performance
typedef enum OpType { Unary = 0, Binary = 1 } OpType;


// Performace - Unary or Binary style mathmatical function pointer
typedef union 
{
    double (*uFunc)(double);
    double (*bFunc)(double, double);
} Performance;


// Op - Container for operation information:
//      - UI symbol
//      - Unary or Binary specifier
//      - Mathmatical function pointer
typedef struct Op
{
    char symbol[10];
    OpType type;
    Performance function;
} Op;

#endif
