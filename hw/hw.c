#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "area.h"


/*int drawCard();
void playerTurn(int* score);
void dealerTurn(int* score);*/

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
    
    playerTurn(&playerScore);
    if (playerScore > 21) {
        printf("�A�����ƶW�L21�I�A�C�������C\n");
        system("pause"); return(0);
    }
   
    dealerTurn(&dealerScore);

   
    //printf("�C�������I\n");
    printf("�A�����ơG%d�I\n", playerScore);
    printf("���a�����ơG%d�I\n", dealerScore);

    if (playerScore > maxScore || (dealerScore <= maxScore && dealerScore >= playerScore)) {
        printf("�A��F�I\n");
    }
    else {
        printf("���ߧAĹ�F�I\n");
    }
    printf("�C�������I\n");
    return 0;
}

