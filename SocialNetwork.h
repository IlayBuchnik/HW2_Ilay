#pragma once
#include <string>
#include "ProfileList.h"
class SocialNetwork
{
private:
	std::string networkName;
	int minAge;
	ProfileList profiles;
public:
	void init(std::string networkName, int minAge);
	void clear();
	std::string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices() const;

};