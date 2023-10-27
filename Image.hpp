#pragma once
#include <QPixmap>

class Image
{
public:
    Image();

    Image(const QPixmap &pm);


    Image(const QString &path);

    void loadFromFile(const QString &path);

    void clear();

    operator QPixmap()const;

    QSize size()const;

    void scaled(QSize minSize, QSize maxSize);

    void scaled(double r);

private:
    QPixmap pixmap;

};

