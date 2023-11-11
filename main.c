#include <stdio.h>

int raise(int base, int exponent)
{
    if (exponent > 0)
    {
        for (int i = 0; i < exponent; i++)
        {
            base *= base;
        }
        return base;
    }

    else if (exponent < 0)
    {
        for (int i = 0; -i > exponent; i--)
        {
            base *= base;
        }
        return 1/base;
    }

    else
    {
        if (base != 0) return 1;
        else return 0;
    }
}

int defineAuxiliars(char operator)
{
        if (operator == '+' || operator == '*') return 1;
        return -1;
}

float expression()
{
    int value0, value1, value2;
    float resultado = 0;
    char operator1, operator2;

    scanf("%d", &value0);
    while (1)
    {
        scanf("%c", &operator1);
        if (operator1 == '\n') 
        {
            resultado += value0;
            break;
        }

        scanf("%d", &value1);

        if (operator1 == '*') {resultado += value0 * value1; continue;}
        else if (operator1 == '/') {resultado += value0 / value1; continue;}
        
        scanf("%c", &operator2);

        int aux1 = defineAuxiliars(operator1);
        int aux2 = defineAuxiliars(operator2);

        if (operator2 == '\n')
        {
            resultado += value0 + value1*aux1;
            break;
        }
        scanf("%d", &value2);

        if(operator2 == '+' || operator2 == '-')
        {
            resultado += value0 + value1*aux1; value0 = value2*aux2;
        }

        else if (operator2 == '*' || operator2 == '/')
        {
        resultado = resultado + value0*aux1; value0 = value1*(raise(value2,aux2));
        }
    }
    return resultado;
}

int main()
{
    float resultado = expression();
    printf("O resultado da sua expressão é %f", resultado);
    return 0;
}