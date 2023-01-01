//Function to fuse the sensor readings using Kalman filter
double kalmanFilter(double magReading, double hallReading, double wifiLocation)
{
    //Kalman filter equations
    // x is the current estimate, x_previous is the previous estimate, P is the variance of the estimate, Q is the variance of the process noise, R is the variance of the measurement noise
    double x_previous = 0;
    double x = 0;
    double P = 0;
    double Q = 0.0001;
    double R = 0.02;

    //Prediction step
    x = x_previous;
    P = P + Q;

    //Update step
    double K = P / (P + R);
    x = x + K * (wifiLocation - x);
    P = (1 - K) * P;

    //Fused value
    double UTMdistance{};
    double fusedValue = UTMdistance + (x - UTMdistance);

    return fusedValue;
}