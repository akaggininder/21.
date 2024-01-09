#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void dealerTurn(int* score) {
    while (1) {
        int card = drawCard();
        printf("莊家抽到了一張牌：%d點\n", card);

        char cardInfo[50];
        sprintf(cardInfo, "莊家抽到了一張牌：%d點", card);
        writeToFile("game_log.txt", cardInfo);

        if (card == 1) {
            int choice;  // 修正此處
            printf("你抽到了A，要將A視為1點還是11點？(1/11)：");
            scanf("%d", &choice);  // 修正此處

            if (choice == 1) {
                *score += 1; // A視為1點
            }
            else if (choice == 11) {
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

        // 檢查分數是否大於21
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