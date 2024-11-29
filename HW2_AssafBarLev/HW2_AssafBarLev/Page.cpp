#include "Page.h"

//void Page::clearPage();
//void Page::setStatus(std::string status);
//void Page::addLineToPosts();

std::string Page::getPosts() const
{
	return this->posts;
}

std::string Page::getStatus() const
{
	return this->status;
}

void Page::init()
{
	this->posts = "";
	this->status = "";
}

void Page::clearPage()
{
	this->posts = "";
}

void Page::setStatus(std::string status)
{
	this->status = status;
}

void Page::addLineToPosts(std::string newLine)
{
	this->posts += "\n"+newLine;
}