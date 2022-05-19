#ifndef CA1PROB5
#define CA1PROB5
// the class rectangle
class rectangle {
private:
	double width;
	double length;
	double perimeter;
	double area;
public:
	
	// Constructor, automatically compute the perimeter and area once it is OK.
	rectangle(double wd, double lg);
	
	// Set the dimension and automatically update the perimeter and area.
	void setDimension(double wd, double lg);
	
	// Set the width and automatically update the perimeter and area.
	void setWidth(double wd);
	
	// Set the length and automatically update the perimeter and area.
	void setLength(double lg);
	
	// Return the width of the rectangle.
	double getWidth();
	
	// Return the length of the rectangle.
	double getLength();
	
	// Return the perimeter of the rectangle.
	double getPerimeter();
	
	// Return the area of the rectangle.
	double getArea();
	
	// True, if width = length.
	bool isSquare();
	
	// to show all aata fast
	//void showalldata();
};

#endif // !CA1PROB5

