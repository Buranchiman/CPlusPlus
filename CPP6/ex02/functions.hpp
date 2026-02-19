#ifndef functions_HPP
#define functions_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
