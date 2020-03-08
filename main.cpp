#include <iostream>
using namespace std;
int i, j;
int IMG[5][6]={{5,5,7,0,0,0},
		       {10,9,7,7,0,1},
			   {14,6,4,7,7,12},
			   {13,6,4,7,7,3},
			   {12,6,8,7,7,3}};
			   
int IMG_mean[4][5]={{5,5,7,0,0},
		       	 	{10,9,7,7,0},
			   		{14,6,4,7,7},
			   		{13,6,4,7,7}};
			
int IMG_median[4][5]={{5,5,7,0,0},
		       		  {10,9,7,7,0},
			   		  {14,6,4,7,7},
			   		  {13,6,4,7,7}};
			   		  
int IMG_gaussian[4][5]={{5,5,7,0,0},
		       		  	{10,9,7,7,0},
			   		  	{14,6,4,7,7},
			   		  	{13,6,4,7,7}};

void Histo(int IMG[5][6], int w, int h,int *hist_array){
	for(i=0;i<16;i++)
		hist_array[i]=0;
	for (i=0;i<w;i++){
		for(j=0;j<h;j++)
			hist_array[IMG[i][j]]++;
	}
	cout<<"histogram"<<endl;
	for(i=0;i<16;i++){
		cout<<hist_array[i]<<" ";
	}
}

int mean_filter_weight[3][3]={{1,2,1},
							  {2,5,2},
							  {1,2,1}};

void mean_filter(int IMG[4][5],int w,int h,int kernel[3][3]){
	int pnew=0;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			pnew=((IMG[i-1][j-1]*kernel[0][0])+(IMG[i][j-1]*kernel[0][1])+(IMG[i+1][j-1]*kernel[0][2])
			+(IMG[i-1][j]*kernel[1][0])+(IMG[i][j]*kernel[1][1])+(IMG[i+1][j]*kernel[1][2])
			+(IMG[i-1][j+1]*kernel[2][0])+(IMG[i][j+1]*kernel[2][1])+(IMG[i+1][j+1]*kernel[2][2]))/17;
			IMG[i][j]=pnew;
		}
	}
	cout<<"mean filter"<<endl;
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			cout<<IMG[i][j]<<" ";
		}
		cout<<endl;
	}
}

void median_filter_2(int IMG[4][5], int w,int h){
	int temp,mid_element,mid_before_element,mid_after_element,avg;
	int median_array[9]={IMG[w-1][h-1],IMG[w][h-1],IMG[w+1][h-1],IMG[w-1][h],
						IMG[w][h],IMG[w+1][h],IMG[w-1][h+1],IMG[w][h+1],IMG[w+1][h+1]};
	for(i=0;i<9;i++){
		for(j=0;j<9-i-1;j++){
			if(median_array[j]>median_array[j+1]){
				int temp = median_array[j];  
    			median_array[j] = median_array[j+1];  
    			median_array[j+1] = temp; 
			}
			mid_before_element=median_array[3];
			mid_element=median_array[4];
			mid_after_element=median_array[5];
			avg=(mid_before_element+mid_element+mid_after_element)/3;
			IMG[w-1][h-1]=avg;
			IMG[w][h-1]=avg;
			IMG[w+1][h-1]=avg;
			IMG[w-1][h]=avg;
			IMG[w][h]=avg;
			IMG[w+1][h]=avg;
			IMG[w-1][h+1]=avg;
			IMG[w][h+1]=avg;
			IMG[w+1][h+1]=avg;
		}
	}
	
	
	cout<<"median filter 3px"<<endl;
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			cout<<IMG[i][j]<<" ";
		}
		cout<<endl;
	}
}

void median_filter(int IMG[4][5], int w,int h){
	int temp,mid_element;
	int median_array[9]={IMG[w-1][h-1],IMG[w][h-1],IMG[w+1][h-1],IMG[w-1][h],
						IMG[w][h],IMG[w+1][h],IMG[w-1][h+1],IMG[w][h+1],IMG[w+1][h+1]};
	for(i=0;i<9;i++){
		for(j=0;j<9-i-1;j++){
			if(median_array[j]>median_array[j+1]){
				int temp = median_array[j];  
    			median_array[j] = median_array[j+1];  
    			median_array[j+1] = temp; 
			}
			mid_element=median_array[4];
			IMG[w-1][h-1]=mid_element;
			IMG[w][h-1]=mid_element;
			IMG[w+1][h-1]=mid_element;
			IMG[w-1][h]=mid_element;
			IMG[w][h]=mid_element;
			IMG[w+1][h]=mid_element;
			IMG[w-1][h+1]=mid_element;
			IMG[w][h+1]=mid_element;
			IMG[w+1][h+1]=mid_element;
		}
	}
	
	
	cout<<"median filter 1px"<<endl;
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			cout<<IMG[i][j]<<" ";
		}
		cout<<endl;
	}
}

double gaussian_kernel[3][3]={{0.0275,0.1102,0.0275},
							  {0.1102,0.4421,0.1102},
							  {0.0275,0.1102,0.0275}};//0,11+0,4408+0,4421

void gaussian_filter(int IMG[4][5],int w,int h){
	int pnew=0;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			pnew=(IMG[i-1][j-1]*gaussian_kernel[0][0])+(IMG[i][j-1]*gaussian_kernel[0][1])+(IMG[i+1][j-1]*gaussian_kernel[0][2])
			+(IMG[i-1][j]*gaussian_kernel[1][0])+(IMG[i][j]*gaussian_kernel[1][1])+(IMG[i+1][j]*gaussian_kernel[1][2])
			+(IMG[i-1][j+1]*gaussian_kernel[2][0])+(IMG[i][j+1]*gaussian_kernel[2][1])+(IMG[i+1][j+1]*gaussian_kernel[2][2]);
			IMG[i][j]=pnew;
		}
	}
	cout<<"gaussian filter"<<endl;
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			cout<<IMG[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char** argv) {
	int histo_array[16];
	Histo(IMG,5,6,histo_array);
	cout<<endl<<endl;
	
	cout<<"original image"<<endl;
	for(i=0;i<5;i++){
		for(j=0;j<6;j++){
			cout<<IMG[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	mean_filter(IMG_mean,4,5,mean_filter_weight);
	cout<<endl;
	
	median_filter(IMG_median,4,5);
	cout<<endl;
	
	median_filter_2(IMG_median,4,5);
	cout<<endl;
	
	gaussian_filter(IMG_gaussian,4,5);
	system("pause");
	return 0;
}
