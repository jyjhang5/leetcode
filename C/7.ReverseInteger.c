#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int x){
    int result = 0;
    int max = INT_MAX / 10, min = INT_MIN / 10;

    while (x) {
        if (result > max || result < min)
            return 0;

        result *= 10;
        result += (x % 10);
        x /= 10;
    }

    return result;
}

int main() {
    int num;
    // num = -123;
    // num = 2147483647; // max
    // num = -2147483648; // min

    printf("%d\n", reverse(num));

    system("pause");

}
