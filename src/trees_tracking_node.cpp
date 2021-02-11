#include "trees_tracking/tracker.h"


using namespace std;
using namespace ros;


int main(int argc, char **argv){

	init(argc, argv, "trees_tracking_node");
	NodeHandle nh("~");

	Tracker tracker(nh);
	spin();

	return 0;
}
