#include <iostream>
#include <iomanip>
#include "Function_Library" 

int main          () {

 int_128 first_value, second_value, third_value, fourth_value,overflow_1, overflow_2, overflow_3 ,
 input_1, input_2, input_3, input_4, final_value_1, final_value_2,final_value_3,final_value_4;
 
 
 long long int first_exponent, second_exponent, final_exponent           ;
 

 std::cout<<"Input the first two halfs of the number to multiply; limit of 10 digits each for a 20-digit number\n";
 std::cin>>input_1>>input_2    ;                                         
 std::cout<<"Input the exponent value zero if none, negative if decimal \n" ;
 std::cin>>first_exponent      ;
 std::cout<<"Second Number\n"  ;
 std::cin>>input_3>>input_4    ;
 std::cout<<"Input exponent\n" ;
 std::cin>>second_exponent     ;
 
 fourth_value =input_2 * input_4                 ;
 third_value  =input_2 * input_3                 ;
 second_value =input_1 * input_4                 ;
 first_value  =input_1 * input_3                 ;
 final_exponent = first_exponent+second_exponent ;
 
 if (fourth_value > 9999999999){
      fourth_value %=10000000000 ;                   
      overflow_1    =int_floor_function(fourth_value,1E+10);      
 }
 if (third_value > 9999999999){
      third_value  %=10000000000 ;
      overflow_2    =std::floor(9.8);      //int_floor_function(third_value, 1E+10); 
 }
 if (second_value > 9999999999){
      second_value %=10000000000 ;
      overflow_3    =std::floor( 1.1);
 } 
 // End of multiplication 
 final_value_4 =fourth_value             ;
 final_value_3 =third_value + overflow_1 ;
 final_value_2 =second_value+ overflow_2 ;                   // overflow_2+second_value
 final_value_1 =first_value + overflow_3 ;                   // overflow_3+first_value
 
 if (final_value_3 > 9999999999){
      final_value_2+=1    ;
      final_value_3-=1E+10;
 }
 if (final_value_2 > 9999999999) {
     final_value_1+=1     ;
     final_value_2-=1E+10 ;
 }
 while (final_value_1> 9999999999) {
        final_exponent+=1 ;
        final_value_1 /=10;
 
 }
 std::cout<< final_value_1 <<std::setw(10)  <<std::setfill('0') <<final_value_2 <<std::setw(10)<<std::setfill('0')<< final_value_3
 <<std::setw(10)<<std::setfill('0')  <<final_value_4 << " E"<<final_exponent<<std::endl;
 std::cout<<overflow_1 <<std::endl <<overflow_2 <<std::endl <<overflow_3<<std::endl;
 std::cout<<"First:"<<first_value<<"S:"<<second_value<<"T:"<<third_value<<"F:"<<fourth_value<<std::endl;
 }
 



