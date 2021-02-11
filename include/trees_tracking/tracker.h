#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>

//YOLO
#include <darknet_ros_msgs/BoundingBoxes.h>


using namespace std;
using namespace ros;

class Tracker{

	NodeHandle nh_;
	string params_;

	/* Parameters from config file*/
	//ROS topic names and queue sizes
	string leftImgTopicName_, depthImgTopicName_, leftInfoTopicName_, depthInfoTopicName_,
	       cameraOdomTopicName_, boxesTopicName_, numBoxesTopicName_;
	int leftImgTopicQueue_, depthImgTopicQueue_, leftInfoTopicQueue_, depthInfoTopicQueue_,
	    cameraOdomTopicQueue_, boxesTopicQueue_;

	//Tracking output
	string ObjectPosesTopicName_;
	int ObjectPosesTopicQueue_;

	//ROS 
	Subscriber left_img_sub_, depth_img_sub_, left_info_sub_, depth_info_sub_,
	           camera_odom_sub_, boxes_sub_, num_boxes_sub;
	Publisher objects_pose_pub_; 

	

	void readParams();//string&);
	void init();

	//ROS callbacks
	void leftImgCallback(const sensor_msgs::Image::ConstPtr& );
	void depthImgCallback(const sensor_msgs::Image::ConstPtr& );
	void leftInfoCallback(const sensor_msgs::CameraInfo::ConstPtr& );
	void depthInfoCallback(const sensor_msgs::CameraInfo::ConstPtr& );
	void cameraOdomCallback(const nav_msgs::Odometry::ConstPtr& );
    void boxesCallback(const darknet_ros_msgs::BoundingBoxes::ConstPtr& );
	void numBoxesCallback(const std_msgs::Int8::ConstPtr& );
	
	public:
	Tracker(NodeHandle&);



};
