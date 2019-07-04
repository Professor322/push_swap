# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlegros <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 18:55:39 by vlegros           #+#    #+#              #
#    Updated: 2019/03/20 23:46:03 by vlegros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make  -C ./checker_folder all
	@make  -C ./push_swap_folder all
clean:
	@make -C ./checker_folder clean
	@make -C ./push_swap_folder clean
fclean: clean
	@rm -f $(NAME)
	@make -C ./checker_folder fclean
	@make -C ./push_swap_folder fclean
re: fclean all
