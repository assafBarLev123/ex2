#include "SocialNetwork.h"
#include "string"
//std::string SocialNetwork::getWindowsDevices();

std::string SocialNetwork::getNetworkName()
{
	return this->_networkName;
}

int SocialNetwork::getMinAge()
{
	return this->_minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < this->_minAge)
	{
		return false;
	}
	this->_profiles->add(profile_to_add);
	return true;
}

void SocialNetwork::init(std::string networkName, int minAge)
{
	this->_networkName = networkName;
	this->_minAge = minAge;
	this->_profiles = new ProfileList;
	this->_profiles->init();
}

void SocialNetwork::clear()
{
	this->_networkName = "";
	this->_minAge = 0;
	this->_profiles->clear();
	delete this->_profiles;
}

std::string SocialNetwork::getWindowsDevices()
{
	std::string temp = "";
	if (this->_profiles != NULL)
	{
		int i = 0;
		ProfileNode* tempList = this->_profiles->get_first();
		DeviceNode* tempDevNode = NULL;
		while (tempList != NULL)
		{
			tempDevNode = tempList->get_data().getOwner().getDevices().get_first();
			while (tempDevNode != NULL)
			{
				if (tempDevNode->get_data().getOS() == WINDOWS7 || tempDevNode->get_data().getOS() == WINDOWS10 || tempDevNode->get_data().getOS() == WINDOWS11)
				{
					if (i != 0)
						temp += ",";
					temp += "[" + std::to_string(tempDevNode->get_data().getID()) + "," + tempDevNode->get_data().getOS() + "]";
					i++;
				}
				tempDevNode = tempDevNode->get_next();
			}
			tempList = tempList->get_next();
		}
	}
	return temp;
}