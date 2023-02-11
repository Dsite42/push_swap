/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:58:36 by chris             #+#    #+#             */
/*   Updated: 2023/02/11 14:06:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstadd_front adds the node ’new’ at the beginning of the 
// list.
// Return: None.

#include "push_swap.h"

void	psw_lstadd_front(t_psw_list **lst, t_psw_list *new)
{
	new->next = *lst;
	*lst = new;
}
