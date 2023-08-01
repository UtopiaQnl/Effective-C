static void print_help(void)
{
    puts("primetest num1 [num2 num3 ... numN]\n");
    puts("Tests positive integers for primality. Supports testing");
    printf("%s [2-%" PRIuMAX "].\n", "numbers in the range", UINTMAX_MAX);
}
