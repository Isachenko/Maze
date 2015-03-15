#ifndef HEDGE_H
#define HEDGE_H
#include <QRectF>

class Hedge
{
private:
    QRectF _recatangle;
public:
    Hedge();
    Hedge(QRectF recatangle);
    ~Hedge();
    QRectF recatangle() const;
    void setRecatangle(const QRectF &recatangle);
};

#endif // HEDGE_H
