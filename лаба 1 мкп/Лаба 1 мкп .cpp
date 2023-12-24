#include <iostream>
#include <cmath>
#include <fstream>

# define PI           3.14159265358979323846

using namespace std;

// метод интераций 
#include <cmath>

double fixed_point_iteration(double M, double e, double epsilon = 1e-6)
{
    double E = M;
    double E_sled;

    for (int i = 0; i <= 30; i++)       
    {
        E_sled = e * sin(E) + M;   
        if (fabs(E_sled - E) < epsilon)
            return E_sled;
   
        E = E_sled; 
    }

    return 0;
}

//метод половинного деления 
double method_bisection(double M, double e, double epsilon = 1e-6) 
{
    double x = M - 5; 
    double y = M + 5;  
    double z = 0;

    for (int i = 0; i <= 100; i++)
    {
        z = (x + y) / 2; 
        if (fabs(y - x) < (2 * epsilon))
            return z;

        if (((x - e * sin(x) - M) * (y - e * sin(y) - M)) < 0)
        {
            y = z; 
        }
        else
        {
            x = z; 
        }
    }

    return z;
}

// метод золотого сечения 
double method_golden_section(double M, double e, double epsilon = 1e-6)  
{
    double x = M - 5; 
    double y = M + 5; 
    double z = 0;
    double phi = (sqrt(5) + 1) / 2; 

    for (int i = 0; i <= 30; i++)
    {
        z = x + (y - x) / phi; 
        if (fabs(y - x) < 2 * epsilon)
            return z;

        if ((x - e * sin(x) - M) * (y - e * sin(y) - M) < 0)
        {
            y = z; 
        }
        else
        {
            x = z; 
        }
    }

    return z;
}

// метод Ньютона 
double method_Newton(double M, double e, double epsilon = 1e-6) 
{
    double E = M; 

    for (int i = 0; i < 40; i++)
    {
        double f = E - e*sin(E) - M; 
        double f_prime = 1 + e*cos(E); 

        E -= f / f_prime; 

        if (abs(f) < epsilon) 
        {
            break;
        }
    }

    return abs(E);
}

int main() {
    
    double T = 9015;                        
    double r_a = 1017000;                   
    double r_p = 350000;                    
    double epsilon = 1e-6;

    double n = 2 * PI / T;                 
    double a = (r_a + r_p) / 2;              
    double e = ((r_a - r_p) / (2 * a));            

    
    ofstream fout1;
    fout1.open("файл 1.txt");

    
    if (!fout1) {
        cout << "ошибка.";
        return 0;
    }

    fout1 << "t, c\t";
    fout1 << "M(t), рад\t";
    fout1 << "E(t), рад\t";
    fout1 << "Teta(t), с\t" << endl;

    
    for (int t = 0; t <= T; t++) {
        fout1 << t << "\t";

        double M = n * t; 
        double E = method_Newton(M, e, epsilon); 
        double true_anomaly = atan(sqrt((1 + e) / (1 - e)) * tan(E / 2)) * 2; 

        if (true_anomaly < 0)
            true_anomaly += 2 * PI;

        fout1 << M << "\t";
        fout1 << E << "\t";
        fout1 << true_anomaly << endl;
    }

    fout1.close();
    cout << "Данные сохранены в  'файл 1.txt' file.";

    ofstream fout2;
    fout2.open("файл 2.txt");

    
    if (!fout2) {
        cout << "ошибка.";
        return 0;
    }

    fout2 << "t, c\t";
    fout2 << "M(t), рад\t";
    fout2 << "E(t), рад\t";
    fout2 << "Teta(t), с\t" << endl;

    
    for (int t = 0; t <= T; t++) {
        fout2 << t << "\t";

        double M = n * t; 
        double E = method_golden_section(M, e, epsilon); 
        double true_anomaly = atan(sqrt((1 + e) / (1 - e)) * tan(E / 2)) * 2; 

        if (true_anomaly < 0)
            true_anomaly += 2 * PI;

        fout2 << M << "\t";
        fout2 << E << "\t";
        fout2 << true_anomaly << endl;
    }

    fout2.close();
    cout << "Данные сохранены в  'файл 2.txt' file.";

    
    ofstream fout3;
    fout3.open("файл 3.txt");

    
    if (!fout3) {
        cout << "ошибка.";
        return 0;
    }

    fout3 << "t, c\t";
    fout3 << "M(t), рад\t";
    fout3 << "E(t), рад\t";
    fout3 << "Teta(t), с\t" << endl;

   
    for (int t = 0; t <= T; t++) {
        fout3 << t << "\t";

        double M = n * t; 
        double E = method_bisection(M, e, epsilon); 
        double true_anomaly = atan(sqrt((1 + e) / (1 - e)) * tan(E / 2)) * 2; 

        if (true_anomaly < 0)
            true_anomaly += 2 * PI;

        fout3 << M << "\t";
        fout3 << E << "\t";
        fout3 << true_anomaly << endl;
    }

    fout3.close();
    cout << "Данные сохранены в  'файл 3.txt' file.";

    
    ofstream fout4;
    fout4.open("файл 4.txt");

    
    if (!fout4) {
        cout << "ошибка.";
        return 0;
    }

    fout4 << "t, c\t";
    fout4 << "M(t), рад\t";
    fout4 << "E(t), рад\t";
    fout4 << "Teta(t), с\t" << endl;

    
    for (int t = 0; t <= T; t++) {
        fout4 << t << "\t";

        double M = n * t; 
        double E = fixed_point_iteration(M, e, epsilon); 
        double true_anomaly = atan(sqrt((1 + e) / (1 - e)) * tan(E / 2)) * 2; 
        if (true_anomaly < 0)
            true_anomaly += 2 * PI;

        fout4 << M << "\t";
        fout4 << E << "\t";
        fout4 << true_anomaly << endl;
    }

    fout4.close();
    cout << "Данные сохранены в  'файл 4.txt' file.";
    
    return 0;
}

 
