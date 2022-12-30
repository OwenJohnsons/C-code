#ifndef COORD_H_TWYFUKH2
#define COORD_H_TWYFUKH2


/*! @struct _Coord 
 *  @brief Simple structure to hold a coordinate
 *
 */
typedef struct _Coord {
	char c;
	int x;
	int y;
} Coord;

/* Function Proto-types */

int sort_x_then_y(const void *f1, const void *f2); /* sorting x values in the struct by decending values */

int sort_y_then_x(const void *f1, const void *f2); /* sorting y values in the struct by decending values */

/* Function Defintions */
sort_x_then_y(const void *f1, const void *f2)
{
	Coord *c1 = (Coord *)f1;
	Coord *c2 = (Coord *)f2;

	if (c1->x == c2->x) {
		return c1->y - c2->y;
	} else {
		return c1->x - c2->x;
	}
}

sort_y_then_x(const void *f1, const void *f2)
{
	Coord *c1 = (Coord *)f1;
	Coord *c2 = (Coord *)f2;

	if (c1->y == c2->y) {
		return c1->x - c2->x;
	} else {
		return c1->y - c2->y;
	}
}

#endif /* end of include guard: COORD_H_TWYFUKH2 */

