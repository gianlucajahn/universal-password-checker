#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int strongPasswordChecker(string s) {
    int res = 0, a = 1, A = 1, d = 1;
    int n = s.length();
    int* arr = new int[n];
        
    for (int i = 0; i < n;) {
        if (islower(s[i])) a = 0;
        if (isupper(s[i])) A = 0;
        if (isdigit(s[i])) d = 0;
            
        int j = i;
        while (i < n && s[i] == s[j]) i++;
        arr[j] = i - j;
    }
        
    int total_missing = (a + A + d);

    if (n < 6) {
        res += total_missing + max(0, 6 - (n + total_missing));
            
    } else {
        int over_len = max(n - 20, 0), left_over = 0;
        res += over_len;
            
        for (int k = 1; k < 3; k++) {
            for (int i = 0; i < n && over_len > 0; i++) {
                if (arr[i] < 3 || arr[i] % 3 != (k - 1)) continue;
                arr[i] -= min(over_len, k);
                over_len -= k;
            }
        }
            
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 3 && over_len > 0) {
                int need = arr[i] - 2;
                arr[i] -= over_len;
                over_len -= need;
            }
                
            if (arr[i] >= 3) left_over += arr[i] / 3;
        }
            
        res += max(total_missing, left_over);
    }
        
    delete[] arr;
    return res;
}