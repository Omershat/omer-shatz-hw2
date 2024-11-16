#pragma once

#include <string>
#include "DeviceList.h"

class User
{
public:
	// methods
	void init(const unsigned int id, const std::string username, const unsigned int age); // init the user
	void clear(); // clear user
	unsigned int getID() const; // get user id
	std::string getUserName() const; // get user name
	unsigned int getAge() const; // get user age
	DevicesList& getDevices(); // get devices from user
	void addDevice(const Device newDevice); // add device to user
	bool checkIfDevicesAreOn() const; // check if all devices are on

private:
	// fields
	unsigned int _id; // user id
	std::string _username; // username
	unsigned int _age; // user age
	DevicesList _devices; // user devices
};

