def strongPasswordChecker(s):
    res = 0
    a = 1
    A = 1
    d = 1
    carr = list(s)
    arr = [0] * len(carr)
        
    i = 0
    while i < len(arr):
        if carr[i].islower():
            a = 0
        if carr[i].isupper():
            A = 0
        if carr[i].isdigit():
            d = 0
            
        j = i
        while i < len(carr) and carr[i] == carr[j]:
            i += 1
        arr[j] = i - j
        
    total_missing = (a + A + d)

    if len(arr) < 6:
        res += total_missing + max(0, 6 - (len(arr) + total_missing))
            
    else:
        over_len = max(len(arr) - 20, 0)
        left_over = 0
        res += over_len
            
        for k in range(1, 3):
            i = 0
            while i < len(arr) and over_len > 0:
                if arr[i] < 3 or arr[i] % 3 != (k - 1):
                    i += 1
                    continue
                arr[i] -= min(over_len, k)
                over_len -= k
                i += 1
            
        i = 0
        while i < len(arr):
            if arr[i] >= 3 and over_len > 0:
                need = arr[i] - 2
                arr[i] -= over_len
                over_len -= need
            
            if arr[i] >= 3:
                left_over += arr[i] // 3
            i += 1
            
        res += max(total_missing, left_over)
        
    return res