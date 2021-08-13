#Compiler and Linker
CC				= 	gcc

#The Directories, Source, Includes, Objects, Binary and Resources
EXECUTABLE		= 	push_swap \
					checker

DEBUG			= 	${wildcard *.dSYM}

MAIN			=   sources/main.c

SRCS_UTILS		= 	${wildcard sources/utils/*.c}

SRCS_CHECKER	=	${wildcard sources/checker/*.c}

SRCS_PUSH_SWAP	=	${wildcard sources/push_swap/*.c}

SRCS_GNL		=	${wildcard get_next_line/*.c}


OBJS_CHECKER			= 	$(SRCS_UTILS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_PUSH_SWAP:.c=.o) $(SRCS_CHECKER:.c=.o)
OBJS_PUSH_SWAP			= 	$(SRCS_UTILS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_PUSH_SWAP:.c=.o) $(MAIN:.c=.o)

RM				= 	rm -f

#Flags, Libraries and Includes
CFLAGS			= 	-Wall -Wextra -Werror -g
GNL				= 	get_next_line/get_next_line.c
all:			push_swap checker

push_swap:		$(OBJS_PUSH_SWAP)
				gcc ${CFLAGS} -o push_swap $(OBJS_PUSH_SWAP)

checker:		$(OBJS_CHECKER)
				gcc ${CFLAGS} -o checker $(OBJS_CHECKER)

clean:
				rm -f  $(OBJS)
				rm -f  $(OBJS_CHECKER)
				rm -f  $(OBJS_PUSH_SWAP)
				rm -f ${EXECUTABLE}
				rm -rf ${DEBUG}

fclean:			clean
				$(RM) $(OBJS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

