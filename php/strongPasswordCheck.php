function strongPasswordChecker($s) {
    $res = 0;
    $a = 1;
    $A = 1;
    $d = 1;

    $carr = str_split($s);
    $arr = [];

    foreach (range(0, count($carr) - 1) as $i) {
        if (ctype_lower($carr[$i])) {
            $a = 0;
        }
        if (ctype_upper($carr[$i])) {
            $A = 0;
        }
        if (ctype_digit($carr[$i])) {
            $d = 0;
        }

        $j = $i;
        while ($i < count($carr) && $carr[$i] == $carr[$j]) {
            $i++;
        }
        $arr[$j] = $i - $j;
    }

    $total_missing = $a + $A + $d;

    if (count($arr) < 6) {
        $res += $total_missing + max(0, 6 - (count($arr) + $total_missing));
    } else {
        $over_len = max(count($arr) - 20, 0);
        $left_over = 0;
        $res += $over_len;

        foreach (range(1, 2) as $k) {
            foreach (range(0, count($arr) - 1) as $i) {
                if ($arr[$i] < 3 || $arr[$i] % 3 != $k - 1) {
                    continue;
                }
                $arr[$i] -= min($over_len, $k);
                $over_len -= $k;
            }
        }

        foreach (range(0, count($arr) - 1) as $i) {
            if ($arr[$i] >= 3 && $over_len > 0) {
                $need = $arr[$i] - 2;
                $arr[$i] -= $over_len;
                $over_len -= $need;
            }

            if ($arr[$i] >= 3) {
                $left_over += $arr[$i] / 3;
            }
        }

        $res += max($total_missing, $left_over);
    }

    return $res;
}