#include"1031434_Function.inl"
#include"1031434_MartixBase.hpp"
#include"1031434_Mat.hpp"
#include"1031434_Vec.hpp"
#include"1031434_VectorBase.hpp"

int main(){
	Mat_3x4<float> m1(Vec3<float>(2, 3, 4), Vec3<float>(1, 5, 7), Vec3<float>(2, 6, 2), Vec3<float>(1, 3, 9));
	Mat_4x3<float> m2(Vec4<float>(3, 3, 1, 2), Vec4<float>(5, 6, 2, 1), Vec4<float>(9, 3, 0, 8));
	Mat_3x3<float> m3 = m1 * m2;

	Mat_3x1<float> v1(Vec3<float>(3, 9, 5));
	Mat_3x1<float> v2 = m3 * v1;

	std::cout << "m1: \n";
	std::cout << m1 << std::endl;

	std::cout << "m1*2: \n";
	std::cout << m1*2.f << std::endl;

	std::cout << "m2: \n";
	std::cout << m2 << std::endl;

	std::cout << "m3 = m1 * m2 ;\nm3: \n";
	std::cout << m3 << std::endl;

	std::cout << "m3 * m3.Inverse (): \n";
	std::cout << m3 * m3.Inverse() << std::endl;

	std::cout << "m2.Transpose (): \n";
	std::cout << m2.Transpose() << std::endl;

	std::cout << "v1: \n";
	std::cout << v1 << std::endl;

	std::cout << "v2 = m3 * v1 ;\nv2: \n";
	std::cout << v2 << std::endl;

	std::cout << "v1.crossProduct (v2): \n";
	std::cout << v1.arr[0].cross(v2.arr[0]) << std::endl;

	std::cout << "v1.dotProduct (v2): \n";
	std::cout << v1.arr[0].dot(v2.arr[0]) << std::endl;

	system("PAUSE");
	return 0;
}