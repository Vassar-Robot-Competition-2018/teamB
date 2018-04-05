
module cylinder_base(x,y){
    cylinder(h=x,r=y,center=true,$fn=50);
}

module nut(){
    difference(){
    cylinder_base(CLockHeight,CLockRadius);
    cylinder_base(CLockHeight,Cradius);
    }
}


translate([0,0,10]){
    nut();
    translate([10,0,0]) nut();
    translate([20,0,0]) nut();
    translate([-10,0,0]) nut();
    translate([0,10,0])nut();
    translate([10,10,0]) nut();
    translate([20,10,0]) nut();
    translate([-10,10,0]) nut();
}


