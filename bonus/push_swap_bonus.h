/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:45:02 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:18 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../push_swap.h"

//Operations functions:
void		sa_bonus(t_psw_list *a_list, t_psw_list *b_list);
void		sb_bonus(t_psw_list *a_list, t_psw_list *b_list);
void		pa_bonus(t_psw_list **a_list, t_psw_list **b_list);
void		pb_bonus(t_psw_list **a_list, t_psw_list **b_list);
void		ra_bonus(t_psw_list **a_list, t_psw_list **b_list);
void		rra_bonus(t_psw_list **a_list, t_psw_list **b_list);
void		rb_bonus(t_psw_list **a_list, t_psw_list **b_list);
void		rrb_bonus(t_psw_list **a_list, t_psw_list **b_list);
void		rr_bonus(t_psw_list **a_list, t_psw_list **b_list);
void		rrr_bonus(t_psw_list **a_list, t_psw_list **b_list);

//Helper functions:
char		*psw_strjoin_free(char const *s1, char const *s2);
void		input_already_sorted(t_psw_list *a_list, t_psw_list *b_list,
				char *new_input);
void		check_result(t_psw_list *a_list, t_psw_list *b_list);

//List functions:

//void		print_stacks(t_psw_list *a_list, t_psw_list *b_list);
#endif