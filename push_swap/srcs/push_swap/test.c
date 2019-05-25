#include <stdio.h>

typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int num_a;
    int num_b;
    int num;
}              t_main;

int ft_ra(t_main *arr)
{
    int i;
    int first_el;

    i = 0;
    first_el = arr->stack_a[0];
    while (i + 1 < arr->num_a)
    {
        arr->stack_a[i + 1] = arr->stack_a[i];
        i++;
    }
    arr->stack_a[i] = first_el;
    return (arr->stack_a[0]);
}

int main(void)
{
    t_main *arr;

    ft_ra(arr);
    printf("%d", ft_ra(arr));
    return (0);
}