/*************************************************************
**************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
**************************************************************
*************************************************************/

#include <string>
#include "random.h"

using namespace std;
 
int main (int argc, char *argv[]){

   Random rnd;
   int seed[4];
   int p1, p2;
   ifstream Primes("Primes");
   if (Primes.is_open()){
     Primes >> p1 >> p2 ;
	 Primes >> p1 >> p2 ;
   } else cerr << "PROBLEM: Unable to open Primes" << endl;
   Primes.close();

   ifstream input("seed.in");
   string property;
   if (input.is_open()){
      while ( !input.eof() ){
         input >> property;
         if( property == "RANDOMSEED" ){
            input >> seed[0] >> seed[1] >> seed[2] >> seed[3];
            rnd.SetRandom(seed,p1,p2);
         }
      }
      input.close();
   } else cerr << "PROBLEM: Unable to open seed.in" << endl;

   int i, j, k; //Contatori
   double box = 10.0; //Lato della scatola
   double dr; //Distanza particella-origine
   int tot_bin = 5; //Numero totale di bin
   int n_bin; //Bin in cui si trova la particella
   int g_r[tot_bin]; //Istogramma, funzione di distribuzione radiale

   for(k=0; k<tot_bin; k++){ //Inizializzo il vettore a zero
      g_r[k] = 0;   
   }
   
   for(i=0; i<100; i++){
	  dr = box*rnd.Rannyu(); //Estraggo una distanza
	  n_bin = tot_bin*(dr/box); //Calcolo in quale bin cade la particella
	  //cout << n_bin << endl;
	  g_r[n_bin] += 1; //Incremento di 1 particella il bin di indice n_bin	  
   }
   
   for(j=0; j<tot_bin; j++){
      cout << "Il bin " << j << " contiene " << g_r[j] << " particelle." << endl;   
   }

   rnd.SaveSeed();
   return 0;
}

/*************************************************************
**************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
**************************************************************
*************************************************************/
