# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chris <chris@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:39:27 by cgodecke          #+#    #+#              #
#    Updated: 2023/02/13 18:10:23 by chris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
#CC_FLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = -crs
INFILES = 	*.c\

OBJFILES = $(INFILES:%.c=%.o)
BONUSFILES = 	ft_printf_bonus.c\
				ft_print_flags_bonus.c\
				ft_put_single.c\
				ft_put_str.c\
				ft_putnbr_base.c\

OBJBONUSFILES = $(BONUSFILES:.c=.o)

BONUSOBJFILES = $(BONUSFILES:.c=.o)

NAME = push_swap

$(NAME): $(OBJFILES)
	$(CC) -c $(CC_FLAGS) $^

%.o: %.c
	$(CC) -c $(CC_FLAGS) $^
	
all: $(NAME)

clean:
	rm -f $(OBJFILES) $(BONUSOBJFILES)

fclean: 	clean
	rm -f $(NAME)
	
bonus: $(OBJBONUSFILES)
	$(AR)  $(AR_FLAGS) $(NAME) $(BONUSOBJFILES) $(LIBFTOBJFILES)

re: fclean all

.PHONY: all clean fclean bonus re