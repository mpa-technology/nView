#include "ContextMenu.hpp"

#include <QCoreApplication>

ContextMenu::ContextMenu(QWidget *parent)
    : QMenu{parent}
{

    auto openAction = new QAction(tr("Open... "),this);
    openAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
    connect(openAction,&QAction::triggered,this, &ContextMenu::onOpen);
    addAction(openAction);



}
