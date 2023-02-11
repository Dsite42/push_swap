/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/11 14:43:57 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	tmp = (*b_list)->next;
	psw_lstadd_back(b_list, *b_list);
	*b_list = tmp;
	write(1, "rb\n", 3);
}
