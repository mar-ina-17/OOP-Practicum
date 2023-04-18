#include <iostream>
#ifndef helpers
#define helpers

char *createString(const std::size_t size)
{
    char *str = new (std::nothrow) char[size + 1];
    if (!str)
    {
        std::cout << "Creation of string failed!" << std::endl;
        return nullptr;
    }
    return str;
}

std::size_t strlen(const char *str)
{
    std::size_t len = 0;

    while (str[len])
    {
        ++len;
    }

    return len;
}

char *strcpy(const char *str, char *dest)
{
    const std::size_t size = strlen(str);
    dest = createString(size);

    for (int i = 0; i < size; i++)
    {
        dest[i] = str[i];
    }
    dest[size] = '\0';
    return dest;
}

char *strcat(char *str1, char *str2)
{
    std::size_t size = strlen(str1) + strlen(str2);
    char *newStr = createString(size);

    int i = 0;

    for (i; i < strlen(str1); i++)
    {
        newStr[i] = str1[i];
    }

    for (int j = strlen(str1), i = 0; j < size; j++)
    {
        newStr[j] = str2[i];
        i++;
    }
    return newStr;
}

// strcmp to do

int strcmp(const char *str1, const char *str2)
{
    std::size_t len1 = strlen(str1), len2 = strlen(str2);
    std::size_t counter = len1 < len2 ? len1 : len2;
    for (int i = 0; i < counter; i++)
    {
        if (str1[i] > str2[i])
            return 1;
        if (str1[i] < str2[i])
            return -1;
    }
    return 2;
}

#endif