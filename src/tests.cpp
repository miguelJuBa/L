#include <iostream>
#include <catch.hpp>
#include "L.hpp"

int main(int argc, char ** argv)
{
    Logger::L L;
    L.setLevel("TRACE");
    L.i("Testing log...");
    return 0;
}
