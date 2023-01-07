#include<stdio.h>
#include<stdlib.h>
#include <math.h>
//Macro sans para
#define PI 3.1415926535897932384626433832795029L

//function a integre
double f(double x){
	return (double)4.0/((double) 1.0 + (double)x*x  );
}

/*$$$$$$$$$$$$$$$$$$$$FUNCT MAIN$$$$$$$$$$$$$$$$$$$*/

int main(int argc, char*argv[])
{
	/* declaration des variable */

	int nbbloc , mon_id , nb_procs , i; //avec nbbloc = nb_points
	double calculs_pi , largeur , somme , tmp; // calculs_pi = surface

	printf("Veuillez-saisir le nombre de points ...sinon taper 0 pour quitter le programme\n");
	scanf("%d", &nbbloc);

	/* Si le nombre de points est egale a 0 , 
	quitter de facon prematurer le programme */

	if (nbbloc == 0)
	{
		/* quitter le programme */

		return 0;
	}

	largeur = (double)1.0 / (double)nbbloc;

	//Par defaut aucune operation n'a ette effectue
	somme = 0.0;
	//Puisque nous avons une sommation, alors utilisons la boucle fort

	for (int i = 0; i < nbbloc; ++i)
	{
		/* Je recupere le tmp */
		tmp = largeur*((double)i - (double)0.5);
		somme += f(tmp); 
	}

	calculs_pi = largeur*somme;
	printf("Le resultat de l'approximation de pi =  %f\n",calculs_pi);
	printf("Evaluation = %f\n", fabs(calculs_pi - PI));

	return EXIT_SUCCESS;
}