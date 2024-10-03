#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "libraryBook.h"

void loadBooks(vector<LibraryBook>& books);

void adjustBooks(vector<LibraryBook>& books);

void printReport(vector<LibraryBook>& books);