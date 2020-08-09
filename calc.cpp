#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#include "Function_Library"
#include "Number_Theory"

//arith_solve(std::string input){

//solve_funct
double arithmetic(std::string input){

std::vector<double>num_vect;  //number vector
std::vector<std::string>word, func_vector, op_vector; //
std::string temp_string;

std::istringstream iss(input);

   std::string op_symbols[5]={"+","-","*","/","^"};

 while(iss >> temp_string) word.emplace_back(temp_string);
  for(int i=0;i<word.size();i+=2){  //transfer numbers to double vector
    num_vect.emplace_back(std::stod(word[i]));
    }

    for(int i=1;i<word.size();i+=2){
     op_vector.emplace_back(word[i]);
      }
      op_vector.emplace_back("");
      
  //exponentiation
for(int i=0;i<=op_vector.size();i++){
for(int i=0;i<=op_vector.size();i++){
if(op_vector[i]==op_symbols[4]){
num_vect[i]=std::pow(num_vect[i],num_vect[i+1]);
num_vect.erase(num_vect.begin()+i+1);
op_vector.erase(op_vector.begin()+i);
break;
}
}
}  
  
  //division
for(int i=0;i<=op_vector.size();i++){
for(int i=0;i<=op_vector.size();i++){
if(op_vector[i]==op_symbols[3]){
num_vect[i]/=num_vect[i+1];
num_vect.erase(num_vect.begin()+i+1);
op_vector.erase(op_vector.begin()+i);
break;
}
}
}
//multiplication
for(int i=0;i<=op_vector.size();i++){
for(int i=0;i<=op_vector.size();i++){
if(op_vector[i]==op_symbols[2]){
num_vect[i]*=num_vect[i+1];
num_vect.erase(num_vect.begin()+i+1);
op_vector.erase(op_vector.begin()+i);
break;
}
}
}
//addition
for(int i=0;i<=op_vector.size();i++){
for(int i=0;i<=op_vector.size();i++){
if(op_vector[i]==op_symbols[1]){
num_vect[i]-=num_vect[i+1];
num_vect.erase(num_vect.begin()+i+1);
op_vector.erase(op_vector.begin()+i);
break;
}
}
}

for(int i=0;i<=op_vector.size();i++){
for(int i=0;i<=op_vector.size();i++){
if(op_vector[i]==op_symbols[0]){
num_vect[i]+=num_vect[i+1];
num_vect.erase(num_vect.begin()+i+1);
op_vector.erase(op_vector.begin()+i);
break;
}
}
}
return num_vect[0];
}


 double paren(std::string input){
       
        std::size_t first_pos =input.find("(");
        std::size_t last_pos =input.find(")",first_pos);
        std::string paren_section = input.substr(first_pos + 1, last_pos -1);
        
    return arithmetic(paren_section);
    }
    
 double func(std::string input){
        std::size_t last_pos = input.find("(");
        std::string func_name = input.substr(0,last_pos);
         if (func_name=="sqrt"){
           return sqrt(paren(input));
         }
         if (func_name=="cos"){
           return cos(paren(input));
         }
         if (func_name=="sin"){
           return sin(paren(input));
         }
         if (func_name=="isprime"){
         return CAS::Number_Theory::is_prime(paren(input));
         }
         if(func_name=="isstrong"){
         return CAS::Number_Theory::is_strong(paren(input));
         }
         if(func_name=="fact"){
         return CAS::Elementary::naive_fact(paren(input));
         }
         if(func_name=="exp"){
         return CAS::Elementary::exp(paren(input));
         }
         if(func_name=="pi"){
         return CAS::Number_Theory::pi_func(paren(input));
         }
         if(func_name=="nearestsqre"){
         return CAS::Number_Theory::nearest_sqre(paren(input));
         }
         if(func_name=="phi"){
         return CAS::Number_Theory::phi(paren(input));
         }
         else{
         return 1.5;
         }
 }
 
int main(){

std::string input;
std::getline(std::cin,input);
std::cout<<func(input)<<std::endl;
}
