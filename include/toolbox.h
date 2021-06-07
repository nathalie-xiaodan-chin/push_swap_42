#ifndef TOOLBOX_H
#define TOOLBOX_H
# include "struct.h"

int is_invisible_char(char c);

int   count_char_in_2d_array(int height, char **double_array);
char**     allocate_2d_array(int size_width, int size_height);
char **    fill_double_array(int width,int height, char **double_array, char content);
void    print_double_array_rectangle(int height_size, char **double_array);
void    print_double_array_square(int size, char **double_array);
int        ft_check_sep(char c, char* sep);
int        ft_count_words(char *str, char *charset);
void    ff();
void    pline(int line);
void    pint(int integer);
void    pstr(char *str);
void    pchar(char c);
void    pfloat(float c);

#endif
