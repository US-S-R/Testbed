#include<iostream>
#include<map>
#include<string>

#include"Conversion_Library.cpp"



f_64 metric_converter(f_64 value, std::string input){

 using namespace CAS::Conversion;

 std::map<std::string, f_64> convert_table;
      
      convert_table.insert(std::pair<std::string,f_64>("in"  ,in_cm(value)));
      convert_table.insert(std::pair<std::string,f_64>("ft"  ,ft_m(value)));
      convert_table.insert(std::pair<std::string,f_64>("yd"  ,yd_m(value)));
      convert_table.insert(std::pair<std::string,f_64>("mi"  ,mi_km(value)));
      convert_table.insert(std::pair<std::string,f_64>("knot",nm_km(value)));
      convert_table.insert(std::pair<std::string,f_64>("in^2",in2_cm2(value)));
      convert_table.insert(std::pair<std::string,f_64>("ft^2",ft2_m2(value)));
      convert_table.insert(std::pair<std::string,f_64>("yd^2",yd2_m2(value)));
      convert_table.insert(std::pair<std::string,f_64>("mi^2",mi2_km2(value)));
      convert_table.insert(std::pair<std::string,f_64>("acre",acre_km2(value)));
      convert_table.insert(std::pair<std::string,f_64>("in^3",in3_cm3(value)));
      convert_table.insert(std::pair<std::string,f_64>("ft^3",ft3_m3(value)));
      convert_table.insert(std::pair<std::string,f_64>("yd^3",yd3_m3(value)));
      convert_table.insert(std::pair<std::string,f_64>("oz"  ,oz_g(value)));
      convert_table.insert(std::pair<std::string,f_64>("lb"  ,lb_kg(value)));
      convert_table.insert(std::pair<std::string,f_64>("ton" ,tn_mt(value)));
      convert_table.insert(std::pair<std::string,f_64>("fl.oz",oz_mil(value)));
      convert_table.insert(std::pair<std::string,f_64>("gal" ,gal_l(value)));
      convert_table.insert(std::pair<std::string,f_64>("F"   ,f_klv(value)));
      convert_table.insert(std::pair<std::string,f_64>("lb/s",fts_jl(value)));
      convert_table.insert(std::pair<std::string,f_64>("btu" ,btu_kc(value)));
      convert_table.insert(std::pair<std::string,f_64>("curie",cu_bql(value)));
      convert_table.insert(std::pair<std::string,f_64>("dyne" ,dyn_nw(value)));
      convert_table.insert(std::pair<std::string,f_64>("erg"  ,erg_jl(value)));
      convert_table.insert(std::pair<std::string,f_64>("hp"   ,hp_wt(value)));
      convert_table.insert(std::pair<std::string,f_64>("Ev"   ,ev_jl(value)));
      convert_table.insert(std::pair<std::string,f_64>("joules",jl_ev(value)));
      convert_table.insert(std::pair<std::string,f_64>("au"   ,au_km(value)));
      convert_table.insert(std::pair<std::string,f_64>("ly"   ,ly_km(value)));
      convert_table.insert(std::pair<std::string,f_64>("Sol_rad",sor_km(value)));
      convert_table.insert(std::pair<std::string,f_64>("Sol_mass",som_kg(value)));
      convert_table.insert(std::pair<std::string,f_64>("M_earth",ert_kg(value)));
      convert_table.insert(std::pair<std::string,f_64>("Planck_Len_Gauss",si_plg(value)));
      convert_table.insert(std::pair<std::string,f_64>("Planck_Len_LH",si_pll(value)));
      convert_table.insert(std::pair<std::string,f_64>("Planck_T_Gauss",si_ptg(value)));
      convert_table.insert(std::pair<std::string,f_64>("Planck_T_lh",si_ptl(value)));
      convert_table.insert(std::pair<std::string,f_64>("dalton",dalt_kg(value)));
      convert_table.insert(std::pair<std::string,f_64>("hz",hz_wl(value)));
      convert_table.insert(std::pair<std::string,f_64>("wavelength",wl_hz(value)));
      convert_table.insert(std::pair<std::string,f_64>("degrees",dg_rad(value)));
      convert_table.insert(std::pair<std::string,f_64>("radians",rad_dg(value)));
      
      
                                                          
      auto search=convert_table.find(input);
      return search->second;
}



int main(){

int a;

std::string test;
//std::cout<<"Input value"<<std::endl;
std::cin>>a;
std::cout<<"Input unit"<<std::endl;
std::cin>>test;
std::cout<< metric_converter(a,test)<<std::endl;

}

