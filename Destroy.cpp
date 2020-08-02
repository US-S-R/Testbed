#include<iostream>
#include<fstream>
#include<vector>
#define i_64 long int
  namespace CAS::Multiprecision {
  
  
  //struct Float{
  
  
  
  
  //};
  
  
  struct Integer{
  std::ofstream output_file;
  std::vector<i_64> number;
  /*
  void assign(std::string vec_or_string,std::string file={})        //if second argument is string read file in local directory and save as 
  
  
  */
 
  void add(Integer number2){
  
  for (unsigned long int i=5;i>0;i--){
  number[i]+=number2.number[i];
  
  }
  }
  
  void print(std::string file={}, std::string vec_or_string={}){                //print to either terminal as string or file  as vector
   if (file!=""){
    output_file.open(file);
  
    for(unsigned long int i=1;i<number.size();i++){
     output_file<<number[i]<<std::endl;
    }
  
  output_file.close();
  }
  else{
  for(unsigned long int i=0;i<number.size();i++){
  std::cout<<number[i];
  }
  }
  
  } //end function
  };//end struct
  }//end namespace
  
  int main() {
  
  CAS::Multiprecision::Integer test, test2;
  test.number={1,2,4,4,5};
  test2.number={1,3,4,6,8};
  test.add(test2);
  test.print();
  test.print("test6");
  }
  
