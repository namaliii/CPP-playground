# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 15:24:48 by anamieta          #+#    #+#              #
#    Updated: 2024/12/03 19:40:21 by anamieta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

CC = c++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++17

SRC = main.cpp Bureaucrat.cpp AForm.cpp \
		PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp Intern.cpp

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