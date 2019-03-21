/*
** EPITECH PROJECT, 2019
** strfind
** File description:
** looks for a function
*/

int strfind(char const *str, char const *to_find)
{
    int count = 0;
    int count2 = 0;
    int exit_while = 0;

    while (str[count2] != '\0') {
        count = 0;
        exit_while = 0;
        while (to_find[count] != '\0' && exit_while == 0) {
            if (to_find[count] != str[count2 + count])
                exit_while = 1;
            count++;
        }
        if (count != 0 && exit_while == 0)
            return (count + count2);
        count2++;
    }
    return (-1);
}