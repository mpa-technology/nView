#pragma once

#include <QMenu>


class ContextMenu : public QMenu
{
    Q_OBJECT
public:
    explicit ContextMenu(QWidget *parent = nullptr);



public slots:


signals:

void onOpen();

private:

};

