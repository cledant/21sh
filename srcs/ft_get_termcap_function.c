/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_termcap_function.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:25:48 by cledant           #+#    #+#             */
/*   Updated: 2016/07/12 15:50:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void		ft_error(t_env *env)
{
	ft_env_destroy(env);
	ft_exit_mess(3);
}

void			ft_get_termcap_function(t_env *env)
{
	if ((env->cl = tgetstr("cl", NULL)) == NULL)
		ft_error(env);
	if ((env->vi = tgetstr("vi", NULL)) == NULL)
		ft_error(env);
	if ((env->ve = tgetstr("ve", NULL)) == NULL)
		ft_error(env);
	if ((env->us = tgetstr("us", NULL)) == NULL)
		ft_error(env);
	if ((env->ue = tgetstr("ue", NULL)) == NULL)
		ft_error(env);
	if ((env->ho = tgetstr("ho", NULL)) == NULL)
		ft_error(env);
	if ((env->ce = tgetstr("ce", NULL)) == NULL)
		ft_error(env);
	if ((env->mr = tgetstr("mr", NULL)) == NULL)
		ft_error(env);
	if ((env->me = tgetstr("me", NULL)) == NULL)
		ft_error(env);
	if ((env->nd = tgetstr("nd", NULL)) == NULL)
		ft_error(env);
	if ((env->cr = tgetstr("cr", NULL)) == NULL)
		ft_error(env);
	if ((env->doo = tgetstr("do", NULL)) == NULL)
		ft_error(env);
}
