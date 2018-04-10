# L

[![Build Status](https://travis-ci.org/miguelJuBa/L.svg?branch=master)](https://travis-ci.org/miguelJuBa/L)

## Introduction
A simple logger class used in my personal projects. 

## How to include in you project
Just add L.hpp to your project.

	 #include "L.hpp"

## Configuration
Configure class instance to meet your requirements: 

	 Logger::L L;
	 std::ostringstream output;
	 // Set trace level. Supported trace levels: "TRACE" as default, "INFO", "WARN", "ERROR", "FATAL"
	 L.setLevel("TRACE");
	 // Default channel is standard output
	 L.setChannel(&output);
	 
## How to use it
There is a method for every log level. Every method uses the first letter from the channel they are managing.

	L.t("This is a TRACE")
	L.i("This is a INFO")
	L.w("This is a WARNING")
	L.e("This is a ERROR")
	L.f("This is a FATAL")
	
Parameter concatenation is archieved adding comma sepparated parameters, supporting the basic C/C++ types and classes like string.

	int counter = 0;
	std::string str="MyString"
	L.i("Counter = ", counter, str);

## How to compile tests
1. Create a build directory and run cmake from there:
>mkdir build
>cd build
>cmake ..

2. Then just execute make command
> make
> ./tests
 

