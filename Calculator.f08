! Log 

! Date              Programmer           Changes made 
! _______          _____________        ________________________________________
!                  
! 2020-03-03        u/S-S-R               Implemented averages, cleaned up code
!
! 2020-03-17           ^                  Variable input Addition
!
!
!
!

module constants
 implicit none 
    integer, parameter,public :: qp = selected_real_kind(33, 4931)
    integer, parameter,public :: i64= selected_int_kind(32)
    integer (kind=i64), public::  int_num_1, int_num_2
    character(len=30), public :: name, filename
    real (kind=qp),parameter,public :: pi= 3.141592653589793238462643383279503, g= 6.67408E-11!, g_earth= 9.80665
    real (kind=qp),public :: x,y,z,t
    real,public :: x_lp,y_lp,z_lp,t_tp, g_earth=9.80665, pi_lp=3.1415927 !low precision for faster computation; projectile array is accurate to +- .005
    real, dimension (:,:), allocatable :: xarray
    real, dimension (100):: default_array
end module constants

program Calc
use constants
Implicit none
do while(.true.)
write(*,*) "Select operation:"
read *, name 
 Select case (name)
Case ("+","addition") 
 call Addition
Case ("arith","math")
 call Arithops
Case ("averages")
 call Averages
Case ("factorial","!")
 call Factorial
Case ("quadratic")
 call Quadratic
Case ("sum")
 call Summation
Case("binomial-distribution") 
 call binomial
Case ("vector")
 call Vector_sum
Case ("ellipse")
 call Ellipsoid
Case ("g-equations") 
 call Gravitationalacc
Case ("suvat")
 call Suvat
Case ("projectile")
 call projectile_array
Case ("help")
 write(*,*)"Program keywords"
 write(*,*)"arith; + - mx div ^ sqrt "
 write(*,*)"averages; arithmetic,geometric,harmonic"
 write(*,*)"quadratic"
 write(*,*)"sum"
 write(*,*)"binomial-distribution"
 write(*,*)"ellipse"
 write(*,*)"g-equations"
 write(*,*)"suvat; velocity, displacement"
 write(*,*)"vector"
 write(*,*)"projectile"
end select
end do
end program Calc

subroutine input(x,y,z,t)
     implicit none
     integer, parameter:: qp = selected_real_kind(33, 4931)
     real (kind=qp):: x,y,z,t
     write(*,*) "Input 4 numbers:"
     read *, x,y,z,t
end subroutine input 

subroutine addition
use constants
write (*,*)"Input how many numbers to add"
read*, int_num_1
write (*,*)"Input the numbers to add"
do i=1, int_num_1
read*, y
z=z+y
end do
end subroutine addition

subroutine arithops
     use constants
     Implicit none
     write(*,*)"Select:+,-,mx,div,^, or root"
      read *, name
       if(name=="+") then
         call addition
         write(*,*)z
    else      
     call input(x,y,z,t)
    Select case (name)                    ! Addition
     Case ("-")
      write(*,*) "Difference:",x-y-z-t         ! Subtraction
     Case ("mx") 
      write(*,*) "Product:",x*y*z*t             ! Multiplication
     Case ("div")
      write(*,*) "Quotient:",((x/y)/z)/t       ! Division 
     Case("^")     
      write(*,*) " Power Sum:",x**(y**(z**t))   ! Exponentiation
     Case ("root")
      write(*,*)"Root:", x**(1/y)               ! Root
  end select
 end if 
end subroutine arithops


subroutine averages
use constants
write (*,*) "Select arithmetic, geometric, or harmonic "
read *, name  
if (name=="arithmetic") then 
     call addition 
     write(*,*) "Arithmetic average:", z/int_num_1
 else    
      call input(x,y,z,t)   
  Select case(name) 
    Case ("geometric")
     write(*,*)"Geometric average (last digit is the root):", (x*y*z)**(1/t)
    Case ("harmonic")
     write (*,*)"Harmonic average:", 4/(1/x + 1/y + 1/z + 1/t)
 end Select
 end if
end subroutine averages

subroutine factorial
use constants
write(*,*)"Input number"
read *, x 
write (*,*) Gamma(x+1)
end subroutine factorial

subroutine summation
 use constants
 implicit none
 write(*,*)"Input first number and last number"
 read  *, x,y
 write(*,*) (y*y+y)/2 - (x*x+x)/2
end subroutine

subroutine Quadratic
 use constants
     Implicit none
     real(kind=qp) :: v1,v2,v3
     write (*,*)"Input quadratic coefficients a,b, and c"
       read  *,x,y,z
     v1=  y**2. - 4.*x*z
     if (v1 > 0) then 
      v2= (-y + sqrt(v1))/(2.*x)
      v3= (-y - sqrt(v1))/(2.*x)
      write(*,*)v2,v3
     else if (v1 == 0) then
      v2 = (-y)/(2.*x)
       write(*,*) v2
     else if (v1 < 0) then 
      v2 = (-y)/(2.*x)
      v3 = sqrt(abs(v1))/( 2.*x)
       write (*,*)"Real part:",v2, "imaginary part:","-i",v3,"+i",v3
    end if
