#ifndef GAMEMODEL_H
#define GAMEMODEL_H

// ---- 五子棋游戏模型类 ---- //
#include <vector>
#include <QDebug>
// 游戏类型，双人还是AI（目前固定让AI下黑子）
enum GameType
{
    PERSON,
    BOT,
    PVPOL
};

// 游戏状态
enum GameStatus
{
    PLAYING,
    WIN,
    DEAD
};

// 棋盘尺寸
const int kBoardSizeNum = 14;
const int kBoardMargin = 50; // 棋盘边缘空隙
const int kBarWidth = 200;
const int kBlackRadius = 20; // 棋子半径
const int kWhiteRadius = 30;
const int kMarkSize = 6; // 落子标记边长
const int kBoardMarkRadius = 4;
const int kBlockSize = 40; // 格子的大小
const int kPosDelta = 20; // 鼠标点击的模糊距离上限

const int kAIDelay = 700; // AI下棋的思考时间

class GameModel
{
public:
    GameModel();
    ~GameModel(){};
public:
    // 存储当前游戏棋盘和棋子的情况,空白为0，白子1，黑子-1
    std::vector<std::vector<int>> gameMapVec;
    // 存储各个点位的评分情况，作为AI下棋依据
    std::vector<std::vector<int>> scoreMapVec;
    bool playerFlag; // 标示下棋方
    GameType gameType; // 游戏模式
    GameStatus gameStatus; // 游戏状态

    void startGame(GameType type); // 开始游戏
    void calculateScore(); // 计算评分
    void actionByPerson(int row, int col); // 人执行下棋
    void calculateByAI(int &clickRow, int &clickCol);
    void actionByAI(int &clickRow, int &clickCol); // 机器执行下棋
    void updateGameMap(int row, int col); // 每次落子后更新游戏棋盘
    bool isWin(int row, int col); // 判断游戏是否胜利
    bool isDeadGame(); // 判断是否和棋


    bool cur;

};

#endif // GAMEMODEL_H
