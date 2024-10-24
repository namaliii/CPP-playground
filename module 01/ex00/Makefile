# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 18:22:22 by anamieta          #+#    #+#              #
#    Updated: 2024/10/24 18:28:10 by anamieta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ

CC = c++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++17

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS = ${SRC:%.cpp=%.o}

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re