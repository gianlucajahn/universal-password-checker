func strongPasswordChecker(s: String) -> Int {
    var res = 0
    var a = 1
    var A = 1
    var d = 1

    let carr = Array(s)
    var arr = [Int](repeating: 0, count: carr.count)

    for i in 0..<arr.count {
        if carr[i].isLowercase { a = 0 }
        if carr[i].isUppercase { A = 0 }
        if carr[i].isNumber { d = 0 }

        var j = i
        while i < carr.count && carr[i] == carr[j] { i += 1 }
        arr[j] = i - j
    }

    let totalMissing = a + A + d

    if arr.count < 6 {
        res += totalMissing + max(0, 6 - (arr.count + totalMissing))
    } else {
        let overLen = max(arr.count - 20, 0)
        var leftOver = 0
        res += overLen

        for k in 1..<3 {
            for i in 0..<arr.count where overLen > 0 {
                if arr[i] < 3 || arr[i] % 3 != (k - 1) { continue }
                arr[i] -= min(overLen, k)
                overLen -= k
            }
        }

        for i in 0..<arr.count {
            if arr[i] >= 3 && overLen > 0 {
                let need = arr[i] - 2
                arr[i] -= overLen
                overLen -= need
            }

            if arr[i] >= 3 { leftOver += arr[i] / 3 }
        }

        res += max(totalMissing, leftOver)
    }

    return res
}