#include <iostream>
#include <cmath>
using namespace std;
int i, j;
int IMG2[4][5]={{5,5,7,2,2},
		       {5,5,6,2,1},
			   {1,1,1,2,1},
			   {0,1,0,1,1}};
int sobel_kernel_x[3][3]={{-1,0,1},
		       			  {-2,0,2},
			   			  {-1,0,1}};

int sobel_kernel_y[3][3]={{1,2,1},
		       			  {0,0,0},
			   			  {-1,-2,-1}};

int prewitt_kernel_x[3][3]={{-1,0,1},
		       			  {-1,0,1},
			   			  {-1,0,1}};

int prewitt_kernel_y[3][3]={{1,1,1},
		       			  {0,0,0},
			   			  {-1,-1,-1}};

void sobeledge(int IMG[4][5],int w,int h){
	int IMG_new[w][h];
	int pnew,sobel_x,sobel_y;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			IMG_new[i][j]=IMG[i][j];
		}
	}
	for(i=1;i<w-1;i++){
		for(j=1;j<h-1;j++){
			sobel_x=(sobel_kernel_x[0][0]*IMG[i-1][j-1])+
					(sobel_kernel_x[0][1]*IMG[i-1][j])+
					(sobel_kernel_x[0][2]*IMG[i-1][j+1])+
					(sobel_kernel_x[1][0]*IMG[i][j-1])+
					(sobel_kernel_x[1][1]*IMG[i][j])+
					(sobel_kernel_x[1][2]*IMG[i][j+1])+
					(sobel_kernel_x[2][0]*IMG[i+1][j-1])+
					(sobel_kernel_x[2][1]*IMG[i+1][j])+
					(sobel_kernel_x[2][2]*IMG[i+1][j+1]);
			
			sobel_y=(sobel_kernel_y[0][0]*IMG[i-1][j-1])+
					(sobel_kernel_y[0][1]*IMG[i-1][j])+
					(sobel_kernel_y[0][2]*IMG[i-1][j+1])+
					(sobel_kernel_y[1][0]*IMG[i][j-1])+
					(sobel_kernel_y[1][1]*IMG[i][j])+
					(sobel_kernel_y[1][2]*IMG[i][j+1])+
					(sobel_kernel_y[2][0]*IMG[i+1][j-1])+
					(sobel_kernel_y[2][1]*IMG[i+1][j])+
					(sobel_kernel_y[2][2]*IMG[i+1][j+1]);
			pnew=sqrt(sobel_x*sobel_x+sobel_y*sobel_y);
			if(pnew>255) pnew=255;
			IMG_new[i][j]=pnew;
		}
	}
	cout<<"sobel edge detection"<<endl;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			cout<<IMG_new[i][j]<<" ";
		}
		cout<<endl;
	}
}

void prewittedge(int IMG[4][5],int w,int h){
	int IMG_new[w][h];
	int pnew,prewitt_x,prewitt_y;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			IMG_new[i][j]=IMG[i][j];
		}
	}
	for(i=1;i<w-1;i++){
		for(j=1;j<h-1;j++){
			prewitt_x=(prewitt_kernel_x[0][0]*IMG[i-1][j-1])+
					(prewitt_kernel_x[0][1]*IMG[i-1][j])+
					(prewitt_kernel_x[0][2]*IMG[i-1][j+1])+
					(prewitt_kernel_x[1][0]*IMG[i][j-1])+
					(prewitt_kernel_x[1][1]*IMG[i][j])+
					(prewitt_kernel_x[1][2]*IMG[i][j+1])+
					(prewitt_kernel_x[2][0]*IMG[i+1][j-1])+
					(prewitt_kernel_x[2][1]*IMG[i+1][j])+
					(prewitt_kernel_x[2][2]*IMG[i+1][j+1]);
			
			prewitt_y=(prewitt_kernel_y[0][0]*IMG[i-1][j-1])+
					(prewitt_kernel_y[0][1]*IMG[i-1][j])+
					(prewitt_kernel_y[0][2]*IMG[i-1][j+1])+
					(prewitt_kernel_y[1][0]*IMG[i][j-1])+
					(prewitt_kernel_y[1][1]*IMG[i][j])+
					(prewitt_kernel_y[1][2]*IMG[i][j+1])+
					(prewitt_kernel_y[2][0]*IMG[i+1][j-1])+
					(prewitt_kernel_y[2][1]*IMG[i+1][j])+
					(prewitt_kernel_y[2][2]*IMG[i+1][j+1]);
			pnew=sqrt(pow(prewitt_x,2)+pow(prewitt_y,2));
			if(pnew>255) pnew=255;
			IMG_new[i][j]=pnew;
		}
	}
	cout<<"prewitt edge detection"<<endl;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			cout<<IMG_new[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char** argv) {
	sobeledge(IMG2,4,5);
	cout<<endl;
	prewittedge(IMG2,4,5);
	system("pause");
	return 0;
}
