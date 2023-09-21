#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* aux_lists.c */
sep_list *add_sep_node(sep_list **head, char sept);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* aux_lists2.c */
r_var *add_var_node(r_var **head, int l_var, char *val, int l_val);
void free_var_list(r_var **head);

/* aux_str */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *acc);

/* aux_memory.c */
void _memcpy(void *dest, const void *src, unsigned int size);
void *_realloc(void *src, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **src, unsigned int old_size, unsigned int new_size);

/* aux_str2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chrs(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* aux_str3.c */
void revs_strgs(char *s);

/* check_syntaxs_err.c */
int repetd_char(char *inpt, int i);
int err_sep_op(char *inpt, int i, char lst);
int first_char(char *inpt, int *i);
void print_syntxs_err(data_shell *datash, char *inpt, int i, int bool);
int check_syntxs_err(data_shell *datash, char *inpt);

/* shll_loop.c */
char *no_cment(char *in);
void shll_loop(data_shell *datash);

/* read_input.c */
char *read_line(int *i_ef);

/* split_func.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* repr_vars.c */
void checks_envr(r_var **h, char *in, data_shell *data);
int checks_vrs(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *repr_vars(char *input, data_shell *datash);

/* gets_liners.c */
void brings_liners(char **liners, size_t *n, char *buffers, size_t k);
ssize_t gets_liner(char **liners, size_t *n, FILE *streamer);

/* execs_lines.c */
int execs_lines(data_shell *datash);

/* cmds_execs.c */
int is_crdir(char *pth, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_err_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* env1s.c */
int cmprs_env(const char *nenvs, const char *name);
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* env2s.c */
char *cpy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

/* cd.c */
