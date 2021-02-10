#include "trees_tracking/tracker.h"
#include <ros/package.h>

using namespace std;
using namespace ros;


int main(int argc, char **argv){

	if (argc < 2){
		cout << "Please specify name of config file" << endl;
		return 1;
	}

	string param_file, param_path;
	param_file = argv[1];
	init(argc, argv, "trees_tracking_node");
	NodeHandle nh("~");
	
	param_path = package::getPath("trees_tracking") + "/config/" + param_file;

	cout << "Params path:" << param_file << " and " << param_path << endl;
	Tracker tracker(nh,param_path);
	spin();

	return 0;
}
