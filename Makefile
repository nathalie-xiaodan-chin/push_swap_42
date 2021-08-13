# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nachin <nachin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 00:38:50 by nachin            #+#    #+#              #
#    Updated: 2021/08/14 01:33:25 by nachin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= 	gcc

CFLAGS			= 	-Wall -Wextra -Werror

NAME			= push_swap

CHECKER 		= checker

MAIN			=   sources/main.c

DIR_UTILS =		sources/utils/

DIR_CHECKER =		sources/checker/

DIR_PUSH_SWAP =	sources/push_swap/

DIR_GNL =			get_next_line/

SRCS_UTILS		= 	actions_for_push_and_swap.c \
					actions_for_reverse_and_rotate.c \
					actions_toolbox.c \
					error.c \
					free_toolbox.c \
					lib.c \
					sort.c \
					stack_toolbox.c \
					stack.c \
					toolbox.c

SRCS_CHECKER	=	checker_actions.c \
					checker_toolbox.c \
					checker.c

SRCS_PUSH_SWAP	=	five_or_four_nb.c \
					insertion_sort.c \
					pre_sorting.c \
					radix_sort.c \
					sort_toolbox_one.c \
					sort_toolbox_two.c \
					three_nb_sort.c

SRCS_GNL		= 	get_next_line.c \
					get_next_line_utils_one.c \
					get_next_line_utils_two.c

PATH_UTILS		= 	$(addprefix $(DIR_UTILS), $(SRCS_UTILS))
PATH_CHECKER	=	$(addprefix $(DIR_CHECKER), $(SRCS_CHECKER))
PATH_PUSH_SWAP	=	$(addprefix $(DIR_PUSH_SWAP), $(SRCS_PUSH_SWAP))
PATH_GNL		=	$(addprefix $(DIR_GNL), $(SRCS_GNL))

OBJS_CHECKER			= 	$(PATH_UTILS:.c=.o) $(PATH_GNL:.c=.o) $(PATH_PUSH_SWAP:.c=.o) $(PATH_CHECKER:.c=.o)
OBJS_PUSH_SWAP			= 	$(PATH_UTILS:.c=.o) $(PATH_GNL:.c=.o) $(PATH_PUSH_SWAP:.c=.o) $(MAIN:.c=.o)

RM				= 	rm -f

DEBUG			= 	${wildcard *.dSYM}

GNL				= 	get_next_line/get_next_line.c

all:			${NAME} ${CHECKER}

push_swap:		$(OBJS_PUSH_SWAP)
				gcc ${CFLAGS} -o ${NAME} $(OBJS_PUSH_SWAP)

checker:		$(OBJS_CHECKER)
				gcc ${CFLAGS} -o ${CHECKER} $(OBJS_CHECKER)

clean:
				rm -f  $(OBJS)
				rm -f  $(OBJS_CHECKER)
				rm -f  $(OBJS_PUSH_SWAP)
				rm -f ${NAME}
				rm -f ${CHECKER}
				rm -rf ${DEBUG}

fclean:			clean
				$(RM) $(OBJS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

