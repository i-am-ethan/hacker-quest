#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef char String[1024];

void displayTitle();
void displayStartGameOptionMessage();
void displayJobs();
void displayGameClearMessage();
void displayUserNameRequestMessage();
void displayUserNameFeedBackMessage(String userName);
void insertLineBreak(int lineCount);
void displayRitchieDiningMessage();
void setUpUserJob(int userJob, String userName, int *userHp, int *userFullHp, int *userAttackPoint);
void exitAndDisplayErrorMessage(String errorMessage);
void displayBattleStatus(String userName, int userHp, int userFullHp, int userAttackPoint, String enemyName, int *enemyHp, int enemyFullHp, int enemyAttackPoint);
void displayAttackOption(int stageNumber);
void displayFirstStageOpeningMessage();
void displaySecondStageOpeningMessage();
void displayUserAttackLog(String userName, int userAttackPoint, String firstStageEnemyName);
void displayEnemyAttackLog(String enemyName, String userName, int enemyAttackPoint);
void decreaseHp(int *hp, int damage);
void displayFirstAttackMessage(String userName);
void displaySecondAttackMessage(String userName);
void displayGameOverMessage(int stageNumber, String userName);
void userAttack(
  String userName,
  int userAttackPoint,
  String enemyName,
  int userHp,
  int userFullHp,
  int *enemyHp,
  int enemyFullHp,
  int enemyAttackPoint,
  int userAttackType,
  int userJob,
  int stageNumber
);

int stageNumber;
int isBattleStart;
int userAttackType;

