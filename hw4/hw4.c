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
    printf("規則");
    printf("2~10的牌值以點數計算。 J、Q、K的牌值以10點計算。 Ace的牌值可記為11點或者1點。 點數合計超過21點時，Ace自動以1點計算。");
    printf("每位玩家手牌最多可補牌至5張。 點數超過21點爆牌時停止補牌並輸掉該次比賽。\n");
    printf("莊家和玩家各發兩張牌，莊家一開始只會露一張，玩家則露兩張，玩家先選擇是否加牌，玩家停牌後，才換莊家加牌\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    FILE* file = fopen("game_log.txt", "w");
    fclose(file);

    playerTurn(&playerScore);
    if (playerScore > 21) {
        printf("你的分數超過21點，遊戲結束。\n");
        writeToFile("game_log.txt", "遊戲結束：玩家分數超過21點");  
        writeToFile("game_result.txt", "你輸了！");  
        system("pause");
        return 0;
    }

    dealerTurn(&dealerScore);

    printf("你的分數：%d點\n", playerScore);
    printf("莊家的分數：%d點\n", dealerScore);

    const char* result;
    if (playerScore > maxScore || (dealerScore <= maxScore && dealerScore >= playerScore)) {
        result = "你輸了！";
        writeToFile("game_log.txt", "遊戲結束：你輸了"); 
    }
    else if (playerScore == dealerScore) {
        result = "平手！";
        writeToFile("game_log.txt", "遊戲結束：平手");  
    }
    else {
        result = "恭喜你贏了！";
        writeToFile("game_log.txt", "遊戲結束：你贏了");  
    }

    printf("%s\n", result);
    writeToFile("game_result.txt", result);  
    printf("遊戲結束！\n");
    system("pause");
    return 0;
}