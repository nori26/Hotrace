NAME		:= hotrace
SHELL		:= /bin/bash

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -MMD -MP

SRCDIR		:= srcs
LIBFTDIR	:= ./libft
LIBFT		:= $(LIBFTDIR)/libft.a

INCLUDE		:= .
LIBINCLUDE	:= $(LIBFTDIR)/includes
INCLUDES	:= $(INCLUDE) $(LIBINCLUDE)

SRCS		:=\
	get_next_line.c\
	gnl_destroy.c\
	gnl_utils.c\
	gnl_utils2.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstnew.c\
	ft_memchr.c\
	ft_setptr.c\
	main.c\

OBJS		:= $(SRCS:.c=.o)
DEPENDS		:= $(OBJS:.o=.d)

PURPLE		:= \033[1;35m
GREEN		:= \033[1;32m
RESET		:= \033[0;39m

# ifdef WITH_BONUS
# NAME	= philo_bonus
# OBJS	= $(shell basename -a $(B_SRCS:.c=.o) $(LIBSRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
# DEPENDS	= $(shell basename -a $(B_SRCS:.c=.d) $(LIBSRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
# endif

all		: $(NAME)

-include $(DEPENDS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "	""$(GREEN)$@$(RESET)"

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo -e "\n$(PURPLE) build	$(GREEN)$@$(RESET)"

clean	: rm_reloc
#	# @make b_clean WITH_BONUS=1

fclean	: clean rm_exec
#	@make b_fclean WITH_BONUS=1

bonus	: $(NAME)
# 	@make WITH_BONUS=1

b_clean	: rm_reloc

b_fclean: rm_exec

rm_reloc:
	$(RM) -r $(OBJS) $(DEPENDS)

rm_exec	:
	$(RM) $(NAME)

# bash make.sh $(DIR2) SRC2
# bash make.sh $(DIR3) SRC3

re		: fclean all

debug	: CFLAGS += -g -fsanitize=address
debug	: re

TESTDIR		= tests
GTESTDIR	= $(TESTDIR)/googletest
GTESTLIB	= $(GTESTDIR)/gtest.a
TESTCASES	= $(wildcard $(TESTDIR)/$(F)*test.cpp) $(TESTDIR)/test_util.cpp
TESTOBJS	= $(filter-out %main.o, $(OBJS))
TESTLIBS	= -lpthread -L$(LIBFTDIR) $(LIBS)
TESTER		= tester

$(GTESTLIB):
	$(MAKE) -C $(TESTDIR)

$(TESTER)	: $(NAME) $(GTESTLIB) $(TESTCASES)
	clang++ -I$(GTESTDIR) $(IOPTIONS) $(GTESTLIB) $(TESTCASES) $(TESTOBJS) $(TESTLIBS) -o $@

gen		:
	python3 $(TESTDIR)/casemaker.py

test	: $(TESTER)
	./$<

leak	: $(TESTER)
	valgrind --leak-check=full ./$<

cinorm	:
	@norminette includes libft $(shell find srcs -mindepth 1 -type d -not -name debug) \
		| grep -v 'Missing or' \
		| grep -v 'WRONG_SCOPE_COMMENT' \
		| grep -v 'TOO_MANY_FUNCS' \
		| grep -v ': OK!' \
		| tee /dev/stderr \
		| grep 'Error: ' > /dev/null; \
		if [ $$? -eq 0 ]; then \
			exit 1; \
		else \
			printf '$(GREEN)%s\n$(RESET)' 'Norm: OK!'; \
		fi

norm	:
	@norminette includes libft srcs \
		| grep -v ': OK!'; \
		if [ $$? -eq 0 ]; then \
			exit 1; \
		else \
			printf '$(GREEN)%s\n$(RESET)' 'Norm: OK!'; \
		fi

.PHONY	: all clean fclean re bonus add norm rm_exec rm_reloc b_clean b_fclean head _libft test rl