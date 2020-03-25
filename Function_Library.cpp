/*
Library of general functions; including averages, quadratic equation, Lorentz transformations, summation series, and much more! 

Log 

Date              Programmer           Changes made 
_______          _____________        ________________________________________
                 
2020-02-19          u/S-S-R            Geometric, Arithmetic, & Harmonic means 

2020-02-20             ^               Alphamax, Finite Geometric Sum, Stirling factorial approximation

2020-02-23             ^               Poisson Distribution (poor accuracy),Coulomb scalar y vector 

2020-03-02             ^               Radian conversion, 

2020-03-17             ^               Addition, Multiplication, Updated Arithmetic y Geometric Mean

2020-03-19             ^               Slight Debugging, tested as library

2020-03-24             ^               Floor function

*/

# include <iostream>
# include <math.h>


typedef long double float_128; 
typedef unsigned long long int int_128;


double addition(int numero){
    float x,result;
 
  for (int i=1; i <=numero; i++){
      std::cin>>x; 
       result+=x;
      }
      return result;
}

float multiplication(int numbers){
    float x, result=1;
  for (int i=1; i <=numbers; i++){
      std::cin>>x; 
      result=result*x;
      }
      return result;
    }
    


double arithmetic_mean(double x){
    return addition(x)/x;
    }

double geometric_mean(double x){
    return  pow(multiplication(x),1/x);
    }

float harmonic_mean(float a, float b, float c) {
return 3/(1/a + 1/b +1/c);
}

/*
float root_square_mean (float a,float b, float c){
 return sqrt(arithmetic_mean(a*a,b*b,c*c))
} 
*/  

unsigned long long int int_floor_function(int_128 input, int_128 floor){
 if (input >  floor){
 input/=floor;
 }
 else{
 input==0;
 }
 return input;
 }
 


float degrees_to_radians(float a)  {
return a*.01745;
}

float radians_to_degrees (float a) {
return a*57.2958;
}

float circular_acceleration(float a, float b){
return (a*a)/b;
}

float kinetic_energy(float a, float b) {
return .5*a*(b*b);
}

float alpha_max(float a, float b) {
return std::max(a,b)*.9604 + std::min(a,b)*.3987;
}

float finite_geometric_sum(float initial_value , float common_ratio, int exponent){
  float sum_of_numbers;
  sum_of_numbers=initial_value * (1-pow(common_ratio,exponent))/(1-common_ratio);
 return sum_of_numbers;
}

// Compute factorials up to 1754! with moderate accuracy

float_128 stirling_factorial(float_128 factorial){                                            
float_128 tau= 6.283185307179586476925286766558,e= 2.718281828459045235360287471352, estimate; 
estimate= sqrt(tau*factorial)* pow((factorial/e),factorial)*(1+1/12*factorial);
return estimate;
}

float poisson_distribution(float a, float b){
float e=2.71828, probability;
probability= pow(a,b)*(1/(pow(e,a)));
return probability/stirling_factorial(b);
}

double coulomb_scalar(double a, double b, float c ){ 
return 8987551787*((a*b)/(c*c));
}
