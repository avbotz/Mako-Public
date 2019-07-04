#include "mission/functions.hpp"
#include "mission/commands.hpp"
#include "vision/tasks.hpp"
#include "vision/config.hpp"
#include "control/atmega.hpp"


void gate(vision::Perception &per, ros::ServiceClient &client)
{
	ROS_INFO("Beginning GATE function.");
	
	ROS_INFO("Set initial state.");
	ROS_INFO("State @ %s.", atmega::state().text().c_str());
	// State initial(3., 2., 0., 28., 0., 0.);
	State initial = atmega::state();
	ROS_INFO("New State @ %s.", initial.text().c_str());
	move(initial);
	per.request.task = Task::GATE;
	per.request.camera = FRONT;
	ros::Duration(6.0).sleep();

	ROS_INFO("Turn towards gate.");
	ROS_INFO("State @ %s.", atmega::state().text().c_str());
	float angle = align(per, client, 5);
	ROS_INFO("Angle @ %f.", angle);
	State move1 = atmega::state();
	move1.axis[YAW] = angle;
	ROS_INFO("New State @ %s.", move1.text().c_str());
	move(move1);
	ros::Duration(2.0).sleep();

	ROS_INFO("Go through gate.");
	ROS_INFO("State @ %s.", atmega::state().text().c_str());
	float dist = 8.;
	State move2 = atmega::state();
	move2.axis[X] += std::cos(angle*M_PI/180.)*dist;
	move2.axis[Y] += std::sin(angle*M_PI/180.)*dist;
	ROS_INFO("New State @ %s", move2.text().c_str());
	move(move2);
}

void octagon()
{
	
}

void printResponse(vision::Perception &per)
{
	ROS_INFO("%i observation @ %0.2f H-deg, %0.2f V-deg, and %0.2f meters.", 
			per.request.task, per.response.hangle, per.response.vangle, per.response.dist);
}
