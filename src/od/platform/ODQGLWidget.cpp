#include "ODQGLWidget.hpp"

namespace od {
namespace platform {

ODQGLWidget::ODQGLWidget(const QSize& window_size,
                         const QGLFormat& format,
                         const QString& window_title,
                         QWidget* parent) :
    QGLWidget()
    //QGLWidget(format, parent)
{
    setMinimumSize(window_size);
    setWindowTitle(window_title);
}

ODQGLWidget::~ODQGLWidget()
{
}

void ODQGLWidget::initializeGL()
{
    // TODO: Do proper opengl initialization stuff
}

void ODQGLWidget::paintGL()
{
    // TODO: Call proper rendering functions
}

void ODQGLWidget::resizeGL(int w, int h)
{
    // TODO: Call resize callback
}

void ODQGLWidget::keyPressEvent(QKeyEvent *event)
{
    // TODO: Fire proper events in event system
}

void ODQGLWidget::keyReleaseEvent(QKeyEvent *event)
{
    // TODO: Fire proper events in event system
}

void ODQGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    // TODO: Fire proper events in event system
}

void ODQGLWidget::mousePressEvent(QMouseEvent *event)
{
    // TODO: Fire proper events in event system
}

void ODQGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    // TODO: Fire proper events in event system
}

void ODQGLWidget::wheelEvent(QWheelEvent *event)
{
    // TODO: Fire proper events in event system
}

void ODQGLWidget::enterEvent(QEvent *event)
{
    // TODO: Fire proper events in event system
}

void ODQGLWidget::leaveEvent(QEvent *event)
{
    // TODO: Fire proper events in event system
}

}
}
