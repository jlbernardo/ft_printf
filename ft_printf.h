/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:23:08 by julberna          #+#    #+#             */
/*   Updated: 2023/07/09 15:45:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_handle_char(va_list args);
int	ft_handle_int(va_list args);
int	ft_handle_lower_hex(va_list args);
int	ft_handle_percent(void);
int	ft_handle_ptr(va_list args);
int	ft_handle_str(va_list args);
int	ft_handle_unsigned_int(va_list args);
int	ft_handle_upper_hex(va_list args);
int	ft_handle_space(va_list args, char specifier);
int	ft_handle_plus(va_list args);
int	ft_handle_octothorpe(char specifier, va_list args);

#endif
