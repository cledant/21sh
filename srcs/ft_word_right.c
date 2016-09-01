/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 18:47:56 by cledant           #+#    #+#             */
/*   Updated: 2016/08/21 19:07:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static inline size_t	ft_seek_space(char *s, size_t type)
{
	if (ft_isspace(s[0]) == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0)
		type++;
	return (type);
}

static inline size_t	ft_seek_char(char *s, size_t type)
{
	if (ft_isspace(s[0]) == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0)
		return (type);
	type++;
	return (type);
}

static inline void		ft_move_cursor(t_env *env, size_t type, size_t dec,
							t_btree *seek)
{
	t_btree		*seek_0;

	if (type == 2)
	{
		env->cur_char = env->cur_char + dec;
		env->cur_il = seek->left;
	}
	if (type == 0)
	{
		seek_0 = (env->cur_char == 2) ? env->cur_il : env->cur_il->right;
		while (seek_0->right != NULL)
			seek_0 = seek_0->right;
		env->cur_char = env->last_char;
		env->cur_il = seek_0;
	}
	ft_move_cursor_from_cur_buff_to_before_prompt(env);
	ft_create_buffer(env);
	ft_print_buffer(env);
	ft_move_cursor_from_last_buff_to_cur_buff(env);
}

int						ft_word_right(t_env *env)
{
	size_t		dec;
	size_t		type;
	t_btree		*seek;

	type = 0;
	seek = (env->cur_char == 2) ? env->cur_il : env->cur_il->right;
	dec = 0;
	if (seek == NULL || seek->content == NULL)
		return (1);
	while (seek != NULL)
	{
		if (type == 0)
			type = ft_seek_space(seek->content, type);
		else if (type == 1)
			type = ft_seek_char(seek->content, type);
		if (type == 2)
			break ;
		dec++;
		seek = seek->right;
	}
	ft_move_cursor(env, type, dec, seek);
	return (1);
}
