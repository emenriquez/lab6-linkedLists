// test file - do not modify
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <ctime>
#include <iostream>
using namespace std;

#include "LLStack.cpp"

LLStack test;

TEST_CASE("LLStack") {
    CHECK_NOTHROW(test);
}

TEST_CASE("top") {
    CHECK(test.top() == "");
}

TEST_CASE("size") {
    CHECK(test.size() == 0);
}

TEST_CASE("push") {
    CHECK_NOTHROW(test.push("hello"));
    CHECK(test.top() == "hello");
    CHECK(test.size() == 1);

    // Add more items
    test.push("here");
    test.push("goes");
    test.push("test");
    test.push("another");

    // check size
    CHECK(test.size() == 5);
}

TEST_CASE("pop") {
    LLStack test2;
    // quick test
    CHECK_NOTHROW(test2.pop());

    // One item
    test2.push("hello");
    test2.pop();
    CHECK(test2.size() == 0);

    // Add more items
    test2.push("here");
    test2.push("goes");
    test2.push("test2");
    test2.push("another");

    CHECK(test2.size() == 4);
    CHECK(test2.top() == "another");
    test2.pop();
    CHECK(test2.size() == 3);
    CHECK(test2.top() == "test2");
    test2.pop();
    CHECK(test2.size() == 2);
    CHECK(test2.top() == "goes");
    test2.pop();
    CHECK(test2.size() == 1);
    CHECK(test2.top() == "here");
    test2.pop();
    CHECK(test2.size() == 0);
    CHECK(test2.top() == "");

    // Should not fail when trying to pop additional items
    CHECK_NOTHROW(test2.pop());
    CHECK_NOTHROW(test2.pop());
    CHECK_NOTHROW(test2.pop());
}