#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "btree.h"
using namespace std;

int main() {
    char name_A[80];
    char name_B[80];
    scanf("%s%s", name_A, name_B);

    FILE* file_A = fopen(name_A, "r");
    FILE* file_B = fopen(name_B, "r");

    btree<string> A;
    
    string help;
    char word_A[80];
    while (fscanf(file_A, "%s", word_A) == 1) {
        help = word_A;
        A.insert(help);
    }
    FILE* file_C = fopen("C.txt", "w");
    char word_B[80];
    while (fscanf(file_B, "%s", word_B) == 1) {
        help = word_B;
        if (A.isHave(help)) fprintf(file_C,"%s ", word_B);
    }
    fclose(file_A);
    fclose(file_B);
    fclose(file_C);
}