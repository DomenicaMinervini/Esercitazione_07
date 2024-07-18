#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//Questo file mi è servito come test per scrivere il codice Python che calcola la correlazione 
//tra gli elementi consecutivi dei blocchi. I valori nei vettori sono da esempio. 

int main(int argc, char * argv[]){
	
   /*PARTE 1: AUTOCORRELAZIONE
   int i,j; //contatori, indici nel vettore: t'
   int t = atoi(argv[1]); //passo nel vettore  
   int t = 0; //passo nel vettore   
   int t_max = 12; //dimensione del vettore   //vettore da studiare
   double m[t_max] = {14.50,13.39,12.50,12.00,10.58,8.25,8.00,7.36,6.91,6.50,6.45,3.08};
     
   double sum_a = 0; //somma dei prodotti a
   double sum_b = 0; //somma dei prodotti b
   double sum_c = 0; //somma dei prodotti c
   double sum_d = 0; //somma dei prodotti d
   double sum_e = 0; //somma dei prodotti e

   double fat; //fattore moltiplicativo del numeratore  
   double fmx; //fattore moltiplicativo del denominatore
   double chi; //funzione di autocorrelazione: la calcolo per tutti i valori di t


   fmx = 1.0/t_max; //fattore che dipende solo da t_max: è uguale per ogni t
  
   for(j=0;j<t_max;j++){ //dipendono da t_max: sono uguali per ogni t
      sum_d += m[j]*m[j];
      sum_e += m[j];	  
   }


   for(t=0; t<t_max; t++){ //calcolo le somme e chi per ogni t, 0<t<t_max
     
      //azzero le somme ad ogni ciclo, per ogni t e quindi per ogni chi
      sum_a = 0;
      sum_b = 0;
      sum_c = 0;
      fat = 1.0/(t_max-t); //fattore moltiplicativo del numeratore: è diverso per ogni t
	  	  
      for(i=0; i<t_max-t; i++){
	     sum_a += m[i]*m[i+t];
	     sum_b += m[i];
	     sum_c += m[i+t];
      }

      cout << sum_a << "  " << sum_b << "  " << sum_c << "  " << sum_d << "  " << sum_e << endl;    
      chi = (fat*sum_a-fat*fat*sum_b*sum_c)/(fmx*sum_d-fmx*fmx*sum_e*sum_e);
      cout << "La funzione di autocorrelazione per t = " << t << " vale: " << chi << endl;
	  
   }
   cout << "Ho calcolato:  " << t_max-t << "  prodotti" << endl;*/
   
   //PARTE 2: INCERTEZZA STATISTICA
   /*int i, j, iblk; //Contatori: indice di lunghezza, indice di elemento e indice di blocco.
   int M = 12; //Numero di lanci = dimensione del vettore.
   //int L = atoi(argv[1]); //Numero di elementi in un blocco = lunghezza del blocco. 
   int L[6] = {12,6,4,3,2,1}; //Vettore con le lunghezze possibili dei blocchi.
   int l = 0; //Lunghezza del blocco selezionata in un ciclo.
   int N = 0; //Numero di blocchi in cui suddivido il vettore = elementi totali / lunghezza blocco.

   double somma = 0; //Somma degli elementi del vettore.   
   double m[M] = {14.50,13.75,13.39,12.00,10.58,8.25,8.00,7.60,7.36,6.50,6.45,3.08};
   double mean[N]; //Vettore con le medie di blocco.
   double square[N]; //Vettore con i quadrati delle medie di blocco. 
   
   double sum_mean = 0; //Somma degli elementi del vettore medie.
   double sum_square = 0; //Somma degli elementi del vettore dei quadrati.
   double mean_mean; //Media delle medie.
   double mean_square; //Media dei quadrati delle medie. 
   
   double varianza;
   double stdev;
   double incertezza;*/

   /* iblk*len: inizio del blocco = numero totale di elementi nei blocchi precedenti.
    (iblk+1)*len: fine del blocco = numero totale di elementi precedenti + di questo blocco.
	  L'indice i scorre su tutti gli elementi contenuti nel blocco iblk-esimo. Fa la somma degli elementi
      selezionati nel vettore, poi al ciclo successivo riparte dal punto a cui era arrivato. */

   /*for(i=0;i<6;i++){
	  l = L[i];
      N = M/l; //Calcola il numero di blocchi per ogni lunghezza.
	  sum_mean = 0;
	  sum_square = 0;
	  
      for(iblk=0;iblk<N;iblk++){ //Per ogni blocco,
         somma = 0; //Azzero la somma all'inizio del ciclo.
	  
         for(j=iblk*l;j<(iblk+1)*l;j++){ //all'interno di ciascun blocco.
            //cout << m[j] << endl; 
            somma += m[j];	  
         }
	  
         mean[iblk] = somma/double(l);
         square[iblk] = (mean[iblk])*(mean[iblk]); 
         //cout << "La media per il blocco  " << iblk+1 << "   vale:  " << mean[iblk] << endl;  
	  
         sum_mean += mean[iblk]; //Somma degli elementi del vettore medie, dal valore 0 al valore numero di blocchi.
         sum_square += square[iblk]; //Somma degli elementi del vettore dei quadrati, dal valore 0 al valore numero di blocchi.

         mean_mean = sum_mean/double(iblk+1); //Calcolo la media dei valori medi di ogni blocco, aggiungendo ogni volta un blocco.
         mean_square = sum_square/double(iblk+1); //Faccio lo stesso per i quadrati delle medie.	
	     //cout << "La media delle medie per  " << iblk+1 << "  blocchi vale:  " << mean_mean << endl;
	  
         if(iblk == 0){ //Nel caso in cui si abbia un solo blocco, l'incertezza statistica è posta a 0.
            varianza = 0;
            stdev = 0;
            incertezza = 0; 
         }
         else{
            varianza = mean_square - mean_mean*mean_mean; //Varianza per la media di 1 blocco, 2 blocchi, ... , N blocchi,
            stdev = sqrt(varianza); //lo stesso per la deviazione standard.
            incertezza = stdev/(sqrt(iblk)); //Incertezza stastistica del valor medio, se sono stati generati iblk blocchi.
            //Nella formula dell'incertezza statistica si divide per un fattore radice di N-1. Dato che il primo elemento del vettore
            //è il numero zero, N è già ridotto di 1. Quindi nella formula divido per la radice di N, ossia per iblK blocchi.
         }
	  
	     //cout << "Numero di blocchi,  media  , incertezza. " << endl;
	     //cout << iblk+1 << "  " << mean_mean << "  " << incertezza << endl;

      }   
	  
      cout << "Lunghezza blocco: " << l << ", media: " << mean_mean << ", incertezza finale: " << incertezza << endl;
   }   */
   

   //PARTE 3: FILE CON LE LUNGHEZZE
   fstream f;
   f.open("lenght.dat", ios::out);
   
   for(int i=0; i<101;i++){
      f << 50*i << endl;   
   }
  
   f.close();
   return 0;
    
}