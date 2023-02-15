/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:36 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_bonus(t_psw_list *a_list, t_psw_list *b_list)
{
	int	tmp;

	if (psw_lstsize(a_list) < 2)
		error(a_list, b_list);
	tmp = a_list->content;
	a_list->content = a_list->next->content;
	a_list->next->content = tmp;
}
