#include<math.h> 
#define f_64 double
#define f_128 long double
#define i_64 long int

#define pi 3.14159265358979323846264338327
/*
#define e 2.718281828459045235360287471352
#define tau 6.28318530717958647692528676654
*/
#pragma once
namespace CAS::Elementary{


/*
            Arithmetic functions
*/
             

                                        //Sigma notation
  
              
              template<typename data_type>
   data_type  sum_series(data_type array[],i_64 length){
              data_type sum{0};
              for (long int i{0}; i <length; i++){
              sum+=array[i];
              }
              return sum;
              }  
              
              
              
                                           //PI notation
              template<typename data_type>
   data_type  product_series(data_type array[],i_64 length){
              data_type product{1};
              for (long int i{0}; i <length; i++){
              product*=array[i];
              }
              return product;
              }  
              
              

                                                //optional exponentiation Function, highly inaccurate  for floating point slow in general    
   inline f_128     int_pow(f_128 a,int b){
              i_64 j{1},c{0};
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
                                          //sqrt algorithm
  data_type  nsqrt(data_type a){
             data_type j{2};
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
                                          // Stirling Factorial, asymptotic to n! up to n=1754. Unable to use macros due to f_128 requirement           
   f_128      s_fact(i_64 a){
              f_128 tau{6.28318530717958647692528676654},e{2.718281828459045235360287471352};
              return nsqrt(tau*a)* pow((a/e),a)*(1+1/12*a); //(1+(1/(a*a*e)));
              }
              
              
                                        //naive factorial 
  f_128       naive_fact(i_64 a){
              f_128 array[a];
              for(long int i{0};i<a;i++){
              array[i]=i+1;
              }
              return product_series<f_128>(array,a);
              }  
             




 


                                        // Euclidean algorithm for GCD  (improve this!)
   i_64  gcd(i_64 a, i_64 b){
             while ((a %= b) && (b %= a));
             return (a + b);
             }
                                                //Coprime test
   bool      is_coprime(i_64 a, i_64 b){
             return gcd(a,b)==1 ? true:false;
             }            
                                       // Least common multiple
   i_64  lcm(i_64 a, i_64 b){
              return (a*b)/gcd(a,b);
             }
                                      // Euler phi (totient) function, coprime counter (improve this!)
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
             
   


  bool       is_int(double a){
             return static_cast<long int>(a)> a ;
             }

                                        //primality by trial division, slower than naive trial division unless compiled with -O3 
  bool       is_prime(i_64 a){
             if(a!=2 && a%2 == 0){
             return false;
             }
             else{ 
             for (i_64 i{3}; i<= sqrt(a); i+=2) {
             if (a%i ==0){
             return false;
             }
             }
             return true;
             }
             } 





  bool       is_strong(i_64 a){
             i_64 next_prime=a+1, past_prime=a-1;
             if(is_prime(a)==1){
             while(is_prime(next_prime)!=1){
             next_prime++;
             }
             while(is_prime(past_prime)!=1){
             past_prime--;
             }
             }
             return ((next_prime+past_prime)>>1) < a ? true: false;
             }

          

          
                                     //algebraic dot product
                                     
 f_128      dot_prod_al(f_128 array_1[],f_128 array_2[], long int size){
              f_128 dot_product{0};
              for(int i{0}; i<=size;i++){
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
