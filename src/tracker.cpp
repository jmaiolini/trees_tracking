#include "trees_tracking/tracker.h"

Tracker::Tracker(NodeHandle& nh) :
	nh_(nh)
	// params_(params)
{
	readParams();

	init();

	
};

void Tracker::readParams(){

	//ROS parameters
	nh_.getParam("/subs/left_img/topic", leftImgTopicName_);  
	nh_.getParam("/subs/depth_img/topic", depthImgTopicName_);  
	nh_.getParam("/subs/left_info/topic", leftInfoTopicName_);  
	nh_.getParam("/subs/depth_info/topic", depthInfoTopicName_);  
	nh_.getParam("/subs/odom/topic", cameraOdomTopicName_);  
	nh_.getParam("/subs/boxes/topic", boxesTopicName_);  
	nh_.getParam("/subs/boxes/num_obj_topic", numBoxesTopicName_);  

	nh_.getParam("/subs/left_img/queue_size", leftImgTopicQueue_);  
	nh_.getParam("/subs/depth_img/queue_size", depthImgTopicQueue_);  
	nh_.getParam("/subs/left_info/queue_size", leftInfoTopicQueue_);  
	nh_.getParam("/subs/depth_info/queue_size", depthInfoTopicQueue_);  
	nh_.getParam("/subs/odom/queue_size", cameraOdomTopicQueue_);  
	nh_.getParam("/subs/boxes/queue_size", boxesTopicQueue_);
	

	nh_.getParam("/subs/objects_position/topic", ObjectPosesTopicName_);  

  	//TODO

}



void Tracker::init(){

	//ROS topics
	left_img_sub_ = nh_.subscribe(leftImgTopicName_, leftImgTopicQueue_, &Tracker::leftImgCallback, this);
	depth_img_sub_ = nh_.subscribe(depthImgTopicName_, depthImgTopicQueue_, &Tracker::depthImgCallback, this);
	left_info_sub_ = nh_.subscribe(leftInfoTopicName_, leftInfoTopicQueue_, &Tracker::leftInfoCallback, this);
	depth_info_sub_ = nh_.subscribe(depthInfoTopicName_, depthInfoTopicQueue_, &Tracker::depthInfoCallback, this);
	camera_odom_sub_ = nh_.subscribe(cameraOdomTopicName_, cameraOdomTopicQueue_, &Tracker::cameraOdomCallback, this); 
	boxes_sub_ = nh_.subscribe(boxesTopicName_, boxesTopicQueue_, &Tracker::boxesCallback, this);
	num_boxes_sub = nh_.subscribe(numBoxesTopicName_, boxesTopicQueue_, &Tracker::numBoxesCallback, this);
	objects_pose_pub_ = nh_.advertise<std_msgs::String>(ObjectPosesTopicName_, ObjectPosesTopicQueue_);

}

//ROS callbacks
void Tracker::leftImgCallback(const sensor_msgs::Image::ConstPtr& msg){

}
void Tracker::depthImgCallback(const sensor_msgs::Image::ConstPtr& msg){

}
void Tracker::leftInfoCallback(const sensor_msgs::CameraInfo::ConstPtr& msg){

}
void Tracker::depthInfoCallback(const sensor_msgs::CameraInfo::ConstPtr& msg){

}
void Tracker::cameraOdomCallback(const nav_msgs::Odometry::ConstPtr& msg){

}
void Tracker::boxesCallback(const  darknet_ros_msgs::BoundingBoxes::ConstPtr& msg){ 

}

void Tracker::numBoxesCallback(const  std_msgs::Int8::ConstPtr& msg){ 

}





