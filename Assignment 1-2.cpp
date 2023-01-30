// Assignment 1-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Kenneth Carr
// The objective of this program is to demonstrate performance testing and test driven development with stacks
// test performed with testing funtions
// speed bencharks put throughout the program for each task

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <time.h>

int STACK[100], TOP=-1;

void push(int[], int);
void pop(int[]);
int peek(int[]);
void display(int[]);
void test_funtions();
double test_max_size_array_speed(int);
void test_full_stack();

int main()
{
    clock_t start, stop;
    start = clock();
    test_funtions();
    stop = clock();
    display(STACK); // show the stack that was tested
    std::cout << "\nTotal funtional test run time = " << (stop - start) << "ms\n\n";
    std::cout << "Array build speed testing:\n";
    std::cout << "Array size 10 builds in " << test_max_size_array_speed(10) << "ms\n";
    std::cout << "Array size 100 builds in " << test_max_size_array_speed(100) << "ms\n";
    test_full_stack();
    stop = clock();
    std::cout << "\nTotal program run time: " << (stop - start) << "ms\n";
}

void push(int stack[], int item) {
    if (TOP < 100) {
        TOP++;
        stack[TOP] = item;
    }
    else {
        std::cout << "Stack is full\n\n";
    }
}

void pop(int stack[]) {
    int deleted_item;
    if (TOP == -1) {
        std::cout << "Stack is empty\n\n";
    }
    else
    {
        deleted_item = stack[TOP];
        TOP--;
        std::cout << deleted_item << "deleted\n\n";
    }
}

int peek(int stack[]) {
    return STACK[TOP];
}

void display(int stack[]) {
    std::cout << "\nStack:\n";
    for (int i = 0; i <= TOP; i++) {
        std::cout << STACK[i] << "\n";
    }
}

void test_funtions() { //validates basic funtionality of the stack operational funtions
    int test_0 = 0, test_1 = 1, test_2 = 15;
    clock_t start, stop;
    // initial test to ensure stack is empty feature is working.
    pop(STACK);
    // Test 1 tests for pushing 0 into the stack as first number and peek funtion
    start = clock();
    push(STACK, test_0);
    int top_peek = peek(STACK);
    if (top_peek == 0 && STACK[0] == 0) {
        stop = clock();
        std::cout << "Test 1 passed in " << (stop-start) << "ms" << "\n";
    }
    else
    {
        std::cout << "Test 1 failed\n";
        stop = clock();
    }
    // Test 2 tests the push funtion again with another number in the stack,verifies the top is the top when multiple numbers
    start = clock();
    push(STACK, test_1);
    top_peek = peek(STACK);
    if (top_peek == 1 && STACK[1] == 1) {
        stop = clock();
        std::cout << "Test 2 passed in " << (stop - start) << "ms" << "\n";
    }
    else { 
        std::cout << "Test 2 failed\n";
        stop = clock();
    }
    // Test 3 tests a number that isn't a edge case value
    start = clock();
    push(STACK, test_2);
    top_peek = peek(STACK);
    if (top_peek == test_2) {
        stop = clock();
        std::cout << "Test 3 passed in " << (stop - start) << "ms" << "\n";
    }
    else
    {
        std::cout << "Test 3 failed";
        stop = clock();
    }
}

double test_max_size_array_speed(int size) {
    clock_t start, stop;
    start = clock();
    for (int i = 0; i < size;  i++) {
        STACK[i] = i;
        TOP++;
    }
    stop = clock();
    double time_lapse = stop - start;
    return time_lapse;
}

void test_full_stack() {
    // test stack pop on full stack
    for (int i = 0; i < 100; i++) {
        STACK[i] = i;
        TOP++;
    }
    std::cout << "\nTest full stack:\n";
    push(STACK, 9);
}
