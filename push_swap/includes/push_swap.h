/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:44:05 by mrolfe            #+#    #+#             */
/*   Updated: 2019/05/28 18:21:43 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int num_a;
    int num_b;
    int num;
    int *array;
    int mediana;
    int block_count_a;
    int block_count_b;
}              t_main;

int check_symbols(int argc, char **argv);
int check_duplicates(t_main *arr);
int check_all(t_main *arr, int argc, char **argv);
int ft_atoi_push_swap(char *str);
void fill_struct(t_main *arr, int argc, char **argv);
void ft_sa(t_main *arr);
void ft_sb(t_main *arr);
void ft_ss(t_main *arr);
void ft_pa(t_main *arr);
void ft_pb(t_main *arr);
void ft_ra(t_main *arr);
void ft_rb(t_main *arr);
void ft_rr(t_main *arr);
void ft_rra(t_main *arr);
void ft_rrb(t_main *arr);
void ft_rrr(t_main *arr);
int main(int argc, char **argv);
void main_algorithm(t_main *arr);
void sorting_three(t_main *arr);
int is_sorted(t_main *arr);
void mediana_rotating_for_a(t_main *arr);
void mediana_rotating_for_b(t_main *arr);
void bubble_sort(t_main *arr);
int is_bubble_sorted(t_main *arr);
void mediana_finding(t_main *arr);
void filling_array(t_main *arr);

#endif