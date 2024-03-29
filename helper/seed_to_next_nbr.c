/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed_to_next_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:05:39 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/14 18:08:47 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	seed_to_next_nbr(char **str)
{
	while (**str != ' ' && **str != '\0')
	{
		*str = *str + 1;
	}
	if (**str != '\0')
		*str = *str + 1;
}
