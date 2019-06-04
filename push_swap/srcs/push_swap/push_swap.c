/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:03:01 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/04 18:28:50 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_main arr;
    int i;

    i = 0;
    if (argc > 1)
    {
        if (check_all(&arr, argc, argv))
        {
            fill_struct(&arr, argc, argv);
            main_algorithm(&arr);
            printf("-----------\n");
            while (i < arr.num)
            {
                printf("%d\n",  arr.stack_a[i]);
                i++;
            }
            free(arr.stack_a);
            free(arr.stack_b);
        }   
    }
    return (0);
}