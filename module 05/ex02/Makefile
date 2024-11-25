# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 15:24:48 by anamieta          #+#    #+#              #
#    Updated: 2024/11/25 15:24:37 by anamieta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm

CC = c++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++17

SRC = main.cpp Bureaucrat.cpp AForm.cpp \
		PresidentialPardonForm.cpp RobotomyCreationForm.cpp \
		ShrubberyCreationForm.cpp

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