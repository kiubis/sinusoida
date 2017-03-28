#include <iostream>
#include <cstdlib>
#include <cmath>

#define debug(x) std::cout << #x <<": "<< x << std::endl
#define version std::cout<< __FILENAME__<<" "<< __DATE__ << " " << __TIME__<<std::endl

using namespace std;

void sinus();
int zaokraglanie(float fDol=0, float fGora=0, int iPrzedzial=0, float fWejscie=0);

int main(){

sinus();

system("PAUSE");
return 0;
}

void sinus(){
	
	int iRozx=0, iY=0, iRozy=0;
	float fSin=0;
	const float PI=3.1415;
	
	cout << "Podaj rozdzielczosc przedzialu X: \n";
	cin >>iRozx;
	cout << "Podaj rozdzielczosc przedzialu Y (nieparzysta): \n";
	cin >>iRozy;
	
	char (**kropka) = new char*[iRozx];
	for(int i=0; i<iRozx; i++)
		(kropka[i])=new char [iRozy];

		for(int i=0; i<iRozx; i++){
			for (int j=0; j<iRozy; j++){
				kropka[i][j]=32;
			}
		}
		
		for (int i=0; i<iRozx; i++){
				fSin=sin((360/iRozx)*i*PI/180);
			//	debug(fSin);
				iY=zaokraglanie(-1,1,iRozy-1,fSin);
			//	cout << "i:"<<i<<" iY:"<<iY<<endl;
				kropka[i][iY]=64;	
		}
		
		for(int j=0; j<iRozy/2; j++){
			cout << "|";
			for (int i=0; i<iRozx; i++){
				cout <<	kropka[i][j];
			}
			cout << endl;
		}
		
		for(int i=0; i<iRozx; i++)
			if(kropka[i][iRozy/2]==32)
				kropka[i][iRozy/2]=61;
				
			
		for(int j=iRozy/2; j<iRozy; j++){
			cout << "|";
			for (int i=0; i<iRozx; i++){
				cout <<	kropka[i][j];
			}
			cout << endl;
		}	
		delete kropka;
}

int zaokraglanie(float fDol, float fGora, int iPrzedzial, float fWejscie){
	float fTest=0, fZaok;
	int iZaok=0;
	
	fZaok=fWejscie-fDol;
	
	for (int i=0; i<=iPrzedzial; i++){
		fTest=fDol+i*((fGora-fDol)/iPrzedzial);
			if(fabs(fWejscie-fTest)<(fZaok)){
				iZaok=i;
				fZaok=fWejscie-fTest;
				}		
		}
	return iZaok;
}
