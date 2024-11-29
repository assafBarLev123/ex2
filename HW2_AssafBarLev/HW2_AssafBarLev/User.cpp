#include "User.h"
#include <string>
#include "DeviceList.h"

//DevicesList& User::getDevices();
//
//void User::addDevice(Device newDevice);
//bool User::checkIfDevicesAreOn() const;

DevicesList& User::getDevices()
{
	DevicesList& temp = this->_devices;
	return temp;
}
unsigned int User::getID() const
{
	return this->_id;
}

std::string User::getUserName() const
{
	return this->_username;
}

unsigned int User::getAge() const
{
	return this->_age;
}

void User::addDevice(Device newDevice)
{
	this->_devices.add(newDevice);
}

void User::init(const unsigned int id, const std::string username, const unsigned int age)
{
	this->_id = id;
	this->_username = username;
	this->_age = age;
}

void User::clear()
{
	this->_devices.clear();
}

bool User::checkIfDevicesAreOn() const
{
	DeviceNode* temp = this->_devices.get_first();
	while (temp != NULL)
	{
		if (!(temp->get_data().isActive()))
		{
			return false;
		}
		temp = temp->get_next();
	}
	return true;
}