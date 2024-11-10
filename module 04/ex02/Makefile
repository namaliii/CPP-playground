# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:29:40 by anamieta          #+#    #+#              #
#    Updated: 2024/11/10 22:27:42 by anamieta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Abstract

CC = c++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++17

SRC = main.cpp Brain.cpp AAnimal.cpp WrongAAnimal.cpp Cat.cpp WrongCat.cpp Dog.cpp WrongDog.cpp
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
# NAME = Animal

# CC = c++
# CFLAGS = -g3 -Wall -Wextra -Werror -std=c++17 -fsanitize=address -fno-omit-frame-pointer

# SRC = main.cpp Animal.cpp WrongAnimal.cpp Cat.cpp WrongCat.cpp Dog.cpp WrongDog.cpp
# OBJS = ${SRC:%.cpp=%.o}

# %.o: %.cpp
# 	$(CC) $(CFLAGS) -c $< -o $@

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
