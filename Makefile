# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 12:42:09 by pramos-m          #+#    #+#              #
#    Updated: 2023/02/21 17:57:00 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------RULES-----------------#

NAME = fdf

#----------------COMANDS-----------------#

CFLAGS = -Wall -Werror -Wextra -W -O3 -Ofast
XFLAGS = -fsanitize=address -g3
RM = rm -rf
MD = mkdir -p
CP = cp -f

#----------------PATH-----------------#

SRC_DIR = src/
UTILS = utils/
INC_DIR = ./inc/
LIB_DIR = ./lib/

OBJ_DIR = ./.obj/

LIBFT_DIR = $(LIB_DIR)libft/

PRINT_DIR = $(LIB_DIR)printf/

LIBRARY = $(LIB_DIR)/*/*.a

#----------------FDF-----------------#

INCLUDE = -I$(INC_DIR) -I$(LIB_DIR) -I$(PRINT_DIR) -Ibonus/inc/

SRC_FLS = fdf.c \
			map_checking.c

UTL_FLS = fdf_utils.c

SRCS += $(addprefix $(SRC_DIR), $(SRC_FLS))
SRCS += $(addprefix $(UTILS), $(UTL_FLS))

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))
DEPS = $(OBJS:%.o=%.d)

#------------------RULES-------------------#

$(OBJ_DIR)%.o: %.c $(LIBRARY)
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) -MMD -Ilib/minilibx_macos/ $(INCLUDE) -c $< -o $@

all:
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	$(CC) $(CFLAGS) -L./lib/minilibx_macos/ -lmlx -framework OpenGL -framework Appkit -MMD $(OBJS) $(LIBRARY) -o fdf

$(NAME)::
	@echo "nothing to be done fdf"

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@echo "clean done"

fclean:
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(NAME)
	@$(RM) -rf $(OBJ_DIR)
	@echo "fclean done"

re:
	@$(MAKE) fclean
	@$(MAKE) all
