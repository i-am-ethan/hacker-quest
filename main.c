#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef char String[1024];

void displayTitle();
void displayJobs();
void displayGameClearMessage();
void insertLineBreak(int lineCount);
void displayRitchieDiningMessage();
void setUpUserjob(int job, String userName, int *userHp, int *userFullHp, int *userAttackPoint);

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
  printf("このゲームをはじめますか?\n");
  printf("\n");
  printf("\033[33m0か1か7を入力してください。\033[0m\n");
  printf("\n");
  printf("(0:いいえ or 1:はい or 7:宝箱を開ける)\n");
  printf("\n");
  int gameStartAnswer;
  String OpenTreasurePassword;
  scanf("%d", &gameStartAnswer);
  insertLineBreak(30);
  printf("--------------------------------------------\n");

  // -----------------------------------------------------
  // (3)ゲームをはじめるorはじめないor宝箱を開ける
  // -----------------------------------------------------
  switch (gameStartAnswer) {
  case 0:
    printf("ゲームを終了しました(code:%d)\n", gameStartAnswer);
    exit(1); //終了
  case 7:
    printf("宝箱を開けるためのパスワードを入力してください。\n");
    scanf("%s", OpenTreasurePassword);

    if(strcmp(OpenTreasurePassword, "web") == 0) {
      insertLineBreak(30);
      displayGameClearMessage();
      exit(1);
    }else{
      printf("パスワードが違います。ゲームを終了します。");
      exit(1);
    }
  }

  // -----------------------------------------------------
  // (4)主人公の名前を8文字以内で入力してください。
  // -----------------------------------------------------
  String userName;  
  printf("\n");
  printf("主人公の名前を\033[33m8文字以内\033[0mで入力してください。\n");
  printf("\n");
  scanf("%8s", userName); // 8文字で切っちゃう。
  if(strcmp(userName, "test") == 0) {
    printf("testユーザーのため処理を中止します。");
    exit(1);
  }
  insertLineBreak(30);
  printf("こんにちは\033[35m%s\033[0m。かっこいい名前ですね。\n", userName);
  printf("--------------------------------------------\n");
  // -----------------------------------------------------
  // (5)職業を選んでください。
  // -----------------------------------------------------
  int job;
  printf("\n");
  printf("\033[35m%s\033[0mの職業を\033[33m1~4の中から\033[0m選択してください。\n", userName);
  printf("\n");
  displayJobs();
  printf("\n");
  scanf("%d", &job); // 職業選択
  insertLineBreak(30);
  int userHp;
  int userFullHp;
  int userAttackPoint;
  setUpUserjob(job, userName, &userHp, &userFullHp, &userAttackPoint);

  // -----------------------------------------------------
  // (6)クエストに挑戦する準備はできましたか？
  // -----------------------------------------------------
  int questStartAnswer;
  printf("クエストに挑戦する準備はできましたか？");
  printf("\n");
  printf("(0:いいえ or 1:はい)\n");
  printf("\n");
  scanf("%d", &questStartAnswer);
  printf("\n");
  if (!questStartAnswer) {
    printf("ゲーム終了:code(%d)\n", questStartAnswer);
    exit(1);
  }
  printf("--------------------------------------------\n");
  insertLineBreak(24);
  // -----------------------------------------------------
  // (7)バトル開始〜〜〜〜〜
  // -----------------------------------------------------

  // -----------------------------------------------------
  // (8)野生のリッチーが現れた:Dennis Ritchie: HP:10 攻撃力:10
  // -----------------------------------------------------
  int RitchieHp = 10;
  int RitchieFullHp = 10;
  int RitchieAttackPoint = 10;
  printf("--------------------------------------------\n");
  printf("\033[45m野生のリッチーが現れた...!!!\033[0m\n");
  printf("\n");
  printf("デニス・リッチー:\n");
  printf("C言語の開発者であり、Unixオペレーティングシステムの共同開発者。\n");
  printf("\n");
  printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
  printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
  printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
  printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
  printf("\n");
  int isBattleStart;
  printf("バトルをはじめる\n");
  printf("(0:いいえ or 1:はい)\n");
  scanf("%d", &isBattleStart);
  if(!isBattleStart){
    printf("ゲームを終了します。code(%d)", isBattleStart);
  }
  insertLineBreak(20);
  // -----------------------------------------------------
  // (8-1)先攻と後攻を決める処理
  // -----------------------------------------------------
  printf("\n");
  printf("\n");
  int userAttackType;
  int isUserFirstAttachForFirstStage = rand() % 2; // ユーザーが先攻か(0か1)
  // -----------------------------------------------------
  // (8-2)バトルの処理
  // -----------------------------------------------------
  switch (isUserFirstAttachForFirstStage) {
    // 先攻の場合
    case 0:
      printf("--------------------------------------------\n");
      printf("\033[35m%s\033[0mが先攻になった...!!!\n", userName);
      printf("\n");
      printf("\n");
      printf("攻撃を選んでください。\n");
      printf("\n");
      switch (job) {
        case 1:
          printf("0:攻撃, 1:未修得\n");
          printf("\033[33m0を入力してください。\033[0m\n");
          scanf("%d", &userAttackType);
          switch (userAttackType) {
            case 0:
              insertLineBreak(24);
              printf("--------------------------------------------\n");
              printf("\033[35m%s\033[0mは攻撃をした...!!!\n", userName);
              printf("リッチーは%dのダメージを受けた...!!!\n", userAttackPoint);
              RitchieHp -= userAttackPoint;
              if (RitchieHp < 0) {
                RitchieHp = 0;
              }
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
              printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              displayRitchieDiningMessage();
              break;
            default:
              printf("ゲームを終了します。code(%d)", userAttackType);
              exit(1);
          }
        case 2:
          printf("0:攻撃, 1:未修得\n");
          printf("\033[33m0を入力してください。\033[0m\n");
          scanf("%d", &userAttackType);
          switch (userAttackType) {
            case 0:
              insertLineBreak(24);
              printf("--------------------------------------------\n");
              printf("\033[35m%s\033[0mは攻撃をした...!!!\n", userName);
              printf("リッチーは%dのダメージを受けた...!!!\n", userAttackPoint);
              RitchieHp -= userAttackPoint;
              if (RitchieHp < 0) {
                RitchieHp = 0;
              }
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
              printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              displayRitchieDiningMessage();
              break;
            default:
              printf("ゲームを終了します。code(%d)", userAttackType);
              exit(1);
          }
        case 3:
          printf("0:攻撃, 1:未修得\n");
          printf("\033[33m0を入力してください。\033[0m\n");
          scanf("%d", &userAttackType);
          switch (userAttackType) {
            case 0:
              insertLineBreak(24);
              printf("--------------------------------------------\n");
              printf("\033[35m%s\033[0mは攻撃をした...!!!\n", userName);
              printf("リッチーは%dのダメージを受けた...!!!\n", userAttackPoint);
              RitchieHp -= userAttackPoint;
              if (RitchieHp < 0) {
                RitchieHp = 0;
              }
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
              printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              displayRitchieDiningMessage();
              break;
            default:
              printf("ゲームを終了します。code(%d)", userAttackType);
              exit(1);
          }
        case 4:
          printf("0:攻撃, 1:未修得\n");
          printf("\033[33m0を入力してください。\033[0m\n");
          scanf("%d", &userAttackType);
          switch (userAttackType) {
            case 0:
              insertLineBreak(24);
              printf("--------------------------------------------\n");
              printf("\033[35m%s\033[0mは攻撃をした...!!!\n", userName);
              printf("リッチーは%dのダメージを受けた...!!!\n", userAttackPoint);
              RitchieHp -= userAttackPoint;
              if (RitchieHp < 0) {
                RitchieHp = 0;
              }
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
              printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              displayRitchieDiningMessage();
              break;
            default:
              printf("ゲームを終了します。code(%d)", userAttackType);
              exit(1);
          }
      }
      break;
    // 後攻の場合
    case 1:
      printf("--------------------------------------------\n");
      printf("\033[35m%s\033[0mは後攻になった...!!!\n", userName);
      printf("\n");
      printf("\n");
      printf("リッチーは\033[91m攻撃\033[0mをしてきた...!!!\n");
      printf("\033[35m%s\033[0mは\033[91m%d\033[0mのダメージを受けた...!!!\n", userName, RitchieAttackPoint);
      userHp -= RitchieAttackPoint;
      printf("\n");
      printf("\n");
      printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
      printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
      printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
      printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
      printf("\n");
      printf("攻撃を選んでください。\n");
      printf("\n");
      switch (job) {
        // 職業の種類
        case 1:
          printf("0:攻撃, 1:未修得\n");
          printf("\033[33m0を入力してください。\033[0m\n");
          scanf("%d", &userAttackType);
          switch (userAttackType) {
            case 0:
              insertLineBreak(20);
              printf("--------------------------------------------\n");
              printf("\033[35m%s\033[0mは攻撃をした...!!!\n", userName);
              printf("リッチーは%dのダメージを受けた...!!!\n", userAttackPoint);
              RitchieHp -= userAttackPoint;
              if (RitchieHp < 0) {
                RitchieHp = 0;
              }
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
              printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              displayRitchieDiningMessage();
              break;
            default:
              printf("ゲームを終了します。code(%d)", userAttackType);
              exit(1);
          }
        case 2:
          printf("0:攻撃, 1:未修得\n");
          printf("\033[33m0を入力してください。\033[0m\n");
          scanf("%d", &userAttackType);
          switch (userAttackType) {
            case 0:
              insertLineBreak(20);
              printf("--------------------------------------------\n");
              printf("\033[35m%s\033[0mは攻撃をした...!!!\n", userName);
              printf("リッチーは%dのダメージを受けた...!!!\n", userAttackPoint);
              RitchieHp -= userAttackPoint;
              if (RitchieHp < 0) {
                RitchieHp = 0;
              }
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
              printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              displayRitchieDiningMessage();
              break;
            default:
              printf("ゲームを終了します。code(%d)", userAttackType);
              exit(1);
          }
        case 3:
          printf("0:攻撃, 1:未修得\n");
          printf("\033[33m0を入力してください。\033[0m\n");
          scanf("%d", &userAttackType);
          switch (userAttackType) {
            case 0:
              insertLineBreak(20);
              printf("--------------------------------------------\n");
              printf("\033[35m%s\033[0mは攻撃をした...!!!\n", userName);
              printf("リッチーは%dのダメージを受けた...!!!\n", userAttackPoint);
              RitchieHp -= userAttackPoint;
              if (RitchieHp < 0) {
                RitchieHp = 0;
              }
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
              printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              displayRitchieDiningMessage();
              break;
            default:
              printf("ゲームを終了します。code(%d)", userAttackType);
              exit(1);
          }
        case 4:
          printf("0:攻撃, 1:未修得\n");
          printf("\033[33m0を入力してください。\033[0m\n");
          scanf("%d", &userAttackType);
          switch (userAttackType) {
            case 0:
              insertLineBreak(20);
              printf("--------------------------------------------\n");
              printf("\033[35m%s\033[0mは攻撃をした...!!!\n", userName);
              printf("リッチーは%dのダメージを受けた...!!!\n", userAttackPoint);
              RitchieHp -= userAttackPoint;
              if (RitchieHp < 0) {
                RitchieHp = 0;
              }
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              printf("リッチーの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", RitchieHp, RitchieFullHp, RitchieAttackPoint);
              printf("\033[35m%s\033[0mの\033[44mHP: %d/%d\033[0m, \033[41m攻撃力: %d\033[0m\n", userName, userHp, userFullHp, userAttackPoint);
              printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
              displayRitchieDiningMessage();
              break;
            default:
              printf("ゲームを終了します。code(%d)", userAttackType);
              exit(1);
          }
      }
      break;
  }
  // -----------------------------------------------------
  // (9)野生のレイモンドが現れた:Eric S. Raymond: HP:10 攻撃力:10
  // -----------------------------------------------------

  // -----------------------------------------------------
  // (10)野生のグレアムが現れた:Paul Graham: HP:400 攻撃力:200
  // -----------------------------------------------------


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
  // printf("---------------------------------------------------------\n");
  // printf("--------------------- \033[31mHacker Quest\033[0m ----------------------\n");
  // printf("-------------------- \033[31mハッカークエスト\033[0m -------------------\n");
  printf("---------------------------------------------------------\n");
  printf("\033[34mHacker Quest is highly difficult,\nand your best chance of completing\nit is by improving your hacking skills.\033[0m\n");
  printf("---------------------------------------------------------\n");
  printf("\n");
};

