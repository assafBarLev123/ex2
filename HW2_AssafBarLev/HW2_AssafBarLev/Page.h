#pragma once
#include <string>

class Page
{
	public:
		//getters:
		std::string getPosts() const;
		std::string getStatus() const;

		void clearPage();
		void setStatus(std::string status);
		void addLineToPosts(std::string neLine);
		void init();

	private:
		std::string status;
		std::string posts;
};
