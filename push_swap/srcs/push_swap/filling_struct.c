/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:09:22 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/06 17:04:41 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi_push_swap(char *str)
{
    int i;
    int j;
    int sign;
    long long int nbr;

    i = 0;
    j = 0;
    sign = 1;
    nbr = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' 
            || str[i] == '\n' || str[i] == '\f')
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = (nbr * 10) + (str[i++] - '0');
        j++;
    }
    if (j > 11 || nbr > 2147483647 || nbr < -2147483648)
        return (0);                                        //!!!!!!!!!!!!
    return (nbr * sign);
}

void fill_struct(t_main *arr, int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    arr->stack_a = malloc(sizeof(int) * argc);
    arr->stack_b = malloc(sizeof(int) * argc);
    arr->block_a = malloc(sizeof(int) * argc);
    arr->block_b = malloc(sizeof(int) * argc);
    while (i < argc)
    {
        arr->stack_a[j] = ft_atoi_push_swap(argv[i]);
        i++;
        j++;
    }
    arr->num_b = 0;
    arr->num_a = argc - 1;
}

//// To add the case when memory is not allocated

// Work correctly 