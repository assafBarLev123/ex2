#pragma once
#include "User.h"
#include "UserList.h"
#include "Page.h"
class Profile
{
	public:
		//getters:
		std::string getPage() const;
		std::string getFriends() const;
		std::string getFriendsWithSameNameLength() const;
		User getOwner() const;

		void init(User owner);
		void clear();
		void setStatus(std::string new_status);
		void addPostToProfilePage(std::string post);
		void addFriend(User friend_to_add);

	private:
		User _owner;
		Page* _page;
		UserList* _friendsList;
};
