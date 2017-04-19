/*********************
 * c-calculator
 * brain.c
 *
 * Calculator Brain
 ********************/

#include "brain.h"

// binary mathematical functions
double add      (double x, double y) { return x + y; }
double subtract (double x, double y) { return x - y; }
double multiply (double x, double y) { return x * y; }
double divide   (double x, double y) { return x / y; }

// unary mathematical functions
double square   (double x) { return pow(x, 2); }
double cube     (double x) { return pow(x, 3); }

// known operations
Op known_operations[] =
{
    // binary

    { "+",    Binary, .function.bFunc = &add      },
    { "-",    Binary, .function.bFunc = &subtract }, 
    { "*",    Binary, .function.bFunc = &multiply },
    { "/",    Binary, .function.bFunc = &divide   },
    { "pow",  Binary, .function.bFunc = &pow      },

    // unary
    
    // angular
    { "cos",  Unary,  .function.uFunc = &cos    },
    { "sin",  Unary,  .function.uFunc = &sin    },
    { "tan",  Unary,  .function.uFunc = &tan    },
    { "cosh", Unary,  .function.uFunc = &cosh   },
    { "sinh", Unary,  .function.uFunc = &sinh   },
    { "tanh", Unary,  .function.uFunc = &tanh   },

    // powers
    { "sqrt", Unary,  .function.uFunc = &sqrt   },
    { "sqr",  Unary,  .function.uFunc = &square },
    { "cub",  Unary,  .function.uFunc = &cube   },

    // exponent
    { "exp",  Unary,  .function.uFunc = &exp    },
    { "exp2", Unary,  .function.uFunc = &exp2   },
    /* { "exp10",Unary,  .function.uFunc = &exp10  }, */

    // logarithm
    { "log",  Unary,  .function.uFunc = &log    },
    { "log2", Unary,  .function.uFunc = &log2   },
    { "log10",Unary,  .function.uFunc = &log10  }

};

// operator failstate
Op fail = { "error", Unary };

/**
 * Performs operation on inputed operand/s
 */
double evaluate(double operand1, double operand2, Op operate)
{
    Performance calc = operate.function;
    double result =  
        operate.type == Binary ? calc.bFunc(operand1, operand2) : calc.uFunc(operand1);
    
    return result;
}

Op checkOperator(char *symbol)
{
    int total_ops = sizeof(known_operations) / sizeof (known_operations[0]);

    for (int i = 0; i < total_ops; ++i)
    {
        if (strcmp(symbol, known_operations[i].symbol) == 0)
        {
            return known_operations[i];
        }
    }

    return fail;
}
