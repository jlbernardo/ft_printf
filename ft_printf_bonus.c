/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:48:14 by julberna          #+#    #+#             */
/*   Updated: 2023/07/10 19:30:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_bonus.h"

static int	ft_print_string(const char *str, va_list args);
static int	ft_handle_specifier(char c, va_list args);
static int	ft_handle_flag(const char *str, va_list args);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_count;

	if (!str)
		return (0);
	char_count = 0;
	va_start(args, str);
	char_count += ft_print_string(str, args);
	va_end(args);
	return (char_count);
}

static int	ft_print_string(const char *str, va_list args)
{
	int	char_count;
	int	i;

	char_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == ' ' || str[i + 1] == '+' || str[i + 1] == '#')
				char_count += ft_handle_flag(&str[i++], args);
			else
				char_count += ft_handle_specifier(str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			char_count++;
		}
		i++;
	}
	return (char_count);
}

static int	ft_handle_flag(const char *str, va_list args)
{
	int	i;
	int	char_count;

	i = 0;
	char_count = 0;
	if (str[i + 1] == ' ')
	{
		if (str[i + 2] == 'd' || str[i + 2] == 'i')
			char_count += ft_handle_space_bonus(args, 'i');
		else if (str[i + 2] == 's')
			char_count += ft_handle_space_bonus(args, 's');
	}
	else if (str[i + 1] == '+')
	{
		if (str[i + 2] == 'd' || str[i + 2] == 'i')
			char_count += ft_handle_plus_bonus(args);
	}
	else if (str[i + 1] == '#')
	{
		if (str[i + 2] == 'x' || str[i + 2] == 'X')
			char_count += ft_handle_octothorpe_bonus(str[i + 2], args);
	}
	return (char_count);
}

static int	ft_handle_specifier(char specifier, va_list args)
{
	if (specifier == 'd' || specifier == 'i')
		return (ft_handle_int(args));
	else if (specifier == 'u')
		return (ft_handle_unsigned_int(args));
	else if (specifier == 'x')
		return (ft_handle_lower_hex(args));
	else if (specifier == 'X')
		return (ft_handle_upper_hex(args));
	else if (specifier == 'c')
		return (ft_handle_char(args));
	else if (specifier == 's')
		return (ft_handle_str(args));
	else if (specifier == 'p')
		return (ft_handle_ptr(args));
	else if (specifier == '%')
		return (ft_handle_percent());
	return (0);
}
