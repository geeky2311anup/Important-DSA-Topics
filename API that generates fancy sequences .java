import java.util.*;

class Fancy {

    private List<Long> arr;
    private long mul = 1;
    private long add = 0;
    private static final long MOD = 1000000007L;

    public Fancy() {
        arr = new ArrayList<>();
    }

    public void append(int val) {
        long inv = modInverse(mul);
        long stored = ((val - add + MOD) % MOD * inv) % MOD;
        arr.add(stored);
    }

    public void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    public void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    public int getIndex(int idx) {
        if (idx >= arr.size()) return -1;

        long val = arr.get(idx);
        long result = (val * mul % MOD + add) % MOD;
        return (int) result;
    }

    private long modInverse(long x) {
        return power(x, MOD - 2);
    }

    private long power(long a, long b) {
        long res = 1;
        a %= MOD;

        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }
}
