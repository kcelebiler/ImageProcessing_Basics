#include <iostream>
using namespace std;
int i, j;
int IMG_laplacian[4][5]={{5,5,7,2,2},
		       			 {5,5,6,2,1},
			   			 {1,1,1,2,1},
			   			 {0,1,0,1,1}};
			   			 
int IMG_sharpen[4][5]={{5,5,7,2,2},
		       		   {5,5,6,2,1},
			   		   {1,1,1,2,1},
			   		   {0,1,0,1,1}};
			   		   
int laplacian_kernel[3][3]={{0,-1,0},
		       			    {-1,4,-1},
			   			    {0,-1,0}};

int sharpen_kernel[3][3]={{0,-1,0},
		       			  {-1,5,-1},
			   			  {0,-1,0}};

void laplacian(int IMG[4][5],int w,int h){
	int IMG_new[4][5];
	int pnew;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			IMG_new[i][j]=IMG[i][j];
		}
	}
	
	for(i=1;i<w-1;i++){
		for(j=1;j<h-1;j++){
			pnew=(laplacian_kernel[0][0]*IMG[i-1][j-1])+
					(laplacian_kernel[0][1]*IMG[i-1][j])+
					(laplacian_kernel[0][2]*IMG[i-1][j+1])+
					(laplacian_kernel[1][0]*IMG[i][j-1])+
					(laplacian_kernel[1][1]*IMG[i][j])+
					(laplacian_kernel[1][2]*IMG[i][j+1])+
					(laplacian_kernel[2][0]*IMG[i+1][j-1])+
					(laplacian_kernel[2][1]*IMG[i+1][j])+
					(laplacian_kernel[2][2]*IMG[i+1][j+1]);
			if(pnew>255) pnew=255;
			if(pnew<0) pnew=0;
			IMG_new[i][j]=pnew;
		}
	}
	cout<<"laplacian operator"<<endl;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			cout<<IMG_new[i][j]<<" ";
		}
		cout<<endl;
	}
}

void sharpen(int IMG[4][5],int w,int h){
	int IMG_new[4][5];
	int pnew;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			IMG_new[i][j]=IMG[i][j];
		}
	}
	for(i=1;i<w-1;i++){
		for(j=1;j<h-1;j++){
			pnew=(sharpen_kernel[0][0]*IMG[i-1][j-1])+
					(sharpen_kernel[0][1]*IMG[i-1][j])+
					(sharpen_kernel[0][2]*IMG[i-1][j+1])+
					(sharpen_kernel[1][0]*IMG[i][j-1])+
					(sharpen_kernel[1][1]*IMG[i][j])+
					(sharpen_kernel[1][2]*IMG[i][j+1])+
					(sharpen_kernel[2][0]*IMG[i+1][j-1])+
					(sharpen_kernel[2][1]*IMG[i+1][j])+
					(sharpen_kernel[2][2]*IMG[i+1][j+1]);
			if(pnew>255) pnew=255;
			if(pnew<0) pnew=0;
			IMG_new[i][j]=pnew;
		}
	}
	cout<<"sharpen"<<endl;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			cout<<IMG_new[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char** argv) {
	laplacian(IMG_laplacian,4,5);
	cout<<endl;
	sharpen(IMG_sharpen,4,5);
	system("pause");
	return 0;
}
