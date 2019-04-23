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
    
    explicit_Euler(400, 1, 0, 0.1, 1, "exp_01.dat");
    explicit_Euler(400, 1, 0, 0.01, 1, "exp_001.dat");
    explicit_Euler(400, 1, 0, 1, 1, "exp_1.dat");
    rk4(400, 1, 0, 0.1, 1, "rk_01.dat");
    rk4(400, 1, 0, 0.01, 1, "rk_001.dat");
    rk4(400, 1, 0, 1, 1, "rk_1.dat");
    
 return 0;   
}



void explicit_Euler(int n, double y0, double z0, double delta, double w, string filename){
    
    double y = y0;
    double x = 0;
    double z = z0;
    double z_n = 0;
    
    ofstream outfile;
    outfile.open(filename);
    
    while(x<30){
        z_n = z;
        z += delta*(-w*w*y);
        y += delta*z_n;
        x += delta;
        outfile << x << " " << y << " " << z << endl;
    }
    outfile.close();
}


void rk4(int n, double y0, double z0, double delta, double w, string filename){
    
    double y = y0; double x = 0; double z = z0;
    double z_n = 0;
    double y_new = 0; double z_new = 0;
    double f0_z = 0; double f0_y = 0;
    double f1_z = 0; double f1_y = 0;
    double f2_z = 0; double f2_y = 0;
    double f3_z = 0; double f3_y = 0;
    double fprom_z = 0; double fprom_y = 0;
    
    ofstream outfile;
    outfile.open(filename);
    
    
    while(x<30){
        
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