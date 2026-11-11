#pragma once
#include <stdio.h>

#ifdef DEBUG
#define LOG(message) fprintf(stderr, "[DEBUG] %s: %i: %s\n", __FILE__, __LINE__, message)
#else
#define LOG(message)
#endif
