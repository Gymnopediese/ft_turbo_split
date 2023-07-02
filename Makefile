# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 16:16:47 by albaud            #+#    #+#              #
#    Updated: 2023/07/02 21:45:39 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

green="\033[0;32m"

all:
	# @norminette
	@gcc -Wall -Werror -Wextra ft_turbo_split.c -o split
	@echo ${green}SPLIT USAGE:  ./split \"String to Split\"