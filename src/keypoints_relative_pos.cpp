#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <keypoint_3d_matching_msgs/Keypoint3d_list.h>

#include <vector>

#define TRANSLATION_SIZE 5

float lWrist, lShoulder, threshold=0.02;
std_msgs::Bool msg;
ros::Publisher pub;
std::vector<float> translations;

void keypoints_relative_pos_callback (const keypoint_3d_matching_msgs::Keypoint3d_list::ConstPtr keypoint_msg){
	for (auto it = keypoint_msg->keypoints.begin(); it != keypoint_msg->keypoints.end(); ++it){
		if (it->name == "LWrist"){
			lWrist = it->points.point.z;
		}
		else if (it->name == "LShoulder"){
			lShoulder = it->points.point.z;
		}
	}
	if (lWrist != 0 and lShoulder !=0){
		translations.push_back(lWrist-lShoulder);
		if (translations.size() > TRANSLATION_SIZE){
			int neg=0;
			for (auto c : translations){
				if (c < 0)
					neg += 1;
			}
			ROS_INFO("%d", neg);
			msg.data = neg > 3 ? false : true;
			translations.clear();
		}
	}
	else{
		msg.data = true;
	}
	pub.publish(msg);
}


int main(int argc, char** argv){
	ros::init(argc, argv, "keypoints_relative_pos");
	ros::NodeHandle nh;

	
	pub = nh.advertise<std_msgs::Bool>("/keypoints_relative_pos_topic", 100);

	ros::Subscriber sub = nh.subscribe("/transform_topic", 100, keypoints_relative_pos_callback);

	ros::spin();
}
