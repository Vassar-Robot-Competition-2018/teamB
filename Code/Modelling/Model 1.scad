
//the distance between two platforms might not be 6cm if Legos are used to connect. 

translate([0,0,6]){
    difference() {
        cube([15.0,15.2,1.5]);
        //arduino board
        translate([8.0,1.0,0.4]) cube(size=[5.5,10.5,1.1], center=false);
        //plugin
        translate([8.0+0.95,0.0,0.4]) cube(size=[1.25,1.0,1.1], center=false);
        //plugin2
        translate([8.0+0.95+1.25+1.9,0.0,0.4]) cube(size=[1.0,1.0,1.1], center=false);
        //breakboard
        translate([1.5,1.0,0.4]) cube(size=[5.7,8.5,1.1], center=false);
    }
}


    union(){
        cube([15.0,15.2,0.5]);
        //RGB sensor vertical attachment. RGB width = 2.0
        translate([6.0, 0-0.2, 0-2.6]) cube(size=[2.4,0.2,0.5+2.6], center=false);
        //RGB sensor horizontal
        difference(){
            translate([6.0,0-0.2-0.8,0-2.6]) cube(size=[2.4,0.8,0.2], center=false);
            //two holes. 0.2cm in y is the distance from the hole to the margin
            translate([6.0 +0.4,0-0.2-0.8 +0.5,0-2.6]) cylinder(h=0.2, d=0.3, center=false, $fn=20);
            translate([6.0+0.4 + 0.3 + 1.2, 0-0.2-0.8+0.5, 0-2.6]) cylinder(h=0.2, d=0.3, center=false, $fn=20);
        }
        //walls
        difference(){
            translate([0,0,0+0.5]) cube(size=[15.0,0.5,2.2]);
            //a hole for the wires of the battery
            //!!meausure the wire lenghth again
            translate([6.0,0,0+1.5]) cube(size=[2.0,0.5,2.2]);
        }
        translate([0,15.2-0.5,0+0.5]) cube(size=[15.0,0.5,2.2]);
        //servo: left top
        difference(){
            translate([0,4.0,0.5]) cube(size=[2,2,1.0]);
            translate([0+0.5,4.0+2.0-0.5,0.5]) cube(size=[0.5,0.5,2.0]);
            
        }
        //servo: right top
        difference(){
            translate([0,4.0+2+4.1,0.5]) cube(size=[2,2,1.0]);
            translate([0+0.5, 4.0+2+4.1,0.5]) cube(size=[0.5,0.5,2.0]);
        }
        //servo: left bottom
        difference(){
            translate([15.0-2,4.0,0.5]) cube(size=[2,2,1.0]);
            translate([15.0+0.5-2,4.0+2.0-0.5,0.5]) cube(size=[0.5,0.5,2.0]);
            
        }
        //servo: right bottom
        difference(){
            translate([15.0-2,4.0+2+4.1,0.5]) cube(size=[2,2,1.0]);
            translate([15.0-2+0.5, 4.0+2+4.1,0.5]) cube(size=[0.5,0.5,2.0]);
        }
    }
