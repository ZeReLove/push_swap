/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana_functions_for_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:12:36 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/06 13:16:44 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(t_main *arr)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = 1;
    while (j != arr->num_a)
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

void filling_array(t_main *arr)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!(arr->array = malloc(sizeof(int) * (arr->num_a + 1))))
        return ;
    while(i < arr->num_a)
    {
        arr->array[i] = arr->stack_a[j];
        i++;
        j++;
    }
}

int is_bubble_sorted(t_main *arr)
{
    int i;

    i = 0;
    while (i < arr->num_a - 1)
    {
        if (arr->array[i] < arr->array[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->num_a - 1)
        return (1);
    else
        return (0);
}

void mediana_finding_for_a(t_main *arr)
{
    int i;
    int mediana;

    i = 0;
    filling_array(arr);
    bubble_sort(arr);
    i = arr->num_a / 2;
    mediana = arr->array[i];
    arr->mediana = mediana;    
}

