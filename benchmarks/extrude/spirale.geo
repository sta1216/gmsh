
lc = 0.005;
lc2 = 4*lc;
Point(1)={0.09,0,0,lc};
Point(2)={0.11,0,0,lc};
Point(3)={0,0.09,0,lc};
Point(4)={0,0.11,0,lc};
Point(5)={0.2,0.09,0,lc};
Point(6)={0.2,0.11,0,lc};
Point(7)={0.09,0.2,0,lc};
Point(8)={0.11,0.2,0,lc};

Point(9)={0.09,0.09,0,lc2};
Point(10)={0.09,0.11,0,lc2};
Point(11)={0.11,0.11,0,lc2};
Point(12)={0.11,0.09,0,lc2};

Line(1) = {1,2};
Line(2) = {2,12};
Line(3) = {12,5};
Line(4) = {5,6};
Line(5) = {6,11};
Line(6) = {11,8};
Line(7) = {8,7};
Line(8) = {7,10};
Line(9) = {10,4};
Line(10) = {4,3};
Line(11) = {3,9};
Line(12) = {9,1};
Line Loop(13) = {2,3,4,5,6,7,8,9,10,11,12,1};
Plane Surface(14) = {13};

//Extrude Point {1, {0,0,0.1} };
//Extrude Point {1, {0,0,1} , {0.05,0.08,0} , Pi/2 };
//Extrude Point {1, {0,0,0.1} , {0,0,1} , {0.05,0.08,0} , Pi/2 , 10};
//Extrude Line {1, {0,0,0.1} , {0,0,1} , {0.05,0.08,0} , 0 , 10};
//Coherence;
//Extrude Line {1, {0,0,0.1}  };

turns = 1/3;
zz = 0.01;
cc = 0.1;

Extrude Surface {news-1, {0,0,2*zz}, {0,0,1} , {cc,cc,0} , 0}
                { Layers {2,1,1}; Recombine; };
For j In {1:3}
  Extrude Surface {news-1, {0,0,zz}, {0,0,1} , {cc,cc,0} , Pi/(40*(4-j))}
                { Layers {1,1,1}; Recombine; };
EndFor
For j In {1:turns*8}
  Extrude Surface {news-1, {0,0,10*zz}, {0,0,1} , {cc,cc,0} , Pi/4}
                { Layers {10,1,1}; Recombine; };
EndFor

For j In {1:3}
  Extrude Surface {news-1, {0,0,zz}, {0,0,1} , {cc,cc,0} , Pi/(40*j)}
                { Layers {1,1,1}; Recombine; };
EndFor

Extrude Surface {news-1, {0,0,2*zz}, {0,0,1} , {cc,cc,0} , 0}
                { Layers {2,1,1}; Recombine; };

Point(1000)={0.1, -0.02, 0,lc};
Point(1001)={0.1, -0.01, 0,lc};
Point(1002)={0.1, -0.02, 0.01,lc};
Point(1003)={0.1, -0.03, 0,lc};
Point(1004)={0.1, -0.02, -0.01,lc};
Circle(1635) = {1001,1000,1002};
Circle(1636) = {1002,1000,1003};
Circle(1637) = {1003,1000,1004};
Circle(1638) = {1004,1000,1001};
Line Loop(1639) = {1635,1636,1637,1638};
Plane Surface(1640) = {1639};

turns = 2;
zz = 0.01/4;

For j In {1:8*turns}
  Extrude Surface {news-1, {0,0,10*zz}, {0,0,1} , {cc,cc,0} , Pi/4}
                { Layers {10,1,1}; Recombine; };
EndFor

Point(4000)={0.1, -0.02 + 0.24, 0, lc};
Point(4001)={0.1, -0.01 + 0.24, 0, lc};
Point(4002)={0.1, -0.02 + 0.24, 0.01, lc};
Point(4003)={0.1, -0.03 + 0.24, 0, lc};
Point(4004)={0.1, -0.02 + 0.24, -0.01, lc};
Circle(4635) = {4001,4000,4002};
Circle(4636) = {4002,4000,4003};
Circle(4637) = {4003,4000,4004};
Circle(4638) = {4004,4000,4001};
Line Loop(4639) = {4635,4636,4637,4638};
Plane Surface(4640) = {4639};

For j In {1:8*turns}
  Extrude Surface {news-1, {0,0,10*zz}, {0,0,1} , {cc,cc,0} , Pi/4}
                { Layers {10,1,1}; Recombine; };
EndFor


