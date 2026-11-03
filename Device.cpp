#include "Device.h"
#include <string>
void Device::init(unsigned int id, DeviceType type, std::string os)
{
	this->id = id;
	this->type = type;
	this->os = os;
	this->active = true;
}
unsigned int Device::getID() const
{
	return this->id;
}
DeviceType Device::getType() const
{
	return this->type;
}
void Device::activate()
{
	this->active = true;
}
void Device::deactivate()
{
	this->active = false;
}
std::string Device::getOS() const
{
	return this->os;
}
bool Device::getActive() const
{
	return this->active;
}
bool Device::isActive() const
{
	return this->active;
}