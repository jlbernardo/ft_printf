/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:10:29 by julberna          #+#    #+#             */
/*   Updated: 2023/07/10 19:39:19 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

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
int	ft_handle_space_bonus(va_list args, char specifier);
int	ft_handle_plus_bonus(va_list args);
int	ft_handle_octothorpe_bonus(char specifier, va_list args);

#endif
