#include "fieldfilemanager.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QRegExp>
#include "hedge.h"

FieldFileManager::FieldFileManager()
{

}

FieldFileManager::~FieldFileManager()
{

}

Field FieldFileManager::loadField(const QString &fileName)
{
    //field size
    QRegExp regExpSize("(\\d+)x(\\d+)");
    QRegExp regExpRectangle("Rectangle: (\\d+) (\\d+), (\\d+) (\\d+)", Qt::CaseInsensitive);
    QRegExp regExpRobot("Robot: (\\d+) (\\d+), (\\d+)", Qt::CaseInsensitive);


    int width = 0;
    int height = 0;
    if (regExpSize.indexIn(fileName) != -1) {
        width = regExpSize.cap(1).toInt();
        height = regExpSize.cap(2).toInt();
    } else {
        return std::move(Field(0, 0));
    }
    Field field(width, height);

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return std::move(field);
    }

    //objects on field
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (regExpRectangle.indexIn(line) != -1) {
            int tlx = regExpRectangle.cap(1).toInt();
            int tly = regExpRectangle.cap(2).toInt();
            int brx = regExpRectangle.cap(3).toInt();
            int bry = regExpRectangle.cap(4).toInt();
            field.appendHedge(Hedge(QRect(QPoint(tlx, tly), QPoint(brx, bry))));
        } else if(regExpRobot.indexIn(line) != -1) {
            int x = regExpRobot.cap(1).toInt();
            int y = regExpRobot.cap(2).toInt();
            int size = regExpRobot.cap(3).toInt();
            field.setRobot(QPoint(x,y), Robot(size));
        }
    }

    return std::move(field);
}

bool FieldFileManager::saveField(const QString &fileName)
{

    return false;
}

Field&& FieldFileManager::generate(QPointF size)
{

    return std::move(Field(0, 0));
}

