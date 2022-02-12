#include <stdio.h>  /* for printf */
#include <stdlib.h> /* for exit */
#include <unistd.h> /* for getopt */
int main(int argc, char **argv) {
    int c;
    int digit_optind = 0;
    int aopt = 0, bopt = 0;
    int copt = 0;
    while ((c = getopt(argc, argv, "abcd:012")) != -1) {
        int this_option_optind = optind ? optind : 1;
        switch (c) {
            case '0':
            case '1':
            case '2':
                if (digit_optind != 0 && digit_optind != this_option_optind)
                    printf("digits occur in two different argv-elements.\n");
                digit_optind = this_option_optind;
                printf("option %c\n", c);
                break;
            case 'a':
                printf("option a\n");
                aopt = 1;
                break;
            case 'b':
                printf("option b\n");
                bopt = 1;
                break;
            case 'c':
                printf("option c\n");
                copt = 0;
                break;
            case '?':
                break;
            default:
                printf("?? getopt returned character code 0%o ??\n", c);
        }
    }
    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }
    if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }
    exit(0);
}