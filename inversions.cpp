#include<iostream>
#include<random>

using namespace std;
void print_array(int* array,int n);
int merge_Sort(int array[],int P, int R);
int merge(int array[],int P,int Q,int R);

int IC = 0;
int main(){
    cout<<"enter array size";
    
    int array_size;
    cin>>array_size;

    int R_array[array_size];
    for(int i = 0; i < array_size;i++){
        R_array[i] = rand()%100;
    }

    print_array(R_array,array_size);

    merge_Sort(R_array,0,array_size);

    cout<<endl;

    print_array(R_array,array_size);

    cout<<endl<<" IC = "<<IC;
    
    return 1;

}

int merge_Sort(int array[],int P, int R){
    IC = 0;
    if (P >= R)
    
        return 0;
    

    int Q = P + (R-P)/2;
    

    IC +=merge_Sort(array,P,Q);
    IC +=merge_Sort(array,Q+1,R);
    IC +=merge(array,P,Q,R);

    return IC;
}

int merge(int array[],int P,int Q,int R){
    int INC = 0;
    int left_s = Q-P + 1;
    int right_s = R-Q;

    int *left = new int[left_s];
    int *right = new int[right_s];


    for (int i = 0; i < left_s; i++)
    {
        left[i] = array[P+i];
    }

    for (int i = 0; i < right_s; i++)
    {
        right[i] = array[Q + 1 + i];
    }



    int LI = 0;
    int RI = 0; 
    int IM = P;

    while (LI < left_s && RI < right_s)
    {
        if (left[LI] <= right[RI])
        {
            array[IM] = left[LI];
            LI+=1;
        }else
        {
            array[IM] = right[RI];
            RI+=1;

            INC = INC + ((Q) - LI);
        }
        IM+=1;
    }


    while (LI < left_s)
    {
        array[IM] = left[LI];
        IM+=1;
        LI+=1;
    }

    while (RI < right_s)
    {
        array[IM] = right[RI];
        IM+=1;
        RI+=1;
    }



    delete[] left;
    delete[] right;

    return INC;


}







void print_array(int* array,int n){
    for(int i =0;i<n && i < 20;i++){
        cout<<array[i]<<",";
    }
}