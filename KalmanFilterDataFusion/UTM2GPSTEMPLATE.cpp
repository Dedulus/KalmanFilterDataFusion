#include <vector>


using namespace std;
//Function to convert from UTM distance to GPS coordinates

vector<double> UTMtoGPS(double UTMdistance, double lastLat, double lastLong)
{
    //Calculate the new Latitude and Longitude
    double newLat = lastLat + UTMdistance * cos(lastLong);
    //utmDistance * cos(lastKnownCoordinate.longitude);
    double newLong = lastLong + UTMdistance * sin(lastLat);

    vector<double> newCoordinates = { newLat, newLong };

    return newCoordinates;
}
