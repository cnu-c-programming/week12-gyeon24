#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";
    
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    char buffer[64];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        int val;
        if (sscanf(buffer, "%d", &val) == 1) {
            sum += val;
        } else {
            buffer[char_caps - 1] = '\0'; 
            fprintf(stderr, "invalid input %s", buffer); 
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
