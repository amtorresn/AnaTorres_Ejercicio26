#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using std::cout;
using std::endl;


void explicit_Euler(int n, double y0, double z0, double delta, double w, string filename);
void rk4(int n, double y0, double z0, double delta, double w, string filename);


int main(){
    
 explicit_Euler(200, 1, 0, 0.1, 1, "ex_01.dat");
 explicit_Euler(200, 1, 0, 0.01, 1, "ex_001.dat");
 explicit_Euler(200, 1, 0, 1, 1, "ex_1.dat");
 return 0;   
}



void explicit_Euler(int n, double y0, double z0, double delta, double w, string filename){
    
    double y = y0;
    double x = 0;
    double z = z0;
    double z_n = 0;
    
    ofstream outfile;
    outfile.open(filename);
    
//     cout << "explicit" << endl;
    for (int i = 0; i < n; i++){
        z_n = z;
        z += delta*(-w*w*y);
        y -= delta*z_n;
        x += delta;
        outfile << x << " " << y << " " << z << endl;
    }
    outfile.close();
}

void rk4(int n, double y0, double z0, double delta, double w, string filename){
    
}