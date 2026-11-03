#include "User.h"
void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->id = id;
	this->username = username;
	this->age = age;
	this->list.init();
}
void User::clear()
{
	this->username.clear();
	this->list.clear();
	this->age = 0;
	this->id = 0;
}
unsigned int User::getID() const
{
	return this->id;
}
std::string User::getUserName() const
{
	return this->username;
}
unsigned int User::getAge() const
{
	return this->age;
}
DevicesList& User::getDevices()
{
	return this->list;
}
void User::addDevice(Device newDevice)
{
	this->list.add(newDevice);
}
bool User::checkIfDevicesAreOn() const
{
	DeviceNode *device = this->list.get_first();
	if (device == nullptr)
	{
		return false;
	}
	while (true)
	{
		if (device == nullptr) // if we got to the end of the list without any of them being deactivated then return true
		{
			return true;
		}
		if (!device->get_data().isActive())
		{
			return false;
		}
		device = device->get_next();
	}
}