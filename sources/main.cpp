// lab05_stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "../include/Stack.h"
#include "../include/NoCopyStack.h"

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

int main()
{
	Stack<int> stack;
	const int a = 5;
    int x=55;
    
	stack.push(a);
	stack.push(3);
	std::cout << "before pop top: " << stack.head() << std::endl;
	stack.pop();
	std::cout << "after pop top: " << stack.head() << std::endl;

	NoCopyStack <Point> NC_stack;
	NC_stack.push_emplace(3, 4);
	NC_stack.push_emplace(Point(5, 6));
	NC_stack.push(Point(7,8));
	NC_stack.push(Point(9, 10));

	std::cout << NC_stack.head().x << ": " << NC_stack.pop().x << "-" << NC_stack.pop().x << std::endl;
	std::cout << NC_stack.head().y << ": " << NC_stack.pop().y << "-" << NC_stack.pop().y << std::endl;
}
