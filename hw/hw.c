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

