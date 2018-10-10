#pragma once

#include <iostream>

#define DEBUG

#ifdef DEBUG
#define LOG_MESSAGE(_text) std::cout << __TIME__ << " MESSAGE: " << _text << std::endl
#define LOG_WARNING(_text) std::cout << "WARNING: " << _text << std::endl
#define LOG_ERROR(_text) std::cout << "ERROR: " << _text << std::endl
#endif