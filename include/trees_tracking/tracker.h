#include <ros/ros.h>

using namespace std;
using namespace ros;

class Tracker{

	NodeHandle nh_;
	string params_;

	Subscriber camera_sub_, boxes_sub_, num_objects_sub_;
	Publisher object_pose_pub_; 

	void readParams();
	void init();

	public:
	Tracker(NodeHandle, string);




};
