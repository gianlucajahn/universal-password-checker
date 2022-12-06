public int strongPasswordChecker(string s)
{
    int res = 0;
    int a = 1, A = 1, d = 1;
    char[] carr = s.ToCharArray();
    int[] arr = new int[carr.Length];
        
    for (int i = 0; i < arr.Length;)
    {
        if (char.IsLower(carr[i])) a = 0;
        if (char.IsUpper(carr[i])) A = 0;
        if (char.IsDigit(carr[i])) d = 0;
            
        int j = i;
        while (i < carr.Length && carr[i] == carr[j]) i++;
        arr[j] = i - j;
    }
        
    int total_missing = (a + A + d);

    if (arr.Length < 6)
    {
        res += total_missing + Math.Max(0, 6 - (arr.Length + total_missing));
            
    }
    else
    {
        int over_len = Math.Max(arr.Length - 20, 0), left_over = 0;
        res += over_len;
            
        for (int k = 1; k < 3; k++)
        {
            for (int i = 0; i < arr.Length && over_len > 0; i++)
            {
                if (arr[i] < 3 || arr[i] % 3 != (k - 1)) continue;
                arr[i] -= Math.Min(over_len, k);
                over_len -= k;
            }
        }
            
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] >= 3 && over_len > 0)
            {
                int need = arr[i] - 2;
                arr[i] -= over_len;
                over_len -= need;
            }
                
            if (arr[i] >= 3) left_over += arr[i] / 3;
        }
            
        res += Math.Max(total_missing, left_over);
    }
        
    return res;
}