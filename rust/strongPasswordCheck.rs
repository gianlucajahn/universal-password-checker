use std::cmp::{max, min};

fn strong_password_checker(s: &str) -> i32 {
    let mut res = 0;
    let mut a = 1;
    let mut A = 1;
    let mut d = 1;
    let mut arr = vec![0; s.len()];

    for (i, c) in s.chars().enumerate() {
        if c.is_lowercase() {
            a = 0;
        }
        if c.is_uppercase() {
            A = 0;
        }
        if c.is_numeric() {
            d = 0;
        }

        let j = i;
        while i < s.len() && s.chars().nth(i) == s.chars().nth(j) {
            i += 1;
        }
        arr[j] = i - j;
    }

    let total_missing = a + A + d;

    if s.len() < 6 {
        res += total_missing + max(0, 6 - (s.len() + total_missing));
    } else {
        let mut over_len = max(s.len() - 20, 0);
        let mut left_over = 0;
        res += over_len;

        for k in 1..3 {
            for i in 0..s.len() {
                if over_len == 0 {
                    break;
                }
                if arr[i] < 3 || arr[i] % 3 != (k - 1) {
                    continue;
                }
                arr[i] -= min(over_len, k);
                over_len -= k;
            }
        }

        for i in 0..s.len() {
            if arr[i] >= 3 && over_len > 0 {
                let need = arr[i] - 2;
                arr[i] -= over_len;
                over_len -= need;
            }

            if arr[i] >= 3 {
                left_over += arr[i] / 3;
            }
        }

        res += max(total_missing, left_over);
    }

    res
}

fn main() {
    let s = "abcdefghijklmnopqrstuvwxyz";
    println!("{}", strong_password_checker(s));
}