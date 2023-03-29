#include "mainwindow.h"

MainWindow::MainWindow()
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::initViewer()
{
    _pWidget = new osgQOpenGLWidget();
    this->setCentralWidget(_pWidget);
    _pWidget->setGeometry(this->geometry());                // 获取窗体大小
    connect(_pWidget, SIGNAL(initialized()), this, SLOT(initOSG()));
}

void MainWindow::initOSG()
{
    // 初始化根节点
    _pRootGroup = new osg::Group();
    osg::MatrixTransform* mt = new osg::MatrixTransform();
    mt->addChild(osgDB::readNodeFile("/home/fzr/Documents/Codes/earthResource/las/038-4201002L063211201072703-00016-0.las"));

    osg::Matrixd sizeMat = osg::Matrixd::scale(osg::Vec3(2.0,1.0,1.0));
    osg::Matrixd baseMat = osg::Matrixd::rotate(osg::inDegrees(0.0f), 0.0f, 0.0f, 0.0f);
    osg::Matrixd headingMat = osg::Matrixd::rotate(osg::inDegrees(0.0f), 0.0f, 0.0f, 0.0f);
    osg::Matrixd rollMat = osg::Matrixd::rotate(osg::inDegrees(0.0f), 0.0f, 0.0f, 0.0f);
    osg::Matrixd pitchMat = osg::Matrixd::rotate(osg::inDegrees(90.0f), 1.0f, 0.0f, 0.0f);

    osg::Matrixd Mat = sizeMat * baseMat * headingMat * rollMat * pitchMat;
    mt->setMatrix(Mat);

    _pRootGroup->addChild(mt);

    // 创建viewer
    _pViewer = _pWidget->getOsgViewer();

    _pViewer->setCameraManipulator(new osgGA::TrackballManipulator());

    // 设置场景数据
    _pViewer->setSceneData(_pRootGroup);
}
