#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void writeToFile(const char* filename, const char* content) {
    FILE* file = fopen(filename, "a");  // �}���ɮץH���[�覡�g�J
    if (file == NULL) {
        printf("�L�k�}���ɮ� %s �i��g�J�C\n", filename);
        return;
    }

    fprintf(file, "%s\n", content);  // �g�J���e���ɮ�
    fclose(file);  // �����ɮ�
}