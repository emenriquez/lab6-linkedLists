// test file - do not modify
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <ctime>
#include <iostream>
using namespace std;

#include "Lab5.cpp"

void createHistory(string inAddress) {
    BrowserHistory history(inAddress);
}

TEST_CASE("Stack") {
    Stack tacoStack;

    CHECK_NOTHROW(tacoStack.empty());
};

TEST_CASE("push") {
    Stack tacoStack;
    CHECK(tacoStack.empty());

	CHECK_NOTHROW(tacoStack.push("bacon"));
	tacoStack.push("chorizo");
	tacoStack.push("huevo");
    CHECK(tacoStack.getNumItems() == 3);
	tacoStack.push("foqua");
	tacoStack.push("queue");
	tacoStack.push("stack");
	tacoStack.push("brisket");
    CHECK(tacoStack.getNumItems() == 7);
}

TEST_CASE("getNumItems") {
    Stack tacoStack;
    CHECK(tacoStack.getNumItems() == 0);
}

TEST_CASE("pop") {
    Stack tacoStack;
    CHECK(tacoStack.empty());

	CHECK_NOTHROW(tacoStack.push("bacon"));
	tacoStack.push("chorizo");
	tacoStack.push("huevo");
    CHECK(tacoStack.getNumItems() == 3);
	tacoStack.push("foqua");
	tacoStack.push("queue");
	tacoStack.push("stack");
	tacoStack.push("brisket");
    CHECK(tacoStack.getNumItems() == 7);
    CHECK_FALSE(tacoStack.empty());

    CHECK(tacoStack.pop() == "brisket");
    CHECK(tacoStack.pop() == "stack");
    CHECK(tacoStack.pop() == "queue");
    
    // empty the stack
    tacoStack.pop();
    tacoStack.pop();
    tacoStack.pop();
    tacoStack.pop();
    CHECK(tacoStack.getNumItems() == 0);
    CHECK(tacoStack.empty());
}

TEST_CASE("BrowserHistory") {
    CHECK_NOTHROW(createHistory("aol.com"));
}

TEST_CASE("getCurrentPage") {
    BrowserHistory history("aol.com");
    BrowserHistory history2("gooogle.com");

    CHECK(history.getCurrentPage() == "aol.com");
    CHECK(history2.getCurrentPage() == "gooogle.com");
}

TEST_CASE("goToPage") {
    BrowserHistory history("aol.com");
    BrowserHistory history2("gooogle.com");

    history.goToPage("news.com");
    history2.goToPage("movies.com");
    CHECK(history.getCurrentPage() == "news.com");
    CHECK(history2.getCurrentPage() == "movies.com");
}

TEST_CASE("goBack") {
    BrowserHistory history("aol.com");
    BrowserHistory history2("gooogle.com");

    history.goToPage("news.com");
    history2.goToPage("movies.com");
    history.goToPage("netflix.com");
    history2.goToPage("utrgv.edu");

    history.goBack();
    history2.goBack();

    CHECK(history.getCurrentPage() == "news.com");
    CHECK(history2.getCurrentPage() == "movies.com");

    history.goBack();
    history2.goBack();

    CHECK(history.getCurrentPage() == "aol.com");
    CHECK(history2.getCurrentPage() == "gooogle.com");

    CHECK_NOTHROW(history.goBack());
    CHECK_NOTHROW(history.goBack());
    CHECK_NOTHROW(history.goBack());
    CHECK_NOTHROW(history.goBack());


}

TEST_CASE("canGoBack") {
    BrowserHistory history("aol.com");
    BrowserHistory history2("gooogle.com");

    CHECK_FALSE(history.canGoBack());
    CHECK_FALSE(history2.canGoBack());

    history.goToPage("news.com");
    history2.goToPage("movies.com");

    CHECK(history.canGoBack());
    CHECK(history2.canGoBack());

    history.goBack();
    history2.goBack();

    CHECK_FALSE(history.canGoBack());
    CHECK_FALSE(history2.canGoBack());
}

TEST_CASE("historyLength") {
    BrowserHistory history("aol.com");
    BrowserHistory history2("gooogle.com");

    CHECK(history.historyLength() == 0);
    CHECK(history2.historyLength() == 0);

    history.goToPage("news.com");
    history2.goToPage("movies.com");
    history.goToPage("netflix.com");
    history2.goToPage("utrgv.edu");
    history2.goToPage("utrgv.edu");

    CHECK(history.historyLength() == 2);
    CHECK(history2.historyLength() == 3);

    history.goBack();
    history2.goBack();

    CHECK(history.historyLength() == 1);
    CHECK(history2.historyLength() == 2);
}