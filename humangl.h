#ifndef HUMANGL_H
#define HUMANGL_H

#include "rrglwidget.h"

struct HumanStl
{
  STLFileLoader *head;  /**< 头部 */

  STLFileLoader *neck1;  /**< 脖子1 */
  STLFileLoader *neck2;  /**< 脖子2 */
  STLFileLoader *neck3;  /**< 脖子3 */

  STLFileLoader *chest; /**< 胸部 */

  STLFileLoader *leftShoulder1;   /**< 左肩1 */
  STLFileLoader *leftShoulder2;   /**< 左肩2 */
  STLFileLoader *leftShoulder3;   /**< 左肩3 */
  STLFileLoader *leftShoulder4;   /**< 左肩4*/
  STLFileLoader *rightShoulder1;  /**< 右肩1*/
  STLFileLoader *rightShoulder2;  /**< 右肩2*/
  STLFileLoader *rightShoulder3;  /**< 右肩3*/
  STLFileLoader *rightShoulder4;  /**< 右肩4*/

  STLFileLoader *leftArm1;       /**< 左手臂1 */
  STLFileLoader *leftArm2;       /**< 左手臂2 */
  STLFileLoader *rightArm1;      /**< 右手臂1 */
  STLFileLoader *rightArm2;      /**< 右手臂2 */

  STLFileLoader *leftHand;       /**< 左手掌 */
  STLFileLoader *rightHand;      /**< 右手掌 */

  STLFileLoader *waist1;       /**< 腰1  */
  STLFileLoader *waist2;       /**< 腰2  */
  STLFileLoader *waist3;       /**< 腰3  */
  STLFileLoader *waist4;       /**< 腰4  */

  STLFileLoader *hip;         /**< 臀部  */

  STLFileLoader *leftThigh;   /**<  左大腿 */
  STLFileLoader *rightThigh;  /**<  右大腿 */
  STLFileLoader *leftLeg;     /**<  左小腿 */
  STLFileLoader *rightLeg;    /**<  右小腿 */

  STLFileLoader *leftFoot1;    /**<  左脚1 */
  STLFileLoader *leftFoot2;    /**<  左脚2 */
  STLFileLoader *rightFoot1;   /**<  右脚1 */
  STLFileLoader *rightFoot2;   /**<  右脚2 */
};

struct RotateAngle{
    int xAngle = 0;
    int yAngle = 0;
    int zAngle = 0;
};

class HumanGL: public RRGLWidget
{
    Q_OBJECT
public:
    HumanGL(QWidget *parent = 0);
    void drawGL() override;
    void drawHuman();
    void test();
    /**
     * @brief drawHead 头部、胸部、肩
     */
    void drawHead();
    /**
     * @brief drawWaist 腰部、臀部
     */
    void drawWaist();
    /**
     * @brief drwaLeftArm  左臂、左手
     */
    void drawLeftArm();
    /**
     * @brief drwaRightArm 右臂、右手
     */
    void drawRightArm();
    /**
     * @brief drawLeftLeg 左腿、脚
     */
    void drawLeftLeg();
    /**
     * @brief drawRightLeg 右腿、脚
     */
    void drawRightLeg();

    inline void setLeftArm1Angle(int xA ,int yA, int zA){
        m_leftArm1Angle.xAngle = xA;
        m_leftArm1Angle.yAngle = yA;
        m_leftArm1Angle.zAngle = zA;
        updateGL();
    }

    inline void setLeftArm2Angle(int xA ,int yA, int zA){
        m_leftArm2Angle.xAngle = xA;
        m_leftArm2Angle.yAngle = yA;
        m_leftArm2Angle.zAngle = zA;
        updateGL();
    }

    inline void setRightArm1Angle(int xA ,int yA, int zA){
        m_rightArm1Angle.xAngle = xA;
        m_rightArm1Angle.yAngle = yA;
        m_rightArm1Angle.zAngle = zA;
        updateGL();
    }

    inline void setRightArm2Angle(int xA ,int yA, int zA){
        m_rightArm2Angle.xAngle = xA;
        m_rightArm2Angle.yAngle = yA;
        m_rightArm2Angle.zAngle = zA;
        updateGL();
    }

    inline void setLeftThighAngle(int xA ,int yA, int zA){
        m_leftThighAngle.xAngle = xA;
        m_leftThighAngle.yAngle = yA;
        m_leftThighAngle.zAngle = zA;
        updateGL();
    }

    inline void setLeftLegAngle(int xA ,int yA, int zA){
        m_leftLegAngle.xAngle = xA;
        m_leftLegAngle.yAngle = yA;
        m_leftLegAngle.zAngle = zA;
        updateGL();
    }

    inline void setRightThighAngle(int xA ,int yA, int zA){
        m_rightThighAngle.xAngle = xA;
        m_rightThighAngle.yAngle = yA;
        m_rightThighAngle.zAngle = zA;
        updateGL();
    }

    inline void setRightLegAngle(int xA ,int yA, int zA){
        m_rightLegAngle.xAngle = xA;
        m_rightLegAngle.yAngle = yA;
        m_rightLegAngle.zAngle = zA;
        updateGL();
    }

    inline void setWholeAngle(int xA ,int yA, int zA){
        m_wholeAngle.xAngle = xA;
        m_wholeAngle.yAngle = yA;
        m_wholeAngle.zAngle = zA;
        updateGL();
    }

protected:
  void paintGL() override;

private:
  HumanStl model;
  RotateAngle m_wholeAngle;     /* 整体 */

  RotateAngle m_leftArm1Angle;
  RotateAngle m_leftArm2Angle;

  RotateAngle m_rightArm1Angle;
  RotateAngle m_rightArm2Angle;

  RotateAngle m_leftThighAngle;
  RotateAngle m_leftLegAngle;

  RotateAngle m_rightThighAngle;
  RotateAngle m_rightLegAngle;
};

#endif // HUMANGL_H
