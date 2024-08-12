#include <stdio.h>
#include <math.h>

int main(){
    FILE* fp = fopen("new.txt", "r");
    fclose(fp);
    return 0;
}