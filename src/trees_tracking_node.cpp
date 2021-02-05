#include "trees_tracking/track.h"

using namespace std;
using namespace ros;


int main(int argc, char **argv){

	if (argc < 2){
		cout << "Please specify name of config file" << endl;
		return 1;
	}

	string params = argv[1];
	init(argc, argv, "trees_tracking_node");
	NodeHandle nh("~");

	Track track();
	spin();

	return 0;
}
