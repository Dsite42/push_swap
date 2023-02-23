# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:39:27 by cgodecke          #+#    #+#              #
#    Updated: 2023/02/23 13:14:17 by cgodecke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CC_FLAGS = -Wall -Wextra -Werror
OBJDIR = obj
INFILES = 	helper/calc_single_index.c\
			helper/error.c\
			helper/rr_cost_optimization.c\
			helper/update_lists.c\
			helper/clear_node_cost_values.c\
			helper/is_duplicate.c\
			helper/rrr_cost_optimization.c\
			helper/clear_stack_values.c\
			helper/is_sorted.c\
			helper/rx_rrx_costs.c\
			helper/copy_node_cost_values.c\
			helper/psw_lstsize.c\
			helper/seed_to_next_nbr.c\
				list/cheapest_node.c\
				list/create_lst_from_str.c\
				list/find_node_b.c\
				list/psw_lstdelone.c\
				list/psw_lstnew.c\
				list/create_lst_from_args.c\
				list/find_node_a.c\
				list/psw_lstclear.c\
				list/psw_lstlast.c\
			operations/pa.c\
			operations/ra.c\
			operations/rr.c\
			operations/run_rotate.c\
			operations/pb.c\
			operations/rb.c\
			operations/rra.c\
			operations/sa.c\
			operations/psw_lstadd_back.c\
			operations/rotate_all.c\
			operations/rrb.c\
			operations/sort_three.c\
			operations/psw_lstadd_front.c\
			operations/rotate_to_min.c\
			operations/rrr.c\
			operations/swap_all_to_a.c\
				main.c\

OBJFILES = $(INFILES:%.c=$(OBJDIR)/%.o)

BONUSFILES = 	helper/calc_single_index.c\
				helper/error.c\
				helper/rr_cost_optimization.c\
				helper/update_lists.c\
				helper/clear_node_cost_values.c\
				helper/is_duplicate.c\
				helper/rrr_cost_optimization.c\
				helper/clear_stack_values.c\
				helper/is_sorted.c\
				helper/rx_rrx_costs.c\
				helper/copy_node_cost_values.c\
				helper/psw_lstsize.c\
				helper/seed_to_next_nbr.c\
					list/cheapest_node.c\
					list/create_lst_from_str.c\
					list/find_node_b.c\
					list/psw_lstdelone.c\
					list/psw_lstnew.c\
					list/create_lst_from_args.c\
					list/find_node_a.c\
					list/psw_lstclear.c\
					list/psw_lstlast.c\
				operations/pa.c\
				operations/ra.c\
				operations/rr.c\
				operations/run_rotate.c\
				operations/pb.c\
				operations/rb.c\
				operations/rra.c\
				operations/sa.c\
				operations/psw_lstadd_back.c\
				operations/rotate_all.c\
				operations/rrb.c\
				operations/sort_three.c\
				operations/psw_lstadd_front.c\
				operations/rotate_to_min.c\
				operations/rrr.c\
				operations/swap_all_to_a.c\
					bonus/check_result_bonus.c\
					bonus/psw_strjoin_free_bonus.c\
					bonus/rr_bonus.c\
					bonus/run_operation_bonus.c\
					bonus/input_already_sorted_bonus.c\
					bonus/rra_bonus.c\
					bonus/sa_bonus.c\
					bonus/pa_bonus.c\
					bonus/ra_bonus.c\
					bonus/rrb_bonus.c\
					bonus/sb_bonus.c\
					bonus/pb_bonus.c\
					bonus/rb_bonus.c\
					bonus/rrr_bonus.c\
					bonus/ss_bonus.c\
				get_next_line/get_next_line_bonus.c\
				get_next_line/get_next_line_utils_bonus.c\
					checker.c\

BONUSOBJFILES = $(BONUSFILES:%.c=$(OBJDIR)/%.o)

NAME = push_swap
NAME_BONUS = checker

all: setup $(NAME)

$(NAME): $(OBJFILES)
	cd libft && $(MAKE)
	$(CC) $(CC_FLAGS) $(OBJFILES) -o $(NAME)  libft/libft.a

$(OBJDIR)/%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

setup:
	@mkdir -p $(OBJDIR)/obj
	@mkdir -p $(OBJDIR)/helper
	@mkdir -p $(OBJDIR)/list
	@mkdir -p $(OBJDIR)/operations
	@mkdir -p $(OBJDIR)/bonus
	@mkdir -p $(OBJDIR)/get_next_line/

clean:
	rm -f $(OBJFILES) $(BONUSOBJFILES)
	rm -r -f obj/
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	cd libft && $(MAKE) fclean
	
bonus: all $(BONUSOBJFILES)
	$(CC) $(CC_FLAGS) $(BONUSOBJFILES) -o $(NAME_BONUS)  libft/libft.a

re: fclean all

.PHONY: all clean fclean bonus re