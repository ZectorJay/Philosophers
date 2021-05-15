# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 15:52:53 by hmickey           #+#    #+#              #
#    Updated: 2021/05/15 13:05:13 by hmickey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_three

SRCS		=	eat_sleep_think.c \
				philo_three_utils.c \
				philo_three_utils2.c \
				philo_three_utils3.c \
				philo_three.c \

OBJS		= ${SRCS:.c=.o}

CC			= gcc
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror

.c.o:		= ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				${CC} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
