/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:21:19 by cledant           #+#    #+#             */
/*   Updated: 2016/11/01 16:49:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_convert_list_into_str(t_env *env)
{
	if (env->cmd_line != NULL)
		ft_strdel(&(env->cmd_line));
	if ((env->cmd_line = ft_convert_btree_to_str(env->last->content,
			env->last_char)) == NULL)
		ft_handler(20000);
}

int						ft_enter(t_env *env)
{
	int		ret;

	ret = -1;
	ft_move_cursor_from_cur_buff_to_end_buff(env);
	write(env->fd_tty, "\n", 1);
	if (env->cur_il->content != NULL)
	{
		if (env->err_quote != NULL)
		{
			ft_add_to_err_quote(env);
			if ((ret = ft_check_quotes(env->stack_quote, env->err_quote->content))
					== 1)
			{
				ft_clear_err_quote(env);
				ft_convert_list_into_str(env);
				if ((env->last = ft_new_right_node(env)) == NULL)
					ft_handler(20000);
			}
			else
			{
				if (ft_new_right_node_error_quote(env, 0) != 1)
					ft_handler(20000);			
			}
		}
		else 
		{
			if ((ret = ft_check_quotes(env->stack_quote, env->cur_il->content))
					== 1)
			{
				ft_convert_list_into_str(env);
				if ((env->last = ft_new_right_node(env)) == NULL)
					ft_handler(20000);
			}
			else
			{
				if (ft_new_right_node_error_quote(env, 1) != 1)
					ft_handler(20000);			
			}
		}
	}
	else
		env->cur = env->last;
	ft_bzero(env->buff, env->last_buff);
	(ret != 0) ? ft_memcpy(env->buff, "$>", 2) : ft_memcpy(env->buff, "\>", 2);
	env->cur_buff = 2;
	env->last_buff = 2;
	(ret != 0) ? ft_main_shell(env) : ret = 0;
	(ret != 0) ? write(env->fd_tty, "$>", 2) : write(env->fd_tty, "\>", 2);
	return (1);
}
