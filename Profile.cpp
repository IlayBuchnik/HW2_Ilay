#include "Profile.h"
void Profile::init(User owner)
{
	this->owner = owner;
	page.init();
	friends.init();
}
void Profile::clear()
{
	page.clearPage();
	friends.clear();
	owner.clear();
}
User Profile::getOwner() const
{
	return this->owner;
}
void Profile::setStatus(std::string new_status)
{
	this->page.setStatus(new_status);
}
void Profile::addPostToProfilePage(std::string post)
{
	this->page.addLineToPosts(post);
}
void Profile::addFriend(User friend_to_add)
{
	this->friends.add(friend_to_add);
}
std::string Profile::getPage() const
{
	return "Status: " + page.getStatus() + "\n" + "*******************" + "\n" + "*******************" + "\n" + page.getPosts();
}
std::string Profile::getFriends() const
{
	UserNode *temp = friends.get_first();
	bool first = true;
	std::string result = "";
	while (true)
	{
		if (temp == nullptr)
		{
			return result;
		}
		if (first)
		{
			result += temp->get_data().getUserName();
			first = false;
		}
		else
		{
			result += ',' + temp->get_data().getUserName();
		}
		temp = temp->get_next();
	}
}
std::string Profile::getFriendsWithSameNameLength() const
{
	std::string friends = this->getFriends(), ownName = this->owner.getUserName(), temp = "", result = "";
	int i, nameSize = ownName.size();
	bool first = true;
	for (i = 0; i < friends.size(); i++)
	{
		if (friends[i] == ',')
		{
			if (temp.size() == nameSize)
			{
				if (first)
				{
					result += temp;
					first = false;
				}
				else
				{
					result += ',' + temp;
				}
			}
			temp = "";
			continue;
		}
		temp += friends[i];
	}
	if (temp.size() == nameSize)
	{
		if (first)
		{
			result += temp;
		}
		else
		{
			result += ',' + temp;
		}
	}
	return result;
}