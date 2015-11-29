
#include <math.h>
#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Bool.h>

const float myPI = 3.141593;
float alpha = 0;
float sin_value;
int led =13;

ros::NodeHandle nh;
std_msgs::Float32 ros_float_msg;
ros::Publisher ros_pub("ros_pub", &ros_float_msg);

void setup()
{
  nh.initNode();
  nh.advertise(ros_pub);
pinMode(led , OUTPUT);

}

void loop()
{

alpha = alpha + 0.1;
if(alpha>2*myPI) alpha = 0;

if (alpha>myPI)
  digitalWrite(led, LOW);
else
  digitalWrite(led, HIGH);
  
  
//sin_value = sin(alpha);

ros_float_msg.data = sin(alpha);

ros_pub.publish(&ros_float_msg);

nh.spinOnce();

//Serial.println(sin_value, DEC);

delay(100);

}
