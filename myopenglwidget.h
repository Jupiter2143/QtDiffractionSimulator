#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class MyOpenGLWidget : public QOpenGLWidget, QOpenGLFunctions
{
public:
    MyOpenGLWidget(QWidget *parent = nullptr);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
};

#endif // MYOPENGLWIDGET_H
