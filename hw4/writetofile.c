#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void writeToFile(const char* filename, const char* content) {
    FILE* file = fopen(filename, "a");  // 開啟檔案以附加方式寫入
    if (file == NULL) {
        printf("無法開啟檔案 %s 進行寫入。\n", filename);
        return;
    }

    fprintf(file, "%s\n", content);  // 寫入內容到檔案
    fclose(file);  // 關閉檔案
}