#pragma once

#include <string>

class Page
{
public:
	
	void init(); // init page
	std::string getPosts() const; // get posts from page
	std::string getStatus() const; // get status' from page
	void clearPage(); // clear page
	void setStatus(const std::string status); // set status of profile to something new
	void addLineToPosts(const std::string new_line); // add line to posts from page

private:
	
	std::string _status; // the status of page
	std::string _posts; // the posts of page
};


