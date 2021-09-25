NAME = pipex

HPATH = -Iincludes

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DIR_SRCS = srcs
DIR_MINILIBFT= minilibft
DIR_PIPEX = pipex
DIR_OBJS = objs
CURRENT_FOLDER = $(shell pwd)
OBJS_PATH = $(addprefix $(CURRENT_FOLDER)/, $(DIR_OBJS))

MINILIBFT_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_MINILIBFT))
PIPEX_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_PIPEX))

MINILIBFT_FILES =	ft_putstr_fd.c \
					ft_memalloc.c \
					ft_strjoin.c \
					ft_strsplit.c \
					ft_strcat.c \
				 	ft_strncmp.c \
					ft_strlen.c \
					ft_putchar_fd.c \
					ft_bzero.c \
					ft_strcpy.c \
					ft_strlcpy.c \
					ft_split.c \
					ft_strdup.c \

PIPEX_FILES	=	pipex.c \
				utils.c \
				parse_cmd_1.c \
				parse_cmd_2.c \
				check_files.c \
				string.c \
				exec_cmds.c \

SRCS_MINILIBFT = $(addprefix $(MINILIBFT_PATH)/, $(MINILIBFT_FILES))
SRCS_PIPEX = $(addprefix $(PIPEX_PATH)/, $(PIPEX_FILES))
SRCS = $(SRCS_MINILIBFT) $(SRCS_PIPEX)

OBJS_FILES = $(PIPEX_FILES:.c=.o) $(MINILIBFT_FILES:.c=.o)
OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS_FILES))

all: $(NAME)

$(OBJS) : $(SRCS)
	-@$(CC) $(FLAGS) $(SRCS) -c
	mv *.o $(DIR_OBJS)

$(NAME) : $(OBJS)
	@echo Compiling: $(NAME)
	@$(CC) $(FLAGS) $(HPATH) $(OBJS) -o $(NAME)
	@echo Compiled successfully!

clean:
	@echo Deleting objects files...
	@rm -f $(OBJS)
	@echo Deleting done!

fclean: clean
	@echo Deleting $(NAME)...
	@rm $(NAME)
	@rm -rf *.o
	@echo Deleting done!

re: fclean all

.PHONY: all clean fclean re