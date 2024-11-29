#include "Device.h"

//void Device::init(unsigned int id, DeviceType type, std::string os);

std::string Device::getOS() const
{
	return this->_os;
}

unsigned int Device::getID() const
{
	return this->_ID;
}

DeviceType Device::getType() const
{
	return this->_type;
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

void Device::init(const unsigned int id, const DeviceType type, const std::string os)
{
	this->_ID = id;
	this->_type = type;
	this->_os = os;
}