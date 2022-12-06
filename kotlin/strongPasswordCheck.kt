fun strongPasswordChecker(s: String): Int {
    var res = 0
    var a = 1
    var A = 1
    var d = 1

    val carr = s.toCharArray()
    val arr = IntArray(carr.size)

    for (i in arr.indices) {
        if (carr[i].isLowerCase()) a = 0
        if (carr[i].isUpperCase()) A = 0
        if (carr[i].isDigit()) d = 0

        var j = i
        while (i < carr.size && carr[i] == carr[j]) i++
        arr[j] = i - j
    }

    val total_missing = a + A + d

    if (arr.size < 6) {
        res += total_missing + kotlin.math.max(0, 6 - (arr.size + total_missing))
    } else {
        val over_len = kotlin.math.max(arr.size - 20, 0)
        var left_over = 0
        res += over_len

        for (k in 1..2) {
            for (i in arr.indices) {
                if (arr[i] < 3 || arr[i] % 3 != (k - 1)) continue
                arr[i] -= kotlin.math.min(over_len, k)
                over_len -= k
            }
        }

        for (i in arr.indices) {
            if (arr[i] >= 3 && over_len > 0) {
                val need = arr[i] - 2
                arr[i] -= over_len
                over_len -= need
            }

            if (arr[i] >= 3) left_over += arr[i] / 3
        }

        res += kotlin.math.max(total_missing, left_over)
    }

    return res
}