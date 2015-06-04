static enum ShapeType{
	Shape = 0, Triangle, Quadrilateral, Pentagon, Parallelogram, Square,
	Trapezium, Isosceles_triangle, Regular_triangle, Right_triangle, Polygon
};

static char *ShapeName[] = {
	"Shape", "Triangle", "Quadrilateral", "Pentagon", "Parallelogram", "Square",
	"Trapezium", "Isosceles_triangle", "Regular_triangle", "Right_triangle", "Polygon"
};

/* Triangle -> 三角形
   Quadrilateral -> 四邊形
   Pentagon -> 五邊形
   Parallelogram -> 平行四邊形
   Square -> 正方形
   Trapezium -> 梯形
   Isosceles_triangle -> 等腰三角形
   Regular_triangle -> 正三角形
   Right_triangle -> 直角三角形
   Polygon -> 多邊形  */