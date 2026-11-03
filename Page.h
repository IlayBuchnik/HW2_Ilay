#pragma once
#include <string>
class Page
{
private:
	std::string status, posts;
public:
	void init();
	void clearPage();
	void setStatus(std::string status);
	void addLineToPosts(std::string new_line);
	std::string getPosts() const;
	std::string getStatus() const;
};