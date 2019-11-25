// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "../include/Stack.h"
//#include "../include/NoCopyStack.h"
/*
class Point
{
public:
    int x;
    int y;

    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x1, int y1)
    {
        this->x = x1;
        this->y = y1;
    }
    Point(const Point& pnt)
    {
        this->x = pnt.x;
        this->y = pnt.y;
    }
};*/

TEST(Stack_Test,AddElem_Test)
{
    Stack<int> stack;
    stack.push(4);
    stack.push(5);
}
/*
TEST(NoCopyStack_Test, AddElem_Test)
{
    NoCopyStack<Point> stack;
    stack.push(Point(3,4));
    stack.push_emplace(5,6);
}*/

