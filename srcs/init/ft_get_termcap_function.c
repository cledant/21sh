/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_termcap_function.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:25:48 by cledant           #+#    #+#             */
/*   Updated: 2016/09/19 20:56:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static inline void		ft_error(t_env *env)
{
	ft_env_destroy(env);
	ft_exit_mess(3);
}

static inline void		ft_get_termcap_next(t_env *env)
{
	if ((env->cd = tgetstr("cd", NULL)) == NULL)
		ft_error(env);
	if ((env->up = tgetstr("up", NULL)) == NULL)
		ft_error(env);
	if ((env->le = tgetstr("le", NULL)) == NULL)
		ft_error(env);
	if ((env->sr = tgetstr("sr", NULL)) == NULL)
		ft_error(env);
}

void					ft_get_termcap_function(t_env *env)
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
	ft_get_termcap_next(env);
}
