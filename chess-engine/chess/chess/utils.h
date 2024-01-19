#pragma once
#include <stdio.h>

#define min(x, y)                                                                                  \
    ({                                                                                             \
        typeof(x) _x = (x), _y = (y);                                                              \
        _x < _y ? _x : _y;                                                                         \
    })

#define max(x, y)                                                                                  \
    ({                                                                                             \
        typeof(x) _x = (x), _y = (y);                                                              \
        _x > _y ? _x : _y;                                                                         \
    })

#define swap(x, y)                                                                                 \
    ({                                                                                             \
        typeof(x) _x = x;                                                                          \
        x = y;                                                                                     \
        y = _x;                                                                                    \
    })

#define between(value, min, max) (value < max && value > min)

#define assert(condition)                                                                          \
    do {                                                                                           \
        printf("assertion failed!");                                                               \
    } while (0);                                                                                   \
