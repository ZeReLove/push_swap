#include <stdio.h>
#include <stdlib.h>



typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int *stack_a2;
    int *stack_b2;
    int num_a;
    int num_b;
    int num_a2;
    int num_b2;
    int num;
    int *array;
    int mediana;
    int block_count_a;
    int block_count_b;
}              t_main;

void ft_pb(t_main *arr)
{
    int i;
    int tmp;

    i = arr->num_b - 1;
    arr->num_b++;
    tmp = arr->stack_a[0];
    while (i != -1)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i--;
    }
    arr->stack_b[0] = tmp;
    i = 0;
    while (i + 1 < arr->num_a)
    {
        arr->stack_a[i] = arr->stack_a[i + 1];
        i++;
    }
    arr->num_a--;
}

void ft_ra(t_main *arr)
{
    int i;
    int first_el;

    i = 0;
    first_el = arr->stack_a[0];
    while (i + 1 < arr->num_a)
    {
        arr->stack_a[i] = arr->stack_a[i + 1];
        i++;
    }
    arr->stack_a[i] = first_el;
}

void mediana_rotating_for_a(t_main *arr)
{
    int i;
    int j;
    int n;
    int k;

    i = 0;
    k = 0;
    if (!(arr->block_count_a))
        arr->block_count_a = arr->num_a;
    n = arr->block_count_a;
   // mediana_finding(arr);
    arr->block_count_a = 0;
    j = i;
    while (j < n)
    {
        if (arr->stack_a[i] >= arr->mediana)
        {
            ft_ra(arr);
            k = 0;
            arr->block_count_a++;
            j++;
        }
        else
        {
            ft_pb(arr);
            k = 0;
            arr->block_count_b++;
            //arr->num_a--;
            //arr->num_b++;
            j++;
        }
    }
}

int main(void)
{
    int i;
    //int *array;
    //int array_len;
    t_main arr;

    arr.mediana = 48;
    arr.stack_b = malloc(sizeof(int) * 5);
    arr.stack_a = malloc(sizeof(int) * 5);
    arr.stack_a[0] = 452;
    arr.stack_a[1] = 9;
    arr.stack_a[2] = 48;
    arr.stack_a[3] = 12;
    arr.stack_a[4] = 234;
    arr.stack_b[0] = 0;
    arr.stack_b[1] = 0;
    arr.stack_b[2] = 0;
    arr.stack_b[3] = 0;
    arr.stack_b[4] = 0;
    //array_len = 4;
    arr.num_a = 5;
    arr.num_b = 5;
    //mediana_rotating_for_a(&arr);
    //ft_pb(&arr);
    //ft_sa(&arr);
    i = 0;
    sort_for_block_count(&arr);
    //printf("-------------------\n");
    while (++i < arr.num_a)
        printf("%d\n", arr.stack_a[i]);
    printf("\n");
    // i = 0;
    // while (i < arr.num_b + 3)
    //         printf("%d\n", arr.stack_b[i++]);

    return (0);
}