end subroutine

subroutine vector_sum
     use constants
     real(kind=qp)::vector_magnitude
     write (*,*) "Input coordinates of the vector, or magnitudes of vectors"
     read *, x,y,z
     vector_magnitude= sqrt((x**2)+(y**2)+(z**2))
     write (*,*)"The magnitude of the vector is:",vector_magnitude
end subroutine vector_sum

subroutine Ellipsoid
     use constants
     Implicit none
     real(kind=qp) ::Circum,Area,Vol,S_Area
     write(*,*) "Body 1: input x,y,z, axes"
     read *, x,y,z
     Vol= (4*pi*x*y*z)/3
     Circum=pi*(3*(x+y)-sqrt((3*x+y)*(3*y+x)))
     Area=pi*x*y
     S_Area= 4.*pi*(((x*y)**1.6075+(x*z)**1.6075+(y*z)**1.6075)/3.)**(1./1.6075)
     write(*,*) "Body "
     write(*,*) "Circum:",Circum              ! Ramanujan approximation
     write(*,*) "Ellipse Area:", Area
     write(*,*) "Volume:", Vol
     write(*,*) "Ellipsoid Surface Area:", S_Area
end subroutine Ellipsoid

subroutine Gravitationalacc
     use constants
     Implicit none
     real :: G_acceleration,Escape_velocity,Orbital_velocity,Radius,Mass
     write(*,*) "Body 1: Input Mass (kg^21),Radius (km)"
     read  *, x,y
     Mass=x*10.**21
     Radius= y*10.**3
     G_acceleration= g*mass/(radius**2)
     Escape_velocity= sqrt(2*g*mass)/radius
     Orbital_velocity= sqrt(g*mass/radius)
     write(*,*) "Gra acceleration:",G_acceleration,"m/s"
     write(*,*) "Escape  velocity:",Escape_velocity, "m/s"
     write(*,*) "Orbital velocity:", Orbital_velocity, "m/s"
end subroutine Gravitationalacc

subroutine Suvat
     use constants
     implicit none
     real(kind=qp):: v1,v2,v3
     write(*,*)"What do you want to know?"
     read *, name
      Select case (name)
       Case("velocity")
        write(*,*)"Input initial velocity, acceleration and time "
        read *,x,y,t 
         v1= x+y*t
        write (*,*) v1      ! final velocity 
       Case("displacement")
        write(*,*)"Input velocity, acceleration and time"
        read *, x,y,t
         v2= x*t -(y*(t**2))
        write(*,*)v2
       end select
end subroutine

subroutine binomial
 use constants
implicit none
   write(*,*) "Iterations:"
    read  *, x
   write(*,*) "Individual probability:"
    read  *, y
   write(*,*) "Desired (non-zero) number of outcomes:"
    read  *, z
   write(*,*) (x/z)*y**z*(1-y)**(x-z)
end subroutine    

subroutine projectile_array
   use constants
   implicit none
   real :: p,r,ycoord, xcoord, velocity, displacement
   integer (kind=i64) :: i,n,k,time
   n=0 
   write (*,*)"Velocity,angle, subsecond increment and supersecond increment"
   read*, x_lp, y_lp,p,k
   write (*,*)"Select terminal or file"
    read *, name
   write (*,*)"Input filename"
     read *, filename
      r = y_lp* (pi_lp/180.) 
   allocate (xarray(i,huge(n)))  
  open(unit=1,file=filename)         
    do i = 1, huge(n),k
         time= real(i/p)                                                            
         xcoord= x_lp*real(i/p)*(cos(r))                                            
         ycoord= x_lp*real(i/p)*(sin(r))-(0.5*g_earth*((i/p)**2))                     
         displacement= sqrt(xcoord**2 + ycoord**2)                                        
         velocity=sqrt(((x_lp*cos(r))**2)+((x_lp*sin(r)-g_earth*real(i/p))**2))     
          xarray(1,1)=time
          xarray(2,1)= xcoord                        
          xarray(3,1)= ycoord 
          xarray(4,1)= displacement
          xarray(5,1)= velocity
        if((ycoord .le. n) .or. (x_lp .gt. 299792458)) stop  
        Select case (name)
          Case ("file")
           write(1,*)"t:",xarray(1,1),"x:", xarray(2,1),"y:",xarray(3,1),"disp.:", xarray(4,1),"vel." ,xarray(5,1)
          Case ("terminal")
           write(*,*)"t:",xarray(1,1),"x:", xarray(2,1),"y:",xarray(3,1),"disp.:", xarray(4,1),"vel." ,xarray(5,1)
         end select
       end do   
        close(unit=1)     
   deallocate (xarray)

end subroutine

