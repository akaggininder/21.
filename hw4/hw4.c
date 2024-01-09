#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"area.h"





int main() {

    srand((unsigned int)time(NULL));


    int playerScore = 0;
    int dealerScore = 0;
    const int maxScore = 21;
    printf("�W�h");
    printf("2~10���P�ȥH�I�ƭp��C J�BQ�BK���P�ȥH10�I�p��C Ace���P�ȥi�O��11�I�Ϊ�1�I�C �I�ƦX�p�W�L21�I�ɡAAce�۰ʥH1�I�p��C");
    printf("�C�쪱�a��P�̦h�i�ɵP��5�i�C �I�ƶW�L21�I�z�P�ɰ���ɵP�ÿ鱼�Ӧ����ɡC\n");
    printf("���a�M���a�U�o��i�P�A���a�@�}�l�u�|�S�@�i�A���a�h�S��i�A���a����ܬO�_�[�P�A���a���P��A�~�����a�[�P\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    FILE* file = fopen("game_log.txt", "w");
    fclose(file);

    playerTurn(&playerScore);
    if (playerScore > 21) {
        printf("�A�����ƶW�L21�I�A�C�������C\n");
        writeToFile("game_log.txt", "�C�������G���a���ƶW�L21�I");  
        writeToFile("game_result.txt", "�A��F�I");  
        system("pause");
        return 0;
    }

    dealerTurn(&dealerScore);

    printf("�A�����ơG%d�I\n", playerScore);
    printf("���a�����ơG%d�I\n", dealerScore);

    const char* result;
    if (playerScore > maxScore || (dealerScore <= maxScore && dealerScore >= playerScore)) {
        result = "�A��F�I";
        writeToFile("game_log.txt", "�C�������G�A��F"); 
    }
    else if (playerScore == dealerScore) {
        result = "����I";
        writeToFile("game_log.txt", "�C�������G����");  
    }
    else {
        result = "���ߧAĹ�F�I";
        writeToFile("game_log.txt", "�C�������G�AĹ�F");  
    }

    printf("%s\n", result);
    writeToFile("game_result.txt", result);  
    printf("�C�������I\n");
    system("pause");
    return 0;
}