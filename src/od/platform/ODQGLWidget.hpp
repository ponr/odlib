#ifndef OD_PLATFORM_ODQGLWIDGET_HPP
#define OD_PLATFORM_ODQGLWIDGET_HPP

#include <QtOpenGL/QGLWidget>

namespace od {
namespace platform {

/// Subclassed implementation of QGLWidget for ODlib.
/// Handles events from Qt.
class ODQGLWidget : public QGLWidget
{
public:
    /// Constructor for ODQGLWidget
    /// @param window_size Minimum size of the window
    /// @param format GLFormat for window
    /// @param window_title Tilte for the window
    /// @param parent Parent widget (Qt)
    ODQGLWidget(const QSize& window_size,
                const QGLFormat& format,
                const QString& window_title,
                QWidget* parent = 0);

    /// Destructor
    virtual ~ODQGLWidget();

protected:
    // This function will be called after context is created.
    // (also before first Qt PaintGL call)
    void initializeGL();

    // This function will be called when widget needs to be painted.
    // Should call rendering functions.
    // TODO: Check out if possible to implement indepently.
    void paintGL();

    // This function will be called when widget is resized.
    void resizeGL(int w, int h);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private:

};

}
}

#endif /* OD_PLATFORM_ODQGLWIDGET_HPP */
