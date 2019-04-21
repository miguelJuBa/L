#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch.hpp>
#include <L.hpp>

TEST_CASE("Test standard logger output")
{
    Logger::L L;
    std::ostringstream output;
    L.setLevel("ERROR");
    L.setChannel(&output);
    L.t("Filtered out");
    REQUIRE(output.str().length() == 0);
    L.setLevel("TRACE");
    L.t("Hello world");
    REQUIRE(output.str().length() > std::string("Hello World").length());
    REQUIRE(output.str() != "");
}
