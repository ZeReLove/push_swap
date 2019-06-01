#include <stdio.h>
#include <stdlib.h>



typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int num_a;
    int num_b;
    int num;
    int *array;
    int mediana;
    int block_count_a;
    int block_count_b;
}              t_main;

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

void ft_pb(t_main *arr)
{
    int i;
    int tmp;

    i = 0;
    tmp = arr->stack_a[0];
    while (i + 1 < arr->num_b)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i++;
    }
    arr->stack_b[0] = tmp;
    i = 0;
    arr->num_a--;
    while (i < arr->num_a)
    {
        arr->stack_a[i] = arr->stack_a[i + 1];
        i++;
    }
}

// void mediana_rotating_for_a(t_main *arr)
// {
//     int i;
//     int n;
//     int sum;

//     i = 0;
//     sum = 0;
//     n = arr->num_a;
//     //arr->num_a = 0;
//     if (!arr->block_count_a)
//         arr->block_count_a = 0; 
//     while(arr->block_count_a < n)
//     {
//         if (arr->stack_a[i] >= arr->mediana)
//         {
//             ft_ra(arr);
//             arr->num_a++;
//             arr->num_b--;
//         }
//         else
//         {
//             ft_pb(arr);
//             arr->block_count_b++;
//             arr->num_b++;
//             arr->num_a--;
//         }
//         arr->block_count_a++;
//         i++;
//     }
// }

//functions rra ans sa work correctly

void mediana_rotating_for_a(t_main *arr)
{
    int i;
    int n;

    i = 0;
    n = arr->num_a;
    if (!arr->block_count_a)
        arr->block_count_a = 0; 
    while (i < n)
    {
        if (arr->stack_a[i] >= arr->mediana)
        {
            ft_ra(arr);
            arr->block_count_a++;
        }
        else
        {
            ft_pb(arr);
            arr->block_count_b++;
            arr->num_a--;
            arr->num_b++;
        }
        i++;
    }
}

// DOESN'T WORT AT ALL (SORTINTG RANDOMLY)

int main(void)
{
    int i;
    //int *array;
    //int array_len;
    t_main arr;

    arr.mediana = 350;
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
    mediana_rotating_for_a(&arr);
    i = 0;
    while (i < arr.num_a + 1)
        printf("%d\n", arr.stack_a[i++]);
    printf("\n");
    i = 0;
    while (i < arr.num_b + 1)
            printf("%d\n", arr.stack_b[i++]);

    return (0);
}