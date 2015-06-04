#include"s1031434_main.h"
#include<vector>

namespace MIME{
	class Vertex{
	public:
		Vertex();
		Vertex(const float, const float);
		void print();
		float x, y;
	};

	class shape{
	public:
		shape();
		size_t addVertex(const float, const float);
		size_t addVertex(Vertex&);
		ShapeType getShape();
		void print();
		virtual float area() = 0;
		virtual bool Valid() = 0;
		//virtual bool Convex() = 0;
	protected:
		ShapeType currentType;
		std::vector<Vertex> V;
	};
	class Triangle :public shape{
	public:
		Triangle();
		float area();
		bool Valid();
		//bool Convex();
	};

	class Quadrilateral :public shape{
	public:
		Quadrilateral();
		float area();
		bool Valid();
		//bool Convex();
	};
	class Pentagon :public shape{
	public:
		Pentagon();
		float area();
		bool Valid();
		//bool Convex();
	};

	class Parallelogram :public Quadrilateral{
	public:
		Parallelogram();
		float area();
		bool Valid();
		//bool Convex();
	};

	class Square :public Parallelogram{
	public:
		Square();
		float area();
		bool Valid();
		//bool Convex();
	};

	class Trapezium :public Quadrilateral{
	public:

	};

	class Isosceles_triangle :public Triangle{
	public:

	};

	class Regular_triangle :public Isosceles_triangle{
	public:

	};

	class Right_triangle :public Triangle{
	public:

	};

	class Polygon :public shape{
	public:
		Polygon();
		float area();
		bool Valid();
		//bool Convex();
	};

}