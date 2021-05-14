# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 15:52:53 by hmickey           #+#    #+#              #
#    Updated: 2021/05/14 11:02:59 by hmickey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_two

SRCS		=	eat_sleep_think.c \
				philo_two_utils.c \
				philo_two_utils2.c \
				philo_two_utils3.c \
				philo_two.c \

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
