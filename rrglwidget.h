#ifndef RRGLWIDGET_H
#define RRGLWIDGET_H

#include "stlfileloader.h"
#include <QGLWidget>
#include <QWidget>

/**
 * @brief The RRGLWidget class 基类，提供了鼠标旋转、方法缩小、平移、网格、坐标系等基本功能
 */
class RRGLWidget : public QGLWidget {

  Q_OBJECT

public:
  RRGLWidget(QWidget *parent = 0);
  ~RRGLWidget();
  /**
   * @brief drawGrid 画网格
   */
  void drawGrid();
  /**
   * @brief drawCoordinates 画坐标系
   */
  void drawCoordinates();
  /**
   * @brief drawSTLCoordinates 画每个组件变换后的坐标系
   * @param r
   * @param g
   * @param b
   */
  void drawSTLCoordinates(int r, int g, int b);

  /**
   * @brief drawGL 画STL模型
   */
  virtual void drawGL();
  /**
   * @brief setupColor  设置显示颜色
   * @param r
   * @param g
   * @param b
   */
  void setupColor(int r, int g, int b);
  /**
   * @brief setXRotation  x轴旋转
   * @param angle
   */
  void setXRotation(int angle);
  /**
   * @brief setYRotation  y轴旋转
   * @param angle
   */
  void setYRotation(int angle);
  /**
   * @brief setXYTranslate  X方向Y方向平移
   * @param dx
   * @param dy
   */
  void setXYTranslate(int dx, int dy);

  int normalizeAngle(int angle);
  /**
   * @brief setZoom
   * @param zoom
   */
  void setZoom(int zoom);

signals:
  void xRotationChanged(int angle);
  void yRotationChanged(int angle);
  void zRotationChanged(int angle);

protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;

  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;

public:
  GLdouble xRot = -2584; // x旋转角度
  GLdouble yRot = 1376;  // y旋转角度
  GLdouble zRot = 0.0;   // z旋转角度
  int z_zoom = -2500;    // 缩放
  int xTran = 0;         // 界面显示X位置
  int yTran = 0;         // 界面显示Y位置
  QPoint lastPos;
};
#endif // RRGLWIDGET_H
