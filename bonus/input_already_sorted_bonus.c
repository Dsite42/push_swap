/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_already_sorted_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:38:31 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:00 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	input_already_sorted(t_psw_list *a_list, t_psw_list *b_list,
			char *new_input)
{
	if (new_input == NULL && is_sorted(a_list) == 1 && psw_lstsize(b_list) == 0)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
}
