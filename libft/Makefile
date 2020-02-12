
SRCS	=	ft_isdigit.c \
			ft_memmove.c \
			ft_strchr.c	\
			ft_strncmp.c \
			ft_atoi.c \
			ft_isprint.c \
			ft_memset.c \
			ft_strdup.c \
			ft_strnstr.c \
			ft_bzero.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_strjoin.c \
			ft_strrchr.c \
			ft_calloc.c	\
			ft_memccpy.c \
			ft_putendl_fd.c \
			ft_strlcat.c \
			ft_strtrim.c \
			ft_isalnum.c \
			ft_memchr.c \
			ft_putnbr_fd.c \
			ft_strlcpy.c \
			ft_substr.c \
			ft_isalpha.c \
			ft_memcmp.c \
			ft_putstr_fd.c \
			ft_strlen.c \
			ft_tolower.c \
			ft_isascii.c \
			ft_memcpy.c \
			ft_split.c \
			ft_strmapi.c \
			ft_toupper.c \
			ft_nbrlen.c \
			ft_unbrlen.c \
			ft_puthex_fd.c \
			ft_strjoin_free.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c


BONUS	= ft_lstnew_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJSB	= ${BONUS:.c=.o}

NAME	= libft.a

.c.o :		gcc -Wall -Wextra -Werror ${SRCS} ${BONUS}

${NAME} :	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all :		${NAME}

clean : 	
			rm -rf ${OBJS} ${OBJSB}

fclean :	clean
			rm -rf ${NAME}

re :		fclean all

bonus :		${OBJS} ${OBJSB}
			ar rc ${NAME} ${OBJS} ${OBJSB}
			ranlib ${NAME}

.PHONY:		all clean fclean re bonus
