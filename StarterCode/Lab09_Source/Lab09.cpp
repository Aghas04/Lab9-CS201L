#include <iostream>
#include <iomanip>
#include "libraryBook.h"
#include "Functions.h"
using namespace std;

int main() {

	vector<LibraryBook> books;
	loadBooks(books);
	
	adjustBooks(books);

	printReport(books);
}