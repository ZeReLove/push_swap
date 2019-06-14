#include <stdio.h>
#include <stdlib.h>

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
    int n;
}              t_main;

// Old version finding mediana_for_a

int is_bubble_sorted(t_main *arr)
{
    int i;

    i = 0;
    while (i < arr->n - 1)
    {
        if (arr->array[i] < arr->array[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->n - 1)
        return (1);
    else
        return (0);
}

void bubble_sort(t_main *arr)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = 1;
    while (j != arr->n)
    {
        if (arr->array[i] > arr->array[j])
        {
            tmp = arr->array[j];
            arr->array[j] = arr->array[i];
            arr->array[i] = tmp;
            i++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if (!(is_bubble_sorted(arr)))
        bubble_sort(arr);
    else
        return ;
}

void filling_array(t_main *arr, int m)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!(arr->block_count_a[m]))
        arr->n = arr->num_b;
    else
        arr->n = arr->block_count_a[m];
    if (!(arr->array = malloc(sizeof(int) * (arr->n + 1))))
        return ;
    while(i < arr->n)
    {
        arr->array[i] = arr->stack_a[j];
        i++;
        j++;
    }
}



void mediana_finding_for_a(t_main *arr, int m)
{
    int i;
    int mediana;

    i = 0;
    filling_array(arr, m);
    bubble_sort(arr);
    i = arr->n / 2;
    mediana = arr->array[i];
    arr->mediana = mediana;
}

int main(void)
{
    t_main arr;
    int m;
    int i;
    int array_len;

    i = 0;
    m = 0;
    arr.stack_a = malloc(sizeof(int) * 5);
    arr.array = malloc(sizeof(int) * 5);
    arr.stack_a[0] = 5;
    arr.stack_a[1] = 133;
    arr.stack_a[2] = 9;
    arr.stack_a[3] = 6;
    arr.stack_a[4] = 4;
    array_len = 5;
    mediana_finding_for_a(&arr, m);
    while (i < array_len)
        {
            printf("%d\n", arr.stack_a[i]);
            i++;
        }
    return (0);
}