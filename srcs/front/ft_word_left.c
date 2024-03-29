/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 21:32:52 by cledant           #+#    #+#             */
/*   Updated: 2016/09/25 20:42:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
	if (type == 3)
	{
		env->cur_char = env->cur_char - dec;
		env->cur_il = seek;
		ft_move_cursor_from_cur_buff_to_before_prompt(env);
		ft_create_buffer(env);
		ft_print_buffer(env);
		ft_move_cursor_from_last_buff_to_cur_buff(env);
	}
	else if (type == 2 && seek == NULL &&
				ft_isspace((char)env->last->content) == 0)
	{
		env->cur_char = 2;
		env->cur_il = env->last->content;
		ft_move_cursor_from_cur_buff_to_before_prompt(env);
		ft_create_buffer(env);
		ft_print_buffer(env);
		ft_move_cursor_from_last_buff_to_cur_buff(env);
	}
}

static inline void		ft_init(t_env *env, t_btree *seek, size_t *dec,
							size_t *type)
{
	*dec = 0;
	*type = 0;
	if (env->cur_char == env->last_char && ft_seek_char(seek->content,
			*type) == 1)
		*type = 2;
}

int						ft_word_left(t_env *env)
{
	size_t		dec;
	size_t		type;
	t_btree		*seek;

	seek = env->cur_il;
	if (seek->content == NULL)
		return (1);
	ft_init(env, seek, &dec, &type);
	while (seek != NULL)
	{
		if (type == 0)
			type = ft_seek_space(seek->content, type);
		else if (type == 1)
			type = ft_seek_char(seek->content, type);
		else if (type == 2)
			type = ft_seek_space(seek->content, type);
		if (type == 3)
			break ;
		dec++;
		seek = seek->left;
	}
	ft_move_cursor(env, type, dec, seek);
	ft_set_pos_col(env);
	return (1);
}
