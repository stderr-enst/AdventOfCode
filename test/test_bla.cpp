#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "bla.h"

TEST_CASE("Test bla zero") {
    auto b = BLA{};
    CHECK(b.getI() == 15);
}
