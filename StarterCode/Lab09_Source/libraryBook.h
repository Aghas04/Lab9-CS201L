#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class LibraryBook {
protected:
	string title;
	string author;
	string ISBN;
	bool check;
public: 

	LibraryBook();
	LibraryBook(string tit, string auth, string IS, bool che = false);

	string getTitle() { return title; }
	string getAuthor() { return author; }
	string getISBN() { return ISBN; }
	bool isCheckedOut() { return check; }

	void setTitle(string tit) { title = tit; }
	void setAuthor(string auth) { author = auth; }
	void setISBN(string IS) { ISBN = IS; }
	void checkOut() { check = true; }
	void checkIn() { check = false; }
};