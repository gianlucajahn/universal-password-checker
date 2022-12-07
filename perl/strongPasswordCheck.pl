sub strongPasswordChecker {
    my $s = shift;
    my $res = 0;
    my $a = 1;
    my $A = 1;
    my $d = 1;

    my @carr = split //, $s;
    my @arr = ();

    for my $i (0..$#carr) {
        if ($carr[$i] =~ /[a-z]/) {
            $a = 0;
        }
        if ($carr[$i] =~ /[A-Z]/) {
            $A = 0;
        }
        if ($carr[$i] =~ /\d/) {
            $d = 0;
        }

        my $j = $i;
        while ($i < @carr && $carr[$i] eq $carr[$j]) {
            $i++;
        }
        $arr[$j] = $i - $j;
    }

    my $total_missing = $a + $A + $d;

    if (@arr < 6) {
        $res += $total_missing + max(0, 6 - (@arr + $total_missing));
    } else {
        my $over_len = max(@arr - 20, 0);
        my $left_over = 0;
        $res += $over_len;

        for my $k (1..2) {
            for my $i (0..$#arr) {
                if ($arr[$i] < 3 || $arr[$i] % 3 != ($k - 1)) {
                    next;
                }
                $arr[$i] -= min($over_len, $k);
                $over_len -= $k;
            }
        }

        for my $i (0..$#arr) {
            if ($arr[$i] >= 3 && $over_len > 0) {
                my $need = $arr[$i] - 2;
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