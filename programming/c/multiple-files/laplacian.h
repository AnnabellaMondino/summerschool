#define NX 5
#define NY 8


typedef struct {
	int Nx;
	int Ny;
	double dx;
	double dy;
	double dx2;
	double dy2;
	double field[NX+2][NY+2];
} temp_field;


void array(temp_field *temp);

void laplacian(temp_field *temp, double *laplacian);
