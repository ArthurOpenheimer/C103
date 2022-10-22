
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double customSquareRoot(double x, double x0, double eNumber){

    double condition = pow(x0, 2) - x;
    if (condition < 0){
        condition = -condition;
    }
    if (condition <= eNumber){
        return x0;
    }
    else{
        double helper = (pow(x0, 2) + x) / (2.00 * x0);
        return customSquareRoot(x, helper, eNumber);
    }
}

int main(){
    double x, x0, eNumber;

    cin >> x >> x0 >> eNumber;
    cout << fixed << setprecision(4) << customSquareRoot(x, x0, eNumber) << endl;

    return 0;
}