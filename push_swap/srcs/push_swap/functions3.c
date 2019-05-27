/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:29:52 by mrolfe            #+#    #+#             */
/*   Updated: 2019/05/27 16:08:43 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ft_rra(t_main *arr)
// {
//     int i;
//     int last_el;

//     i = 0;
//     last_el = arr->stack_a[arr->num_a - 1];
//     while (i + 1 < arr->num_a)
//     {
//         arr->stack_a[i + 1] = arr->stack_a[i];
//         i++;
//     }
//     arr->stack_a[0] = last_el;
// }

void ft_rra(t_main *arr)
{
    int i;
    int last_el;

    i = arr->num_a - 2;
    last_el = arr->stack_a[arr->num_a - 1];
    while (i != -1)
    {
        arr->stack_a[i + 1] = arr->stack_a[i];
        i--;
    }
    arr->stack_a[0] = last_el;
}

void ft_rrb(t_main *arr)
{
    int i;
    int last_el;

    i = 0;
    last_el = arr->stack_b[arr->num_b];
    while (i + 1 < arr->num_b)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i++;
    }
    arr->stack_b[i] = last_el;
}

void ft_rrr(t_main *arr)
{
    ft_rra(arr);
    ft_rrb(arr);
}

void num_a_calculation(t_main *arr)
{
    int len;
    
    len = 0;
    while(arr->stack_a[len])
        len++;
    arr->num_a = len;
}

void num_b_calculation(t_main *arr)
{
    int len;
    
    len = 0;
    while(arr->stack_b[len])
        len++;
    arr->num_b = len;
}