int main(void){
  // -----------------------------------------------------
  // ランダム生成のための準備
  // -----------------------------------------------------
  srand((unsigned)time(NULL));

  // -----------------------------------------------------
  // (1)タイトルとサブタイトルを表示する
  // -----------------------------------------------------
  displayTitle();
  // -----------------------------------------------------
  // (2)ゲームをはじめますか？
  // -----------------------------------------------------
  displayStartGameOptionMessage();

  int gameStartAnswer;
  String OpenTreasurePassword;
  String secretPassword = "web";
  scanf("%d", &gameStartAnswer);
  insertLineBreak(30);
  printf("--------------------------------------------\n");

  // -----------------------------------------------------
  // (3)ゲームをはじめるorはじめないor宝箱を開ける
  // -----------------------------------------------------
  switch (gameStartAnswer) {
  case 0:
    exitAndDisplayErrorMessage("準備を整えるのも大切なことです。");
  case 1:
    break;
  case 7:
    printf("宝箱を開けるためのパスワードを入力してください。\n");
    scanf("%s", OpenTreasurePassword);
    if(strcmp(OpenTreasurePassword, secretPassword) == 0) {
      displayGameClearMessage();
    }else{
      exitAndDisplayErrorMessage("パスワードが違います。");
    }
  }

  // -----------------------------------------------------
  // (4)主人公の名前を8文字以内で入力してください。
  // -----------------------------------------------------
  String userName;  
  displayUserNameRequestMessage();
  scanf("%8s", userName); // 8文字で切っちゃう。
  if(strcmp(userName, "test") == 0) {
    exitAndDisplayErrorMessage("testユーザーが選択されました。");
  }
  displayUserNameFeedBackMessage(userName);
  // -----------------------------------------------------
  // (5)職業を選んでください。
  // -----------------------------------------------------
  int userJob;
  int userHp;
  int userFullHp;
  int userAttackPoint;
  insertLineBreak(1);
  printf("\033[35m%s\033[0mの職業を\033[33m1~4の中から\033[0m選択してください。\n", userName);
  displayJobs();
  scanf("%d", &userJob); // 職業選択
  setUpUserJob(userJob, userName, &userHp, &userFullHp, &userAttackPoint);

  // -----------------------------------------------------
  // (6)クエストに挑戦する準備はできましたか？
  // -----------------------------------------------------
  int questStartAnswer;
  printf("クエストに挑戦する準備はできましたか？");
  insertLineBreak(1);
  printf("(0:いいえ or 1:はい)\n");
  insertLineBreak(1);
  scanf("%d", &questStartAnswer);
  insertLineBreak(1);
  if (!questStartAnswer) {
    exitAndDisplayErrorMessage("クエストに挑戦する準備ができていないようです。");
  }
  // -----------------------------------------------------
  // (7)バトル開始〜〜〜〜〜
  // -----------------------------------------------------

  // -----------------------------------------------------
  // (8)野生のリッチーが現れた:Dennis Ritchie: HP:10 攻撃力:10
  // -----------------------------------------------------
  String firstStageEnemyName = "リッチー";
  int RitchieHp = 10;
  int RitchieFullHp = 10;
  int RitchieAttackPoint = 10;
  stageNumber = 1;
  
  displayFirstStageOpeningMessage();
  displayBattleStatus(userName, userHp, userFullHp, userAttackPoint, firstStageEnemyName, &RitchieHp, RitchieFullHp, RitchieAttackPoint);
  printf("ステージ1/3(リッチーとたたかう)\n");
  printf("(0:いいえ or 1:はい)\n");
  scanf("%d", &isBattleStart);
  if(!isBattleStart){
    exitAndDisplayErrorMessage("バトルに挑戦する準備ができていないようです。");
  }
  insertLineBreak(20);
  // -----------------------------------------------------
  // (8-1)先攻と後攻を決める処理
  // -----------------------------------------------------
  // int isUserFirstAttackForFirstStage = 0; // ユーザーが先攻か後攻かをランダム関数で決める(0か1)
  int isUserFirstAttackForFirstStage = rand() % 2; // ユーザーが先攻か後攻かをランダム関数で決める(0か1)
  // -----------------------------------------------------
  // (8-2)バトルの処理
  // -----------------------------------------------------
  switch (isUserFirstAttackForFirstStage) {
  // 先攻の場合-----------------------------------------------
  case 0:
    displayFirstAttackMessage(userName);
    displayAttackOption(stageNumber);      
    scanf("%d", &userAttackType);
    userAttack(userName, userAttackPoint, firstStageEnemyName, userHp, userFullHp, &RitchieHp, RitchieFullHp, RitchieAttackPoint, userAttackType, userJob, stageNumber);
    break;
  // 後攻の場合-----------------------------------------------
  case 1:
    displaySecondAttackMessage(userName);
    displayEnemyAttackLog(firstStageEnemyName, userName, RitchieAttackPoint);
    userHp -= RitchieAttackPoint;
    displayBattleStatus(userName, userHp, userFullHp, userAttackPoint, firstStageEnemyName, &RitchieHp, RitchieFullHp, RitchieAttackPoint);
    printf("攻撃を選んでください。\n");
    displayAttackOption(stageNumber);
    scanf("%d", &userAttackType);
    userAttack(userName, userAttackPoint, firstStageEnemyName, userHp, userFullHp, &RitchieHp, RitchieFullHp, RitchieAttackPoint, userAttackType, userJob, stageNumber);
    break;
  }
  // -----------------------------------------------------
  // (9)野生のレイモンドが現れた:Eric S. Raymond: HP:10 攻撃力:10
  // -----------------------------------------------------
  printf("--------------------------------------------\n");
  printf("ステージ2/3をはじめる\n");
  printf("(0:いいえ or 1:はい)\n");
  scanf("%d", &isBattleStart);
  if(!isBattleStart){
    exitAndDisplayErrorMessage("バトルに挑戦する準備ができていないようです。");
  }

  String secondStageEnemyName = "レイモンド";
  int RaymondHp = 12;
  int RaymondFullHp = 12;
  int RaymondAttackPoint = 12;
  stageNumber = 2;

  displaySecondStageOpeningMessage();
  displayBattleStatus(userName, userHp, userFullHp, userAttackPoint, secondStageEnemyName, &RaymondHp, RaymondFullHp, RaymondAttackPoint);

  printf("--------------------------------------------\n");
  printf("ステージ2/3(レイモンドとたたかう)\n");
  printf("(0:いいえ or 1:はい)\n");
  scanf("%d", &isBattleStart);
  if(!isBattleStart){
    exitAndDisplayErrorMessage("バトルに挑戦する準備ができていないようです。");
  }
  insertLineBreak(20);
  // -----------------------------------------------------
  // (9-1)先攻と後攻を決める処理
  // -----------------------------------------------------
  int isUserFirstAttackForSecondStage = rand() % 2; // ユーザーが先攻か後攻かをランダム関数で決める(0か1)
  // -----------------------------------------------------
  // (9-2)バトルの処理
  // -----------------------------------------------------
  switch (isUserFirstAttackForSecondStage) {
  // 先攻の場合-----------------------------------------------
  case 0:
    displayFirstAttackMessage(userName);
    displayAttackOption(stageNumber);      
    scanf("%d", &userAttackType);
    userAttack(userName, userAttackPoint, secondStageEnemyName, userHp, userFullHp, &RitchieHp, RitchieFullHp, RitchieAttackPoint, userAttackType, userJob, stageNumber);
    break;
  // 後攻の場合-----------------------------------------------
  case 1:
    displaySecondAttackMessage(userName);
    displayEnemyAttackLog(firstStageEnemyName, userName, RitchieAttackPoint);
    userHp -= RitchieAttackPoint;
    displayBattleStatus(userName, userHp, userFullHp, userAttackPoint, secondStageEnemyName, &RaymondHp, RaymondFullHp, RaymondAttackPoint);
    if(userHp <= 0) {
      // ゲームオーバーになる。
      displayGameOverMessage(stageNumber, userName);
    }
    printf("攻撃を選んでください。\n");
    displayAttackOption(stageNumber);
    scanf("%d", &userAttackType);
    userAttack(userName, userAttackPoint, secondStageEnemyName, userHp, userFullHp, &RitchieHp, RitchieFullHp, RitchieAttackPoint, userAttackType, userJob, stageNumber);
    break;
  }

  // -----------------------------------------------------
  // (10)野生のグレアムが現れた:Paul Graham: HP:400 攻撃力:200
  // -----------------------------------------------------
  printf("--------------------------------------------\n");
  printf("ステージ3/3をはじめる\n");
  printf("(0:いいえ or 1:はい)\n");
  scanf("%d", &isBattleStart);
  if(!isBattleStart){
    exitAndDisplayErrorMessage("バトルに挑戦する準備ができていないようです。");
  }



  return 0;
}



