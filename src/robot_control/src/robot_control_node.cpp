
#include <iostream>
//#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "ros/ros.h"
#include <errno.h>
#include "wiringPiI2C.h"	//library for using I2C with WiringPi
#include <unistd.h>		//Needed for I2C port
#include <fcntl.h>		//Needed for I2C port
#include <sys/ioctl.h>		//Needed for I2C port
#include <linux/i2c-dev.h>	//Needed for I2C port
#include "shared_files/Drive.h"
#include "shared_files/Ladder.h"
#include "shared_files/Bucket.h"
#include "shared_files/WriteI2C.h"

//===========| Arduino Addr. |===========

int bucketAddr = 0x05;		// Arduino Mega @ address 0x05
int platformAddr = 0x06;	// Arduino Mega @ address 0x06
//int sensorAddr(4);
//=======================================

//===| initi. wiringPi I2C-Arduino addr. |===

//int bucketWrite = wiringPiI2CSetup(bucketAddr);	//Write to I2C
int platformWrite = wiringPiI2CSetup(platformAddr);
//int sensorRead = wiringPiI2CSetup(sensorAddr);	//Read from I2C

int length = 4;				//Number of bytes to read
unsigned char buffer[4] = {0};		//Buffer to Write Data to I2C
//unsigned char readBuffer[4] = {0};	//Buffer to store the Received Bytes

//==============| TIMERS |================

const ros::Duration tenth_of_sec(0.1);
//========================================

shared_files::Drive last_drive_msg;
shared_files::Bucket last_bucket_msg;
shared_files::Ladder last_ladder_msg;

ros::Time last_drive_sub_time;
ros::Time last_drive_pub_time;
ros::Time last_bucket_sub_time;
ros::Time last_bucket_pub_time;
ros::Time last_ladder_sub_time;
ros::Time last_ladder_pub_time;

ros::Publisher i2c_pub;

ros::Subscriber drive_sub;
ros::Subscriber bucket_sub;
ros::Subscriber ladder_sub;

void driveSubCallback (const shared_files::Drive drive_msg){
	last_drive_msg = drive_msg;
	last_drive_sub_time = ros::Time::now();
}

void bucketSubCallback(const shared_files::Bucket bucket_msg){
	last_bucket_msg = bucket_msg;
	last_bucket_sub_time = ros::Time::now();
}

void ladderSubCallback(const shared_files::Ladder ladder_msg){
	last_ladder_msg = ladder_msg;
	last_ladder_sub_time = ros::Time::now();
}

//Re-set the Buffer Data
void flush_buffer(){

	for(int i=0; i <= 3; i++)
	{
		buffer[i] = 0;
	}
}
//generate a stop message for the desired address
int generate_stop_msg(int address){

	int tempWrite = wiringPiI2CSetup(address);
//	wiringPiI2CWrite(tempWrite,0x00);
//	tenth_of_sec.sleep();

//	wiringPiI2CWriteReg8(tempWrite, 0x40, 0x01);
//	wiringPiI2CWriteReg16(tempWrite, 0x40, 0xFD01);	//Sends bytes 0x40 then 0x01 then 0xFD to the slave device with address arduino

	buffer[0] = 0;
	buffer[1] = 0;
	buffer[2] = 0;
	buffer[3] = 0;

  if (write(tempWrite, buffer, length) != length){

	ROS_INFO("Failed to write to the I2C Bus.\n");	//ERROR HANDLING I2C transaction failed
	return 0;
  }

return 1;
}

int generate_drive_msg(){

	/* Note about direction byte
		Left Forward, Right Forward: 1
		Left Forward, Right Backward: 2
		Left Backward, Right Forward: 3
		Left Backward, Right Backward: 4
	*/

	if(last_drive_msg.left > 0 && last_drive_msg.right > 0){
		//Left Forward, Right Forward
		buffer[0] = 1;
	}
	if(last_drive_msg.left > 0 && last_drive_msg.right < 0){
		//Left Forward, Right Backward
		buffer[0] = 2;
	}
	if(last_drive_msg.left < 0 && last_drive_msg.right > 0){
		//Left Backward, Right Forward
		buffer[0] = 3;
	}
	if(last_drive_msg.left < 0 && last_drive_msg.right < 0){
		//Left Backward, Right Backward
		buffer[0] = 4;
	}
	char left = (char) (abs(last_drive_msg.left*255.0));
//	char right = (char) (abs(last_drive_msg.right*255.0));
	buffer[1] =  left ;
//	buffer[2] =  right ;
	buffer[2] = 0;
	buffer[3] = 0;

//	wiringPiI2CWriteReg8(platformWrite, buffer[0], buffer[1]);

  if (write(platformWrite, buffer, length) != length){
	ROS_INFO("Drive, Failed to write to the I2C Bus.\n");	//ERROR HANDLING: i2c transaction failed
	return 0;
  }
	flush_buffer();
return 1;
}

