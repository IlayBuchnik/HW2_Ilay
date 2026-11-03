#include "Page.h"

void Page::init()
{
	this->status = "";
	this->posts = "";
}
void Page::clearPage()
{
	this->posts = "";
}
void Page::setStatus(std::string status)
{
	this->status = status;
}
void Page::addLineToPosts(std::string new_line)
{
	this->posts += new_line + '\n';
}
std::string Page::getPosts() const
{
	return this->posts;
}
std::string Page::getStatus() const
{
	return this->status;
}