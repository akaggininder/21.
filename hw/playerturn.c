#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playerTurn(int* score) {
    while (1) {
        int card = drawCard();
        printf("你抽到了一張牌：%d點\n", card);

        if (card == 1) {
            char choice;
            printf("你抽到了A，要將A視為1點還是11點？(1/11)：");
            scanf(" %c", &choice);

            if (choice == '1') {
                *score += 1; // A視為1點
            }
            else if (choice == '11') {
                *score += 11; // A視為11點
            }
            else {
                printf("無效的選擇，遊戲結束。\n");
                break;
            }
        }
        else {
            *score += card;
        }

        printf("你目前的分數：%d點\n", *score);

        // ?查分?是否大于21
        if (*score > 21) {
            printf("你的分數超過21點。\n");
            break;
        }

        char continueChoice;
        printf("是否繼續抽牌？(y/n)：");
        scanf(" %c", &continueChoice);

        if (continueChoice != 'y') {
            break;
        }
    }
}
