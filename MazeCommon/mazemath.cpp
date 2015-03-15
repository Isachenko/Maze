#include "mazemath.h"

MazeMath::MazeMath()
{

}

MazeMath::~MazeMath()
{

}

int MazeMath::cohenSutherland(const MazeMath::rect *r, MazeMath::point *a, MazeMath::point *b)
{
    int code_a, code_b, code; /* код кінців відрізка */
    struct point *c; /* одна з точок */

    code_a = vcode(r, a);
    code_b = vcode(r, b);

    /* поки одна з точок відрізка поза прямокутником */
    while (code_a | code_b) {
        /* якщо обидві точки з одного боку прямокутника, то відрізок не перетинає прямокутник */
        if (code_a & code_b)
            return -1;

        /* обираємо точку c з ненульовим кодом */
        if (code_a) {
            code = code_a;
            c = a;
        } else {
            code = code_b;
            c = b;
        }

        /* якщо c лівіше r, тоді переміщуємо c на пряму x = r->x_min
           якщо c правіше r, тоді переміщуємо c на пряму x = r->x_max */
        if (code & LEFT) {
            c->y += (a->y - b->y) * (r->x_min - c->x) / (a->x - b->x);
            c->x = r->x_min;
        } else if (code & RIGHT) {
            c->y += (a->y - b->y) * (r->x_max - c->x) / (a->x - b->x);
            c->x = r->x_max;
        }/* якщо c нижче r, тоді переміщуємо c на пряму y = r->y_min
            якщо c вище r, то переміщуємо c на пряму y = r->y_max */
        else if (code & BOT) {
            c->x += (a->x - b->x) * (r->y_min - c->y) / (a->y - b->y);
            c->y = r->y_min;
        } else if (code & TOP) {
            c->x += (a->x - b->x) * (r->y_max - c->y) / (a->y - b->y);
            c->y = r->y_max;
        }

        /* оновлюємо код */
        if (code == code_a) {
            a = c;
            code_a = vcode(r,a);
        } else {
            b = c;
            code_b = vcode(r,b);
        }
    }

    /* коди рівні 0, отже обидві точки в прямокутнику */
    return 0;
}

