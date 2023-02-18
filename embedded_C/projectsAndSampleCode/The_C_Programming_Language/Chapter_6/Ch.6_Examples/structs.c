
#include <stdio.h>

#define XMAX 100
#define YMAX 100

struct point_struct{
	int x;
	int y;
};
// Reserves no storage

struct point{
	int x;
	int y;
} a, b, c;
// Analogous to int a, b, c; but for structs
// Reserves storage for a, b, and c

struct point pt;
// Declares a point struct called pt

struct point pt1 = {320, 200};
// Initializing the pt instance of a struct point

struct rect{
	struct point pt1;
	struct point pt2;
};

struct rect screen;

struct point makepoint(int x, int y){
	// A function which returns a struct point
	
	struct point temp;
	// Declare a temporary point struct

	temp.x = x;
	temp.y = y;
	// Assign passed arguments to the members of the point

	return temp;
	// Return a struct point with passed values
}

struct point addpoint(struct point p1, struct point p2){
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

int pt_in_rect(struct point p, struct rect r){
	return p.x >= r.pt1.x && p.x < r.pt2.x
		&& p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct rect canonrect(struct rect r){
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
	// This function guarantees that pt1 coordinates are always less
	// than pt2 coordinates, which standardizes all rect returned from it
}

struct {
	int len;
	char *str;
} *p;

int main(int argc, char *argv[]){
	double dist, sqrt(double);
	printf("%d,%d\n", pt.x, pt.y);
	// Use the dot operator to access individual members of the struct pt
	dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);

	struct rect screen;
	struct point middle;
	struct point makepoint(int, int);
	
	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(XMAX, YMAX);
	middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
					   (screen.pt1.y + screen.pt2.y) / 2);

	struct point origin, *pp;


	pp = &origin;
	printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
	printf("origin is (%d,%d)\n", pp->x, pp->y);

	++p->len;
	// This increments len because -> binds tighter than ++

	return 0;

}
