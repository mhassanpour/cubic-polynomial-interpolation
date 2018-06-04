//
// Created by mostafa-nao on 5/14/18.
//

#include <iostream>
#include <fstream>
#include "Polynomial.h"

using namespace std;

int main(){

    Polynomial polynomial;

    cout << "How many point do you want??" << endl;
    int n = 0;
    cin >> n;

    Polynomial x[n];
    Polynomial y[n];
    Polynomial z[n];
    double XPoint[n], YPoint[n], ZPoint[n];
    double XSlope[n], YSlope[n], ZSlope[n];
    double finalTime[n];

    for (int i = 0; i < n  ; i++)
    {

            cout << "please enter your first point and point slope" << endl << i <<  " Point X :" << endl;

            cin >> XPoint[i];
            cout << i << "  Point Y :" << endl;
            cin >> YPoint[i];
            cout << i << " Point Z :" << endl;
            cin >> ZPoint[i];
            cout << i << " Slope X Point :" << endl;
            cin >> XSlope[i];
            cout << i << " Slope Y Point :" << endl;
            cin >> YSlope[i];
            cout << i << " Slope Z Point :" << endl;
            cin >> ZSlope[i];
//
//        cout << "X[" <<  i << "] " << XPoint[i] << endl;
//        cout << "Y[" <<  i << "] " << YPoint[i] << endl;
//        cout << "Z[" <<  i << "] " << ZPoint[i] << endl;
//
//        cout << "Xs[" <<  i << "] " << XSlope[i] << endl;
//        cout << "Ys[" <<  i << "] " << YSlope[i] << endl;
//        cout << "Zs[" <<  i << "] " << ZSlope[i] << endl;


        cout << "please enter your time" <<  endl;
        cout << "Time :" << endl;
        cin >> finalTime[i];

        cout << "Time["  << i  << "]  " << finalTime[i] << endl;

        if(i == 0)
            continue;

        x[i] =  Polynomial(XPoint[i-1], XPoint[i], XSlope[i-1], XSlope[i], finalTime[i] - finalTime[i-1]);

        y[i] =  Polynomial(YPoint[i-1], YPoint[i], YSlope[i-1], YSlope[i], finalTime[i] - finalTime[i-1]);

        z[i] =  Polynomial(ZPoint[i-1], ZPoint[i], ZSlope[i-1], ZSlope[i], finalTime[i] - finalTime[i-1]);


        std::cout << "a(0)  " << x[i].a.at(0) << std::endl;
        std::cout << "a(1)  " << x[i].a.at(1) << std::endl;
        std::cout<< "a(2)  " << x[i].a.at(2) << std::endl;
        std::cout << "a(3)  " << x[i].a.at(3) << std::endl;

        for(float j = 0 ; j < finalTime[i] - finalTime[i-1] ; j = j + 0.01)
        {
            x[i](j);
            y[i](j);
            z[i](j);

            ofstream myfile;
            myfile.open ("point.txt" , ios::app);
            myfile << j << "," <<x[i](j) << "," << y[i](j) << "," << z[i](j) << "\n";
            myfile.close();

        }


    }

    return 0;

}
