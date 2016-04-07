#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>

class GameImplementer {
public:
    static GameImplementer *instanciate()
    {
        if (!s_instance)
          s_instance = new GameImplementer;
        return s_instance;
    }
private:
    QGraphicsScene *m_scene;
    static GameImplementer *s_instance;
    GameImplementer(){}
};

class Game
{
public:
    Game();
};

#endif // GAME_H
