#include "Functions.h"




void loadBooks(vector<LibraryBook>& books) {
	ifstream inFile("books.txt");
	if (!inFile.is_open()) {
		cout << "file not open";
	}
	string line,title,author,ISBN;
	int num = 0;
	
	while (getline(inFile, line)) {
		if (num == 0) { 
			title = line;
			num++;
		}
		else if (num == 1) { 
			author = line;
			num++;
		}
		else if (num == 2) {
			ISBN = line;
			num++;
			LibraryBook tempB(title, author, ISBN);
			books.push_back(tempB);
			num = 0;
		}
		
	}
	inFile.close();
}

int findBook(vector<LibraryBook>& books, string isbn) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getISBN() == isbn) {
			return i;
		}
	}
	return -1;
}



void adjustBooks(vector<LibraryBook>& books) {
	ifstream inFile("isbns.txt");
	string line;
	int bookplace;
	bool isout;
	while (getline(inFile, line)) {
		bookplace = findBook(books, line);
		if (bookplace != -1) {
			isout = books[bookplace].isCheckedOut();
			if (isout) { books[bookplace].checkIn(); }
			else { books[bookplace].checkOut(); }
		}
	}
	inFile.close();
}


void printReport(vector<LibraryBook>& books) {
	ofstream outFile("checkedout.txt");

	outFile << "Books checked out :" << endl;
	outFile << "-----------------------------------------------------------------------------------------" << endl;
	outFile << setw(60) << left << "Title" << setw(19) << left << "Author" << setw(11) << left << "ISBN" << endl;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].isCheckedOut()) {
			outFile << setw(60) << left << books[i].getTitle() << setw(19) << left << books[i].getAuthor() << setw(11) << left << books[i].getISBN() << endl;
		}
	}
	outFile.close();
}