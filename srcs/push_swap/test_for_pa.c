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

// void ft_pa(t_main *arr)
// {
//     int i;
//     int tmp;

//     i = 0;
//     arr->num_a++;
//     tmp = arr->stack_b[0];
//     while (i + 1 < arr->num_a)
//     {
//         arr->stack_a[i + 1] = arr->stack_a[i];
//         i++;
//     }
//     arr->stack_a[0] = tmp;
//     i = 0;
//     while (i + 1 < arr->num_b)
//     {
//         arr->stack_b[i] = arr->stack_b[i + 1];
//         i++;
//     }
//     arr->num_b--;
// }

void ft_pa(t_main *arr)
{
    int i;
    int tmp;

    i = arr->num_a - 1;
    arr->num_a++;
    tmp = arr->stack_b[0];
     while (i != -1)
    {
        arr->stack_a[i + 1] = arr->stack_a[i];
        i--;
    }
    arr->stack_a[0] = tmp;
    i = 0;
    while (i + 1 < arr->num_b)
    {
        arr->stack_b[i] = arr->stack_b[i + 1];
        i++;
    }
    arr->num_b--;
}

void ft_pb(t_main *arr)
{
    int i;
    int k;
    int tmp;

    k = 0;
    i = arr->num_b - 1;
    arr->num_b++;
    tmp = arr->stack_a[0];
    while (i != -1)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i--;
        printf("first_while\n");
        printf("stack_b\n");
        while (k < arr->num_b)
            printf("%d\n", arr->stack_b[k++]);
        printf("------\n");
    }
    printf("first\n");
    printf("stack_a\n");
    while (i < arr->num_a)
        printf("%d\n", arr->stack_a[i++]);
    printf("\n");
    printf("------\n");
    i = 0;
    printf("stack_b\n");
    while (i < arr->num_b)
        printf("%d\n", arr->stack_b[i++]);
    printf("------\n");
    arr->stack_b[0] = tmp;
    i = 0;
    printf("second\n");
    printf("stack_a\n");
    while (i < arr->num_a)
        printf("%d\n", arr->stack_a[i++]);
    printf("\n");
    printf("------\n");
    i = 0;
    printf("stack_b\n");
    while (i < arr->num_b)
        printf("%d\n", arr->stack_b[i++]);
    i = 0;
    while (i + 1 < arr->num_a)
    {
        arr->stack_a[i] = arr->stack_a[i + 1];
        i++;
    }
    arr->num_a--;
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
    // arr.stack_a[2] = 48;
    // arr.stack_a[3] = 12;
    // arr.stack_a[4] = 234;
    arr.stack_b[0] = 1;
    arr.stack_b[1] = 2;
    // arr.stack_b[2] = 3;
    // arr.stack_b[3] = 4;
    // arr.stack_b[4] = 5;
    //array_len = 4;
    arr.num_a = 2;
    arr.num_b = 2;
    //mediana_rotating_for_a(&arr);
    ft_pa(&arr);
    //ft_sa(&arr);
    i = 0;
    printf("-------------------\n");
    while (i < arr.num_a)
        printf("%d\n", arr.stack_a[i++]);
    printf("\n");
    printf("------\n");
    i = 0;
    while (i < arr.num_b)
            printf("%d\n", arr.stack_b[i++]);

    return (0);
}