#ifndef PG2_main
#define PG2_main

static enum ShapeType{
	Shape = 0, Triangle, Quadrilateral, Pentagon, Parallelogram, Square,
	Trapezium, Isosceles_triangle, Regular_triangle, Right_triangle, Polygon
};

static char *ShapeName[] = {
	"Shape", "Triangle", "Quadrilateral", "Pentagon", "Parallelogram", "Square",
	"Trapezium", "Isosceles_triangle", "Regular_triangle", "Right_triangle", "Polygon"
};

#endif

/* Triangle -> �T����
   Quadrilateral -> �|���
   Pentagon -> �����
   Parallelogram -> ����|���
   Square -> �����
   Trapezium -> ���
   Isosceles_triangle -> ���y�T����
   Regular_triangle -> ���T����
   Right_triangle -> �����T����
   Polygon -> �h���  */