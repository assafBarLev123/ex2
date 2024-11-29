#pragma once
#include <string>
#include "DeviceList.h"
class User
{
	public:
		//getters:
		unsigned int getID() const;
		std::string getUserName() const;
		unsigned int getAge() const;
		DevicesList& getDevices();

		void addDevice(Device newDevice);
		bool checkIfDevicesAreOn() const;
		void init(const unsigned int id, const std::string username, const unsigned int age);
		void clear();

	private:
		unsigned int _id;
		std::string _username;
		unsigned int _age;
		DevicesList _devices;
};