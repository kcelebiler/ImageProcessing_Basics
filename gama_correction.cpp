#include <iostream>
#include <cmath>
using namespace std;
int i,j;
float IMG[4][5]={{55,15,77,12,12},
			   {158,115,65,72,33},
			   {112,10,125,42,91},
			   {201,111,1,31,18}};
			   
void gamacorrection(float IMG[4][5],int w,int h,float g){
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			IMG[j][i]=255*pow(IMG[j][i]/255, 1/g);
			if(IMG[j][i]>255) IMG[j][i]=255;
			else if(IMG[j][i]<0) IMG[j][i]=0;
		}
	}
	cout<<"gama correction"<<endl;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			cout<<trunc(IMG[i][j])<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char** argv) {
	gamacorrection(IMG,4,5,0.5);
	system("pause");
	return 0;
}