void displayTitle() {
  printf("---------------------------------------------------------\n");
  printf("\033[92m.##.....##....###.....######..##....##.########.########.\033[0m\n");
  printf("\033[92m.##.....##...##.##...##....##.##...##..##.......##.....##\033[0m\n");
  printf("\033[92m.##.....##..##...##..##.......##..##...##.......##.....##\033[0m\n");
  printf("\033[92m.#########.##.....##.##.......#####....######...########.\033[0m\n");
  printf("\033[92m.##.....##.#########.##.......##..##...##.......##...##..\033[0m\n");
  printf("\033[92m.##.....##.##.....##.##....##.##...##..##.......##....##.\033[0m\n");
  printf("\033[92m.##.....##.##.....##..######..##....##.########.##.....##\033[0m\n");
  printf("\033[92m.........................................................\033[0m\n");
  printf("\033[92m..#######..##.....##.########..######..########..........\033[0m\n");
  printf("\033[92m.##.....##.##.....##.##.......##....##....##.............\033[0m\n");
  printf("\033[92m.##.....##.##.....##.##.......##..........##.............\033[0m\n");
  printf("\033[92m.##.....##.##.....##.######....######.....##.............\033[0m\n");
  printf("\033[92m.##..##.##.##.....##.##.............##....##.............\033[0m\n");
  printf("\033[92m.##....##..##.....##.##.......##....##....##.............\033[0m\n");
  printf("\033[92m..#####.##..#######..########..######.....##.............\033[0m\n");
  printf("---------------------------------------------------------\n");
  printf("\033[34mHacker Quest is highly difficult,\nand your best chance of completing\nit is by improving your hacking skills.\033[0m\n");
  printf("---------------------------------------------------------\n");
  printf("\n");
};

void displayStartGameOptionMessage() {
  printf("このゲームをはじめますか?\n");
  insertLineBreak(1);
  printf("\033[33m0か1か7を入力してください。\033[0m\n");
  insertLineBreak(1);
  printf("(0:いいえ or 1:はい or 7:宝箱を開ける)\n");
  insertLineBreak(1);
}

void displayJobs() {
  insertLineBreak(1);
  printf("1:\033[91m勇者\033[0m\n");
  printf("たまに一撃必殺を発動する。\n");
  printf("2:\033[94m魔法使い\033[0m\n");
  printf("たまに一撃必殺の魔法を唱える。\n");
  printf("3:\033[96mニート\033[0m\n");
  printf("基本弱い。たまにとんでもなくやる気が出る。\n");
  printf("4:\033[92mエンジニア\033[0m\n");
  printf("勉強が好き、ハッキングのヒントを得たいと思っている。\n");
  insertLineBreak(1);
};

