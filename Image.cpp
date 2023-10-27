#include "Image.hpp"

Image::Image()
{

}

Image::Image(const QPixmap &pm)
    : pixmap(pm)
{

}

Image::Image(const QString &path)
    : pixmap(path)
{

}

void Image::loadFromFile(const QString &path){
    pixmap.load(path);
}

void Image::clear(){
    pixmap = QPixmap();
}

Image::operator QPixmap() const{
    return pixmap;
}

QSize Image::size() const{
    return pixmap.size();
}

void Image::scaled(QSize minSize, QSize maxSize){
    const auto ratio = static_cast<double>(pixmap.width())/static_cast<double>(pixmap.height());

    if(pixmap.width() > maxSize.width()){
        int width = maxSize.width();
        int height = width * ratio;
        pixmap = pixmap.scaled(width,height);
    }

    if(pixmap.height() > maxSize.height()){
        int height = maxSize.height();
        int width = height * ratio;
        pixmap = pixmap.scaled(width,height);
    }

    if(pixmap.width() < minSize.width()){
        int width = minSize.width();
        int height = width * ratio;
        pixmap = pixmap.scaled(width,height);
    }

    if(pixmap.height() < minSize.height()){
        int height = minSize.height();
        int width = height * ratio;
        pixmap = pixmap.scaled(width,height);
    }


}

void Image::scaled(double r){

}
