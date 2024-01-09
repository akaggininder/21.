#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playerTurn(int* score) {
    while (1) {
        int card = drawCard();
        printf("�A���F�@�i�P�G%d�I\n", card);

        if (card == 1) {
            char choice;
            printf("�A���FA�A�n�NA����1�I�٬O11�I�H(1/11)�G");
            scanf(" %c", &choice);

            if (choice == '1') {
                *score += 1; // A����1�I
            }
            else if (choice == '11') {
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

        // ?�d��?�O�_�j�_21
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
