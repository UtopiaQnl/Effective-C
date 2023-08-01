bool is_prime(uint64_t n, uint32_t k)
{
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    uint64_t d = n - 1;
    while (d % 2 == 0) d /= 2;

    for (; k != 0; --k) {
        if (!miller_rabin_test(d, n)) return false;
    }
    return true;
}
