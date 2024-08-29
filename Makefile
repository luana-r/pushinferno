# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 17:54:23 by lsouza-r          #+#    #+#              #
#    Updated: 2024/08/28 20:42:58 by lsouza-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CFLAGS := -Wextra -Wall -Werror -g3

HEADER := -I include 

SRC := src/push_swap.c \
			src/cmd_push.c \
			src/cmd_rev_rotate.c \
			src/cmd_swap.c \
			src/cmd_rotate.c \
			src/sort.c \
			src/sort_three.c \
			src/stack_init.c \
			src/utils.c \
			src/sort_2.c \
			src/sort_3.c

OBJS := ${SRC:src/%.c=obj/%.o}

all: ${NAME}

${NAME}: ${OBJS}
		@${CC} ${OBJS} ${HEADER} -o ${NAME}

obj/%.o: src/%.c
		@mkdir -p ${dir $@}
		@${CC} ${CFLAGS} -o $@ -c $< ${HEADER}

clean:
		@rm -rf obj

fclean: clean
		@rm -f ${NAME}

re: fclean all