int main(int argc, char *argv[])
{
    size_t num_args;

    uint64_t *vals = convert_command_line_args(argc, argv, &num_args);

    if (!vals) return EXIT_FAILURE;

    for (size_t i = 0; i < num_args; ++i) {
        printf("%" PRIu64 " is %s.\n", vals[i], is_prime(vals[i], 100) ? "probably prime" : "not prime");
    }
    free(vals);

    return EXIT_SUCCESS;
}
