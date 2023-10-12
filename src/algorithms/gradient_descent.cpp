#include "algorithms/gradient_descent.h"

GradientDescent::GradientDescent(float start_x, float learning_rate)
    : x(start_x), learningRate(learning_rate) {}

float GradientDescent::step()
{
    float gradient = 2.0f * x;
    x -= learningRate * gradient;
    return x;
}
