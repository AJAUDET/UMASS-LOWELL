#include "Template.hpp"

// template prefix needed for all member funcitions
template <class T>
Pair<T>::Pair()
{
    // T{} initialization value
    first = T{};
    second = T{};
}

template <class T>
Pair<T>::Pair(T new_first, T new_second)
{
    first = new_first;
    second = new_second;
}

// getters and setters
template <class T>
T Pair<T>::get_first(void) const
{
    return first;
}

template <class T> 
T Pair<T>::get_second(void) const
{
    return second;
}

template <class T>
void Pair<T>::set_first(T new_first)
{
    first = new_first;
}

template <class T>
void Pair<T>::set_second(T new_second)
{
    second = new_second;
}

template <typename T>
ostream& operator<<(ostream& out, const Pair<T>& pair)
{
    out << pair.get_first();
    out << ", ";
    out << pair.get_second();
    return out;
}

template <typename T>
T addUp(const Pair<T>& aPair)
{
    return aPair.get_first() + aPair.get_second();
}