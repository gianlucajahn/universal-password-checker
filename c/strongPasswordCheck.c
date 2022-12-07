#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strongPasswordChecker(char *s)
{
    int res = 0, a = 1, A = 1, d = 1;
    int len = strlen(s);
    int arr[len];

    for (int i = 0; i < len;)
    {
        if (islower(s[i]))
            a = 0;
        if (isupper(s[i]))
            A = 0;
        if (isdigit(s[i]))
            d = 0;

        int j = i;
        while (i < len && s[i] == s[j])
            i++;
        arr[j] = i - j;
    }

    int total_missing = (a + A + d);

    if (len < 6)
    {
        res += total_missing + fmax(0, 6 - (len + total_missing));
    }
    else
    {
        int over_len = fmax(len - 20, 0), left_over = 0;
        res += over_len;

        for (int k = 1; k < 3; k++)
        {
            for (int i = 0; i < len && over_len > 0; i++)
            {
                if (arr[i] < 3 || arr[i] % 3 != (k - 1))
                    continue;
                arr[i] -= fmin(over_len, k);
                over_len -= k;
            }
        }

        for (int i = 0; i < len; i++)
        {
            if (arr[i] >= 3 && over_len > 0)
            {
                int need = arr[i] - 2;
                arr[i] -= over_len;
                over_len -= need;
            }

            if (arr[i] >= 3)
                left_over += arr[i] / 3;
        }

        res += fmax(total_missing, left_over);
    }

    return res;
}

int main(void)
{
    char s[] = "abcdefghijklmnopqrstuvwxyz";
    printf("%d\n", strongPasswordChecker(s));
    return 0;
}