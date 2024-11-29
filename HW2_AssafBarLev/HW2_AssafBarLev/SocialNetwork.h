#pragma once
#include "string"
#include "Profile.h"
#include "ProfileList.h"

class SocialNetwork
{
	public:
		//getters:
		std::string getNetworkName();
		int getMinAge();
		std::string getWindowsDevices();

		bool addProfile(Profile profile_to_add);
		void init(std::string networkName, int minAge);
		void clear();

	private:
		std::string _networkName;
		ProfileList* _profiles;
		int _minAge;
};