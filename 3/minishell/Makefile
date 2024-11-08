CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=minishell
OBJDIR=obj

INCLUDES = -I include
LDFLAGS = -lreadline

SRCS=src/main.c \
     src/builtin/builtin_cd.c \
     src/builtin/builtin_cd_util.c \
     src/builtin/builtin_echo.c \
     src/builtin/builtin_env.c \
     src/builtin/builtin_exit.c \
     src/builtin/builtin_export.c \
     src/builtin/builtin_pwd.c \
     src/builtin/builtin_unset.c \
     src/context/env_delete.c \
     src/context/env_expand.c \
     src/context/env_find.c \
     src/context/env_get_value.c \
     src/context/env_sort.c \
     src/context/env_update.c \
     src/context/token_append.c \
     src/context/token_assign_type.c \
     src/context/token_expand.c \
     src/context/token_len.c \
     src/context/token_remove_all.c \
     src/context/token_validate_syntax.c \
     src/context/tokenize_str.c \
     src/context/tokens_append.c \
     src/context/tokens_get_cmd.c \
     src/context/tokens_len.c \
     src/context/tokens_separate.c \
     src/execution/excute_multi_cmd.c \
     src/execution/execute_builtin.c \
     src/execution/execute_cmd.c \
     src/execution/execute_tokens_as_cmd.c \
     src/execution/execution.c \
     src/execution/handle_redirect.c \
     src/execution/handle_redirect_single.c \
     src/execution/init_exec.c \
     src/execution/init_exec_sub.c \
     src/execution/is_builtin.c \
     src/heredoc/heredoc.c \
     src/heredoc/heredoc_expand.c \
     src/heredoc/heredoc_parsing.c \
     src/heredoc/heredoc_to_file.c \
     src/parsing/get_input.c \
     src/parsing/parse_input_to_tokens.c \
     src/utils/do_calloc.c \
     src/utils/do_dup2.c \
     src/utils/do_exit.c \
     src/utils/do_fork.c \
     src/utils/do_free.c \
     src/utils/do_free_all.c \
     src/utils/do_readline.c \
     src/utils/sig_handler.c \
     src/utils/str_atoi.c \
     src/utils/str_cmp.c \
     src/utils/str_cmp_by_n.c \
     src/utils/str_cpy.c \
     src/utils/str_cpy_by_n.c \
     src/utils/str_dup.c \
     src/utils/str_dup_by_n.c \
     src/utils/str_find_chr.c \
     src/utils/str_itoa.c \
     src/utils/str_join.c \
     src/utils/str_len.c \
     src/utils/str_len_until_chr.c \
     src/utils/str_split_by_chr.c \
     src/utils/strs_append.c \
     src/utils/strs_dup.c \
     src/utils/strs_len.c \
     src/utils/strs_remove.c

OBJS=$(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re