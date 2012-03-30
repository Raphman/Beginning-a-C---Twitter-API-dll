#pragma once
#include <iostream>
#include <stdlib.h>
#using <mscorlib.dll>
#include <string>
#using "System.dll"
#using "System.Xml.dll"

class TwitterAPI
{

public:
	static _declspec(dllexport) void GetStatus();
};