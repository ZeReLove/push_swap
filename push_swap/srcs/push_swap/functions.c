/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:26:19 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/04 18:13:06 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void ft_ss(t_main *arr)
{
    ft_sa(arr);
    ft_sb(arr);
}

void ft_pa(t_main *arr)
{
    int i;
    int tmp;

    i = 0;
    tmp = arr->stack_b[0];
    while (i + 1 < arr->num_a)
    {
        arr->stack_a[i + 1] = arr->stack_a[i];
        i++;
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
    int j;
    int tmp;

    i = 0;
    j = 0;
    arr->num_b++;
    tmp = arr->stack_a[0];
    while (i + 1 < arr->num_b)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i++;
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

// CHANGED PB, NEDEED TO CHANGE PA  

void copying_arrays_to_stacks2(t_main *arr)
{
    int i;
    int j;

    i = 0;
    j = 0;
    arr->num_a2 = arr->num_a - 1;
    arr->num_b2 = arr->num_b + 1;
    arr->stack_a2 = malloc(sizeof(int) * arr->num_a2);
    arr->stack_b2 = malloc(sizeof(int) * arr->num_b2);
    while (i < arr->num_a2)
    {
        arr->stack_a2[i] = arr->stack_a[j];
        i++;
        j++;
    }
    while (i < arr->num_b2)
    {
        arr->stack_b2[i] = arr->stack_b[j];
        i++;
        j++;
    }
}

void copying_arrays_to_stacks(t_main *arr)
{
    int i;
    int j;

    i = 0;
    j = 0;
    arr->stack_a = malloc(sizeof(int) * arr->num_a2);
    arr->stack_b = malloc(sizeof(int) * arr->num_b2);
    while (i < arr->num_a)
    {
        arr->stack_a[i] = arr->stack_a2[j];
        i++;
        j++;
    }
    while (i < arr->num_b)
    {
        arr->stack_b[i] = arr->stack_b2[j];
        i++;
        j++;
    }
}
