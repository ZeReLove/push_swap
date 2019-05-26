/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:26:19 by mrolfe            #+#    #+#             */
/*   Updated: 2019/05/26 19:20:42 by mrolfe           ###   ########.fr       */
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
    tmp = 0;
    tmp = i;
    i = j;
    j = tmp;
}

void ft_sb(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->stack_b[0];
    j = arr->stack_b[1];
    tmp = 0;
    tmp = i;
    i = j;
    j = tmp;
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
    while (i + 1 < arr->num_a)
    {
        arr->stack_a[i] = arr->stack_a[i + 1];
        i++;
    }
}
