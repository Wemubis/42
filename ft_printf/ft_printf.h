/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:44:52 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/29 16:23:23 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*-------------------------HEAD-------------------------*/

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

/*-------------------------FCTN-------------------------*/

/*----------------CORE----------------*/
int		ft_printf(const char *format, ...);

/*---------------FT-STR---------------*/
size_t	ft_strlen(char *s);

/*---------------FT-PUT---------------*/
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_base(long nb, char *base);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putptr_base(void *n, char *base);

#endif
