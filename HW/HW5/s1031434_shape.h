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
	class Triangle:public shape{
	public:
		Triangle();
		float area();
		bool Valid();
		//bool Convex();
	};

}