/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/11 14:44:05 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	tmp = (*a_list)->next;
	psw_lstadd_back(a_list, *a_list);
	*a_list = tmp;
	write(1, "ra\n", 3);
}
