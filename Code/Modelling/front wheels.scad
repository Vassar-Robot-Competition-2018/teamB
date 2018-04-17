module cylinder_base(x,y){
    cylinder(h=x,r=y,center=true,$fn=50);
}

//changing the holes to poles
module pole_base(x,y,z){
    translate([x,y,z])
    cylinder(h=Cheight,r=Cradius,center = true, $fn=50);
}

//front wheels attachement
FWAdiameter = 21.5;
FWAradius = FWAdiameter/2;
FWAheight2 = 2.5;
FWAdistance = 15.0;
FWAholeRadius = 2.0/2;

FWApoleDiameter = 8.0;
FWApoleRadius = FWApoleDiameter/2;
FWApoleheight = 20.0;

hole2X = UBlength/2 - FWAdistance;
hole2Y = UBwidth/2 - FWAdistance;
hole2Z = LBtranslate+LBheight/2;

module front_wheel_holes(){
    translate([hole2X,hole2Y,hole2Z]){
        cylinder_base(15.0,FWAradius);
    }
}


module front_wheel(){
    cylinder_base(FWApoleheight,FWApoleRadius);
    difference(){
        translate([0,0,-FWApoleheight/2]) cylinder_base(FWAheight2,FWAradius);
        translate([FWAdistance/2,0,-FWApoleheight/2]) cylinder_base(FWAheight2,FWAholeRadius);
        translate([-FWAdistance/2,0,-FWApoleheight/2]) cylinder_base(FWAheight2,FWAholeRadius);
    }
}

front_wheel();