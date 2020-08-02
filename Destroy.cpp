#include<iostream>
#include<fstream>
#include<vector>
#define i_64 long int
  namespace CAS::Multiprecision {
  
  
  //struct Float{
  
  
  
  
  //};
  
  
  struct Integer{
  std::vector<i_64> number;
  
  void assign(const std::string file={}) {       //read vector if file is given else read string
  if (file!=""){
  std::ifstream input_file;
  i_64 x;
  input_file.open(file);
  
  while(!input_file.eof()){
  input_file>>x;
      if( input_file.eof() ) break;
  number.emplace_back(x);
  }
  input_file.close(); 
  }
  /*
  else{
  std::string number_string;
  std::cin>>number_string;
  
  }*/
  } 
 
  
 
  void add(const Integer &number2){
  
  for (unsigned long int i=number.size();i>0;i--){
  number[i]+=number2.number[i];
  
  }
  }
  
  void print(std::string file={}, std::string vec_or_string={}){                //print to either terminal as string or file  as vector
   if (file!=""){
     std::ofstream output_file;
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
  test.assign("file.txt");
  test2.assign("file.txt");
  test.add(test2);
  test.print();
  test.print("test6");
  }
  
