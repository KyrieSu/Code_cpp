Assignment 05 - the Shapes
===================

Please attend my course and read ***Hw5_The_Shapes.pdf*** carefully.

This time, we ask you to create a series of classes to manage various type of shape and provide basic operations on shapes.

These operation include:

print(): Print information of this shape.

Example:
> TYPE: Pentagon <br>
(2.01, 4.56) <br>
(7.45, 5.65) <br>
(6.55, 2.44) <br>
(3.05, 0.0) <br>
(0.0, 3.15) <br>

getType(): return **ShapeType** directly. (the Enumeration)

getArea(): return the area(float) of this shape.

isValid(): check the correctness of shape type.
for example, a Square has 4 right angle, a Pentagon has 5 vertices, a Parallelogram has 2 pair of parallel lines...

isConvex(): check the shape is convex or not. (BONUS)

Besides, the collection of shapes are "Shape, Triangle, Quadrilateral, Pentagon, Parallelogram, Square, Trapezium(BONUS), Isosceles_triangle, Regular_triangle, Right_triangle(BONUS), Polygon(BONUS)"

Please refer to pdf file for more detail.



Sample inputs
-------------
>  3   2.01 4.56  7.45  5.65  6.55  2.44  3.05  0.0  0.0  3.15 <br>
1   2.01 4.56  7.45  5.65  6.55  2.44 <br>
7   -2.0  0.0 0.0 6.0 2.0 0.0  <br>

Sample outputs
-------------
> \# of shapes = 3 <br>
TYPE: Pentagon <br>
(2.01,4.56) <br>
(7.45,5.65) <br>
(6.55,2.44) <br>
(3.05,0) <br>
(0,3.15) <br>
AREA: ... (please calculate this value by yourself) <br>
Valid?: YES <br>
Convex?: YES <br>
 <br>
TYPE: Triangle <br>
(2.01,4.56) <br>
(7.45,5.65) <br>
(6.55,2.44) <br>
AREA: ... <br>
Valid?: YES <br>
Convex?: YES <br>
 <br>
TYPE: Isosceles_triangle <br>
(-2,0) <br>
(0,6) <br>
(2,0) <br>
AREA: 2 <br>
Valid?: YES <br>
Convex?: YES <br>
 <br>
 
----------

There are at least five files need to be submitred: (s1234567 is just a example of student ID)

s1234567hw5_main.h (hw5_main.h) > the header of driver program

s1234567hw5_main.cpp (hw5_main.cpp) > the driver program

s1234567hw5_Shape.h (Shape.h) > your own classes
s1234567hw5_shape.cpp (Shape.cpp) > partial implmentation

In the end, please follow rules strictly. (Include 作業繳交規範 by 徐皓)

**Due date:  6/6 (Sat.)**

----------
A common workflow of preparation of your homework
-------------
(In the following text, we assume your student ID is s1234567 and # is the NUMBER of homework in one digit, Please replace it with your student ID and follow the steps exactly!)


1. Clone your private repository of hw# to your home directory on server or another suitable location from our organization on GitHub (https://github.com/YZU-CSE-CS114-Computer-Programming-II)

2. After you start to deal with your homework, add a file s1234567hw#_main.cpp as your main program and s1234567hw#_report.md as your report (optional). Then, commit it! **(Don't forget to push it onto GitHub, too)** 
**Any of your code should be prefixed with "s1234567hw#_"**.

3. Complete your program and write your report (if necessary) with Markdown.
*. Please commit your homework when you have any progress (The project should be compilable 可編譯).

4. Make sure you have complete the assignment and prepare a clear demo in your report. **Do it ON YOUR OWN and ON TIME.** (You have **only 2 chances in this semester** to request additional time for doing your homework, each chance will give you additional **24Hours**. Please contact the TAs **BEFORE** the deadline and use it wisely)
