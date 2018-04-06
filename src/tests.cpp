#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../external/catch.hpp"
#include "L.hpp"

TEST_CASE("TEST EXAMPLE")
{
    Logger::L * L = new Logger::L();

    REQUIRE(1==1);
    REQUIRE(1==3);
    
    delete L;
}
