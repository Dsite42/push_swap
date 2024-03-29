/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/21 14:26:13 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	b_list = NULL;
	tmp = (*a_list)->next;
	psw_lstadd_back(a_list, *a_list);
	*a_list = tmp;
	write(1, "ra\n", 3);
}
