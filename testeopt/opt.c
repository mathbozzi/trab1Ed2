#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int aopt = 0, hopt = 0;
    int qopt = 0;
    int opt1 = 0, opt2 = 0;
    int opt3 = 0;
    int iopt = 0, sopt = 0;
    int eopt = 0;
    int opt;
    // int nsecs = 0;
    // int tfnd = 0;
    // int flags = 0;

    opt = getopt(1, argv, "123iseqha");
    switch (opt) {
        case '1':
            opt1 = 1;
            break;
        case '2':
            opt2 = 2;
            break;
        case '3':
            opt3 = 3;
            break;
        case 'i':
            iopt = 4;
            break;
        case 's':
            sopt = 5;
            break;
        case 'e':
            eopt = 6;
            break;
        case 'q':
            qopt = 7;
            break;
        case 'h':
            hopt = 8;
            break;
        case 'a':
            aopt = 9;
            break;

        default: /* '?' */
            fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                    argv[0]);
            exit(EXIT_FAILURE);
    }

    // printf("flags=%d; tfnd=%d; optind=%d\n", flags, tfnd, optind);

    // if (optind >= argc) {
    //     fprintf(stderr, "Expected argument after options\n");
    //     exit(EXIT_FAILURE);
    // }

    // printf("name argument = %s\n", argv[optind]);

    /* Other code omitted */

    return 0;
}