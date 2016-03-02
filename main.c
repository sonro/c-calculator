/******************************************************
 * c-calculator
 * main.c
 *
 * Topher Zero
 * github/topherzero
 * 
 * Command line scientific calculator
 ******************************************************/

#include "brain.h"
#include "uiFunc.h"


int main(void)
{
    int i = 0;
    bool running = true;
    while (running)
    {

        // get first operand from user
        double operand1 = getOperand();

        // get operator from user and check it against known ops
        char *operator_symbol = getOperator();
        Op operator = checkOperator(operator_symbol);
        free(operator_symbol);
        if (strcmp(operator.symbol, "error") == 0)
        {
            printf("Invalid/unkown operator\n");
            return 2;
        }

        // get another operand from user if binary operation
        double operand2 = operator.type == Binary ? getOperand() : 0;

        double result = evaluate(operand1, operand2, operator);

        displayHistory();
        displayResult(operand1, operand2, operator.symbol, result, operator.type);

        if (i++ > 2)
        {
            running = false;
            clearHistory();
        }
    }

    return 0;
}
