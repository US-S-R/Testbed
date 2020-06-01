#include<iostream>
#include<cmath> //Cmath does not support long double for s_factorial
#define f_128 long double
#define i_64 long int
namespace CAS{

             

                                        //Iterative addition 
   f_128      iter_add(i_64 a){
              f_128 x,result{0};
              for (int i{1}; i <=a; i++){
              std::cin>>x; 
              result+=x;
              }
              return result; 
              }
              
                                         //Iterative multiplication
   f_128      iter_mx(i_64 a){
              f_128 x, result{1};
              for (int i{1}; i <=a; i++){
              std::cin>>x; 
              result=result*x;
              }
              return result;
              }           

                                                //optional exponentiation Function, highly inaccurate      
    f_128     int_pow(f_128 a,int b){
              i_64 j=1,c=0;
              i_64 d=a;
              while(j < b){
              j*=2;
              c++;
              }
              b-=(j/2);
              for(int i{2}; i <= c; i++){
              a*=a;
              }
              for(int i{0}; i < b; i++){
              a=d*a;
              }
              return a;
              }         
             
             
             
             
             template<typename data_type>
                                          //sqrt algorithm, nearly as fast as math.h header
   data_type nsqrt(data_type a){
             data_type j=2;
             data_type c;
             while(j*j <= a){
             j*=2;
             }
             c=j;
             for (int i{0}; i<6;i++){
             c= (c + a/c)/2;
             }
             return c;
             }
             

             template<typename data_type>
                                                 // nthroot algorithm
  data_type  nthroot(data_type a, data_type b){
             data_type c=nsqrt(nsqrt(a));
             int i{0};
             while(i<26){
             c= ((b-1)*c + a/pow(c,b-1))/b;
             i++;
             }
             return c;
             }

            
    
             template<typename data_type>														

                                          //Arithmetic mean
   data_type  a_mean(data_type a, i_64 b ){
              return a/b;  
              }       
                                           // Geometric mean
   f_128      g_mean(f_128 a, f_128 b){
              return pow(a,1/b);
              }
                                          // Stirling Factorial, asymptotic to n! up to n=1754             
   f_128      s_fact(i_64 a){
              f_128 tau{6.283185307179586476925286766558},e{2.718281828459045235360287471352}, estimate; 
              estimate= sqrt(tau*a)* pow((a/e),a)*(1+1/12*a);
              return estimate;//*(1+(1/(a*a*e)));
              }
    
             




 


                                        // Euclidean algorithm for GCD
   i_64  gcd(i_64 a, i_64 b){
             while ((a %= b) && (b %= a));
             return (a + b);
             }
                                                //Coprime test
   bool      coprime(i_64 a, i_64 b){
             if(gcd(a,b)==1){
             return true;
             }
             return false;
             }            
                                       // Least common multiple
   i_64  lcm(i_64 a, i_64 b){
              return (a*b)/gcd(a,b);
             }
                                      // Euler phi (totient) function, coprime counter
   i_64  phi(i_64 a){
             i_64 b{0};
             for (i_64 i{1};i< a; i++)
             if (gcd(a,i) == 1){
             b+=1;
             }
             return b;   
             }       
                                     // integer floor function 
   i_64  floor(i_64 a, i_64 b){
             if (a >  b){
             a/=b;
             }
             return a*b;
             }
             
   




                                        //primality by abridged trial division
   bool      primality(i_64 a){
             if (a%2 == 0 || a%3 == 0){  
             return false;
             }
             else{                                      
             for (i_64 i=5; i<= sqrt(a); i+=2) {
             if (a%i==0){
             return false;
             }
             }
             }
             return true;
             } 


          
                                     //algebraic dot product
                                     
 f_128      dot_prod_al(f_128 array_1[],f_128 array_2[], long int size){
              f_128 dot_product=0;
              for(int i=0; i<=size;i++){
              dot_product=dot_product + array_1[i]*array_2[i];
              }
              return dot_product;
              }
              
                                   //euclidean vector magnitude
              
  f_128      eu_vec_mag(f_128 vec_1[], long int size){
               return sqrt(dot_prod_al( vec_1, vec_1,size));
               }
               
                                  ////geometric dot product
              
  f_128     dot_prod_geo(f_128 vec_mag_1,f_128 vec_mag_2,f_128 angle){
               return vec_mag_1*vec_mag_2*cos(angle);
               }


}
