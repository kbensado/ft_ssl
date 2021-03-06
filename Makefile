# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/21 02:48:50 by kbensado          #+#    #+#              #
#    Updated: 2018/08/05 02:52:36 by kbensado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc

CFLAG =			 -g # -Wall -Wextra -Werror -g #-Weverything -g 

FSANITIZE = 	-fsanitize=address

NAME_N =		ft_ssl

SRC_PATH_N =	./src/

OBJ_PATH_N =	./obj/

LIBFT_PATH =	./libft/

INC_PATH_N =	./inc/

SRC_NAME_N =	main.c error.c command.c hash.c file.c md5.c md5_1.c md5_2.c sha256_1.c sha256.c 

OBJ_NAME_N =	$(SRC_NAME_N:.c=.o)

LIBFT_NAME =	libft.a

INC_NAME_N =	ft_ssl.h md5.h sha.h

SRC_N =			$(addprefix $(SRC_PATH_N),$(SRC_NAME_N))

OBJ_N =			$(addprefix $(OBJ_PATH_N),$(OBJ_NAME_N))


INC_N =			$(addprefix $(INC_PATH_N),$(INC_NAME_N))

LIBFT =			$(addprefix $(LIBFT_PATH),$(LIBFT_NAME))

INCLIBFT = 		$(LIBFT_PATH)inc


LIBFT_FLAG = 	-L$(LIBFT_PATH) -lft

all:			libft $(NAME_N) $(NAME_O)
				

$(NAME_N):		$(OBJ_N)

				$(CC) $(LIBFT_FLAG) -o $@ $^ $(FSANITIZE) ./libft/libft.a

				@echo "Done"

$(OBJ_PATH_N)%.o: 	$(SRC_PATH_N)%.c $(INC_N)
					mkdir -p $(OBJ_PATH_N)
					$(CC) $(CFLAG) -I$(INC_PATH_N) -I$(INCLIBFT) -o $@ -c $< $(FSANITIZE)

libft:			$(LIBFT)

$(LIBFT):		$(LIBFT_PATH)
				@make -C $(LIBFT_PATH)

clean:
				@make clean -C $(LIBFT_PATH)
				@rm -f $(OBJ_N)

fclean:			
				@rm -f $(OBJ_N)
				@make fclean -C $(LIBFT_PATH)
				@rm -f $(NAME_N)

re: 			fclean all

.PHONY:			all libft clean fclean re