void displayGameClearMessage() {
  insertLineBreak(30);
  printf("\033[43mおめでとうございます!!!\033[0m\n\n");
  printf("\033[43mあなたは既にハッカーかハッカーになる素質があります!!!\033[0m\n\n");
  printf("\033[43mこれでこのゲームを終わります!!!\033[0m\n\n");
  printf("\033[43mチャレンジありがとうございました!!!\033[0m\n\n");
  printf("\033[43m---- Hacker Quest\033[0m\n\n");
  exit(1);
}

void insertLineBreak(int lineCount) {
  for (int i = 0; i <= lineCount; i++){
    printf("\n");
  }
}

void displayUserNameRequestMessage() {
  insertLineBreak(1);
  printf("主人公の名前を\033[33m8文字以内\033[0mで入力してください。\n");
  insertLineBreak(1);
}

void displayUserNameFeedBackMessage(String userName) {
  insertLineBreak(30);
  printf("こんにちは\033[35m%s\033[0m。かっこいい名前ですね。\n", userName);
  printf("--------------------------------------------\n");
}

void displayRitchieDiningMessage() {
  printf("リッチーのHPは0になった...!!!\n");
  printf("リッチーはメッセージを残して立ち去った...\n");
  printf("\n");
  printf("\033[42m「The only way to learn a new programming language is by writing programs in it.」\033[0m\n"); 
  printf("\033[42m「新しいプログラミング言語を学ぶ唯一の方法は、それでプログラムを書くことだ。」\033[0m\n"); 
}
void displayRaymondDiningMessage() {
  printf("レイモンドのHPは0になった...!!!\n");
  printf("レイモンドはメッセージを残して立ち去った...\n");
  printf("\n");
  printf("\033[42m「Good programmers know what to write. Great ones know what to rewrite and reuse.」\033[0m\n"); 
  printf("\033[42m「良いプログラマーは何を書くべきかを知っている。偉大なプログラマーは、何を書き直し、再利用するべきかを知っている。」\033[0m\n"); 
}

void setUpUserJob(int userJob, String userName, int *userHp, int *userFullHp, int *userAttackPoint) {
  insertLineBreak(30);
  switch (userJob) {
  case 1:
    printf("\033[35m%s\033[0mは\033[91m勇者\033[0mを選んだ。\n", userName);
    printf("不思議な力によりHPと攻撃力が付与された。\n");
    printf("\033[44mHP: 200\033[0m, \033[41m攻撃力: 80\033[0m\n");
    *userHp = 200;
    *userFullHp = 200;
    *userAttackPoint = 80;
    break;
  case 2:
    printf("\033[35m%s\033[0mは\033[94m魔法使い\033[0mを選んだ。\n", userName);
    printf("不思議な力によりHPと攻撃力が付与された。\n");
    printf("\033[44mHP: 200\033[0m, \033[41m攻撃力: 80\033[0m\n");
    *userHp = 200;
    *userFullHp = 200;
    *userAttackPoint = 80;
    break;
  case 3:
    printf("\033[35m%s\033[0mは\033[96mニート\033[0mを選んだ。\n", userName);
    printf("不思議な力によりHPと攻撃力が付与された。\n");
    printf("\033[44mHP: 20\033[0m, \033[41m攻撃力: 20\033[0m\n");
    *userHp = 20;
    *userFullHp = 20;
    *userAttackPoint = 20;
    break;
  case 4:
    printf("\033[35m%s\033[0mは\033[92mエンジニア\033[0mを選んだ。\n", userName);
    printf("不思議な力によりHPと攻撃力が付与された。\n");
    printf("\033[44mHP: 40\033[0m, \033[41m攻撃力: 40\033[0m\n");
    *userHp = 40;
    *userFullHp = 40;
    *userAttackPoint = 40;
    break;
  default:
    printf("無効な数字が入力されました。\nゲームを終了します。");
    exit(1);
  }
  printf("--------------------------------------------\n");
}

void exitAndDisplayErrorMessage(String errorMessage) {
  if(strcmp(errorMessage, "") != 0) {
    printf("%s\n", errorMessage);
  }
  printf("ゲームを終了しました。\n");
  exit(1);
}

void displayBattleStatus(String userName, int userHp, int userFullHp, int userAttackPoint, String enemyName, int *enemyHp, int enemyFullHp, int enemyAttackPoint) {
  insertLineBreak(1);
  printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
  printf("%sの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", enemyName, *enemyHp, enemyFullHp, enemyAttackPoint);
  printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
  printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
  insertLineBreak(1);
}

