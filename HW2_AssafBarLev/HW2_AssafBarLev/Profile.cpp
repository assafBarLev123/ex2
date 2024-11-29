#include "Profile.h"
#include "User.h"
#include "UserList.h"
#include "Page.h"



void Profile::init(User owner)
{
	this->_owner = owner;
	this->_friendsList = new UserList;
	this->_friendsList->set_first(nullptr);
	this->_page = new Page;
}

void Profile::clear()
{
	this->_friendsList->clear();
	delete this->_friendsList;
	this->_page->clearPage();
	delete this->_page;
}

User Profile::getOwner() const
{
	return this->_owner;
}

void Profile::setStatus(std::string new_status)
{
	this->_page->setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	this->_page->addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	this->_friendsList->add(friend_to_add);
}

std::string Profile::getPage() const
{
	std::string page = "Status: " + this->_page->getStatus() + "\n";
	page += "*******************\n*******************";
	page += this->_page->getPosts() + "\n";
	return page;
}

std::string Profile::getFriends() const
{
	std::string friends = "";
	UserNode* cur = this->_friendsList->get_first();
	while (cur->get_next() != NULL)
	{
		friends += cur->get_data().getUserName() + ",";
		cur = cur->get_next();
	}
	friends += cur->get_data().getUserName();
	return friends;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	int i = 0;
	std::string friends = "";
	unsigned int size = this->_owner.getUserName().length();
	UserNode* cur = this->_friendsList->get_first();
	while (cur->get_next() != NULL)
	{
		if (cur->get_data().getUserName().length() == size)
		{
			if (i != 0)
				friends += ",";
			friends += cur->get_data().getUserName();
			i++;
		}
		cur = cur->get_next();
	}
	return friends;
}