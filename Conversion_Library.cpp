#include<cmath>
#include"Function_Library_2"



 namespace CAS::Conversion {


   
                                //Distance to metric
   f_64       in_cm(f_64 a){
              return a*2.54;
              }
   f_64       ft_m (f_64 a){
              return a*.3048;
              }
                       
   f_64       yd_m (f_64 a){
              return a*.9144;
              }
              
   f_64       mi_km(f_64 a){
              return a* 1.609344;
              }
                                   //nautical miles  
   f_64       nm_km(f_64 a){
              return a* 1.852;
              }
                                   // Square area units              
   f_64       in2_cm2(f_64 a){
              return a*6.4516;
              }
                             
   f_64       ft2_m2(f_64 a){
              return a*.092903;
              }
              
   f_64       yd2_m2(f_64 a){
              return a*.8361273;
              }
               
   f_64       mi2_km2(f_64 a){
              return a*2.5899881;
              }
                                                                        
   f_64       acre_km2(f_64 a){
              return a*.004047;
              }
                                      //Cubic volume units
   f_64       in3_cm3(f_64 a){
              return a*16.3871;
              } 
    
   f_64       ft3_m3 (f_64 a){
              return a*.0283168;
              }
              
   f_64       yd3_m3 (f_64 a){
              return a*.7645548;
              }                                

                                        //oz to milliter
   f_64       oz_mil(f_64 a){
              return a*29.5735;
              }
                                         //Gallon to liter
   f_64       gal_l (f_64 a){
              return a*3.78541;
              }
              
   f_64       oz_g  (f_64 a){
              return a*28.3495231; 
              }                    
                                         // Avoirdupois pound (aka standard pound) to kg
   f_64       lb_kg (f_64 a){
              return a*.4535924;
              }
                                          //US Short ton to metric ton              
   f_64       tn_mt (f_64 a){
              return a*.907185;
              }
/*
          Energy conversions
*/              
              
              
                                          //Fahrenheit to Kelvin 
   f_64       f_klv(f_64 a){
              return (a-32)*.55555+273.15;
              }
                                         //Foot-pound/sec to joule
   f_64       fts_jl(f_64 a){
              return a*1.35518; 
              }
                                        //BTU to kilocalorie
   f_64       btu_kc(f_64 a){
              return a*.252164;
              }
                                       //BTU to joules (ISO standard)
   f_64       btu_jl(f_64 a){
              return a*1055.06;
              }
                                       //Curie to Becquerel
   f_64       cu_bql (f_64 a){
              return a*3.7E+10;
              }   
                                      //Dyne to newton
   f_64       dyn_nw(f_64 a){
              return a*1E-5;
              }                   
                                      //erg to joule
   f_64       erg_jl(f_64 a){
              return a*1E-7; 
              }           
                                     //horsepower to watt
   f_64       hp_wt (f_64 a){
              return a*735.499;
              }  
                                    //Electron volts to joules
  f_64        ev_jl (f_64 a){
              return a*1.60218E-19;
              }
                                   //Joules to electron volts 
  f_64        jl_ev (f_64 a){
              return a*6.242E+18;
              }                          
/*
          Astronomical Conversions
*/                         
              
                                     //Astronomical unit to km
   f_64       au_km (f_64 a){
              return a*149597870.7;
              }                
                                     //lightyear to km
   f_64       ly_km (f_64 a){
              return a*9460730472580.8;
              }
                                     //parsec to km
   f_64       pc_km (f_64 a){
              return a*30856775814913.673;
              }          
                                     //Solar radius to km
   f_64       sor_km(f_64 a){
              return a*695700;
              }
                                     //Solar mass to kilograms
   f_64       som_kg(f_64 a){
              return a*1.98847E+30; 
              }
                                     //Earth mass to kg
   f_64       ert_kg (f_64 a){
              return a*5.974E+24;
              }           
              
/*
            Planck unit conversions
*/               
                                    //SI to planck length (Gaussian)
  f_64       si_plg (f_64 a){
             return a*6.18792353E+34;
             }
                                   //SI to planck length (Lorentz-Heaviside)
  f_64       si_pll (f_64 a){
             return a*1.745505324E+34;
             }
                                  //SI to Planck temperature (Gaussian)
  f_64       si_ptg (f_64 a){
             return a*7.058109415E+31;
             }           
                                  //SI to Planck temperature (Lorentz-Heaviside)
  f_64       si_ptl (f_64 a){
             return a*2.502039162E+30;
             }                  
              
              
              
/*
            Atomic Units
*/              


  f_64      dalt_kg(f_64 a){
            return a*1.66054E-27; 
            }
            
/*
            Prefix conversion   where n_b and n is the prefix b= base unit
*/              

  f_64       yota_base  (f_64 a){
             return a*1E+24; 
             } 
             
  f_64       zeta_base  (f_64 a){
             return a*1E+21;
             }
             
  f_64       exa_base  (f_64 a){
             return a*1E+18;
             }
       
  f_64       peta_base  (f_64 a){
             return a*1E+15;
             } 
             
  f_64       tera_base (f_64 a){
             return a*1E+12;
             }
 
  f_64       giga_base (f_64 a){
             return a*1E+9;
             }    
             
  f_64       mega_base (f_64 a){
             return a*1E+6;
             }                  
   
   f_64      kilo_base  (f_64 a){
             return a*1E+3;
             }  
   
   f_64      mill_base (f_64 a){
             return a*1E-3;
             }  
             
   f_64      micr_base (f_64 a){
             return a*1E-6;
             }  
             
   f_64      nano_base (f_64 a){
             return a*1E-9;
             }  
             
   f_64      pico_base (f_64 a){
             return a*1E-12;
             }  
             
   f_64      femt_base (f_64 a){
             return a*1E-15;
             }  
             
   f_64      atto_base  (f_64 a){
             return a*1E-18;
             }  
             
   f_64      zept_base (f_64 a){
             return a*1E-21;
             }  
             
   f_64      yoct_base (f_64 a){
             return a*1E-24;
             }                                                                                                                 

/*
            Physics conversions
*/


                                    //Frequency to wavelength
   f_64       hz_wl(f_64 a){
              return a*3.33564095198152E-9; 
              } 
              
   f_64       wl_hz(f_64 a){             //Wavelength to frequency
              return a*299792458;
              }            



/*

Math conversions

*/

   
                                   //Degrees to radians         
   f_64       dg_rad(f_64 a ){
              return fmod(a*1.7453292E-2,6.28319);
              }
                                  //Radians to degrees
   f_64       rad_dg(f_64 a){
              return fmod(a*57.2957795,360) ;
              }          
                                 //Input Radians only; a=angle b=distance; 
   void       polar_cart(f_64 a,f_64 b){
              f_64 x= b*cos(a);
              f_64 y= b*sin(a);
              } 
                                // a= x-coord, b= y-coord; x= distance, y= angle radians
   void       cart_polar(f_64 a, f_64 b){
              f_64 x=sqrt(a*a+b*b);
              f_64 y=tan(b/a);
              }           



};




