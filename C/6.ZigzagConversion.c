#include <stdio.h>
#include <string.h>
#include <cstdlib>

char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s)) {
        return s;
    }

    char *result = (char *)malloc(strlen(s) + 1);
    if (!result) {
        return NULL;
    }

    int pos = 0;
    int cycleLen = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {
        for (int j = 0; j + row < strlen(s); j += cycleLen) {
            result[pos++] = s[row + j];

            if (row != 0 && row != numRows - 1 && j + cycleLen - row < strlen(s)) {
                result[pos++] = s[j + cycleLen - row];
            }
        }
    }

    result[pos] = '\0';
    return result;
}

int main()
{
    char str[] = "PAYPALISHIRING";
    int numRows = 3;
    char *result = convert(str, numRows);
    printf("%s\n", result);

    system("pause");
}