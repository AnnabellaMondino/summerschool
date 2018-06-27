typedef struct {
	int Nx;
	int Ny;
	double dx;
	double dy;
	double dx2;
	double dy2;
	double field[NX+2][NY+2];
} temp_field;


void array(temp_field *temp){
	int i, j;
    	// Initialize first the zeros
        for (i=1; i<(temp->Nx-1); i++){
                for (j=1; j<(temp->Ny-1); j++){
                        temp->field[i][j] = 0.;
                }
        }
    // Initial conditions for left and right
        for (i=0; i<temp->Nx; i++){
                temp->field[i][0] = 20.;
                temp->field[i][temp->Ny-1] = 70.;
        }
    // and top and bottom boundaries
        for (j=0; j<temp->Ny; j++){
               	temp->field[0][j] = 85.;
                temp->field[temp->Nx-1][j] =5.;
       	}
}


//double [][] laplacian(temp_field *temp){
void laplacian(temp_field *temp, double *laplacian){
	int i, j, ind;
        for (i = 1; i < temp->Nx-1; i++){
                for (j = 1; j < temp->Ny; j++){
                        double l1 = temp->field[i-1][j] - 2.*temp->field[i][j] + temp->field[i+1][j];
                        l1 /= temp->dx*temp->dx;

                        double l2 = temp->field[i][j-1] - 2.*temp->field[i][j] + temp->field[i][j+1];
                        l2 /= temp->dy*temp->dy;

                        ind = j * temp->Nx + i;   
                        laplacian[ind] = l1 + l2;
                }
        }
//        return laplacian
}
