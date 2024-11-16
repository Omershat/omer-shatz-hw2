
#include "SocialNetwork.h"

void SocialNetwork::init(const std::string networkName, const int minAge)
{
	this->_networkName = networkName;
	this->_minAge = minAge;
	this->_profileList.init();
}


std::string SocialNetwork::getNetworkName() const
{
	return this->_networkName;
}

int SocialNetwork::getMinAge() const
{
	return this->_minAge;
}

bool SocialNetwork::addProfile(const Profile profile_to_add)
{
	return this->_profileList.add(profile_to_add);


}


std::string SocialNetwork::getWindowsDevices()
{
	ProfileNode* profile = this->_profileList.get_first();
	DeviceNode* device = profile->get_data().getOwner().getDevices().get_first();
	std::string os = device->get_data().getOS(); 
	std::string windowsDevices = "";


	while (profile)
	{
		windowsDevices += getDevicesFromProfile(device);
		profile = profile->get_next();

		if (profile) 
		{
			device = profile->get_data().getOwner().getDevices().get_first();
		}

	return returnAllButLast(windowsDevices);
	}

}



