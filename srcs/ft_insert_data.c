/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n_insert_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:42:37 by cledant           #+#    #+#             */
/*   Updated: 2016/08/20 12:13:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		ft_insert_data(char s[4], t_env *env)
{
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_insert_char(s, env);
	ft_create_buffer(env);
}
