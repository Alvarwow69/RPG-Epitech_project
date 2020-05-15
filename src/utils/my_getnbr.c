/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** return the first number as int
*/

/*
** Test if the number is out of memory
*/
static int is_toolong(long long int number, int neg)
{
    if (number > 2147483647 && neg == 1)
        return (1);
    if (number > 2147483648 && neg == -1)
        return (1);
    return (0);
}

/*
** Test if the number is negativ
*/
static void is_neg(char const *str, int *neg, int i)
{
    if (str[i] == '-')
        *neg *= -1;
}

/*
** Loop all the char add the number if is it
** add '-' if is negativ and return the value
*/
int my_get_nbr(char const *str)
{
    int finded = 0;
    int stop = 0;
    long int number = 0;
    int neg = 1;

    for (int i = 0; str[i] != '\0' && stop == 0; i++) {
        is_neg(str, &neg, i);
        if (is_toolong(number, neg) == 1)
            return (0);
        if (str[i] >= 48 && str[i] <= 57) {
            number = (number * 10) + (str[i] - 48);
            finded = 1;
        } else if (finded == 1)
            stop = 1;
    }
    stop = (int) number * neg;
    return (stop);
}
