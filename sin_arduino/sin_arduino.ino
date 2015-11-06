
#include <math.h>

const float myPI = 3.141593;
float alpha = 0;
float sin_value;
int led =13;


void setup()
{
pinMode(led , OUTPUT);
Serial.begin(9600);
}

void loop()
{

alpha = alpha + 0.1;
if(alpha>2*myPI) alpha = 0;

if (alpha>myPI)
  digitalWrite(led, LOW);
else
  digitalWrite(led, HIGH);
  
  
sin_value = sin(alpha);

//ros_float_msg.data = sin(alpha);

//ros_pub.publish(&ros_float_msg);

//nh.spinOnce();

Serial.println(sin_value, DEC);

delay(100);

}











