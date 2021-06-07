#Compiler and Linker
CC				= 	gcc

#The Directories, Source, Includes, Objects, Binary and Resources

EXECUTABLE		= 	push_swap \
					checker \
					test

DEBUG			= 	${wildcard *.dSYM}

SRCS_UTILS		= 	${wildcard sources/utils/*.c}

SRCS_CHECKER	=	${wildcard sources/checker/*.c}

SRCS_PUSH_SWAP	=	${wildcard sources/push_swap/*.c}

SRCS_TEST		= 	${wildcard test_files/*.c}

# SRCS_TEST		= 	$(filter-out $(MAIN), $(SRCS)) \

OBJS_CHECKER			= 	$(SRCS_UTILS:.c=.o) $(SRCS_CHECKER:.c=.o)
OBJS_PUSH_SWAP			= 	$(SRCS_UTILS:.c=.o) $(SRCS_PUSH_SWAP:.c=.o)
OBJS_TEST				= 	$(SRCS_UTILS:.c=.o) $(SRCS_TEST:.c=.o)

RM				= 	rm -f

#Flags, Libraries and Includes
CFLAGS			= 	-g
# LIB_MLX			= 	-I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext
LIBFT			= 	libft/libft.a
GNL				= 	get_next_line/get_next_line.c
# CFLAGS			= -Wall -Wextra -Werror -I

all:			push_swap checker test

push_swap:		$(OBJS_PUSH_SWAP)
				cd libft && $(MAKE)
				gcc ${CFLAGS} -o push_swap $(OBJS_PUSH_SWAP) ${LIB_MLX} ${LIBFT} ${GNL}
				rm $(OBJS_PUSH_SWAP)

checker:		$(OBJS_CHECKER)
				cd libft && $(MAKE)
				gcc ${CFLAGS} -o checker $(OBJS_CHECKER) ${LIB_MLX} ${LIBFT} ${GNL}
				rm $(OBJS_CHECKER)

test:			$(OBJS_TEST)
				cd libft && $(MAKE)
				gcc ${CFLAGS} -o test ${OBJS_TEST} ${LIB_MLX} ${LIBFT} ${GNL}
				rm ${OBJS_TEST}

clean:
				rm -f  $(OBJS)
				rm -f  $(OBJS_CHECKER)
				rm -f  $(OBJS_PUSH_SWAP)
				rm -f ${EXECUTABLE}
				rm -rf ${DEBUG}
				rm -rf test/*.o

cleaner:		clean
				$(RM) $(OBJS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

