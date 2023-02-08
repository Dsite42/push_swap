/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:45:02 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/08 18:59:08 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <strings.h>
# include <stdlib.h>
//# include <stddef.h>
//# include <unistd.h>

typedef struct s_psw_list
{
	int					content;
	//int			position;

	struct s_psw_list	*next;
}						t_psw_list;



t_psw_list	*psw_lstnew(int content);
t_psw_list	*create_list(char **argv);
void	psw_lstadd_back(t_psw_list **lst, t_psw_list *new);


#endif