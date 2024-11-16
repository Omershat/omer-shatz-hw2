#include "User.h"
#include "DeviceList.h"

//gets the id , username and age
void User::init(const unsigned int id, const std::string username, const unsigned int age)
{
	this->_id = id;
	this->_username = username;
	this->_age = age;
	this->_devices.init();
}

// reset id username and age
void User::clear()
{
	this->_id = 0;
	this->_username = "";
	this->_age = 0;
	this->_devices.clear();
}

// return the user id
unsigned int User::getID() const
{
	return this->_id;
}

// return the username
std::string User::getUserName() const
{
	return this->_username;
}

// return the user age
unsigned int User::getAge() const
{
	return this->_age;
}

// return the user device 
DevicesList& User::getDevices()
{
	return this->_devices;
}

// get a new device
void User::addDevice(const Device newDevice)
{
	this->_devices.add(newDevice);
}

// retrn if everything is on
bool User::checkIfDevicesAreOn() const
{
	DevicesList deviceList = this->_devices; // get the devices list
	DeviceNode* currentNode = deviceList.get_first(); // get current device

	// current device is not null
	while (currentNode)
	{
		// check if isnt active
		if (!currentNode->get_data().isActive())
		{
			
			return false;
		}

		
		currentNode = currentNode->get_next();
	}

	return true;
}

