#include <QApplication>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );

    // 加载图片
    cv::Mat image = cv::imread( "0.jpg" );  // 替换为你的图片路径
    if ( image.empty() )
    {
        return -1;
    }

    // 将OpenCV的Mat转换为QImage
    QImage  img( image.data, image.cols, image.rows, image.step, QImage::Format_RGB888 );
    QPixmap pixmap = QPixmap::fromImage( img.rgbSwapped() );

    // 显示图片
    QLabel label;
    label.setPixmap( pixmap );
    label.show();

    return a.exec();
}
