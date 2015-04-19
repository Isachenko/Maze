#ifndef MAZEMATH_H
#define MAZEMATH_H

#include <QRectF>
#include "mazecommon_global.h"

#define LEFT 1
#define RIGHT 2
#define BOT 4
#define TOP 8

#define vcode(r, p) ((((p)->x < (r)->x_min) ? LEFT : 0)  + (((p) -> x> (r) -> x_max)? RIGHT: 0) + (((p) -> y <(r) -> y_min)? BOT: 0) + (((p) -> y> (r) -> y_max)? TOP: 0))


class MAZECOMMONSHARED_EXPORT MazeMath
{
public:
    MazeMath();
    ~MazeMath();

    struct point {
        double x, y;
    };

    struct rect {
        double x_min, y_min, x_max, y_max;
    };

    static int cohenSutherland(const struct rect *r, struct point *a, struct point *b);
};

#endif // MAZEMATH_H
