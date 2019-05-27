/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:10:56 by mrolfe            #+#    #+#             */
/*   Updated: 2019/05/27 17:56:27 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_algorithm(t_main *arr)
{
    while (!(is_sorted(arr)))
    {
        while (arr->num_a > 3)
            mediana_rotating_for_a(arr);
        while (arr->num_b > 3)
            mediana_rotating_for_b(arr);
        if (arr->num_a <= 3 || arr->num_b <= 3)
            sorting_three(arr);          
    }
}

void sorting_three(t_main *arr)
{
    if (arr->num_a <= 3)
    {
        while (!(is_sorted(arr)))
        {
            ft_sa(arr);
            while (!(is_sorted(arr)))
                ft_rra(arr);
        }
    }
    if (arr->num_b <= 3)
    {
        while (!(is_sorted(arr)))
        {
            ft_sb(arr);
            ft_rrb(arr);
        }
    }
}

int is_sorted(t_main *arr)
{
    int i;

    i = 0;
    if (arr->num_b == 0)
    {
        while (i < arr->num_a - 1)
        {
            if (arr->stack_a[i] < arr->stack_a[i + 1])
                i++;
            else
                return (0);
        }
    }
    if (i == arr->num_a - 1)
        return (1);
    else
        return (0);
}

void mediana_rotating_for_a(t_main *arr)
{
    int i;
    int sum;
    int mediana;

    i = 0;
    sum = 0;
    mediana = 0;
    while (i < arr->num_a)
    {
        sum += arr->stack_a[i];
        i++;
    }
    mediana = sum / arr->num_a;
    i = 0;
    if (arr->stack_a[i] >= mediana)
        ft_ra(arr);
    else
        ft_pa(arr);
}

void mediana_rotating_for_b(int *array, t_main *arr)
{
    int i;
    int sum;
    int mediana;

    i = 0;
    sum = 0;
    mediana = mediana_finding(array, arr);
    if (arr->stack_b[i] >= mediana)
        ft_rb(arr);
    else
        ft_pb(arr);
}

int *bubble_sort(t_main *arr)
{
    int i;
    int j;
    int tmp;
    int *array;

    i = 0;
    j = 1;
    array = malloc(sizeof(int) * arr->num_a);
    array = ft_strcpy(array, arr->stack_a);
    while (j != arr->num_a)
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
    if (is_bubble_sorted(array, arr))
        return (array);
    else
        bubble_sort(arr);
    return (array);
}


int is_bubble_sorted(int *array, t_main *arr)
{
    int i;

    i = 0;
    while (i < arr->num_a - 1)
    {
        if (array[i] < array[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->num_a - 1)
        return (1);
    else
        return (0);
}

int mediana_finding(int *array, t_main *arr)
{
    int i;
    int *array_f;
    int mediana;

    i = 0;
    array_f = bubble_sort(arr);
    i = arr-> num_a / 2;
    mediana = array[i];
    return (mediana);    
}

// Changed mediana finding in mediana_rotating_for_b
// Saved mediana finding in mediana_rotating_for_a
// Needed to test what variant is correct