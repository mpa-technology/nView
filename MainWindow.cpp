#include "MainWindow.hpp"
#include "./ui_MainWindow.h"

#include <QScreen>
#include <QFileDialog>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
            SLOT(customMenuRequested(QPoint)));

    if(qApp->arguments().size() > 1){
        loadImage(qApp->arguments()[1]);
        this->resize(currentImg.size());
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateViewImage(){
    ui->pixWgt->setPixmap(currentImg);
}

void MainWindow::loadImage(const QString &path){
    Image img(path);

    const auto screenSize = qApp->primaryScreen()->size();
    const auto minSize = QSize(
                static_cast<double>(screenSize.width()) * 0.2,
                static_cast<double>(screenSize.height()) * 0.2
                );

    const auto maxSize = QSize(
                static_cast<double>(screenSize.width()) * 0.75,
                static_cast<double>(screenSize.height()) * 0.75
                );

    img.scaled(minSize, maxSize);

    currentImg = img;

    updateViewImage();

}



void MainWindow::customMenuRequested(QPoint pos){
    auto menu = new ContextMenu(this);
    connect(menu,&ContextMenu::onOpen,this,&MainWindow::onOpen);
    menu->popup(this->mapToGlobal(pos));
}




void MainWindow::resizeEvent(QResizeEvent *event){

    QMainWindow::resizeEvent(event);


}




void MainWindow::onOpen(){
    const auto path = QFileDialog::getOpenFileName(this,tr("Open..."),QString(), tr("Support format (*.jpg *.jpeg *.png *.webp);;All files (*.*)"));

    if(path.isEmpty()){
        return;
    }

    auto backup = currentImg;

    loadImage(path);




}




