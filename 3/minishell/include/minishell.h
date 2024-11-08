/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:11:58 by suham             #+#    #+#             */
/*   Updated: 2024/01/26 15:16:43 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>
# include <sys/ioctl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

# define SUCCESS	0
# define FAILURE	-1

# define TRUE	1
# define FALSE	0

/*********** utils ***********/
typedef struct s_memory
{
	void			*address;
	struct s_memory	*next;
}	t_memory;

void	*do_calloc(size_t size, t_memory **memory);
void	do_free(void *target, t_memory **memory);
void	do_free_all(t_memory **memory);
void	do_exit(int status, t_memory **memory);
pid_t	do_fork(t_memory **memory);
void	do_dup2(int old_fd, int new_fd, char *str);
char	*do_readline(char *prompt, t_memory **memory);

size_t	str_len(char *str);
size_t	str_len_until_chr(char *str, char chr);
char	str_cmp(char *str_1, char *str_2);
char	str_cmp_by_n(char *str_1, char *str_2, size_t n);
void	str_cpy(char *dst, char *src);
void	str_cpy_by_n(char *dst, char *src, size_t n);
char	*str_dup(char *src, t_memory **memory);
char	*str_dup_by_n(char *str, size_t n, t_memory **memory);
char	*str_join(char *dst, char *src, size_t src_len, t_memory **memory);
char	**str_split_by_chr(char *str, char chr, t_memory **memory);
char	*str_find_chr(char *str, char *chrset);
char	*str_itoa(int num, t_memory **memory);
int		str_atoi(char *str);

size_t	strs_len(char **strs);
char	**strs_dup(char **src, t_memory **memory);
char	**strs_append(char **strs, char *new_str, t_memory **memory);
char	**strs_remove(char **strs, char *target, t_memory **memory);

/*********** context ***********/

// Token type
# define COMMON					0b1
# define FILE_IN				0b10
# define FILE_OUT				0b100
# define FILE_OUT_APPEND		0b1000
# define HEREDOC				0b10000
# define HEREDOC_END			0b100000
# define HEREDOC_END_WITH_QUOTE	0b1000000
# define PIPE					0b10000000

# define FILE_NAME				"./tmp"

typedef struct s_token
{
	char			*value;
	int				type;

	struct s_token	*next;
}	t_token;

typedef struct s_tokens
{
	t_token			*token;
	int				idx;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_exec
{
	t_token	*current_token;
	int		idx;
	int		pid;
	char	**path;
	char	**cmds;
	char	*cmd;
	char	*p_cmd;
}	t_exec;

typedef struct s_context
{
	t_memory	*memory;
	char		**env;

	char		*input;
	t_token		*raw_token;
	t_tokens	*tokens;

	int			cmd_cnt;
	int			fd[2];
	int			before_out_fd;
	char		*home;
}	t_context;

void	tokenize_str(t_token **head, char *str, t_memory **memory);
void	token_append(t_token **head, char *value, t_memory **memory);
void	token_assign_type(t_token *head);
void	token_remove_all(t_token *head, t_memory **memory);
int		token_validate_syntax(t_token *token);
void	token_expand(t_token *head, char **env, t_memory **memory);
int		token_len(t_token *head);

void	tokens_append(t_tokens **head, t_token *token, t_memory **memory);
void	tokens_separate(t_tokens **new, t_token *token, t_memory **memory);
int		tokens_len(t_tokens *head);
char	*tokens_get_cmd(t_tokens *head, t_memory **memory);

char	*env_find(char *key, char **env, t_memory **memory);
char	**env_sort(char **env, t_memory **memory);
char	**env_update(char *src, char **env, t_memory **memory);
char	*env_get_value(char *key, char **env, t_memory **memory);
char	**env_delete(char *key, char **env, t_memory **memory);
void	env_expand(char **new, char **ptr, char **env, t_memory **memory);

int		heredoc(t_context *context, t_memory **memory);
t_token	*heredoc_parsing(char *delimiter, t_memory **memory);
void	heredoc_expand(t_token *head, char **env, int type, t_memory **memory);
void	heredoc_to_file(t_token *head, int idx, t_memory **memory);

int		execution(t_context *context, t_memory **memory);
int		execute_cmd(t_context *context, char *cmd, int idx, t_memory **memory);
int		is_builtin(char *cmd);
t_exec	*init_exec(t_context *context, char *cmd, int idx, t_memory **memory);
void	pipe_and_execute(t_context *context, int *pids, t_memory **memory);
void	exit_child(t_context *context, int *pids, t_memory **memory);

void	execute_builtin(t_context *context, char **cmds);
void	builtin_cd(t_context *context, char **cmds);
void	print_error(char *errmsg, int exit_code);
void	builtin_echo(char **cmds);
void	builtin_env(char **cmds, char **env);
void	builtin_exit(char **cmds, t_memory **memory);
void	builtin_export(t_context *context, char **cmds);
void	builtin_pwd(char **cmds);
void	builtin_unset(t_context *context, char **cmds);

void	handle_infile(char *target, t_memory **memory);
void	handle_outfile(char *target, t_memory **memory);
void	handle_outfile_append(char *target, t_memory **memory);

int		handle_infile_single(char *target);
int		handle_outfile_single(char *target);
int		handle_outfile_append_single(char *target);

int		get_input(t_context *context);
int		parse_input_to_tokens(t_context *context);
int		execute_tokens_as_cmd(t_context *context);

void	sig_handler_main(int sig);
void	sig_handler_heredoc(int sig);

#endif
