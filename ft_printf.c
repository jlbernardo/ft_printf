/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:24:00 by julberna          #+#    #+#             */
/*   Updated: 2023/06/27 20:26:32 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_string(const char *str, va_list args);
static int	ft_handle_specifier(char c, va_list args);

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

static int	ft_handle_specifier(char specifier, va_list args)
{
	if (specifier == 'd' || specifier == 'i')
		return (ft_handle_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_handle_unsigned_int(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_handle_lower_hex(va_arg(args, int)));
	else if (specifier == 'X')
		return (ft_handle_upper_hex(va_arg(args, int)));
	else if (specifier == 'c')
		return (ft_handle_char(va_arg(args, char)));
	else if (specifier == 's')
		return (ft_handle_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_handle_ptr(va_arg(args, void *)));
	else if (specifier == '%')
		return (ft_handle_percent());
	return (0);
}
