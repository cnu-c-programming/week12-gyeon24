#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 3) {return 1;}
    
    FILE* fp_src = fopen(argv[1], "r");
    if (fp_src == NULL) {
        fprintf(stderr, "error: cannot open\n");
        return 1;
    }
    FILE* fp_dst = fopen(argv[2], "w");
    if (fp_dst == NULL) {
        fprintf(stderr, "error: cannot open\n");
        fclose(fp_src);
        return 1;
    }

    int c;
    while ((c = fgetc(fp_src)) != EOF) {
        if (fputc(c, fp_dst) == EOF) {
            fprintf(stderr, "error: cannot write\n"); [cite: 524]
            fclose(fp_src);
            fclose(fp_dst);
            return 1;
        }
    }

    if (ferror(fp_src)) {
        fprintf(stderr, "error: cannot read\n"); [cite: 523]
        fclose(fp_src);
        fclose(fp_dst);
        return 1;
    }

    fclose(fp_src);
    fclose(fp_dst);
    return 0;
}
