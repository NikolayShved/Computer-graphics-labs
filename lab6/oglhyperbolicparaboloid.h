#include <QOpenGLWidget>

class OGLHyperbolicParaboloid : public QOpenGLWidget
{
private:
    GLuint m_nHyperbolicParaboloid;
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint m_ptPosition;

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int nWidth, int nHeight) override;
    virtual void paintGL() override;
    virtual void mousePressEvent(QMouseEvent *e) override;
    virtual void mouseMoveEvent (QMouseEvent *e) override;
    GLuint createHyperbolicParaboloid();
public:
    OGLHyperbolicParaboloid(QWidget* pwgt = 0);
};
