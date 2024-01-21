/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:05:15 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/01/21 17:05:19 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}


void ft_putstr(char *str)
{
    int i;

    i = 0;
    if(str)
    {
        while(*str != '\0')
        {
            ft_putchar(*str);
            ++str;
            i++;
        }
    }
}

void ft_reverse(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void ft_itoa(int num, char *str) {
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        int rem = num % 10;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / 10;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0'; // Null-terminate string

    ft_reverse(str, i); // Reverse the string
}

void ft_putnbr(int n) {
    char str[12]; // Enough to hold any int value
    ft_itoa(n, str);
    ft_putstr(str);
}

char *ft_strdup(const char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    char *dup = (char *)malloc((length + 1) * sizeof(char));
    if (dup == NULL) {
        return NULL; // Return NULL if allocation fails
    }

    for (int i = 0; i <= length; i++) {
        dup[i] = s[i];
    }

    return dup;
}

char *ft_strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return (*str == c) ? (char *)str : NULL;
}


char *ft_strtok(char *str, const char *delim) {
    static char *lasts;
    int ch;

    if (str == NULL) {
        str = lasts;
    }
    if (str == NULL) {
        return NULL;
    }

    // Skip the leading delimiters
    while ((ch = *str) != '\0' && ft_strchr(delim, ch) != NULL) {
        str++;
    }

    if (ch == '\0') {
        return NULL;
    }

    char *token = str;

    // Find the end of the token
    while ((ch = *str) != '\0' && ft_strchr(delim, ch) == NULL) {
        str++;
    }

    if (ch != '\0') {
        *str = '\0';
        str++;
    }

    lasts = str;
    return token;
}
