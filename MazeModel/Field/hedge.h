#ifndef HEDGE_H
#define HEDGE_H
#include <QRect>

class Hedge
{
private:
    QRect _recatangle;
public:
    Hedge();
    Hedge(QRect recatangle);
    ~Hedge();
};

#endif // HEDGE_H
