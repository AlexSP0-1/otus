#ifndef IPFUNCTIONS_H
#define IPFUNCTIONS_H

#include <iostream>
#include <vector>
#include <list>


namespace TypeTemplates
{

template<typename T>
using EnableIfIntegralType = std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>>;

template<typename T, template<typename> class Container>
using EnableIfContainerType = std::enable_if_t<std::is_same_v<Container<T>, std::vector<T>>
|| std::is_same_v<Container<T>, std::list<T>>>;

template<typename T>
using EnableIfStringType = std::enable_if_t<std::is_same_v<std::decay_t<T>, std::string>>;

template<typename T, typename ...Args>
using EnableIfAllTheSame = std::enable_if_t<std::conjunction_v<std::is_same<T, Args>...>>;

}

#endif //IPFUNCTIONS_H
