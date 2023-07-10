/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:24:00 by julberna          #+#    #+#             */
/*   Updated: 2023/07/07 19:42:05 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

// fn(specifier){
// 	char	*arr_spec[9];
// 	while(*arr){
// 		if (arr[i] == specifier)
// 			return (arr[i](va_args(args, void *)));
// 	}
// }