void displayJobs() {
  printf("1:\033[91m勇者\033[0m\n");
  printf("たまに一撃必殺の攻撃力を得る。\n");
  printf("2:\033[94m魔法使い\033[0m\n");
  printf("たまに一撃必殺の魔法を唱える。\n");
  printf("3:\033[96mニート\033[0m\n");
  printf("基本弱い。たまにとんでもなくやる気が出る。\n");
  printf("4:\033[92mエンジニア\033[0m\n");
  printf("勉強が好き、ハッキングのヒントを得たいと思っている。\n");
};

void displayGameClearMessage() {
  printf("\033[43mおめでとうございます!!!\033[0m\n\n");
  printf("\033[43mあなたは既にハッカーかハッカーになる素質があります!!!\033[0m\n\n");
  printf("\033[43mこれでこのゲームを終わります!!!\033[0m\n\n");
  printf("\033[43mチャレンジありがとうございました!!!\033[0m\n\n");
  printf("\033[43m---- Hacker Quest\033[0m\n\n");
}

void insertLineBreak(int lineCount) {
  for (int i = 0; i <= lineCount; i++){
    printf("\n");
  }
}

void displayRitchieDiningMessage() {
  printf("リッチーのHPは0になった...!!!\n");
  printf("リッチーはメッセージを残して息絶えた...\n");
  printf("\n");
  printf("\033[42m「The only way to learn a new programming language is by writing programs in it.」\033[0m\n"); 
  printf("\033[42m「新しいプログラミング言語を学ぶ唯一の方法は、それでプログラムを書くことだ。」\033[0m\n"); 
}

void setUpUserjob(int job, String userName, int *userHp, int *userFullHp, int *userAttackPoint) {
  switch (job) {
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