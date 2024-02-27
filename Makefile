NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
AR = ar rcs
DIR_OBJ = obj
DIR_SRC = src
HEADER = inc
SOURCES = get_next_line_bonus.c \
          get_next_line_utils_bonus.c \
          here_doc.c \
		  utils.c \
		  piping.c \
          main.c \

SOURCES_BONUS = get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				here_doc.c \
				utils.c \
				piping.c \
				main_bonus.c \

LIBFT = libft
SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
SRCS_BONUS = $(addprefix $(DIR_SRC)/,$(SOURCES_BONUS))
OBJS = $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))
OBJS_BONUS = $(addprefix $(DIR_OBJ)/,$(SOURCES_BONUS:.c=.o))
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m
BOLD = $(shell tput bold)

title: all
title: bonus

all: $(NAME)
$(NAME): $(OBJS)
	@echo "$(COLOR_BLUE)Creating libft.a and copying it to root directory.$(COLOR_END)"
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	@echo "$(COLOR_BLUE)Creating $(NAME).$(COLOR_END)"
	$(CC) $(OBJS) libft.a -o $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) created.✅$(COLOR_END)"

bonus: $(OBJS_BONUS)
	@echo "$(COLOR_BLUE)Creating libft.a and copying it to root directory.$(COLOR_END)"
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	@echo "$(COLOR_BLUE)Creating bonus $(NAME).$(COLOR_END)"
	$(CC) $(OBJS_BONUS) libft.a -o $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) created.✅$(COLOR_END)"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@echo "Compiling $< into $@.\n"
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled.✅$(COLOR_END)"

clean:
	clear
	@echo "$(COLOR_BLUE)Cleaning object files.$(COLOR_END)"
	$(RM) -r $(DIR_OBJ)/*.o
	make -C $(LIBFT) clean
	@echo "$(COLOR_GREEN)$(NAME) object files cleaned.✅$(COLOR_END)"

fclean: clean
	@echo "$(COLOR_BLUE)Cleaning $(NAME) and libft.$(COLOR_END)"
	$(RM) $(NAME) libft.a
	make -C $(LIBFT) fclean
	clear
	@echo "$(COLOR_GREEN)Project $(NAME) cleaned.✅$(COLOR_END)"

re: fclean all title

.PHONY: all clean fclean re
.SILENT: clean fclean re $(NAME) $(OBJS) $(DIR_OBJ)/%.o $(DIR_SRC)/%.c

title:
	@clear
	@echo "$(COLOR_RED)$(BOLD)__| |__________________________________________| |__"
	@echo "__   __________________________________________   __"
	@echo "  | |                                          | |  "
	@echo "  | | ______   _____  ______   _______  _    _ | |  "
	@echo "  | |(_____ \ (_____)(_____ \ (_______)\ \  / /| |  "
	@echo "  | | _____) )   _    _____) ) _____    \ \/ / | |  "
	@echo "  | ||  ____/   | |  |  ____/ |  ___)    )  (  | |  "
	@echo "  | || |       _| |_ | |      | |_____  / /\ \ | |  "
	@echo "  | ||_|      (_____)|_|      |_______)/_/  \_\| |  "
	@echo "__| |__________________________________________| |__"
	@echo "__   __________________________________________   __"
	@echo "  | |                                          | |  $(COLOR_END)"
	@echo " "
	@echo "$(COLOR_BLUE)$(BOLD)Pipex reproduces the behaviour of the shell pipe | command in C.$(COLOR_END)"
	@echo "$(COLOR_BLUE)$(BOLD)It launches as: ./pipex infile cmd1 cmd2 outfile and behaves as this line does in the shell < infile cmd1 | cmd2 > outfile.$(COLOR_END)"
	@echo "$(BOLD)	- ./pipex infile cmd1 cmd2 outfile"
	@echo "$(COLOR_BLUE)$(BOLD)	  and behaves as this line does in the shell$(COLOR_END)"
	@echo "$(BOLD)	- < infile cmd1 | cmd2 > outfile."
	@echo "$(COLOR_BLUE)$(BOLD)Bonus part allows to handle multiple pipes (and the <</>> operators when the first parameter is "here_doc") as follows:$(COLOR_END)"
	@echo "$(BOLD)	- ./pipex here_doc LIMITER cmd1 cmd2 ... cmdn outfile"
	@echo "$(COLOR_BLUE)$(BOLD)	  should behave the same as launching$(COLOR_END)"
	@echo "$(BOLD)	- << LIMITER cmd1 | cmd2 | ... | cmdn >> outfile."
