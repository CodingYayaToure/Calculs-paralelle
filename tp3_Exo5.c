#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpi.h>

	/*$$$$$$$$$$$$$$$$ PROGRAMME_CALCULS_PI $$$$$$$$$$$$$$$$ */

/* ---------------------------------------------------- */

/* Definissons notre macro sans parenthese*/
#define PI 3.1415926535897932384626433832795029L

/* ----------------------------------------------------*/

// definissons notre fonction a integrer f(x) = 1 / (1 + x^2)
double f(double x){
	return (double )4.0/((double)1.0 + x*x);
}

/*--------------------------------------------------------*/

int main ( int argc , char * argv [])
{
	int nbbloc , mon_id , nb_procs , i;
	double calculs_pi , pi , largeur , somme , tmp;
	MPI_Init (&argc ,&argv );

	MPI_Comm_size ( MPI_COMM_WORLD ,& nb_procs );
	MPI_Comm_rank ( MPI_COMM_WORLD ,& mon_id );
	nbbloc = 0;

	
	if ( mon_id == 0) {
	 printf (" Veuillez Enter le nombre de points ... "); 
	 scanf ("%d" ,&nbbloc ); 
	MPI_Bcast (&nbbloc, 1, MPI_INT , 0 , MPI_COMM_WORLD );

/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ */

if ( nbbloc == 0) break ;
	else {
			largeur = 1.0 / ( double ) nbbloc ;
			somme = 0.0;
			for ( i = mon_id + 1; i <= nbbloc ; i += nb_procs ) {
				tmp = largeur * (( double ) i - 0.5);
				somme += f (tmp );
			}
			calculs_pi = largeur * somme ;
			MPI_Reduce (& calculs_pi , &pi , 1 , MPI_DOUBLE , MPI_SUM , 0 , MPI_COMM_WORLD );
			if(mon_id==0) { printf ("la valeur approcher de pi est %f %f : ... \n", pi , fabs ( pi - PI ));

			}
		}

	}
MPI_Finalize ();
return EXIT_SUCCESS ;
}


