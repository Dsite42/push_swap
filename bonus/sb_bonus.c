/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:40 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb_bonus(t_psw_list *a_list, t_psw_list *b_list)
{
	int	tmp;

	if (psw_lstsize(b_list) < 2)
		error(a_list, b_list);
	tmp = b_list->content;
	b_list->content = b_list->next->content;
	b_list->next->content = tmp;
}
