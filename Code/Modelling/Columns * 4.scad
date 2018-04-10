//print 4 columns to connect two bases

UBlength = 150.0; //length is x-axis
UBwidth = 165.0; //y-axis
UBheight = 17.0;
UBgapCam = 12.0;
UBgap1 = (UBlength - UBgapCam - ABwidth - BBwidth) / 2;
UBholeGap = 7.0;

//Camera Attachment
CAdiameter = 6.0;
CAradius = CAdiameter/2;
CAlength = 30.0;

//Lower Base
LBlength = UBlength;
LBwidth = UBwidth;
LBheight = 7.0;
LBgap1 = 30.0;
LBtranslate = -60.0;

//Columns
Clength = 8.0; 
Cheight = UBheight/2+LBheight/2-LBtranslate+Clength*2;
Cdiameter = 4.0;
Cradius = Cdiameter/2;
CLockHeight = 1.5;
CLockDiameter = 8.0;
CLockRadius = CLockDiameter/2;
Cdistance = 10.0;  //the center of the hole
holeX = UBlength/2 - Cdistance;
holeY = UBwidth/2 - Cdistance;
holeZ = -(Cheight/2-Clength-UBheight/2);

module cylinder_base(x,y){
    cylinder(h=x,r=y,center=true,$fn=50);
}

module column(){
    rotate([0,90,0]) cylinder_base(Cheight,Cradius);
}

module nut(){
    difference(){
    cylinder_base(CLockHeight,CLockRadius);
    cylinder_base(CLockHeight,Cradius);
    }
}


translate([0,-30,0]){
    nut();
    translate([10,0,0]) nut();
    translate([20,0,0]) nut();
    translate([-10,0,0]) nut();
    translate([0,10,0])nut();
    translate([10,10,0]) nut();
    translate([20,10,0]) nut();
    translate([-10,10,0]) nut();
}


column();
translate([0,10,0]) column();
translate([0,-10,0]) column();
translate([0,20,0]) column();
