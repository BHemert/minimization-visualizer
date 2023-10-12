#pragma once

class GradientDescent
{
public:
    GradientDescent(float start_x, float learning_rate);
    float step(); // Performs one step of the algorithm and returns new x value

private:
    float x;
    float learningRate;
};
