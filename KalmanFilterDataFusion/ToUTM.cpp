const double g = 9.81; // acceleration due to gravity (m/s^2)
const double lambda = 0.1; // coefficient for rate of change of velocity

//Function to convert from magnetometer and hall sensor to UTM distance
double convertToUTM(double magReading, double hallReading)
{
    //Calculate the UTM distance using the sensor readings
    double UTMdistance = magReading - hallReading + (g * lambda * lambda / 2);

    return UTMdistance;
}