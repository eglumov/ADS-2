// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    while (n > 0) {
        result *= value;
        n--;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i <= count; ++i) {
        sum += calcItem(x, i);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    double sign = 1.0;
    for (uint16_t i = 0; i < count; ++i) {
        uint16_t power = 2 * i + 1;
        sum += sign * calcItem(x, power);
        sign = -sign;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    double sign = 1.0;
    for (uint16_t i = 0; i < count; ++i) {
        uint16_t power = 2 * i;
        sum += sign * calcItem(x, power);
        sign = -sign;
    }
    return sum;
}
