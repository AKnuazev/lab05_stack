#pragma once
#include <exception>

template <typename T>
struct Node
{
	T value;
	Node<T>* prev;
};

template <typename T>
class Stack
{
private:
	Node<T>* top_elem = nullptr;
public:
    Stack()= default;
    Stack(const Stack &stack)= delete; // no copy
    Stack(Stack&& stack)= default; // constructable move
    auto operator=(Stack&& stack) noexcept ->class Stack& = default; // assignable move

	void push(T&& value);
	void push(const T& value);
	void pop();
	const T& head() const;
};

template<typename T>
void Stack<T>::push(T && value)
{
	if (!top_elem) // No elements
	{
		top_elem = new Node<T>;
		top_elem->value = value;
		top_elem->prev = nullptr;
	}
	else
	{
		Node<T> *curr = new Node<T>;
		curr->value = top_elem->value;
		curr->prev = top_elem->prev;
		top_elem->value = value;
		top_elem->prev = curr;
	}
}

template<typename T>
void Stack<T>::push(const T & value)
{
	if (!top_elem) // No elements
	{
		top_elem = new Node<T>;
		top_elem->value = value;
		top_elem->prev = nullptr;
	}
	else
	{
		Node<T> *curr = new Node<T>;
		curr->value = top_elem->value;
		curr->prev = top_elem->prev;
		top_elem->value = value;
		top_elem->prev = curr;
	}
}

template<typename T>
void Stack<T>::pop()
{
	if (top_elem)
		top_elem = top_elem->prev;
	else
		throw std::exception();
}

template<typename T>
const T & Stack<T>::head() const
{
	return top_elem->value;
}