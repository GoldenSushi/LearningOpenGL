#include "Curve.h"



Curve :: Curve(std::vector<Point> &points)
	   : m_points(points), m_iterations(0)
{
	createIndex(points);
}

Curve::~Curve()
{
}

std::vector<Point> Curve :: chaikinPoints(std::vector<Point>& points)
{
	std::vector<Point> newPoints;
	newPoints.push_back(points[0]);					//first point never changes

			for (int i = 0; i < points.size() - 1; ++i)
			{
				newPoints.push_back({ points[i].x + ((points[i + 1].x - points[i].x) * 0.25f),		//0.25 X point
									  points[i].y + ((points[i + 1].y - points[i].y) * 0.25f) });	//0.25 Y point

				newPoints.push_back({ points[i].x + ((points[i + 1].x - points[i].x) * 0.75f),		//0.75 X point
									  points[i].y + ((points[i + 1].y - points[i].y) * 0.75f) });	//0.75 Y point
			}

	newPoints.push_back(points[points.size() - 1]); //last point never changes
	return newPoints;
}

void Curve :: createIndex(std::vector<Point> points)
{
	int count = points.size() * 2;
	std::vector<unsigned int> indices;

			for (int i = 0; i < count; ++i)
			{
				indices.push_back(i);
				indices.push_back(i + 1);
			}

	m_indices = indices;
}

void Curve::setPoints(std::vector<Point> &points)
{
	m_points = points;
}

void Curve::setIterations(unsigned int &it)
{
	m_iterations = it;
}

std::vector<unsigned int> Curve::getIndices()
{
	return m_indices;
}

std::vector<Point> Curve :: chaikinCurve()
{
	std::vector<Point> resultPoints;
	resultPoints = chaikinPoints(m_points);

			for (int i = 0; i < m_iterations; ++i)
			{
				resultPoints = chaikinPoints(resultPoints);
			}

	m_points = resultPoints;
	createIndex(m_points); //updates index list
	return resultPoints;
}

std::ostream& operator<< (std::ostream& os, const Curve& curveObj)
{
	os << "[ ";
	for (int i = 0; i < curveObj.m_points.size(); ++i)
	{
			os
			<< " (" << curveObj.m_points[i].x 
			<< ", " 
			<< curveObj.m_points[i].y 
			<< ") ";
	}
	os << " ]" << std::endl;
	return os;
}