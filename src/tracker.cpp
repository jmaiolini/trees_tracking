#include "trees_tracking/tracker.h"

Tracker::Tracker(NodeHandle& nh, string& params) :
	nh_(nh),
	params_(params)
{
	readParams(params);

	init();
};

void Tracker::readParams(string& params_file){

	YAML::Node configuration = YAML::LoadFile(params_file);

	//ROS parameters
	leftImgTopicName_ = configuration["subscribers"]["left_img"]["topic"].as<string>();    
	depthImgTopicName_ = configuration["subscribers"]["depth_img"]["topic"].as<string>(); 
	leftInfoTopicName_ = configuration["subscribers"]["left_info"]["topic"].as<string>();    
	depthInfoTopicName_ = configuration["subscribers"]["depth_info"]["topic"].as<string>();   
	cameraOdomTopicName_ = configuration["subscribers"]["odom"]["topic"].as<string>();    
	boxesTopicName_ = configuration["subscribers"]["boxes"]["topic"].as<string>(); 

	leftImgTopicQueue_ = configuration["subscribers"]["left_img"]["queue_size"].as<int>();    
	depthImgTopicQueue_ = configuration["subscribers"]["depth_img"]["queue_size"].as<int>();  
	leftInfoTopicQueue_ = configuration["subscribers"]["left_info"]["queue_size"].as<int>();    
	depthInfoTopicQueue_ = configuration["subscribers"]["depth_info"]["queue_size"].as<int>();  	
	cameraOdomTopicQueue_ = configuration["subscribers"]["odom"]["queue_size"].as<int>();    
	boxesTopicQueue_ = configuration["subscribers"]["boxes"]["queue_size"].as<int>();     

	ObjectPosesTopicName_ =configuration["publishers"]["objects_position"]["topic"].as<string>(); 

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
void Tracker::boxesCallback(const std_msgs::String::ConstPtr& msg){ //TOCHANGE WITH YOLO

}



