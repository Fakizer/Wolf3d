#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/01 15:10:23 by vvlasenk          #+#    #+#              #
#    Updated: 2017/01/01 15:10:25 by vvlasenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	=	wolf3d
LIBFT	=	libft.a

GCC		=	gcc
WWW		=	-Wall -Wextra -Werror
IGRAPH	=	-L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL \
			-framework AppKit

SRCWOLF	=	checker.c error.c floor_ceiling.c hook.c hook1.c init_data.c \
			parcing_map.c ray_cast.c ray_cast1.c wall.c wolf3d.c wolf3d1.c
SRCLIB	=	ft_memset.c ft_memcpy.c ft_memchr.c ft_memcmp.c \
			ft_strcmp.c ft_bzero.c ft_memmove.c ft_strlen.c \
			ft_strcpy.c ft_strncpy.c ft_memccpy.c ft_toupper.c \
			ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_tolower.c ft_strstr.c ft_strdup.c \
			ft_strnstr.c ft_atoi.c ft_strlcat.c ft_isalpha.c \
			ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c \
			ft_putstr.c ft_putchar.c ft_memalloc.c ft_memdel.c \
			ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
			ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
			ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_lstmap.c ft_lstnew.c ft_lstiter.c ft_lstdelone.c \
			ft_lstdel.c ft_lstadd.c ft_putnbr_fd.c ft_nbrlen.c \
			get_next_line.c

OBJLIB	=	$(addprefix $(OBJDIRL),$(SRCLIB:.c=.o))
OBJWOLF	=	$(addprefix $(OBJDIRW),$(SRCWOLF:.c=.o))

INCLUDES=	-I./includes/

LIBFTDIR=	./libft/
OBJDIRL	=	./objlib/
OBJDIRW =	./objwolf/
SRCDIR	=	./sources/

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_YELLOW		= \033[1;33m
LOG_GREEN		= \033[1;32m

all: $(NAME)

$(NAME):	$(LIBFT) $(OBJDIRW) $(OBJWOLF)
			@echo ""
			@echo -e "----$(LOG_CLEAR)$(LOG_VIOLET) compiled........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"
			@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW) Compile $@$(LOG_NOCOLOR)"
			@$(GCC) -o $@ $(IGRAPH) $(OBJWOLF) $(LIBFT)
			@echo -e "----$(LOG_CLEAR)$(LOG_VIOLET) compiled........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(LIBFT):	$(OBJDIRL) $(OBJLIB)
			@echo ""
			@echo -e "------$(LOG_CLEAR)$(LOG_VIOLET) compiled........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"
			@echo -e "----$(LOG_CLEAR)$(LOG_YELLOW)Build $@$(LOG_NOCOLOR)"
			@ar rc $@ $(OBJLIB)
			@echo -e "------$(LOG_CLEAR)$(LOG_VIOLET) compiled........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJDIRL):
			@echo -e "$(LOG_CLEAR)$(LOG_YELLOW) Assemble $(NAME)$(LOG_NOCOLOR)"
			@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW) Assemble $(LIBFT)$(LOG_NOCOLOR)"
			@echo -e "----$(LOG_CLEAR)$(LOG_YELLOW) Create directory $@$(LOG_NOCOLOR)"
			@mkdir -p $@
			@echo -e "------$(LOG_CLEAR)$(LOG_VIOLET) created........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"
			@echo -e "----$(LOG_CLEAR)$(LOG_YELLOW) Compile libft object files $(LOG_NOCOLOR)"

$(OBJDIRL)%.o:$(LIBFTDIR)%.c
			@echo ".\c"
			@$(GCC) $(WWW) $(INCLUDES) -o $@ -c $<

$(OBJDIRW):
			@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW) Create directory $@$(LOG_NOCOLOR)"
			@mkdir -p $@
			@echo -e "----$(LOG_CLEAR)$(LOG_VIOLET) created........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"
			@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW) Compile wolf3d object files $(LOG_NOCOLOR)"

$(OBJDIRW)%.o:$(SRCDIR)%.c
			@echo ".\c"
			@$(GCC) $(WWW) $(INCLUDES) -o $@ -c $<

clean:
	@echo "----$(LOG_CLEAR)$(LOG_YELLOW) Delete object files and directorys $(LOG_NOCOLOR)"
	@rm -rf $(OBJLIB) $(OBJDIRL) $(OBJWOLF) $(OBJDIRW)
	@echo -e "----$(LOG_CLEAR)$(LOG_VIOLET) deleted........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

fclean: clean
	@echo "----$(LOG_CLEAR)$(LOG_YELLOW) Delete $(LIBFT) and $(NAME) $(LOG_NOCOLOR)"
	@rm -f $(NAME) $(LIBFT)
	@echo -e "----$(LOG_CLEAR)$(LOG_VIOLET) deleted........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

rec:
	@echo "--$(LOG_CLEAR)$(LOG_YELLOW) Recompile project$(LOG_NOCOLOR)"

re: rec fclean all
