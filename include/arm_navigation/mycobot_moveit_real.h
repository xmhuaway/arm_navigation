#ifndef ARM_REAL_CONTROL_H
#define ARM_REAL_CONTROL_H

#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/robot_hw.h>
#include <controller_manager/controller_manager.h>
#include "ros/ros.h"
#include "aibot_msgs/ServoCtrl.h"
#include <thread>
#include <cmath>

#define PI 3.1415926

namespace AIBotArmHardwareInterface{

	class Joint
	{
		private:
		public:
			int mId;
			double	mPosition;
			double	mVelocity;
			double	mEffort;
			double	mPosCmd;
			double	mVelCmd;
			float mAngleOrigin;
			int mServoMode;
			int mServoRange;
			int mServoSpeed;
			std::string mName;

			Joint(){};
			~Joint(){};
	};

    class AIBot : public hardware_interface::RobotHW {
	public:
	
		AIBot();
		AIBot(std::string node);
		~AIBot();

		ros::NodeHandle mNodeHandle;
		ros::Publisher mPublisher;
		aibot_msgs::ServoCtrl mServoCtrl;

		Joint mJoints[6];
		void write(const ros::Time& time, const ros::Duration& period);
		void read(const ros::Time& time, const ros::Duration& period);
		void start();

	private: 
		hardware_interface::JointStateInterface mJointStateInterface;
		hardware_interface::PositionJointInterface mJointPositionInterface;
    }; 
}

#endif