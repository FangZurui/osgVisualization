#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <osg/Group>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgDB/ReaderWriter>
#include <osg/MatrixTransform>
#include <osgGA/TrackballManipulator>
#include <osgQOpenGL/osgQOpenGLWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

public:
    void initViewer();

public slots:
    void initOSG();

private:
    osgQOpenGLWidget*               _pWidget;
    osg::ref_ptr<osg::Group>        _pRootGroup;
    osg::ref_ptr<osgViewer::Viewer> _pViewer;
};
#endif // MAINWINDOW_H
