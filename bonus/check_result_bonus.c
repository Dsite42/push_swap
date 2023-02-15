/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:40:02 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:41:57 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_result(t_psw_list *a_list, t_psw_list *b_list)
{
	if (is_sorted(a_list) == 1 && psw_lstsize(b_list) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	psw_lstclear(&a_list);
	psw_lstclear(&b_list);
}
