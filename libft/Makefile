# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 16:05:14 by nosuzuki          #+#    #+#              #
#    Updated: 2022/03/20 14:17:06 by nosuzuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
SHELL	:= /bin/bash
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP
PURPLE	:= \033[1;35m
GREEN	:= \033[1;32m
RESET	:= \033[0;39m
AR		:= ar
ARFLAGS	:= scr
SRCDIR  := srcs
CTYPDIR := ./srcs/ctype
GNLDIR	:= ./srcs/gnl
FREEDIR := ./srcs/free
IODIR	:= ./srcs/io
LISTDIR := ./srcs/list
SORTDIR := ./srcs/sort
STRDIR	:= ./srcs/string
CHARDIR	:= ./srcs/string/char
MEMDIR  := ./srcs/string/mem
SDIR  	:= ./srcs/string/str
UTILDIR := ./srcs/utils
HASHDIR	:= ./srcs/hash
OPTDIR	:= ./srcs/getopt
PATHDIR	:= ./srcs/path
OBJDIR	:= ./obj
INCLUDE	:= ./includes
VPATH 	:= $(shell find $(SRCDIR) -type d | awk '{print $$0":"}')
CTYPSRC	=\
	./srcs/ctype/ft_isalnum.c\
	./srcs/ctype/ft_isalpha.c\
	./srcs/ctype/ft_isascii.c\
	./srcs/ctype/ft_isdigit.c\
	./srcs/ctype/ft_isprint.c\
	./srcs/ctype/ft_tolower.c\
	./srcs/ctype/ft_toupper.c\

GNLSRC	=\
	./srcs/gnl/get_next_line.c\
	./srcs/gnl/gnl_destroy.c\
	./srcs/gnl/gnl_utils.c\
	./srcs/gnl/gnl_utils2.c\

FREESRC	=\
	./srcs/free/free_all.c\
	./srcs/free/free_set.c\
	./srcs/free/freeturn.c\

IOSRC	=\
	./srcs/io/ft_putbin.c\
	./srcs/io/ft_putchar_fd.c\
	./srcs/io/ft_putendl_fd.c\
	./srcs/io/ft_puterr.c\
	./srcs/io/ft_putnbr_fd.c\
	./srcs/io/ft_putstr_fd.c\
	./srcs/io/ft_putstrs_fd.c\

LISTSRC	=\
	./srcs/list/ft_clst_begin.c\
	./srcs/list/ft_clst_clear.c\
	./srcs/list/ft_clst_insert.c\
	./srcs/list/ft_clst_insert_all.c\
	./srcs/list/ft_clst_isempty.c\
	./srcs/list/ft_clst_isend.c\
	./srcs/list/ft_clst_last.c\
	./srcs/list/ft_clst_link.c\
	./srcs/list/ft_clst_next.c\
	./srcs/list/ft_clst_pop.c\
	./srcs/list/ft_clst_popdel.c\
	./srcs/list/ft_clst_size.c\
	./srcs/list/ft_clstadd_back.c\
	./srcs/list/ft_clstadd_front.c\
	./srcs/list/ft_clstdelone.c\
	./srcs/list/ft_clstfirst.c\
	./srcs/list/ft_clstnew.c\
	./srcs/list/ft_clstnew_add_back.c\
	./srcs/list/ft_lstadd_back.c\
	./srcs/list/ft_lstadd_front.c\
	./srcs/list/ft_lstclear.c\
	./srcs/list/ft_lstdelone.c\
	./srcs/list/ft_lstiter.c\
	./srcs/list/ft_lstlast.c\
	./srcs/list/ft_lstmap.c\
	./srcs/list/ft_lstnew.c\
	./srcs/list/ft_lstnew_add_front.c\
	./srcs/list/ft_lstsize.c\

SORTSRC	=\
	./srcs/sort/ft_msort.c\
	./srcs/sort/ft_qsort.c\

STRSRC	=\
	./srcs/string/mem/ft_bzero.c\
	./srcs/string/mem/ft_calloc.c\
	./srcs/string/mem/ft_memccpy.c\
	./srcs/string/mem/ft_memchr.c\
	./srcs/string/mem/ft_memcmp.c\
	./srcs/string/mem/ft_memcpy.c\
	./srcs/string/mem/ft_memmove.c\
	./srcs/string/mem/ft_memset.c\
	./srcs/string/str/ft_atoi.c\
	./srcs/string/str/ft_atoi_err.c\
	./srcs/string/str/ft_atol.c\
	./srcs/string/str/ft_chr_in_str.c\
	./srcs/string/str/ft_fastrlen.c\
	./srcs/string/str/ft_itoa.c\
	./srcs/string/str/ft_itoa_buf.c\
	./srcs/string/str/ft_split.c\
	./srcs/string/str/ft_strbsearch.c\
	./srcs/string/str/ft_strchr.c\
	./srcs/string/str/ft_strcmp.c\
	./srcs/string/str/ft_strcpy.c\
	./srcs/string/str/ft_strdup.c\
	./srcs/string/str/ft_streq.c\
	./srcs/string/str/ft_strjoin.c\
	./srcs/string/str/ft_strlcat.c\
	./srcs/string/str/ft_strlcpy.c\
	./srcs/string/str/ft_strlen.c\
	./srcs/string/str/ft_strmapi.c\
	./srcs/string/str/ft_strncmp.c\
	./srcs/string/str/ft_strncpy.c\
	./srcs/string/str/ft_strndup.c\
	./srcs/string/str/ft_strnlen.c\
	./srcs/string/str/ft_strnstr.c\
	./srcs/string/str/ft_strrchr.c\
	./srcs/string/str/ft_strsep.c\
	./srcs/string/str/ft_strsjoin.c\
	./srcs/string/str/ft_strtrim.c\
	./srcs/string/str/ft_substr.c\

UTILSRC	=\
	./srcs/utils/ft_free_assign.c\
	./srcs/utils/ft_labs.c\
	./srcs/utils/ft_min.c\
	./srcs/utils/ft_setptr.c\
	./srcs/utils/ft_utoa_len.c\

HASHSRC	=\
	./srcs/hash/add.c\
	./srcs/hash/bucket.c\
	./srcs/hash/clear.c\
	./srcs/hash/del.c\
	./srcs/hash/get.c\
	./srcs/hash/hash.c\
	./srcs/hash/util.c\

OPTSRC	=\
	./srcs/getopt/getopt.c\
	./srcs/getopt/getopt_uitls.c\

PATHSRC	=\
	./srcs/path/create_normalized.c\
	./srcs/path/ft_is_relative_path.c\
	./srcs/path/ft_join_path.c\
	./srcs/path/ft_normalize_path.c\
	./srcs/path/ft_remove_first_slash.c\
	./srcs/path/ft_resolve_ralative.c\


SRCS	:= $(CTYPSRC)$(FREESRC)$(GNLSRC)$(IOSRC)$(LISTSRC)$(SORTSRC)$(STRSRC)$(UTILSRC)$(HASHSRC)$(OPTSRC)$(PATHSRC)
OBJS	:= $(shell basename -a $(SRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
DEPENDS	:= $(OBJS:.o=.d)

all		: $(NAME)

-include $(DEPENDS)

$(OBJDIR)/%.o : %.c
	@if [ ! -d $(OBJDIR) ];then mkdir $(OBJDIR); fi
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
	@echo -e "	""$(GREEN)$@$(RESET)"

$(NAME)	: $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $^
	@echo -e "\n$(PURPLE) build	$(GREEN)$@$(RESET)"

bonus	: $(NAME)

clean	:
	rm -rf $(OBJDIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

add		:
# bash header.sh ./ libft.h
	bash header.sh "$(STRDIR)" $(INCLUDE)/ft_string.h
	bash header.sh "$(IODIR)" $(INCLUDE)/ft_io.h
	bash header.sh "$(LISTDIR)" $(INCLUDE)/ft_list.h
	bash header.sh "$(FREEDIR)" $(INCLUDE)/ft_free.h
	bash header.sh "$(SORTDIR)" $(INCLUDE)/ft_sort.h
	bash header.sh "$(UTILDIR)" $(INCLUDE)/ft_utils.h
	bash header.sh "$(HASHDIR)" $(INCLUDE)/hash.h
	bash header.sh "$(OPTDIR)" $(INCLUDE)/ft_getopt.h
	bash header.sh "$(CTYPDIR)" $(INCLUDE)/ft_ctype.h
	bash header.sh "$(PATHDIR)" $(INCLUDE)/ft_path.h
	bash header.sh "$(GNLDIR)" $(INCLUDE)/get_next_line.h
	bash make.sh $(CTYPDIR) CTYPSRC
	bash make.sh $(STRDIR) STRSRC
	bash make.sh $(IODIR) IOSRC
	bash make.sh $(LISTDIR) LISTSRC
	bash make.sh $(FREEDIR) FREESRC
	bash make.sh $(SORTDIR) SORTSRC
	bash make.sh $(UTILDIR) UTILSRC
	bash make.sh $(HASHDIR) HASHSRC
	bash make.sh $(OPTDIR) OPTSRC
	bash make.sh $(GNLDIR) GNLSRC
	bash make.sh $(PATHDIR) PATHSRC

.PHONY	: all clean fclean re bonus add