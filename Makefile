# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:39:27 by cgodecke          #+#    #+#              #
#    Updated: 2023/02/22 10:02:05 by cgodecke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CC_FLAGS = -g #-Wall -Wextra -Werror
AR = ar
AR_FLAGS = -crs
INFILES = 	main.c\
			helper/*.c\
			list/*.c\
			operations/*.c\

BONUSFILES = 	checker.c\
				helper/*.c\
				list/*.c\
				operations/*.c\
				bonus/*.c\
				get_next_line/*.c\

BONUSOBJFILES = $(BONUSFILES:.c=.o)

NAME = push_swap
NAME_BONUS = checker

$(NAME):
	cd libft && $(MAKE)
#	cd helper && $(MAKE)
#	cd list && $(MAKE)
#	cd operations && $(MAKE)
	$(CC) $(CC_FLAGS) -o $(NAME) $(INFILES) libft/libft.a
#$(AR)  $(AR_FLAGS) $(NAME) $(OBJFILES) $(LIBFTOBJFILES)
#$(HELPEROBJFILES) $(LISTOBJFILES) $(OPERATIONSOBJFILES)

#%.o: %.c
#	$(CC) $(CC_FLAGS) $^

#%.o: %.c
#$(CC) -c $(CC_FLAGS) $< -o $@
	
all: $(NAME)

clean:
	rm -f $(OBJFILES) $(BONUSOBJFILES)
	cd libft && $(MAKE) clean

fclean: 	clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	cd libft && $(MAKE) fclean
	
bonus:
	cd libft && $(MAKE)
	$(CC) $(CC_FLAGS) -o $(NAME_BONUS) $(BONUSFILES) libft/libft.a

re: fclean all

.PHONY: all clean fclean bonus re