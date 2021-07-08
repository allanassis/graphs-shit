/*Neste programa voc� vai trabalhar com o algoritmo de Dijkstra
   para digrafos, usando a representa��o de matriz de adjac�ncias,
   e implementando a Quest�o 3 da P1.
1. Implemente o algoritmo de Dijkstra.
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
const int NVM=1001;
const int INF=1000000000;
struct nojar{int x;  int y;};
// Declara��es para o grafo
int a, b, c, n, m, pre[NVM], E[NVM][NVM], Di[NVM];  nojar noj;

int min(int x, int y){
	if(x > y){
		return y;
	}
	return x;
}

void Inicializa(int n){
    memset(E, 0, sizeof(E));
    memset(pre, 0, sizeof(pre));    
    for (int i=1; i<=n+1; i++) Di[i]=INF;
    m=0;
}

int Converte (int x, int y, int a, int b){
    return ((b+1)*x + y+1);
}

nojar InvConv (int r, int a, int b){
    nojar noj;
    noj.y = (r-1) % (b+1);
    noj.x = (r-noj.y-1)/(b+1);
    return noj;
}

void CriaDigrafo (int n, int a, int b){
    int v, w, xo, xd, yo, yd, t;  nojar nojo, nojd;
    for (v=1; v<=(a+1)*(b+1); v++){
        noj = InvConv(v, a, b);  xo = noj.x;  yo = noj.y;
		//Aresta do tipo 1: encher o jarro 1
		if (xo < a){
		    xd = a;  yd = yo;  w = Converte(xd, yd, a, b);
		    m++;  E[v][w] = 1;
		}     
		//Aresta do tipo 2: encher o jarro 2
		if (yo < b){
		    xd = xo;  yd = b;  w = Converte(xd, yd, a, b);
		    m++;  E[v][w] = 2;
		}    
		//Aresta do tipo 3: esvaziar jarro 1
		if (xo > 0){
		    xd = 0;  yd = yo;  w = Converte(xd, yd, a, b);
		    m++;  E[v][w] = 3;
		}     
		//Aresta do tipo 4: esvaziar jarro 2
		if (yo > 0){
		    xd = xo;  yd = 0;  w = Converte(xd, yd, a, b);
		    m++;  E[v][w] = 4;
		}  
		//Aresta do tipo 5: transferir do jarro 1 para o 2
		if (xo > 0 && yo < b){
		    t = min(xo, b-yo);  xd = xo-t;  yd = yo+t;  w = Converte(xd, yd, a, b);
		    m++;  E[v][w] = 5;
		}  	
		//Aresta do tipo 6: transferir do jarro 2 para o 1
		if (xo < a && yo > 0){
		    t = min(a-xo, yo);  xd = xo+t;  yd = yo-t;  w = Converte(xd, yd, a, b);
		    m++;  E[v][w] = 6;
		}			    
    }
}

void Dijkstra(int v){
	int i, j, w, z;
		
	Di[v] = 0;
	for(int i = 1; i <= n; i++){
		w = n + 1;
		for(int j = n; j >= 1; j--){
			if(pre[j] != 0 && Di[j] <= Di[w]){
				w = j;
			}
		}
		pre[w] = 1;
		for(int z = 1; z <= n ; z++){
			if(E[w][z] > 0 && pre[z] == 0){
				Di[z] = min(Di[z], Di[w] + 1);
			}
		}
	}
 /* 	Di[v] <-  0  
	para i <- 1..n incl.:
		w <- n+1
		para j <- n..1 incl.:
			se j n�o marcado e Di[j] <= Di[w]:
				w <- j
        marcar w
		para z <- 1..n incl.:
			se E[w,z]> 0 e z n�o marcado: 
				Di[z] <-  min( Di[z], Di[w] + 1)
*/
}

void CaminhoMinimo(int v,int t, int d){
    int i;  nojar noj;
	if(Di[t] > 0){
		for(int i = 1; i <= NVM; i++){
			if(E[i][t] > 0 && Di[i]+E[i][t] == d){
				CaminhoMinimo(v, i, Di[i]);
				break;
			}
		}
	}
/*  se Di[t] > 0:
        para i <- 1..n incl.:
            se  E[i,t] > 0 e  Di[i]+E[i,t] = d:
                CaminhoMinimo(v, i, Di[i])
                parar loop
    escrever (t)
// */
    if (Di[t] > 0){
        for (i=1; i<=n; i++){
            if (E[i][t] > 0 && Di[i]+1 == d){
                CaminhoMinimo(v, i, Di[i]);
                break;
            }
        }
    }
    noj = InvConv(t, a, b);
    cout<<noj.x<<"/"<<noj.y<<"("<<d<<")"<<"   ";
}

int main(){
    int i, j, k,v, vf, vi, t, xi, yi, xf, yf;  
	while (true){
        cout<<endl<<"Par�metros dos jarros: a b = ";  cin>>a>>b;
        n =(a+1)*(b+1);
	    Inicializa(n);   
        CriaDigrafo(n, a, b);
        for (i=1; i<=n; i++){
            for (j=1; j<=n; j++) cout<<E[i][j]<<" "; cout<<endl;
        }
	    cout<<endl<<"Situa��o inicial xi yi =: "; cin>>xi>>yi;
	    vi = Converte(xi, yi, a, b);
	    Dijkstra(vi);
	    cout<<"Distancias minimas: ";
	    for(i=1; i<=n; i++) cout<<Di[i]<<" ";  cout<<endl<<endl;
	    while(true){
            cout<<endl<<endl<<"Caminho minimo para: xf yf = " ; cin>>xf>>yf;
            vf = Converte(xf, yf, a, b);
	        if (xf == -1) break;
	        cout<<endl;
            CaminhoMinimo(vi, vf, Di[vf]);
        }	    
	}
	return 0;
}


