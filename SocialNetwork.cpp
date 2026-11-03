#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
	this->networkName = networkName;
	this->minAge = minAge;
}
void SocialNetwork::clear()
{
	profiles.clear();
}
std::string SocialNetwork::getNetworkName() const
{
	return this->networkName;
}
int SocialNetwork::getMinAge() const
{
	return this->minAge;
}
bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() > this->getMinAge())
	{
		this->profiles.add(profile_to_add);
		return true;
	}
	return false;
}
std::string SocialNetwork::getWindowsDevices() const
{
	ProfileNode *head = this->profiles.get_first();
	DeviceNode* node;
	std::string result = "";
	while (head != nullptr)
	{
		node = head->get_data().getOwner().getDevices().get_first();
		while (node != nullptr)
		{
			if (node->get_data().getOS().find("Windows") != std::string::npos) // if windows is found in the os
			{
				result += "[" + std::to_string(node->get_data().getID()) + ", " + node->get_data().getOS() + "], ";
			}
			node = node->get_next();
		}
		head = head->get_next();
	}
	result.pop_back();
	result.pop_back();
	return result;
}