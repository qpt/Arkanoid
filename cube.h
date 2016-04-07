#ifndef CUBE_H
#define CUBE_H

#include <QRect>

enum Cubes { Red, Blue, Green, Yellow, Unbreakable };

class AbstractCube {
public:
    virtual ~AbstractCube(){}
    static AbstractCube *makeCube();
    virtual void draw(QRect& coord);

private:
    bool breakable;
    int color;
};

class RedCube: public AbstractCube {
    RedCube(){}
    ~RedCube(){}
};

class GreenCube: public AbstractCube {
    GreenCube(){}
    ~GreenCube(){}
};

class BlueCube: public AbstractCube {
    BlueCube(){}
    ~BlueCube(){}
};

class YellowCube: public AbstractCube {
    YellowCube(){}
    ~YellowCube(){}
};

class UnbreakableCube: public AbstractCube {
    UnbreakableCube(){}
    ~UnbreakableCube(){}
};

class CubeFactory
{
public:
    CubeFactory();
};

#endif // CUBE_H
