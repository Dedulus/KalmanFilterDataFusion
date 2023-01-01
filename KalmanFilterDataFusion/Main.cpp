//Usage: C++ code to convert sensor reading from magnetometer and hall sensor to UTM distance from the last known 
//GPS coordinate and calculate the new GPS coordinate and use the Kalman filter to fuse the sensor readings from 
//available wifi location. Take custom input for the sensor readings and last known GPS coordinates

//Version: 1.4, Date: 1 January 2023

//Owner: Arnab Mitra

//Contact: papan.mitra.2121@gmail.com


#include <iostream>
#include <math.h>
#include "ToUTM.h"
#include "UTM2GPSTEMPLATE.h"
#include "CustomKalman.h"


//Main function
int main() {
    //Variables to store the sensor readings and GPS coordinates
    double magReading, hallReading, lastLat, lastLong, wifiLocation;

    //Take custom input for the sensor readings and last known GPS coordinates
    cout << "Enter sensor readings from magnetometer(in micro Tesla) and hall sensor(in Meters): \n";
    cin >> magReading >> hallReading;

    cout << "Enter last known GPS coordinates (latitude and longitude): \n";
    cin >> lastLat >> lastLong;

    cout << "Enter wifi location: \n";
    cin >> wifiLocation;

    //Calculate the UTM distance using the sensor readings
    double UTMdistance = convertToUTM(magReading, hallReading);

    //Convert from UTM distance to GPS coordinates
    vector<double> newCoordinates = UTMtoGPS(UTMdistance, lastLat, lastLong);

    //Fuse the sensor readings using Kalman filter
    double fusedValue = kalmanFilter(magReading, hallReading, wifiLocation);

    //Print the results
    cout << "New GPS coordinates: " << newCoordinates[0] << " " << newCoordinates[1] << endl;
    cout << "Fused value: " << fusedValue << endl;
    cout << "             " << endl;
    cout << "Liked what you see? :) ...Feel free to use or modify this code without any restriction. Please contact me for any changes or bugs. Kindly note that I am looking out for a job in the Autonomous Vehicle domain .Please contact me if you have any opportunity for me...."  << endl;

    return 0;
}