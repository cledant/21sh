/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_key.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:53:42 by cledant           #+#    #+#             */
/*   Updated: 2016/09/24 16:38:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_KEY_H
# define SHELL_KEY_H

# ifdef __APPLE__
# define ENTER 10 /*ENTER*/
# define CTRL_D 4 /*CTRL+D*/
# define CLEAR_WIN 12 /*CTRL + L*/
# define HIST_UP 4283163 /*UP*/
# define HIST_DOWN 4348699 /*DOWN*/
# define CHAR_RIGHT 4414235 /*RIGHT*/
# define CHAR_LEFT 4479771 /*LEFT*/
# define LINE_UP 4741915 /*HOME*/
# define LINE_DOWN 4610843 /*END*/
# define CUR_DEL 2117294875 /*DEL*/
# define BACK_DEL 127 /*BACK_DEL*/
# define WORD_LEFT 1146821403 /*OPT+LEFT*/
# define WORD_RIGHT 1130044187 /*OPT+RIGHT*/
# define BUFF_UP 1096489755 /*OPT+UP*/
# define BUFF_DOWN 1113266971 /*OPT+DOWN*/
# define SELECT_MODE 40899 /*OPT+S*/
# define COPY 42947 /*OPT+C*/
# define CUT 8948194 /*OPT+X*/
# define PASTE 10127586 /*OPT+V*/
# define ESC 27 /*ESC*/
# define M_LINE 46530 /*OPT+M*/
# define TAB 9 /*TAB*/
#else
# define ENTER 10 /*ENTER*/
# define CTRL_D 4 /*CTRL+D*/
# define CLEAR_WIN 12 /*CTRL + L*/
# define HIST_UP 4283163 /*UP*/
# define HIST_DOWN 4348699 /*DOWN*/
# define CHAR_RIGHT 4414235 /*RIGHT*/
# define CHAR_LEFT 4479771 /*LEFT*/
# define LINE_UP 4741915 /*HOME*/
# define LINE_DOWN 4610843 /*END*/
# define CUR_DEL 2117294875 /*DEL*/
# define BACK_DEL 127 /*BACK_DEL*/
# define WORD_LEFT 24859 /*ALT+A*/
# define WORD_RIGHT 31259 /*ALT+Z*/
# define BUFF_UP 28443 /*ALT+O*/
# define BUFF_DOWN 28699 /*ALT+P*/
# define SELECT_MODE 29467 /*ALT+S*/
# define COPY 25371 /*ALT+C*/
# define CUT 30747 /*ALT+X*/
# define PASTE 30235 /*ALT+V*/
# define ESC 27 /*ESC*/
# define M_LINE 27931 /*ALT+M*/
# define TAB 9 /*TAB*/
# endif

#endif
