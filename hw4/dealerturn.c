#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void dealerTurn(int* score) {
    while (1) {
        int card = drawCard();
        printf("���a���F�@�i�P�G%d�I\n", card);

        char cardInfo[50];
        sprintf(cardInfo, "���a���F�@�i�P�G%d�I", card);
        writeToFile("game_log.txt", cardInfo);

        if (card == 1) {
            int choice;  // �ץ����B
            printf("�A���FA�A�n�NA����1�I�٬O11�I�H(1/11)�G");
            scanf("%d", &choice);  // �ץ����B

            if (choice == 1) {
                *score += 1; // A����1�I
            }
            else if (choice == 11) {
                *score += 11; // A����11�I
            }
            else {
                printf("�L�Ī���ܡA�C�������C\n");
                break;
            }
        }
        else {
            *score += card;
        }

        printf("�A�ثe�����ơG%d�I\n", *score);

        // �ˬd���ƬO�_�j��21
        if (*score > 21) {
            printf("�A�����ƶW�L21�I�C\n");
            break;
        }

        char continueChoice;
        printf("�O�_�~���P�H(y/n)�G");
        scanf(" %c", &continueChoice);

        if (continueChoice != 'y') {
            break;
        }
    }
}