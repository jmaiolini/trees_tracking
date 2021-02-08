#include "trees_tracking/tracker.h"

Tracker::Tracker(NodeHandle nh, string params) :
	nh_(nh),
	params_(params)
{
	readParams();

	init();
};

void Tracker::readParams(){

  //TODO

};

void Tracker::init(){


};



