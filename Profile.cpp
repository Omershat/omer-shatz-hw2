#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Profile.h"


// gets the user owner of the profile and init the page and the friend list
void Profile::init(const User owner) 

{

	this->_owner = owner;
	this->_page.init();
	this->_friendList.init();
}

void Profile::clear() 
{
	this->_page.clearPage();
	this->_friendList.clear();
}

User Profile::getOwner() const
{
	return this->_owner;
}

void Profile::setStatus(const std::string new_status)
{
	this->_page.setStatus(new_status);
}


void Profile::addPostToProfilePage(const std::string post)
{
	this->_page.addLineToPosts(post);
}


void Profile::addFriend(const User friend_to_add)
{
	this->_friendList.add(friend_to_add);
}

std::string Profile::getPage() const
{
	return "Status: " + this->_page.getStatus() + DEVIDER + this->_page.getPosts();
}


std::string Profile::getFriends() const
{
	UserNode* friendNode = this->_friendList.get_first();
	std::string friends = "";

	// loop while node is not null
	while (friendNode)
	{
		// add to friends string the current friend name + devider
		friends += friendNode->get_data().getUserName() + FRIENDS_DEVIDER;

		friendNode = friendNode->get_next();
	}

	// return all the friends wih out the devider at the end
	return returnAllButLast(friends);
}

// return the string without the last char 
std::string Profile::returnAllButLast(std::string str) const
{
	std::string newString = "";

	// check if string is not empty
	if (!str.empty()) {
		// remove last character
		newString = str.substr(0, str.size() - 1);
	}

	return newString;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	UserNode* friendNode = this->_friendList.get_first();
	std::string ownerName = this->_owner.getUserName();
	std::string friendName = "";
	std::string friends = "";

	// loop while friend node is not null
	while (friendNode)
	{
		// get friend name
		friendName = friendNode->get_data().getUserName();

		// check if the length of the names are equal
		if (ownerName.size() == friendName.size())
		{
			// add to the string
			friends += friendName + FRIENDS_DEVIDER;
		}

		// go to the next node
		friendNode = friendNode->get_next();
	}

	// return all the friends wih out the devider at the end
	return returnAllButLast(friends);
}
