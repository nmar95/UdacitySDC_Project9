#include "PID.h"
#include <iostream>

using namespace std;

PID::PID() {}

PID::~PID() {}

// TODO: Complete the PID class

// Intialization Function
void PID::Init(double Kp, double Ki, double Kd) {
    // Proportional
    this->Kp = Kp;
    // Integral
    this->Ki = Ki;
    // Differential
    this->Kd = Kd;

    // Initialize errors
    i_error = 0;
    d_error = 0;
    p_error = 0;
}

// Update Error Function
void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    i_error = i_error + cte;
    p_error = cte;
}

// Total Error Function
double PID::TotalError() {
  double steer = - (Kp * p_error) - (Ki * i_error) - (Kd * d_error);
	return steer;
}
