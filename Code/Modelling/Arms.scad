//Front Wall
FWlength = LBwidth; //y-axis
FWwidth = 25.0;  //x-axis
FWheight = 30.0;
FWhole = 25.0;
FWgap1 = (FWlength - FWhole)/2;  //distance to the gap
FWgap2 = (FWlength - RGBlength)/2;

//Lower Base
LBlength = UBlength;
LBwidth = UBwidth;
LBheight = 7.0;
LBgap1 = 30.0;
LBtranslate = -60.0;

//RGB
RGBlength = 20.44;
RGBdiameter = 2.9;
RGBA = 12.5;
RGBB = 1.0;

//RGB attachment
RAwidth = RGBlength; //y-axis
RAheight = 15.0;  //z-axis
RAdepth = 5.0; //x-axis

//battery hole
BAlength = 5.0; //y
BAheight = 20.0; //z
BAdepth = FWwidth;

//arms attachment
AAlength = 20.0;
AAwidth = 5.0; //y-axis
AAheight = 40.0;
AAdistance = 90.0;
AAtranslate = 20.0;
AAholeHeight = AAheight/2 - (AAtranslate - FWheight/2) + LBheight;

//Arm connection
ACdistance = 30.0 + AAlength; //needs to be greater than RB2length = 20.0; 
AAdistance = 90.0;
AClength = AAdistance + AAwidth;
ACheight = FWheight- AAtranslate + AAheight/2 + RBheight - RAheight;
ACwidth = 4.0;

module cube_true(x, y, z){
    cube(size = [x, y, z], center = true);
}

//sticking-out
SOlength = ACdistance; //y
SOheight = AAheight; //z
SOwidth = AAwidth; //x

module SO(x){
    translate([x,0,0]){
            difference(){
            cube_true(SOwidth,SOlength,SOheight);
            translate([0,AAlength/2-SOlength/2,SOheight/2-AAholeHeight/2]) cube_true(AAwidth,AAlength,SOheight-AAholeHeight);
            }
        }
    }

SO(AAdistance/2);
SO(-AAdistance/2);

