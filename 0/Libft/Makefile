NAME = libft.a
HEADER = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AFLAGS = -rc
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: make_all

make_all: $(NAME)
	touch $@

$(NAME): $(OBJS)
	ar $(AFLAGS) $@ $^

$(OBJS): $(HEADER)
	$(CC) $(CFLAGS) $(SRCS)

bonus: make_bonus

make_bonus: $(OBJS_BONUS)
	ar $(AFLAGS) $(NAME) $^
	touch $@

$(OBJS_BONUS): $(HEADER)
	$(CC) $(CFLAGS) $(SRCS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS) make_bonus make_all

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re