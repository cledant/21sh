/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_key.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:53:42 by cledant           #+#    #+#             */
/*   Updated: 2016/09/25 12:44:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_KEY_H
# define SHELL_KEY_H

# ifdef __APPLE__
/*
** ENTER
*/
#  define ENTER 10
/*
** CTRL+D
*/
#  define CTRL_D 4
/*
** CTRL+L
*/
#  define CLEAR_WIN 12
/*
** UP
*/
#  define HIST_UP 4283163
/*
** DOWN
*/
#  define HIST_DOWN 4348699
/*
** RIGHT
*/
#  define CHAR_RIGHT 4414235
/*
**LEFT
*/
#  define CHAR_LEFT 4479771
/*
** HOME
*/
#  define LINE_UP 4741915
/*
** END
*/
#  define LINE_DOWN 4610843
/*
** DEL
*/
#  define CUR_DEL 2117294875
/*
** BACK_DEL
*/
#  define BACK_DEL 127
/*
** OPT+LEFT
*/
#  define WORD_LEFT 1146821403
/*
** OPT+RIGHT
*/
#  define WORD_RIGHT 1130044187
/*
** OPT+UP
*/
#  define BUFF_UP 1096489755
/*
** OPT+DOWN
*/
#  define BUFF_DOWN 1113266971
/*
** OPT+S
*/
#  define SELECT_MODE 40899
/*
** OPT+C
*/
#  define COPY 42947
/*
** OPT+X
*/
#  define CUT 8948194
/*
** OPT+V
*/
#  define PASTE 10127586
/*
** ESC
*/
#  define ESC 27
/*
** OPT+M
*/
#  define M_LINE 46530
/*
** TAB
*/
#  define TAB 9
# else
/*
** ENTER
*/
#  define ENTER 10
/*
** CTRL+D
*/
#  define CTRL_D 4
/*
** CTRL+L
*/
#  define CLEAR_WIN 12
/*
** UP
*/
#  define HIST_UP 4283163
/*
** DOWN
*/
#  define HIST_DOWN 4348699
/*
** RIGHT
*/
#  define CHAR_RIGHT 4414235
/*
** LEFT
*/
#  define CHAR_LEFT 4479771
/*
** HOME
*/
#  define LINE_UP 4741915
/*
** END
*/
#  define LINE_DOWN 4610843
/*
** DEL
*/
#  define CUR_DEL 2117294875
/*
** BACK_DEL
*/
#  define BACK_DEL 127
/*
** ALT+A
*/
#  define WORD_LEFT 24859
/*
** ALT+Z
*/
#  define WORD_RIGHT 31259
/*
** ALT+O
*/
#  define BUFF_UP 28443
/*
** ALT+P
*/
#  define BUFF_DOWN 28699
/*
** ALT+S
*/
#  define SELECT_MODE 29467
/*
** ALT+C
*/
#  define COPY 25371
/*
** ALT+X
*/
#  define CUT 30747
/*
** ALT+V
*/
#  define PASTE 30235
/*
** ESC
*/
#  define ESC 27
/*
** ALT+M
*/
#  define M_LINE 27931
/*
** TAB
*/
#  define TAB 9
# endif

#endif
