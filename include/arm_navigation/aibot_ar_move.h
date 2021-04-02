#ifndef AR_MOVE_H
#define AR_MOVE_H

#include <iostream>
#include "ros/ros.h"
#include "tf/transform_listener.h"
#include <visualization_msgs/Marker.h>
#include <std_msgs/String.h>

#define PI 3.1415926

namespace aibot{

    class OdomAction{

        public:
            enum OdomActionDirection
            {
                front = 0,  //前
                back = 1,   //后
                left = 2,   //左
                right = 3,  //右
                clockwise = 4,  //顺时针
                counterclockwise = 5,    //逆时针
                none = -1
            };
            OdomAction();
            OdomAction(ros::NodeHandle &nodeHandle);
            ~OdomAction();
            void Start(bool run);

            void StartFindMarker();

            void timerCallback(const ros::TimerEvent& e);

            /**
             * @brief ar_track_alvar 识别图像订阅反馈
             * 
             * @param marker_tmp 
             */
            void subCallBack(const visualization_msgs::Marker &marker_tmp);
            void OdomActionLinear(float LinearDistance,float moveSpeed,float LinearTolerance,OdomActionDirection odomActionDirection);

            void OdomActionAngular(float AngularAngle,float AngularSpeed,float AngularTolerance,OdomActionDirection odomActionDirection);

            void FindMarker(float partAngle);


            ros::NodeHandle *mPnodeHandler;
            ros::Timer mTimer;
            ros::Subscriber mMarkerSub;
            ros::Publisher mPublisher;
            ros::Publisher mPublisherFinish;
            tf::StampedTransform mTransform;
            tf::StampedTransform mCameraTransform;

        private:
            tf::TransformListener mListener;

            /**
             * @brief rpy
             * 
             */
            double mRoll, mPitch, mYaw;

            /**
             * @brief marker相对摄像头的位置信息
             * 
             */
            float mPositionX, mPositionY, mPositionZ;

            /**
             * @brief Get the Odom Angle
             * 
             * @return float 
             */
            float getOdomAngle();

            float normalizeAngle(float angle);

            void getTransform();

            float getCameraBaseLinkX();

            /**
             * @brief 运行一次
             * 
             */
            bool mRunOnce;

            /**
             * @brief 是否找到标签
             * 
             */
            bool mFindMarker;

            /**
             * @brief 标签找到后执行
             * 
             */
            bool mEndRunMarker;


            double mBeginTime;
            double mBeginRunAngularTime;

            double mBeginLinearTime;

            bool mRunFirstStep;

            bool mRunSecondStep;

            bool mRunThirdStep;

            bool mRunFourthStep;

            float mCarDisTranslation;

            float mCarDisTar;

            int mStatus;

            bool mStartRun;




    };

}

#endif