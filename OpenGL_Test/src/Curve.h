#ifndef CURVE_H
#define CURVE_H
#include <vector>
#include <iostream>

struct Point
{
	float x, y;
};

class Curve
{
private:

	std::vector<Point>			m_points;
	unsigned int				m_iterations;
	std::vector<unsigned int>	m_indices;

private:

	std::vector<Point>			chaikinPoints(std::vector<Point>& points);	//calculate new points
	void						createIndex(std::vector<Point> points);		// calculate indices to use in element buffers

public:

	Curve(std::vector<Point> &points);
	~Curve();

	void						setPoints(std::vector<Point> &points);
	void						setIterations(unsigned int &it);
	std::vector<unsigned int>	getIndices();
	std::vector<Point>			chaikinCurve();

	friend std::ostream&		operator<<(std::ostream& os, const Curve& curveObj);
};

/*		
	Example on how to use this class.

	1)	Load the points inside the class
	2)	set the iterator based on how many cutting edge steps wil be performed
	3)	Call chaikinCurve to calculate the points and itterate
	4)	Call getIndices to retrieve the element buffer vector


		Point				point0{ 0.0f, 0.0f };
		Point				point1{ 0.2f, 0.5f };
		Point				point2{ 0.3f, 0.1f };
		Point				point3{ 0.5f, 0.3f };
		Point				point4{ 0.4f, 0.5f };

		std::vector<Point>	points1
		{
							point0,
							point1,
							point2,
							point3,
							point4
		};

		Curve				chaikin(points1);
		unsigned int		it = 1;

		chaikin.setIterations(it);
		points1 = chaikin.chaikinCurve();

		std::cout << chaikin << std::endl;

		std::vector<unsigned int> indices;
		indices = chaikin.getIndices();
*/

#endif CURVE_H