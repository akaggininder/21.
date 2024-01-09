#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int drawCard();
void direction();
void playerTurn(int* score);
void dealerTurn(int* score);

int drawCard() {
    return rand() % 11 + 1;
}

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

void dealerTurn(int* score) {
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

int main() {

    srand((unsigned int)time(NULL));


    int playerScore = 0;
    int dealerScore = 0;
    const int maxScore = 21;
    printf("規則");
    printf("2~10的牌值以點數計算。 J、Q、K的牌值以10點計算。 Ace的牌值可記為11點或者1點。 點數合計超過21點時，Ace自動以1點計算。");
    printf("每位玩家手牌最多可補牌至5張。 點數超過21點爆牌時停止補牌並輸掉該次比賽。\n");
    printf("莊家和玩家各發兩張牌，莊家一開始只會露一張，玩家則露兩張，玩家先選擇是否加牌，玩家停牌後，才換莊家加牌\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    playerTurn(&playerScore);
    if (playerScore > 21) {
        printf("你的分數超過21點，遊戲結束。\n");
        system("pause"); return(0);
    }

    dealerTurn(&dealerScore);


    //printf("遊戲結束！\n");
    printf("你的分數：%d點\n", playerScore);
    printf("莊家的分數：%d點\n", dealerScore);

    if (playerScore > maxScore || (dealerScore <= maxScore && dealerScore >= playerScore)) {
        printf("你輸了！\n");
    }
    else {
        printf("恭喜你贏了！\n");
    }
    printf("遊戲結束！\n");
    return 0;
}

