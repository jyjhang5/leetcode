#include <stdio.h>
#include <string.h>
#include <cstdlib>

void expandAroundCenter(char *str, int left, int right, int *outResultStart, int *outMaxLength)
{
    int strLen = strlen(str);

    while (left >= 0 && right < strLen && str[left] == str[right]) {
        left--;
        right++;
    }

    if ((right - left - 1) > *outMaxLength) {
        *outResultStart = left + 1;
        *outMaxLength = right - left - 1;
    }

    return;
}

char* longestPalindrome(char* s)
{
    int maxLength = 0;
    int outResultStart = 0;
    char *result = NULL;

    for (int i = 0; i < strlen(s); i++) {
        expandAroundCenter(s, i, i, &outResultStart, &maxLength);
        expandAroundCenter(s, i, i + 1, &outResultStart, &maxLength);
    }

    if (maxLength > 0) {
        result = s + outResultStart;
        result[maxLength] = '\0';

    }

    return result;
}

int main()
{
    char str[] = "babad";
    // char str[] = "cbbd";
    char *result = longestPalindrome(str);
    printf("%s\n", result);

    system("pause");
}