#include "hedge.h"


QRectF Hedge::recatangle() const
{
    return _recatangle;
}

void Hedge::setRecatangle(const QRectF &recatangle)
{
    _recatangle = recatangle;
}
Hedge::Hedge()
{
    
}

Hedge::Hedge(QRectF recatangle):
    _recatangle(recatangle)
{
    
}

Hedge::~Hedge()
{
    
}

