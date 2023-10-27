#pragma once

#include <QMainWindow>

#include "ContextMenu.hpp"
#include "Image.hpp"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


void updateViewImage();

    void loadImage(const QString &path);



public slots:
    void customMenuRequested(QPoint pos);

    void onOpen();

protected:
    void resizeEvent(QResizeEvent* event);


private slots:

private:
    Ui::MainWindow *ui;
    Image currentImg;
    ContextMenu *contextMenu;








};
