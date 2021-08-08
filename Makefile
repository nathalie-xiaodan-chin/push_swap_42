#Compiler and Linker
CC				= 	gcc

#The Directories, Source, Includes, Objects, Binary and Resources

EXECUTABLE		= 	push_swap \
					checker \
					test

DEBUG			= 	${wildcard *.dSYM}

MAIN            =   sources/main.c

SRCS_UTILS		= 	${wildcard sources/utils/*.c}

SRCS_CHECKER	=	${wildcard sources/checker/*.c}

SRCS_PUSH_SWAP	=	${wildcard sources/push_swap/*.c}

SRCS_TEST		= 	${wildcard test_files/*.c}

# SRCS_TEST		= 	$(filter-out $(MAIN), $(SRCS)) \

OBJS_CHECKER			= 	$(SRCS_UTILS:.c=.o) $(SRCS_PUSH_SWAP:.c=.o) $(SRCS_CHECKER:.c=.o)
OBJS_PUSH_SWAP			= 	$(SRCS_UTILS:.c=.o) $(SRCS_PUSH_SWAP:.c=.o) $(MAIN:.c=.o)
OBJS_TEST				=	$(SRCS_UTILS:.c=.o) $(SRCS_PUSH_SWAP:.c=.o) $(SRCS_TEST:.c=.o)

RM				= 	rm -f

#Flags, Libraries and Includes
# CFLAGS			= 	-Wall -Wextra -Werror -g
CFLAGS			= 	 -g

LIBFT			= 	libft/libft.a
GNL				= 	get_next_line/get_next_line.c
# CFLAGS			= -Wall -Wextra -Werror -I

all:			push_swap checker test

push_swap:		$(OBJS_PUSH_SWAP)
				cd libft && $(MAKE)
				gcc ${CFLAGS} -o push_swap $(OBJS_PUSH_SWAP) ${LIBFT} ${GNL}


checker:		$(OBJS_CHECKER)
				cd libft && $(MAKE)
				gcc ${CFLAGS} -o checker $(OBJS_CHECKER) ${LIBFT} ${GNL}


test:			$(OBJS_TEST)
				gcc -o test ${OBJS_TEST} ${LIBFT} ${GNL} ${LIBFT}


clean:
				rm -f  $(OBJS)
				rm -f  $(OBJS_CHECKER)
				rm -f  $(OBJS_PUSH_SWAP)
				rm -f ${EXECUTABLE}
				rm -rf ${DEBUG}
				rm -rf test_files/*.o

cleaner:		clean
				$(RM) $(OBJS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

