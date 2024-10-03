#include "libraryBook.h"



LibraryBook::LibraryBook() {}
LibraryBook::LibraryBook(string tit, string auth, string IS, bool che) : title(tit), author(auth), ISBN(IS), check(che = false) {}