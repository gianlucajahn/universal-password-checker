function strongPasswordChecker(s: string): number {
    let res: number = 0
    let a: number = 1
    let A: number = 1
    let d: number = 1

    let n: string = s.length
    let arr = new Array(n)

    for (let i = 0; i < n;) {
        if (/[a-z]/.test(s[i])) a = 0
        if (/[A-Z]/.test(s[i])) A = 0
        if (/[0-9]/.test(s[i])) d = 0

        let j: number = i
        while (i < n && s[i] == s[j]) i++
        arr[j] = i - j
    }

    let totalMissing = a + A + d

    if (n < 6) {
        res += totalMissing + Math.max(0, 6 - (n + totalMissing))
    } else {
        let overLen = Math.max(n - 20, 0)
        let leftOver = 0
        res += overLen

        for (let k = 1; k < 3; k++) {
            for (let i = 0; i < n && overLen > 0; i++) {
                if (arr[i] < 3 || arr[i] % 3 != (k - 1)) continue
                arr[i] -= Math.min(overLen, k)
                overLen -= k
            }
        }

        for (let i = 0; i < n; i++) {
            if (arr[i] >= 3 && overLen > 0) {
                let need = arr[i] - 2
                arr[i] -= overLen
                overLen -= need
            }

            if (arr[i] >= 3) leftOver += arr[i] / 3
        }

        res += Math.max(totalMissing, leftOver)
    }

    return res
}