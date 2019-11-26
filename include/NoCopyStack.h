#pragma once
#include <utility>

template <typename T>
struct NoCopyNode
{
	T value;
	NoCopyNode<T>* prev;
};

template <typename T>
class NoCopyStack
{
private:
	NoCopyNode<T>* top_elem = nullptr;
public:
    NoCopyStack()= default;
    NoCopyStack(const NoCopyStack &NoCopyStack)= delete; // no copy
    NoCopyStack(NoCopyStack&& NoCopyStack)= default; // constructable move
    auto operator=(NoCopyStack&& NoCopyStack) noexcept ->class NoCopyStack& = default; // assignable move

	template <typename ... Args>
	void push_emplace(Args&&... value);
	void push(T&& value);
	const T& head() const;
	T pop();
};

template<typename T>
template<typename ...Args>
inline void NoCopyStack<T>::push_emplace(Args && ...value)
{
	auto* curr = top_elem;
	//top_elem = new NoCopyNode<T>;
    top_elem = new NoCopyNode<T>{{std::forward<Args>(value)...}, curr};
//	top_elem->value = std::move({ std::forward<Args>(value)... });
}

template<typename T>
inline void NoCopyStack<T>::push(T && value)
{
	auto* curr = top_elem;
	top_elem = new NoCopyNode<T>{std::forward<T>(value), curr};
//	top_elem->value = std::move(value);
//	top_elem->prev = curr;
}

template<typename T>
const T & NoCopyStack<T>::head() const
{
	return top_elem->value;
}

template<typename T>
T NoCopyStack<T>::pop()
{
	T value = top_elem->value;
	top_elem = top_elem->prev;

	return value;
}
