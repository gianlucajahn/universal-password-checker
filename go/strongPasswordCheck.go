package main

import "fmt"

func strongPasswordChecker(s string) int {
    res := 0
    a := 1
    A := 1
    d := 1
    arr := make([]int, len(s))

    for i := 0; i < len(s); {
        if s[i] >= 'a' && s[i] <= 'z' {
            a = 0
        }
        if s[i] >= 'A' && s[i] <= 'Z' {
            A = 0
        }
        if s[i] >= '0' && s[i] <= '9' {
            d = 0
        }

        j := i
        for ; i < len(s) && s[i] == s[j]; i++ {
        }
        arr[j] = i - j
    }

    total_missing := a + A + d

    if len(s) < 6 {
        res += total_missing + max(0, 6 - (len(s) + total_missing))
    } else {
        over_len := max(len(s) - 20, 0)
        left_over := 0
        res += over_len

        for k := 1; k < 3; k++ {
            for i := 0; i < len(s); i++ {
                if over_len == 0 {
                    break
                }
                if arr[i] < 3 || arr[i] % 3 != (k - 1) {
                    continue
                }
                arr[i] -= min(over_len, k)
                over_len -= k
            }
        }

        for i := 0; i < len(s); i++ {
            if arr[i] >= 3 && over_len > 0 {
                need := arr[i] - 2
                arr[i] -= over_len
                over_len -= need
            }

            if arr[i] >= 3 {
                left_over += arr[i] / 3
            }
        }

        res += max(total_missing, left_over)
    }

    return res
}

func main() {
    s := "abcdefghijklmnopqrstuvwxyz"
    fmt.Println(strongPasswordChecker(s))
}