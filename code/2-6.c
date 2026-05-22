#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    const char* target_str = argv[2];
    char buf[512];
    while (fgets(buf, sizeof(buf), fp))
        if (strstr(buf, target_str)) printf("%s", buf);
    fclose(fp);
}