void displayAttackOption(int stageNumber) {
  switch (stageNumber) {
  case 1:
  case 2:
    printf("0:攻撃, 1:未習得\n");
    printf("\033[33m0を入力してください。\033[0m\n");
    break;
  case 3:
    printf("0:攻撃, 1:必殺技\n");
    printf("\033[33m0か1を入力してください。\033[0m\n");
    break;
  };
};

void displayFirstStageOpeningMessage() {
  insertLineBreak(24);
  printf("--------------------------------------------\n");
  printf("\033[45m野生のリッチーが現れた...!!!\033[0m\n");
  insertLineBreak(1);
  printf("デニス・リッチー:\n");
  printf("C言語の開発者であり、Unixオペレーティングシステムの共同開発者。\n");
}

void displaySecondStageOpeningMessage() {
  insertLineBreak(24);
  printf("--------------------------------------------\n");
  printf("\033[45m野生のレイモンドが現れた...!!!\033[0m\n");
  insertLineBreak(1);
  printf("エリック・レイモンド:\n");
  printf("How To Become A Hackerの著者。\nオープンソース運動を通じて、プログラミングやハッカー文化に深く影響を与えた人物。\n");
}

void displayUserAttackLog(String userName, int userAttackPoint, String firstStageEnemyName) {
  insertLineBreak(24);
  printf("--------------------------------------------\n");
  printf("\033[35m%s\033[0mは攻撃をした...!!!\n", userName);
  printf("%sは%dのダメージを受けた...!!!\n", firstStageEnemyName, userAttackPoint);
}

void displayEnemyAttackLog(String enemyName, String userName, int enemyAttackPoint){
  printf("リッチーは\033[91m攻撃\033[0mをしてきた...!!!\n");
  printf("\033[35m%s\033[0mは\033[91m%d\033[0mのダメージを受けた...!!!\n", userName, enemyAttackPoint);
}


void decreaseHp(int *hp, int damage) {
  *hp -= damage;
  if (*hp < 0) {
    *hp = 0;
  }
}

void displayFirstAttackMessage(String userName) {
  printf("--------------------------------------------\n");
  printf("\033[35m%s\033[0mが先攻になった...!!!\n", userName);
  insertLineBreak(1);
  printf("攻撃を選んでください。\n");
  insertLineBreak(1);
}
void displaySecondAttackMessage(String userName) {
  printf("--------------------------------------------\n");
  printf("\033[35m%s\033[0mは後攻になった...!!!\n", userName);
  insertLineBreak(1);
}

void displayGameOverMessage(int stageNumber, String userName) {
  printf("\033[35m%s\033[0mは静かにその場に倒れた...\n", userName);
  printf("\n");
  printf("===> 記録: Stage %d\n", stageNumber - 1);
  printf("\n");
  printf("\033[93m*********************************************\033[0m\n");
  printf("\033[93m*                                           *\033[0m\n");
  printf("\033[93m*                 GAME OVER                 *\033[0m\n");
  printf("\033[93m*                                           *\033[0m\n");
  printf("\033[93m*********************************************\033[0m\n");
  printf("\033[93m------- Hacker Quest\033[0m\n\n");
  exit(1);
}

void userAttack(
    String userName,
    int userAttackPoint,
    String enemyName,
    int userHp,
    int userFullHp,
    int *enemyHp,
    int enemyFullHp,
    int enemyAttackPoint,
    int userAttackType,
    int userJob,
    int stageNumber
  ) {
  // printf("%d\n", *enemyHp); // enemyHpが指す値
  // printf("%p\n", (void*)&enemyHp); // enemyHp変数のポインターのアドレス
  // printf("%p\n", (void*)enemyHp); // enemyHpの値のポインター
  printf("攻撃の種類:%d\n", userAttackType);
  printf("ユーザーの職業:%d\n", userJob);
  switch (userAttackType) {
  case 0:
    displayUserAttackLog(userName, userAttackPoint, enemyName);
    decreaseHp(enemyHp, userAttackPoint);
    displayBattleStatus(userName, userHp, userFullHp, userAttackPoint, enemyName, enemyHp, enemyFullHp, enemyAttackPoint);
    switch (stageNumber) {
    case 1:
      displayRitchieDiningMessage();
      break;
    case 2:
      displayRaymondDiningMessage();
      break;
    }
    break;
  default:
    exitAndDisplayErrorMessage("存在しない技が選択されました。");
  }
}