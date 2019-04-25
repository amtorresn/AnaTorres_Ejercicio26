#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using std::cout;
using std::endl;


void explicit_Euler(int xi, int xf, double delta, double w, string filename);
void rk4(int xi, int xf, double delta, double w, string filename);
void leap_frog(int xi, int xf, double delta, double w, string filename);

// float dzdx(float x, float y, float z, float omega);
// float dydx(float x, float y, float z, float omega);

int main(){
    
    float omega = 1.0;
    explicit_Euler(0.0, 10000.0, omega/2, omega, "euler.dat");
    rk4(0.0, 10000.0, omega/2, omega, "rk4.dat");
    leap_frog(0.0, 10000.0, omega/2, omega, "frog.dat");
    
    return 0;   
}

// float dzdx(float x, float y, float z, float omega){
//     return omega*(-omega*omega*y)/2
// }

// float dydx(float x, float y, float z, float omega){
// }


void explicit_Euler(int xi, int xf, double delta, double w, string filename){
    
    double y = 1;
    double x = xi;
    double z = 0;
    double z_n = 0;
    
    ofstream outfile;
    outfile.open(filename);
    
    while(x<xf){
        z_n = z;
        z += delta*(-w*w*y);
        y += delta*z_n;
        x += delta;
        outfile << x << " " << y << " " << z << endl;
    }
    outfile.close();
}


void rk4(int xi, int xf, double delta, double w, string filename){
    
    double y = 1; double x = xi; double z = 0;
    double z_n = 0;
    double y_new = 0; double z_new = 0;
    double f0_z = 0; double f0_y = 0;
    double f1_z = 0; double f1_y = 0;
    double f2_z = 0; double f2_y = 0;
    double f3_z = 0; double f3_y = 0;
    double fprom_z = 0; double fprom_y = 0;
    
    ofstream outfile;
    outfile.open(filename);
    
    
    while(x<xf){
        
        z_n = z;
        f0_z = delta*(-w*w*y);
        f0_y = delta*z_n;
        
        y_new = y + f0_y/2;
        z_new = z + f0_z/2;
        
        f1_z = delta*(-w*w*y_new);
        f1_y = delta*z_new;
        
        y_new = y + f1_y/2;
        z_new = z + f1_z/2;
            
        f2_z = delta*(-w*w*y_new);
        f2_y = delta*z_new;
        
        y_new = y + f2_y;
        z_new = z + f2_z;
        
        f3_z = delta*(-w*w*y_new);
        f3_y = delta*z_new;
        
        fprom_z = f0_z/6 + f1_z/3 + f2_z/3 + f3_z/6;
        fprom_y = f0_y/6 + f1_y/3 + f2_y/3 + f3_y/6;
        
        z += fprom_z;
        y += fprom_y;
        x += delta;
        outfile << x << " " << y << " " << z << endl;
    }
    outfile.close();
    
}

void leap_frog(int xi, int xf, double delta, double w, string filename){
    
    double y = 1;
    double x = xi;
    double z = 0;
//     double z_n = 0;
//     double z_n1 = 0;
    double y_1 = 0;
    double z_12 = 0;
    double z_32 = 0;
    
    ofstream outfile;
    outfile.open(filename);
    
    y_1 = y + (-w*w*y)*delta/2;
    
    while(x<xf){
//         z_n = z;
//         y_1 = y;
        z_12 = delta*(-w*w*y_1)/2;
        y_1 += (z_12)*delta;
        
        z_32 = z_12 + 2*(-w*w*y_1)*delta;
        
//         z += delta*(-w*w*y);
//         y += delta*z_n1;
        x += delta;
        outfile << x << " " << y_1 << " " << z_12 << endl;
    }
    outfile.close();
    
}