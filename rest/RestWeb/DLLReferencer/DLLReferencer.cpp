// DLLReferencer.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include "twitterAPI.h"
using namespace std;

int main()
{
	TwitterAPI::GetStatus();
	cin.get();
	return 0;
}