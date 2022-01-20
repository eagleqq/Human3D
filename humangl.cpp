#include "humangl.h"
#include <QDebug>

HumanGL::HumanGL(QWidget *parent)
    :RRGLWidget(parent)
{
    QString root = "./STLFile/human/";
    model.head = new STLFileLoader(root + "头.STL", 10);

    model.neck1 = new STLFileLoader(root + "脖子1.STL", 10);
    model.neck2 = new STLFileLoader(root + "脖子2.STL", 10);
    model.neck3 = new STLFileLoader(root + "脖子3.STL", 10);

    model.chest = new STLFileLoader(root + "胸部.STL", 10);

    model.leftShoulder1 = new STLFileLoader(root + "左肩1.STL", 10);
    model.leftShoulder2 = new STLFileLoader(root + "左肩2.STL", 10);
    model.leftShoulder3 = new STLFileLoader(root + "左肩3.STL", 10);
    model.leftShoulder4 = new STLFileLoader(root + "左肩4.STL", 10);
    model.rightShoulder1 = new STLFileLoader(root + "右肩1.STL", 10);
    model.rightShoulder2 = new STLFileLoader(root + "右肩2.STL", 10);
    model.rightShoulder3 = new STLFileLoader(root + "右肩3.STL", 10);
    model.rightShoulder4 = new STLFileLoader(root + "右肩4.STL", 10);

    model.leftArm1 = new STLFileLoader(root + "A左大臂.stl", 10);
    model.leftArm2 = new STLFileLoader(root + "A左小臂.stl", 10);

    model.rightArm1 = new STLFileLoader(root + "A右大臂.stl", 10);
    model.rightArm2 = new STLFileLoader(root + "A右小臂.stl", 10);

    model.leftHand = new STLFileLoader(root + "A左手掌.stl", 10);
    model.rightHand = new STLFileLoader(root + "A右手掌.stl", 10);

    model.waist1 = new STLFileLoader(root + "腰1.STL", 10);
    model.waist2 = new STLFileLoader(root + "腰2.STL", 10);
    model.waist3 = new STLFileLoader(root + "腰3.STL", 10);
    model.waist4 = new STLFileLoader(root + "腰4.STL", 10);

    model.hip = new STLFileLoader(root + "臀部.STL", 10);

    model.leftThigh = new STLFileLoader(root + "A左大腿.stl", 10);
    model.leftLeg = new STLFileLoader(root + "A左小腿.stl", 10);

    model.rightThigh = new STLFileLoader(root + "A右大腿.stl", 10);
    model.rightLeg = new STLFileLoader(root + "A右小腿.stl", 10);

    model.leftFoot1 = new STLFileLoader(root + "左脚1.STL", 10);
    model.leftFoot2 = new STLFileLoader(root + "左脚2.STL", 10);
    model.rightFoot1 = new STLFileLoader(root + "右脚1.STL", 10);
    model.rightFoot2 = new STLFileLoader(root + "右脚2.STL", 10);
}

void HumanGL::drawGL()
{
    drawGrid();
    drawCoordinates();
    drawHuman();
}

void HumanGL::drawHuman()
{
    glRotatef(m_wholeAngle.xAngle, 1.0, 0.0, 0.0);
    glRotatef(m_wholeAngle.yAngle, 0.0, 1.0, 0.0);
    glRotatef(m_wholeAngle.zAngle, 0.0, 0.0, 1.0);

    drawHead();
    drawWaist();

    drawLeftArm();
    drawRightArm();

    drawLeftLeg();
    drawRightLeg();
//    test();
}

void HumanGL::test()
{
    glPushMatrix();
    setupColor(255, 69, 0);
    model.rightLeg->draw();
    glPopMatrix();
}

void HumanGL::drawHead()
{
    glPushMatrix();
    setupColor(255, 69, 0);

    model.head->draw();
    model.neck1->draw();
    model.neck2->draw();
    model.neck3->draw();
    model.chest->draw();
    model.leftShoulder1->draw();
    model.leftShoulder2->draw();
    model.leftShoulder3->draw();
    model.leftShoulder4->draw();
    model.rightShoulder1->draw();
    model.rightShoulder2->draw();
    model.rightShoulder3->draw();
    model.rightShoulder4->draw();
    glPopMatrix();
}

void HumanGL::drawWaist()
{
    glPushMatrix();
    setupColor(255, 69, 0);

    model.waist1->draw();
    model.waist2->draw();
    model.waist3->draw();
    model.waist4->draw();
    model.hip->draw();
    glPopMatrix();
}

