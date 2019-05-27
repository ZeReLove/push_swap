typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int num_a;
    int num_b;
    int num;
}              t_main;

int is_bubble_sorted(int *array, int array_len)
{
    int i;

    i = 0;
    while (i < array_len - 1)
    {
        if (array[i] < array[i + 1])
            i++;
        else
            return (0);
    }
    if (i == array_len - 1)
        return (1);
    else
        return (0);
}

int *bubble_sort(int *array, int array_len)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = 1;
    while (j != array_len)
    {
        if (array[i] > array[j])
        {
            tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
            i++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if (is_bubble_sorted(array, array_len))
            return (array);
    else
        bubble_sort(array, array_len);
    return (array);
}

int main(void)
{
    int i;
    int *array;
    int array_len;

    i = 0;
    array = malloc(sizeof(int) * 5);
    array[0] = 5;
    array[1] = 133;
    array[2] = 9;
    array[3] = 6;
    array[4] = 4;
    array_len = 5;
    bubble_sort(array, array_len);
    while (i < array_len)
        {
            printf("%d\n", array[i]);
            i++;
        }
    return (0);
}