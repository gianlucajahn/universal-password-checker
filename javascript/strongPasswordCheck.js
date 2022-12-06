function strongPasswordChecker(s) {
    let res = 0, a = 1, A = 1, d = 1;
    let n = s.length;
    let arr = new Array(n);
        
    for (let i = 0; i < n;) {
        if (/[a-z]/.test(s[i])) a = 0;
        if (/[A-Z]/.test(s[i])) A = 0;
        if (/[0-9]/.test(s[i])) d = 0;
            
        let j = i;
        while (i < n && s[i] == s[j]) i++;
        arr[j] = i - j;
    }
        
    let total_missing = (a + A + d);

    if (n < 6) {
        res += total_missing + Math.max(0, 6 - (n + total_missing));
            
    } else {
        let over_len = Math.max(n - 20, 0), left_over = 0;
        res += over_len;
            
        for (let k = 1; k < 3; k++) {
            for (let i = 0; i < n && over_len > 0; i++) {
                if (arr[i] < 3 || arr[i] % 3 != (k - 1)) continue;
                arr[i] -= Math.min(over_len, k);
                over_len -= k;
            }
        }
            
        for (let i = 0; i < n; i++) {
            if (arr[i] >= 3 && over_len > 0) {
                let need = arr[i] - 2;
                arr[i] -= over_len;
                over_len -= need;
            }
                
            if (arr[i] >= 3) left_over += arr[i] / 3;
        }
            
        res += Math.max(total_missing, left_over);
    }
        
    return res;
}