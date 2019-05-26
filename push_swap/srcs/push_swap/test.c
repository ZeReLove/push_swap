#include <stdio.h>
#include <stdlib.h>

typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int num_a;
    int num_b;
    int num;
}              t_main;

int ft_atoi_push_swap(char *str)
{
    int i;
    int j;
    int sign;
    long long int nbr;

    i = 0;
    j = 0;
    sign = 1;
    nbr = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' 
            || str[i] == '\n' || str[i] == '\f')
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = (nbr * 10) + (str[i++] - '0');
        j++;
    }
    if (j > 11 || nbr > 2147483647 || nbr < -2147483648)
        return (0);                                        //!!!!!!!!!!!!
    return (nbr * sign);
}

void fill_struct(t_main *arr, int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    arr->stack_a = malloc(sizeof(int) * argc);
    arr->stack_b = malloc(sizeof(int) * argc);
    while (i < argc)
    {
        arr->stack_a[j] = ft_atoi_push_swap(argv[i]);
        i++;
        j++;
    }
}

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    t_main arr;
    fill_struct(&arr, argc, argv);
    return (0);
}