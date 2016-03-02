/***********************
 * c-calculator
 * uiFunc.c
 *
 * Command line User Interface functions
 ***********************/

#include "uiFunc.h"

// private types
typedef struct
{
    char **array;
    size_t used;
    size_t bytes;
} StringArray;

// private variables
StringArray history = { NULL, 0, 0 };

// private function prototypes
void addHistory(char*);
void initHistory(char*);
char *getStr(void);

/**
 * Asks the user for an operand for part of an operation
 */
double getOperand(void)
{
    // prompt user for input
    printf("Enter an operand: ");
    char *input = getStr();
    if (!input)
    {
        printf("Out Of Memory!\n");
        exit(1);
    }

    // parse user input
    double operand;
    sscanf(input, "%lf", &operand);
    free(input);
    return operand;
}

/**
 * Asks the user for an operation to perform
 */
char *getOperator(void)
{
    // prompt user for input
    printf("Enter an operation: ");
    char *input = getStr();
    if (!input)
    {
        printf("Out Of Memory!\n");
        exit(1);
    }

    return input;
}

/**
 * Displays calculation and result to user
 */
void displayResult(double operand1, double operand2, char *operator, double result, bool binary)
{
    char operation[BUFSIZ];

    if (binary)
    {
        sprintf(operation, "%f %s %f = %f", operand1, operator, operand2, result);
    }
    else
    {
        sprintf(operation, "%s(%f) = %f", operator, operand1, result);
    }
    
    printf("\n%s\n\n", operation);

    addHistory(operation);
}

/**
 * Display calculation history
 */
void displayHistory(void)
{
    if (history.used > 0)
    {
        printf("\n");
        for (int i = 0; i < history.used; ++i)
        {
            printf("[%s]\n", history.array[i]);
        }
    }
}

void addHistory(char* operation)
{
    if (!history.array)
    {
        initHistory(operation);
    }
    else
    {
        history.bytes += strlen(operation)+1;
        history.array = (char **) realloc(history.array, history.bytes);
    }
    
    history.array[history.used++] = operation;
}

void clearHistory(void)
{
    free(history.array);  
    history.array = NULL;
    history.used = history.bytes = 0;
}

void initHistory(char* operation)
{
    history.bytes = strlen(operation)+1;
    history.used = 0;
    history.array = (char **) malloc(history.bytes);
}

/**
 * Get a character string from user returning NULL if unsucsessful
 */
char *getStr(void)
{
    char buf[BUFSIZ];
    int n = 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (n > BUFSIZ - 1)
        {
            return NULL;
        }
        else
        {
            buf[n++] = c;
        }
    }

    if (n == 0 && c == EOF)
    {
        return NULL;
    }

    char *str = malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        str[i] = buf[i];
    }
    str[n] = '\0';
    return str;
}
