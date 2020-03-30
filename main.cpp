#include <iostream>
using namespace std;
int i,j;
int IMG[4][5]={{55,15,77,12,12},
			   {158,115,65,72,33},
			   {112,10,125,42,91},
			   {201,111,1,31,18}};
void brightness(int IMG[4][5],int w,int h,int b){
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			IMG[j][i]+=b;
			if(IMG[j][i]>255) IMG[j][i]=255;
			else if(IMG[j][i]<0) IMG[j][i]=0;
		}
	}
	cout<<"Brightness"<<endl;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			cout<<IMG[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char** argv) {
	brightness(IMG,4,5,50);
	system("pause");
	return 0;
}
