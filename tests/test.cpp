// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "../include/Stack.h"
#include "../include/NoCopyStack.h"
#include <exception>
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
};

TEST(Stack_Test,AddElem_Test)
{
    int a=5,b=8;
    Stack<int> stack;
    stack.push(a);
    stack.push(b);

    EXPECT_EQ(stack.head(),b);
    stack.pop();
    EXPECT_EQ(stack.head(),a);
    stack.pop();

    EXPECT_THROW(stack.pop(), std::exception);

    EXPECT_EQ(std::is_move_constructible<Stack<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<Stack<int>>::value, true);
    EXPECT_EQ(std::is_copy_constructible<Stack<int>>::value, false);
    EXPECT_EQ(std::is_copy_assignable<Stack<int>>::value, false);
}

TEST(NoCopyStack_Test, AddElem_Test)
{
    int x1=2,y1=4;
    int x2=3,y2=7;
    Point pnt(x1,y1);

    NoCopyStack<Point> stack;
    stack.push(Point(x1,y1));
    stack.push_emplace(x2,y2);

    EXPECT_EQ(stack.head().x,x2);
    stack.pop();
    EXPECT_EQ(stack.head().y,y1);

    EXPECT_EQ(std::is_move_constructible<NoCopyStack<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<NoCopyStack<int>>::value, true);
    EXPECT_EQ(std::is_copy_constructible<NoCopyStack<int>>::value, false);
    EXPECT_EQ(std::is_copy_assignable<NoCopyStack<int>>::value, false);
}

