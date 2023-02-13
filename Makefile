# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chris <chris@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:39:27 by cgodecke          #+#    #+#              #
#    Updated: 2023/02/13 19:11:58 by chris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
#CC_FLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = -crs
INFILES = 	main.c\
			helper/*.c\
			list/*.c\
			operations/*.c\

OBJFILES = $(INFILES:%.c=%.o)
OBJDIR = obj
BONUSFILES = 	ft_printf_bonus.c\
				ft_print_flags_bonus.c\
				ft_put_single.c\
				ft_put_str.c\
				ft_putnbr_base.c\

OBJBONUSFILES = $(BONUSFILES:.c=.o)

LIBFTOBJFILES = libft/*.o
HELPEROBJFILES = helper/*.o
LISTOBJFILES = list/*.o		
OPERATIONSOBJFILES = operations/*.o		

BONUSOBJFILES = $(BONUSFILES:.c=.o)

NAME = push_swap

$(NAME): $(OBJFILES)
	cd libft && $(MAKE)
	cd helper && $(MAKE)
	cd list && $(MAKE)
	cd operations && $(MAKE)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJFILES) $(LIBFTOBJFILES)
#$(AR)  $(AR_FLAGS) $(NAME) $(OBJFILES) $(LIBFTOBJFILES)
#$(HELPEROBJFILES) $(LISTOBJFILES) $(OPERATIONSOBJFILES)

%.o: %.c
	$(CC) -c $(CC_FLAGS) $^

#%.o: %.c
#$(CC) -c $(CC_FLAGS) $< -o $@
	
all: $(NAME)

clean:
	rm -f $(OBJFILES) $(BONUSOBJFILES)
	cd libft && $(MAKE) clean

fclean: 	clean
	rm -f $(NAME)
	rm *.o
	cd libft && $(MAKE) fclean
	
bonus: $(OBJBONUSFILES)
	cd libft && $(MAKE)
	$(AR)  $(AR_FLAGS) $(NAME) $(BONUSOBJFILES) $(LIBFTOBJFILES)

re: fclean all

.PHONY: all clean fclean bonus re