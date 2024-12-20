#include "Device.h"


void Device::init(const unsigned int id, const DeviceType type, const std::string os)
{
	this->_id = id;
	this->_type = type;
	this->_os = os;
	activate(); 
}


unsigned int Device::getID() const
{
	return this->_id;
}


DeviceType Device::getType() const
{
	return this->_type;
}


std::string Device::getOS() const
{
	return this->_os;

}


bool Device::isActive() const
{
	return this->_active;
}


void Device::activate()
{
	this->_active = true;
}


void Device::deactivate()
{
	this->_active = false;
}