int generate_bucket_msg(){

        if(last_bucket_msg.dump > 0){
                // Go Up , Dump
                buffer[0] = 5;
        }
        if(last_bucket_msg.dump < 0){
               // Go Down, Return to Normal Mode
                buffer[0] = 6;
        }

	//scale motor pwm values to 0-255
	//sign is handled in direction byte, so take absolute value
        char dump = (char) (abs(last_bucket_msg.dump*255.0));
        buffer[1] = dump ;	// Dumping Speed
	buffer[2] = 0;
	buffer[3] = 0;

if (write(platformWrite, buffer, length) != length){
	ROS_INFO("Hopper, Failed to write to the I2C Bus.\n");	//ERROR HANDLING: i2c transaction failed
	return 0;
  }
	flush_buffer();
return 1;
}

int generate_ladder_msg(){

        if(last_ladder_msg.lift > 0){
                //
                buffer[0] = 7;
        }
        if(last_ladder_msg.lift < 0){
                //
                buffer[0] = 8;
        }
        if(last_ladder_msg.conv > 0){
                //
                buffer[0] = 9;
        }
        if(last_ladder_msg.conv < 0){
                //
                buffer[0] = 10;
        }
        //scale motor pwm values to 0-255
        //sign is handled in direction byte, so take absolute value
        char lift = (char) (abs(last_ladder_msg.lift*255.0));
        char conv = (char) (abs(last_ladder_msg.conv*255.0));
        buffer[1] = lift;
        buffer[2] =  conv;
	buffer[3] = 0;

if (write(platformWrite, buffer, length) != length){
	ROS_INFO("Ladder/Mine, Failed to write to the I2C Bus.\n");	//ERROR HANDLING: i2c transaction failed
	return 0;
  }
	flush_buffer();
return 1;
}

int main(int argc, char** argv){
	ros::init(argc, argv, "robot_control_node");
	ros::NodeHandle nh;

	//Subscribe to motor value messages
	drive_sub = nh.subscribe("drive_vals", 10, driveSubCallback);
	bucket_sub = nh.subscribe("bucket_vals", 10, bucketSubCallback);
	ladder_sub = nh.subscribe("ladder_vals", 10, ladderSubCallback);
	i2c_pub = nh.advertise<shared_files::WriteI2C>("write_i2c", 100);

	ros::Duration motor_update_rate(.25);
	ros::Time curr_time = ros::Time::now();
//	ros::spinOnce();
	if (platformWrite == -1){//sensorRead == -1){
		ROS_INFO("Error: Could not connect to Arduino!");
	}

	while(ros::ok()){
		//constantly check if we need to write new messages
		//if we do, check if the message is recent
		//convert the motor message to an I2C message if it is recent, and publish
		//else, write an I2C message of 0's to stop the motors

		//start with drive message
		curr_time = ros::Time::now();
		if(curr_time - last_drive_pub_time > motor_update_rate){
			//it's time to update the motors
			//check if we've received a motor_msg recently
			if(curr_time - last_drive_sub_time > motor_update_rate){
				//the last drive msg has expired
				//send a message to stop Teensy 3.1 motors
			//	generate_stop_msg(5);
				generate_stop_msg(6);
				last_drive_pub_time = ros::Time::now();
			}else{
				//the last drive msg is recent enough to send
				generate_drive_msg();
			/*
				shared_files::WriteI2C i2c_msg;
				i2c_msg.addr = 6;
				i2c_msg.data.push_back(buffer[0]);
				i2c_msg.data.push_back(buffer[1]);
				i2c_msg.data.push_back(buffer[2]);
				i2c_msg.data.push_back(buffer[3]);
				i2c_pub.publish(i2c_msg);
			*/
				last_drive_pub_time = ros::Time::now();
			}
		}

		//handle bucket message
		curr_time = ros::Time::now();
		if(curr_time - last_bucket_pub_time > motor_update_rate){
			//it's time to update bucket motors
			//check if we've received a bucket msg recently
			if(curr_time - last_bucket_sub_time > motor_update_rate){
				//last message has expired
				//send a stop message to the Mega (address 2)
			//	generate_stop_msg(5);
				generate_stop_msg(6);
				last_bucket_pub_time = ros::Time::now();
			}else{
				//the last message is recent enough to send
				generate_bucket_msg();
				last_bucket_pub_time = ros::Time::now();
			}
		}

		//handle ladder message
		curr_time = ros::Time::now();
                if(curr_time - last_ladder_pub_time > motor_update_rate){
                        //it's time to update ladder motors
                        //check if we've received a ladder msg recently
                        if(curr_time - last_ladder_sub_time > motor_update_rate){
                                //last message has expired
                                //send a stop message to the Mega (address 2)
                          //      generate_stop_msg(5);
				generate_stop_msg(6);
                                last_ladder_pub_time = ros::Time::now();
                        }else{
                                //the last message is recent enough to send
                                generate_ladder_msg();
                                last_ladder_pub_time = ros::Time::now();
                        }
                }

		ros::spinOnce();
	}
}
