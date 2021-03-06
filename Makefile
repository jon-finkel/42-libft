# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 18:20:14 by nfinkel           #+#    #+#              #
#    Updated: 2019/03/15 13:31:10 by nfinkel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Environment
OS :=					$(shell uname)

#	Output
NAME :=					libft.a
DYN_NAME :=				${NAME:a=so}

#	Compiler
CC :=					gcc
FLAGS :=				-Wall -Wextra -Werror

ifeq ($(OS), Darwin)
	THREADS := 			$(shell sysctl -n hw.ncpu)
else
	THREADS :=			4
endif

FAST :=					-j$(THREADS)

DYN_FLAG :=				-shared
HEADERS :=				-I ./include/
O_FLAG :=				-O2

#	Directories
OBJDIR :=				./build/
DYN_OBJDIR :=			./dyn_build/

API_DIR :=				./api/
CHAR_DIR :=				./char/
HDL_DIR :=				./hdl/
IO_DIR :=				./io/
LIST_DIR :=				./list/
MATH_DIR :=				./math/
MEM_DIR :=				./mem/
MLX_DIR :=				./mlx/
OPT_DIR :=				./opt/
PF_DIR :=				./pf/
STR_DIR :=				./str/
VARY_DIR :=				./vary/
VEC_DIR :=				./vec/

#	Sources
API +=					api_ctime.c api_env.c
CHAR +=					char_char1.c char_char2.c
HDL +=					hdl_err.c
IO +=					io_file.c io_gnl.c io_pf1.c io_pf2.c io_pf3.c
IO +=					io_put1.c io_put2.c io_put3.c io_sys.c
LIST +=					list_add.c list_append.c list_ctor.c list_dtor.c
LIST +=					list_eject.c list_fdup.c list_fiter.c list_insert.c
LIST +=					list_len.c list_node.c list_pop.c list_rem.c
MATH +=					math_npow.c math_nxpow2.c math_zpow.c
MEM +=					mem_alloc.c mem_ccpy.c mem_chr.c
MEM +=					mem_cleanup.c mem_cmp.c mem_cpy.c mem_dtor.c
MEM +=					mem_move.c mem_nccpy.c mem_set.c mem_swap.c
MEM +=					mem_toi.c mem_zero.c
MLX +=					mlx_blur.c mlx_clear.c mlx_clip.c mlx_ctor.c mlx_dtor.c
MLX +=					mlx_line.c mlx_pixel.c mlx_set.c mlx_show.c
OPT +=					opt_parse.c opt_usage.c
PF +=					pf_ansi_color.c pf_fill_buffer.c
PF +=					pf_buff_format.c pf_get_flags.c
PF +=					pf_output_char.c pf_output_string.c
PF +=					pf_output_extras.c pf_output_noprint.c
PF +=					pf_output_double.c pf_output_pointer.c
PF +=					pf_output_signed.c pf_output_unsigned.c
STR +=					str_cat.c str_chr.c str_cjoin.c str_clr.c str_cmp.c
STR +=					str_cpy.c str_dtor.c str_dup.c str_equ.c str_iter.c
STR +=					str_iteri.c str_join.c str_len.c str_map.c str_mapi.c
STR +=					str_ncpy.c str_ndup.c str_new.c str_nstr.c str_rchr.c
STR +=					str_rdup.c str_rev.c str_rewrite.c str_split.c
STR +=					str_str.c str_sub.c str_toi.c str_trim.c
VARY +=					vary_begin.c vary_clr.c vary_ctor.c vary_dtor.c
VARY +=					vary_end.c vary_grow.c vary_ncpush.c vary_ncpy.c
VARY +=					vary_fpush.c vary_npush.c vary_push.c
VEC +=					vec_center.c vec_ctor.c vec_m4iter.c
VEC +=					vec_mult.c vec_new.c vec_norm.c vec_rot.c vec_scale.c
VEC +=					vec_trans.c vec_update.c

DYN_OBJECTS =				$(patsubst %.c,$(DYN_OBJDIR)%.o,$(SRCS))
OBJECTS =					$(patsubst %.c,$(OBJDIR)%.o,$(SRCS))

SRCS +=						$(API)
SRCS +=						$(CHAR)
SRCS +=						$(HDL)
SRCS +=						$(IO)
SRCS +=						$(LIST)
SRCS +=						$(MATH)
SRCS +=						$(MEM)
SRCS +=						$(MLX)
SRCS +=						$(OPT)
SRCS +=						$(PF)
SRCS +=						$(STR)
SRCS +=						$(VARY)
SRCS +=						$(VEC)

vpath %.c $(API_DIR)
vpath %.c $(CHAR_DIR)
vpath %.c $(HDL_DIR)
vpath %.c $(IO_DIR)
vpath %.c $(LIST_DIR)
vpath %.c $(MATH_DIR)
vpath %.c $(MEM_DIR)
vpath %.c $(MLX_DIR)
vpath %.c $(OPT_DIR)
vpath %.c $(PF_DIR)
vpath %.c $(STR_DIR)
vpath %.c $(VARY_DIR)
vpath %.c $(VEC_DIR)

#################
##    RULES    ##
#################

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $@ $(patsubst %.c,$(OBJDIR)%.o,$(SRCS))
	@ranlib $@
	@printf  "\033[92m\033[1;32mCompiling -------------> \033[91m$(NAME)\033[0m:\033[0m%-13s\033[32m[✔]\033[0m\n"

$(OBJECTS): | $(OBJDIR)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o: %.c
	@printf  "\033[1;92mCompiling $(NAME)\033[0m %-28s\033[32m[$<]\033[0m\n" ""
	@$(CC) $(VERSION) $(DEBUG)$(FLAGS) $(O_FLAG) $(HEADERS) -c $< -o $@
	@printf "\033[A\033[2K"

$(DYN_OBJECTS): | $(DYN_OBJDIR)

$(DYN_OBJDIR):
	@mkdir -p $@

$(DYN_OBJDIR)%.o: %.c
	@printf  "\033[1;92mCompiling $(NAME:a=so)\033[0m %-27s\033[32m[$<]\033[0m\n" ""
	@$(CC) $(VERSION) $(FLAGS) $(O_FLAG) $(HEADERS) -fpic -c $< -o $@
	@printf "\033[A\033[2K"

clean:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -rf $(DYN_OBJDIR)
	@printf  "\033[1;32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-13s\033[32m[✔]\033[0m\n"

fast:
	@$(MAKE) --no-print-directory $(FAST)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(DYN_NAME)
	@printf  "\033[1;32mCleaning binary -------> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-13s\033[32m[✔]\033[0m\n"

nohdl: HDL :=
nohdl: re

re: fclean fast

so: fclean $(DYN_OBJECTS)
	@$(CC) $(VERSION) $(DYN_FLAG) -o $(DYN_NAME) $(patsubst %.c,$(DYN_OBJDIR)%.o,$(notdir $(SRCS)))
	@printf  "\033[92m\033[1;32mCompiling -------------> \033[91m$(DYN_NAME)\033[0m:\033[0m%-12s\033[32m[✔]\033[0m\n"

.PHONY: all clean fast fclean nohdl re so
