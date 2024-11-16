#pragma once

#include <string>

#include "User.h"
#include "Page.h"
#include "UserList.h"

#define DEVIDER "\n*******************\n*******************\n"
#define FRIENDS_DEVIDER ','

class Profile
{
public:
	
	void init(const User owner);
	void clear(); 
	User getOwner() const; 
	void setStatus(const std::string new_status); 
	void addPostToProfilePage(const std::string post); 
	void addFriend(const User friend_to_add); 
	std::string getPage() const; 
	std::string getFriends() const; 
	std::string getFriendsWithSameNameLength() const; 
	std::string returnAllButLast(std::string str) const; // return all of the string but the last characters

	
	

private:
	
	User _owner; 
	Page _page; 
	UserList _friendList; 
};


