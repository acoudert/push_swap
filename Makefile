NAME1      = push_swap
NAME2      = checker

CC         = gcc
CINCLUDES  = -I includes
CINCLUDES += -I libft -I get_next_line -I ft_printf
CFLAGS     = -Wall -Wextra -Werror $(CINCLUDES)
RM         = rm -f

DIR1       = srcs/push_swap
DIR2       = srcs/checker
DIRCOMMON  = srcs/common
DIRGNL     = get_next_line

SRCS1      = $(DIR1)/main.c \
			 $(DIR1)/arg.c \
			 $(DIR1)/data.c \
			 $(DIR1)/sizes.c \
			 $(DIR1)/copy_stacks.c \
			 $(DIR1)/apply_move.c \
			 $(DIR1)/quick_sort_x/quick_sort_x.c \
			 $(DIR1)/sort_stack_3_elems.c \
			 $(DIR1)/min_sort/min_sort.c \
			 $(DIR1)/min_sort/find_low_index.c \
			 $(DIR1)/min_sort/sort_stack_b.c \
			 $(DIR1)/recursive_sort/recursive_sort.c \
			 $(DIR1)/chunk_recursive_sort/chunk_recursive_sort.c \
			 $(DIR1)/chunk_recursive_sort/stack_b_recursion_launcher.c \
			 $(DIR1)/chunk_recursive_sort/opti_rsb.c \
			 $(DIR1)/chunk_recursive_sort/set_up_chunk_rs.c \
			 $(DIR1)/chunk_recursive_sort/closest_to_top.c \
			 $(DIR1)/chunk_recursive_sort/is_b_sorted.c \
			 $(DIR1)/quick_sort/quick_sort.c \
			 $(DIR1)/quick_sort/sorting_mid_a.c \
			 $(DIR1)/quick_sort/sorting_mid_b.c \
			 $(DIR1)/optimize_sol/optimize_sol.c \
			 $(DIR1)/optimize_sol/cancelling_moves_opti.c \
			 $(DIR1)/optimize_sol/double_moves_opti.c \
			 $(DIR1)/optimize_sol/set_up_t_opti/set_up_t_opti.c \
			 $(DIR1)/optimize_sol/set_up_t_opti/set_up_t_opti_sx.c \
			 $(DIR1)/optimize_sol/set_up_t_opti/set_up_t_opti_px.c \
			 $(DIR1)/optimize_sol/set_up_t_opti/set_up_t_opti_rx.c \
			 $(DIR1)/optimize_sol/set_up_t_opti/set_up_t_opti_rrx.c
SRCS2      = $(DIR2)/main.c \
			 $(DIR2)/arg.c \
			 $(DIR2)/show_stack/show_stack.c \
			 $(DIR2)/show_stack/define_last.c \
			 $(DIR2)/show_stack/define_last_sx.c \
			 $(DIR2)/show_stack/define_last_px.c \
			 $(DIR2)/show_stack/define_last_rx.c \
			 $(DIR2)/show_stack/define_last_rrx.c \
			 $(DIRGNL)/get_next_line.c \
			 $(DIRGNL)/get_next_line_utils.c
SRCSCOMMON = $(DIRCOMMON)/convert_input.c \
			 $(DIRCOMMON)/set_up_t_ft.c \
			 $(DIRCOMMON)/display_stacks.c \
			 $(DIRCOMMON)/error.c \
			 $(DIRCOMMON)/free_stacks.c \
			 $(DIRCOMMON)/is_sorted.c \
			 $(DIRCOMMON)/shift_stack.c \
			 $(DIRCOMMON)/move_sx.c \
			 $(DIRCOMMON)/move_px.c \
			 $(DIRCOMMON)/move_rx.c \
			 $(DIRCOMMON)/move_rrx.c

OBJS1      = $(SRCS1:.c=.o)
OBJS2      = $(SRCS2:.c=.o)
OBJSCOMMON = $(SRCSCOMMON:.c=.o)

all        : $(NAME1) $(NAME2)

$(NAME1)   : $(OBJS1) $(OBJSCOMMON)
	@$(MAKE) -C libft --no-print-directory
	@$(MAKE) -C ft_printf --no-print-directory
	$(CC) $^ -o $@ -Llibft -Lft_printf -lft -lftprintf 

$(NAME2)   : $(OBJS2) $(OBJSCOMMON)
	@$(MAKE) -C libft --no-print-directory
	@$(MAKE) -C ft_printf --no-print-directory
	$(CC) $^ -o $@ -Llibft -Lft_printf -lft -lftprintf -lncurses

$(OBJS1)   : %.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS2)   : %.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJSCOMMON) : %.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

re         : fclean all

clean      :
	@$(MAKE) clean -C libft --no-print-directory
	@$(MAKE) clean -C ft_printf --no-print-directory
	$(RM) $(OBJS1) $(OBJS2) $(OBJSCOMMON)

fclean     : clean
	@$(MAKE) fclean -C libft --no-print-directory
	@$(MAKE) fclean -C ft_printf --no-print-directory
	$(RM) $(NAME1) $(NAME2)

.PHONY     : all re clean fclean
