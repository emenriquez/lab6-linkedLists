#include <iostream>
#include <string>
#include <cassert>
#include "LLStack.cpp"

using namespace std;

// Simple test framework
int total_tests = 0;
int passed_tests = 0;

void test_assert(bool condition, const string& test_name) {
    total_tests++;
    if (condition) {
        cout << "✓ PASS: " << test_name << endl;
        passed_tests++;
    } else {
        cout << "✗ FAIL: " << test_name << endl;
    }
}

void print_test_summary() {
    cout << "\n" << string(50, '=') << endl;
    cout << "Test Summary: " << passed_tests << "/" << total_tests << " tests passed" << endl;
    if (passed_tests == total_tests) {
        cout << "🎉 All tests passed! Great job!" << endl;
    } else {
        cout << "❌ Some tests failed. Keep working on your implementation!" << endl;
    }
    cout << string(50, '=') << endl;
}

void test_constructor() {
    cout << "\nTesting Constructor..." << endl;
    
    LLStack stack;
    test_assert(stack.size() == 0, "Constructor - size should be 0");
    test_assert(stack.top() == "", "Constructor - top should return empty string");
}

void test_push_single() {
    cout << "\nTesting Push (single item)..." << endl;
    
    LLStack stack;
    stack.push("hello");
    
    test_assert(stack.size() == 1, "Push single - size should be 1");
    test_assert(stack.top() == "hello", "Push single - top should be 'hello'");
}

void test_push_multiple() {
    cout << "\nTesting Push (multiple items)..." << endl;
    
    LLStack stack;
    stack.push("first");
    stack.push("second");
    stack.push("third");
    
    test_assert(stack.size() == 3, "Push multiple - size should be 3");
    test_assert(stack.top() == "third", "Push multiple - top should be 'third' (LIFO)");
}

void test_pop_empty() {
    cout << "\nTesting Pop (empty stack)..." << endl;
    
    LLStack stack;
    
    // Should not crash when popping empty stack
    try {
        stack.pop();
        stack.pop(); // Try multiple times
        test_assert(true, "Pop empty - should not crash");
        test_assert(stack.size() == 0, "Pop empty - size should remain 0");
        test_assert(stack.top() == "", "Pop empty - top should remain empty string");
    } catch (...) {
        test_assert(false, "Pop empty - should not throw exception");
    }
}

void test_pop_single() {
    cout << "\nTesting Pop (single item)..." << endl;
    
    LLStack stack;
    stack.push("only");
    stack.pop();
    
    test_assert(stack.size() == 0, "Pop single - size should be 0 after pop");
    test_assert(stack.top() == "", "Pop single - top should be empty after pop");
}

void test_pop_multiple() {
    cout << "\nTesting Pop (multiple items)..." << endl;
    
    LLStack stack;
    stack.push("first");
    stack.push("second");
    stack.push("third");
    stack.push("fourth");
    
    // Pop and check LIFO order
    test_assert(stack.top() == "fourth", "Pop multiple - top should be 'fourth' before pop");
    stack.pop();
    test_assert(stack.size() == 3, "Pop multiple - size should be 3 after first pop");
    test_assert(stack.top() == "third", "Pop multiple - top should be 'third' after first pop");
    
    stack.pop();
    test_assert(stack.size() == 2, "Pop multiple - size should be 2 after second pop");
    test_assert(stack.top() == "second", "Pop multiple - top should be 'second' after second pop");
    
    stack.pop();
    test_assert(stack.size() == 1, "Pop multiple - size should be 1 after third pop");
    test_assert(stack.top() == "first", "Pop multiple - top should be 'first' after third pop");
    
    stack.pop();
    test_assert(stack.size() == 0, "Pop multiple - size should be 0 after final pop");
    test_assert(stack.top() == "", "Pop multiple - top should be empty after final pop");
}

void test_mixed_operations() {
    cout << "\nTesting Mixed Operations..." << endl;
    
    LLStack stack;
    
    // Push some items
    stack.push("A");
    stack.push("B");
    test_assert(stack.size() == 2, "Mixed - size should be 2 after 2 pushes");
    
    // Pop one
    stack.pop();
    test_assert(stack.size() == 1, "Mixed - size should be 1 after pop");
    test_assert(stack.top() == "A", "Mixed - top should be 'A' after pop");
    
    // Push more
    stack.push("C");
    stack.push("D");
    test_assert(stack.size() == 3, "Mixed - size should be 3 after more pushes");
    test_assert(stack.top() == "D", "Mixed - top should be 'D'");
    
    // Pop all
    stack.pop(); // Remove D
    stack.pop(); // Remove C
    stack.pop(); // Remove A
    test_assert(stack.size() == 0, "Mixed - size should be 0 after popping all");
    test_assert(stack.top() == "", "Mixed - top should be empty after popping all");
}

void test_stress() {
    cout << "\nTesting Stress (many operations)..." << endl;
    
    LLStack stack;
    
    // Push many items
    for (int i = 0; i < 100; i++) {
        stack.push("item" + to_string(i));
    }
    
    test_assert(stack.size() == 100, "Stress - size should be 100 after 100 pushes");
    test_assert(stack.top() == "item99", "Stress - top should be 'item99'");
    
    // Pop half
    for (int i = 0; i < 50; i++) {
        stack.pop();
    }
    
    test_assert(stack.size() == 50, "Stress - size should be 50 after 50 pops");
    test_assert(stack.top() == "item49", "Stress - top should be 'item49'");
    
    // Pop all remaining
    for (int i = 0; i < 50; i++) {
        stack.pop();
    }
    
    test_assert(stack.size() == 0, "Stress - size should be 0 after popping all");
    test_assert(stack.top() == "", "Stress - top should be empty after popping all");
}

int main() {
    cout << "🔗 Linked List Stack - Unit Tests" << endl;
    cout << string(50, '=') << endl;
    cout << "Complete the methods in LLStack.cpp to make all tests pass!" << endl;
    
    // Run all tests
    test_constructor();
    test_push_single();
    test_push_multiple();
    test_pop_empty();
    test_pop_single();
    test_pop_multiple();
    test_mixed_operations();
    test_stress();
    
    // Print final summary
    print_test_summary();
    
    return (passed_tests == total_tests) ? 0 : 1;
}
