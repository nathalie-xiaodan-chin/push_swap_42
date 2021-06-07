#include "../../include/push_swap.h"

int is_invisible_char(char c)
{
    if (c == ' ' || c == '\t' || c == '\v'|| c == '\r' || c == '\v')
        return (1);
    return (0);
}

int   count_char_in_2d_array(int height, char **double_array)
{
    int i = 0;
    int total_count = 0;
    while(i < height)
    {

        total_count += ft_strlen(double_array[i]);
        i++;
    }
    return(total_count);
}
char**     allocate_2d_array(int size_width, int size_height)
{
    char** double_array = NULL;
    int i = 0;
    //Allocate memory for row
    double_array = (char**)malloc(size_height * sizeof(char*));
    //Allocate memory for column
    while (i < size_height)
    {
        double_array[i] = (char*)malloc(size_width * sizeof(char));
        i++;
    }
    return (double_array);
}

char **    fill_double_array(int width,int height, char **double_array, char content)
{
    int i = 0;
    int j = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            double_array[i][j] = content;
            j++;
        }
        double_array[i][j] = '\0';
        i++;
    }
    return (double_array);
}

/**
 * DEBUG TOOLS - BEGIN
*/

void    print_double_array_rectangle(int height_size, char **double_array)
{
    int i = 0;
    int j = 0;
    while(i < height_size)
    {

         printf("%s\n", double_array[i]);

        i++;
    }

}

void    print_double_array_square(int size, char **double_array)
{
    int i = 0;
    int j = 0;
    while(i < size)
    {
        j = 0;
        while(j < size)
        {
            printf("%c ", double_array[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

//used to print 2d array
int        ft_check_sep(char c, char* sep)
{
    int i;

    i = 0;
    while (sep[i])
    {
        if (c == sep[i])
            return (1);
        i++;
    }
    return (0);
}

//used to print 2d array
int        ft_count_words(char *str, char *charset)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (str[i] != '\0')
    {
        while (str[i] != '\0' && (ft_check_sep(str[i], charset) == 1)) // si c'est un charset
        {
            if (str[i + 1] == '\0') // si le prochain char est un '\0'
                return (count);
            i++;
        }
        while (str[i] != '\0' && (ft_check_sep(str[i], charset) == 0))
            i++;
        count++;
    }
    return (count);
}

void    ff()
{
    fflush(stdout);
}

void    pline(int line)
{
    printf("line |%d|\n", line);
    fflush(stdout);
}


void    pint(int integer)
{
    printf("int |%d|\n", integer);
    fflush(stdout);
}

void    pstr(char *str)
{
    printf("str |%s|\n", str);
    fflush(stdout);
}

void    pchar(char c)
{
    printf("c |%c|\n", c);
    fflush(stdout);
}

void    pfloat(float c)
{
    printf("float |%f|\n", c);
    fflush(stdout);
}
