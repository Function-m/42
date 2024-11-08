# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 21:23:48 by suham             #+#    #+#              #
#    Updated: 2024/01/04 21:23:49 by suham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC_BONUS = ft_string_bonus/ft_strchr_bonus.c ft_string_bonus/ft_strlen_num_bonus.c ft_string_bonus/ft_memcpy_bonus.c ft_string_bonus/ft_strlen_unum_bonus.c ft_string_bonus/ft_strlen_bonus.c ft_buffer_bonus/ft_lstloop_bonus.c ft_buffer_bonus/ft_bufjoin_bonus.c ft_buffer_bonus/ft_num_tostr_bonus.c ft_buffer_bonus/ft_chr_tostr_bonus.c ft_buffer_bonus/ft_str_tostr_bonus.c ft_buffer_bonus/ft_null_tostr_bonus.c ft_buffer_bonus/ft_lsttail_bonus.c ft_buffer_bonus/ft_unum_tostr_bonus.c ft_buffer_bonus/ft_lstadd_bonus.c ft_buffer_bonus/ft_lstnew_bonus.c ft_buffer_bonus/ft_lstcombine_bonus.c ft_printf_bonus/ft_printf_bonus.c ft_printf_bonus/_ftpf_read_str_bonus.c ft_printf_bonus/_ftpf_read_arg_one_bonus.c ft_printf_bonus/_ftpf_apply_precision_bonus.c ft_printf_bonus/_ftpf_end_bonus.c ft_printf_bonus/_ftpf_extra_read_bonus.c ft_printf_bonus/_ftpf_extra_apply_bonus.c ft_printf_bonus/_ftpf_apply_width_bonus.c ft_printf_bonus/_ftpf_read_arg_two_bonus.c ft_printf_bonus/_ftpf_read_bonus.c ft_printf_bonus/_ftpf_print_bonus.c ft_printf_bonus/_ftpf_apply_rmprefix_bonus.c ft_printf_bonus/_ftpf_apply_addprefix_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

ifdef BONUS_FLAG

HEADER_DIR = include_bonus

SRC = $(SRC_BONUS)
OBJ = $(OBJ_BONUS)

else

HEADER_DIR = include

SRC = ft_buffer/ft_lstadd.c ft_buffer/ft_null_tostr.c ft_buffer/ft_lstnew.c ft_buffer/ft_chr_tostr.c ft_buffer/ft_str_tostr.c ft_buffer/ft_lstcombine.c ft_buffer/ft_unum_tostr.c ft_buffer/ft_bufjoin.c ft_buffer/ft_lstloop.c ft_buffer/ft_lsttail.c ft_buffer/ft_num_tostr.c ft_string/ft_strlen.c ft_string/ft_strlen_num.c ft_string/ft_strchr.c ft_string/ft_memcpy.c ft_string/ft_strlen_unum.c ft_printf/_ftpf_read_str.c ft_printf/_ftpf_end.c ft_printf/ft_printf.c ft_printf/_ftpf_read_arg_two.c ft_printf/_ftpf_print.c ft_printf/_ftpf_read.c ft_printf/_ftpf_read_arg_one.c 
OBJ = $(SRC:.c=.o)

endif

all: $(NAME)

bonus:
	$(MAKE) BONUS_FLAG=1 all

$(NAME): $(OBJ)	
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
