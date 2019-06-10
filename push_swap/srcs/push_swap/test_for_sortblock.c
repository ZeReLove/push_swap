#include <stdlib.h>
#include <stdio.h>

typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int num_a;
    int num_b;
    int *block_a;
    int *block_b;
    int num;
    int *array;
    int mediana;
    int *block_count_a;
    int *block_count_b;
}              t_main;

int is_sorted_for_block_b(t_main *arr, int l)
{
    int i;

    i = 0;
    while (i < arr->block_count_b[l] - 1)
    {
        if (arr->stack_b[i] > arr->stack_b[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->block_count_b[l] - 1)
        return (1);
    else
        return (0);
}

void ft_sa(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->stack_a[0];
    j = arr->stack_a[1];
    tmp = i;
    arr->stack_a[0] = j;
    arr->stack_a[1] = tmp;
}

void ft_sb(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->stack_b[0];
    j = arr->stack_b[1];
    tmp = i;
    arr->stack_b[0] = j;
    arr->stack_b[1] = tmp;
}

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

void ft_rb(t_main *arr)
{
    int i;
    int first_el;

    i = 0;
    first_el = arr->stack_b[0];
    while (i + 1 < arr->num_b)
    {
        arr->stack_b[i] = arr->stack_b[i + 1];
        i++;
    }
    arr->stack_b[i] = first_el;
}

void ft_rrb(t_main *arr)
{
    int i;
    int last_el;

    i = 0;
    if (arr->num_b != 0) // ???
        i = arr->num_b - 2;
    last_el = arr->stack_b[arr->num_b - 1];
    while (i != -1)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i--;
    }
    arr->stack_b[0] = last_el;
}

void sort_for_block_count(t_main *arr, int l)
{
    int i;

    i = 0;

    if (arr->block_count_b[l] == 3 && !(is_sorted_for_block_b(arr, l)))
    {
        if (arr->stack_b[i] > arr->stack_b[i + 1] && arr->stack_b[i] > arr->stack_b[i + 2] && arr->stack_b[i + 1] < arr->stack_b[i + 2])
        {
            ft_pa(arr);
            ft_sb(arr);
            ft_pb(arr);
        }
        if (arr->stack_b[i] < arr->stack_b[i + 1] && arr->stack_b[i] < arr->stack_b[i + 2] && arr->stack_b[i + 1] < arr->stack_b[i + 2])
        {
            ft_pa(arr);
            ft_sb(arr);
            ft_pa(arr);
            ft_sa(arr);
            ft_pb(arr);
            ft_sb(arr);
            ft_pb(arr);
        }
        if (arr->stack_b[i] < arr->stack_b[i + 1] && arr->stack_b[i] < arr->stack_b[i + 2] && arr->stack_b[i + 1] > arr->stack_b[i + 2])
        {
            ft_pa(arr);
            ft_pa(arr);
            ft_rb(arr);
            ft_sa(arr);
            ft_pb(arr);
            ft_rrb(arr);
            ft_pb(arr);
        }
        if (arr->stack_b[i] < arr->stack_b[i + 1] && arr->stack_b[i] > arr->stack_b[i + 2] && arr->stack_b[i + 1] > arr->stack_b[i + 2])
            ft_sb(arr);
        if (arr->stack_b[i] > arr->stack_b[i + 1] && arr->stack_b[i] < arr->stack_b[i + 2] && arr->stack_b[i + 1] < arr->stack_b[i + 2])
        {
            ft_pa(arr);
            ft_sb(arr);
            ft_pb(arr);
            ft_sb(arr);

        }
    }
    if (arr->block_count_b[l] == 2 && !(is_sorted_for_block_b(arr, l)))
        ft_sb(arr);
}


int main(void)
{
    int i;
    //int *array;
    //int array_len;
    t_main arr;

    // arr.mediana = 48;
    int l = 0;
    arr.stack_b = malloc(sizeof(int) * 5);
    arr.stack_a = malloc(sizeof(int) * 5);
    arr.block_b = malloc(sizeof(int) * 5);
    arr.stack_a[0] = 452;
    arr.stack_a[1] = 9;
    arr.stack_a[2] = 48;
    // arr.stack_a[3] = 12;
    // arr.stack_a[4] = 234;
    arr.stack_b[0] = 3;
    arr.stack_b[1] = 6;
    //arr.stack_b[2] = 5;
    arr.num_a = 3;
    arr.num_b = 2;
    // arr.stack_b[3] = 0;
    // arr.stack_b[4] = 0;
    // arr.block_a = malloc(sizeof(int) * 5);
    // arr.block_b = malloc(sizeof(int) * 5);
    //array_len = 4;
    //arr.block_count_a[l] = 3;
    arr.block_count_b[l] = 2;
    // arr.block_a[0] = -2;
    // arr.block_a[1] = 1;
    // arr.block_a[2] = 3;
    // arr.block_a[3] = 5;
    // arr.block_a[4] = 9;
    //mediana_rotating_for_a(&arr);
    //ft_pb(&arr);
    //ft_sa(&arr);
    i = 0;
    sort_for_block_count(&arr, l);
    //printf("-------------------\n");
    while (i < arr.block_count_b[l])
        printf("%d\n", arr.stack_b[i++]);
    printf("\n");
    // i = 0;
    // while (i < arr.num_b + 3)
    //         printf("%d\n", arr.stack_b[i++]);

    return (0);
}