void HumanGL::drawLeftArm()
{
    glPushMatrix();
    //左大臂
    setupColor(255, 69, 0);
    glTranslatef(150, 0, 1340);
    glRotatef(m_leftArm1Angle.xAngle, 1.0, 0.0, 0.0);
    glRotatef(m_leftArm1Angle.yAngle, 0.0, 1.0, 0.0);
    glRotatef(m_leftArm1Angle.zAngle, 0.0, 0.0, 1.0);
    drawSTLCoordinates(0, 255, 0);
    model.leftArm1->draw();
    glTranslatef(200, 0, -15);
    //左小臂
    glRotatef(m_leftArm2Angle.xAngle, 1.0, 0.0, 0.0);
    glRotatef(m_leftArm2Angle.yAngle, 0.0, 1.0, 0.0);
    glRotatef(m_leftArm2Angle.zAngle, 0.0, 0.0, 1.0);
    drawSTLCoordinates(0, 255, 0);
    model.leftArm2->draw();
    glTranslatef(230, 0, -30);
    model.leftHand->draw();
    glPopMatrix();
}

void HumanGL::drawRightArm()
{
    glPushMatrix();
    //右大臂
    setupColor(255, 69, 0);
    glTranslatef(-145, 0, 1340);
    glRotatef(m_rightArm1Angle.xAngle, 1.0, 0.0, 0.0);
    glRotatef(m_rightArm1Angle.yAngle, 0.0, 1.0, 0.0);
    glRotatef(m_rightArm1Angle.zAngle, 0.0, 0.0, 1.0);
    drawSTLCoordinates(0, 255, 0);
    model.rightArm1->draw();
    glTranslatef(-190, 10, -40);

    //右小臂
    glRotatef(m_rightArm2Angle.xAngle, 1.0, 0.0, 0.0);
    glRotatef(m_rightArm2Angle.yAngle, 0.0, 1.0, 0.0);
    glRotatef(m_rightArm2Angle.zAngle, 0.0, 0.0, 1.0);
    drawSTLCoordinates(0, 255, 0);
    model.rightArm2->draw();
    glTranslatef(-230, 0, -30);
    model.rightHand->draw();
    glPopMatrix();
}

void HumanGL::drawLeftLeg()
{
    glPushMatrix();
    //左大腿
    setupColor(255, 69, 0);
    glTranslatef(110, 0, 870);
    glRotatef(m_leftThighAngle.xAngle, 1.0, 0.0, 0.0);
    glRotatef(m_leftThighAngle.yAngle, 0.0, 1.0, 0.0);
    glRotatef(m_leftThighAngle.zAngle, 0.0, 0.0, 1.0);
    drawSTLCoordinates(255, 255, 0);
    model.leftThigh->draw();
    //左小腿
    glTranslatef(0, -25, -370);
    glRotatef(m_leftLegAngle.xAngle, 1.0, 0.0, 0.0);
    glRotatef(m_leftLegAngle.yAngle, 0.0, 1.0, 0.0);
    glRotatef(m_leftLegAngle.zAngle, 0.0, 0.0, 1.0);
    drawSTLCoordinates(255, 255, 0);
    model.leftLeg->draw();
    glTranslatef(-110, 37, -500);
    model.leftFoot1->draw();
    model.leftFoot2->draw();
    glPopMatrix();
}

void HumanGL::drawRightLeg()
{
    glPushMatrix();
    //右大腿
    setupColor(255, 69, 0);
    glTranslatef(-100, 30, 870);
    glRotatef(m_rightThighAngle.xAngle, 1.0, 0.0, 0.0);
    glRotatef(m_rightThighAngle.yAngle, 0.0, 1.0, 0.0);
    glRotatef(m_rightThighAngle.zAngle, 0.0, 0.0, 1.0);
    drawSTLCoordinates(0, 255, 255);
    model.rightThigh->draw();
    glTranslatef(20, -70, -370);

    //右小腿
    glRotatef(m_rightLegAngle.xAngle, 1.0, 0.0, 0.0);
    glRotatef(m_rightLegAngle.yAngle, 0.0, 1.0, 0.0);
    glRotatef(m_rightLegAngle.zAngle, 0.0, 0.0, 1.0);
    drawSTLCoordinates(0, 255, 255);
    model.rightLeg->draw();

    glTranslatef(60, 40, -495);
    model.rightFoot1->draw();
    model.rightFoot2->draw();
    glPopMatrix();
}

void HumanGL::paintGL()
{
    /* 用来绘制OpenGL的窗口了，只要有更新发生，这个函数就会被调用 */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* 清除屏幕和深度缓存 */
    glPushMatrix();
    glTranslated(0, 0, z_zoom);
    glTranslated(xTran, yTran, 0);
    glRotated(xRot / 16.0, 1.0, 0.0, 0.0); /* 绕x轴旋转 */
    glRotated(yRot / 16.0, 0.0, 1.0, 0.0); /* 绕y轴旋转 */
    glRotated(zRot / 16.0, 0.0, 0.0, 1.0); /* 绕z轴旋转 */
    glRotated(+90.0, 1.0, 0.0, 0.0);
    drawGL();
    glPopMatrix();
}
