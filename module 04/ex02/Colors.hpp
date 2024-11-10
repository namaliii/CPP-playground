/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:55:19 by anamieta          #+#    #+#             */
/*   Updated: 2024/11/10 22:07:34 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP

#define BOLD(text) "\033[1m" text "\033[0m"
#define ITALIC(text) "\033[3m" text "\033[0m"

#define LIGHT_RED(text) "\033[38;5;208m" text "\033[0m"
#define RED(text) "\033[38;5;160m" text "\033[0m"
#define DARK_RED(text) "\033[38;5;124m" text "\033[0m"

#define LIGHT_GREEN(text) "\033[38;5;107m" text "\033[0m"
#define GREEN(text) "\033[38;5;28m" text "\033[0m"
#define DARK_GREEN(text) "\033[38;5;22m" text "\033[0m"

#define LIGHT_BLUE(text) "\033[38;5;33m" text "\033[0m"
#define BLUE(text) "\033[38;5;32m" text "\033[0m"
#define DARK_BLUE(text) "\033[38;5;17m" text "\033[0m"

#define YELLOW(text) "\033[38;5;220m" text "\033[0m"
#define SOFT_GREEN(text) "\033[38;5;107m" text "\033[0m"
#define MAGENTA(text) "\033[38;5;213m" text "\033[0m"
#define CYAN(text) "\033[38;5;51m" text "\033[0m"

#endif
