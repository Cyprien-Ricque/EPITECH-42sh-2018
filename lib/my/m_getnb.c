/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

long m_getnb(char const *str)
{
    long nb = 0;
    int neg = 1;

    if (!str)
        return (0);
    for (int i = 0; str[i] != '\0' && ((str[i] <= '9' && str[i] >= '0') ||
        (str[i] == '-' || str[i] == '+')); ++i) {
        neg *= (str[i] == '-') ? -1 : 1;
        nb = str[i] >= '0' && str[i] <= '9' ? nb * 10 + str[i] - 48 : nb;
    }
    return (nb * neg);
}