#include <stdio.h>

int int_cmp(const void* e1,const void* e2){
    return *(int*)e2-*(int*)e1;
}

int double_cmp(const void* e1,const void* e2){
    return *(double*)e2-*(double*)e1;
}

void my_swap(void* e1,void*e2,int width){
    char* p1=(char*)e1;
    char* p2=(char*)e2;
    for(int i=0;i<width;++i){
        char ch=*p1;
        *p1=*p2;
        *p2=ch;
        ++p1;
        ++p2;
    }
}

void my_qsort(void* base,int Elem_number,int Elem_size,int(*cmp)(const void*,const void*)){
    for(int i=0;i<Elem_number-1;++i){
        for(int j=0;j<Elem_number-1-i;++j){
            if(cmp((char*)base+j*Elem_size,(char*)base+(j+1)*Elem_size)>0){
                my_swap((char*)base+j*Elem_size,(char*)base+(j+1)*Elem_size,Elem_size);
            }
        }
    }
}

int main(){
    int arr[10]={4,7,5,6,1,3,2,9,8,10};
    double arr1[10]={4.3,7.1,5.2,6.7,1.4,3.7,2.9,9.5,8.4,10.8};

    my_qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),int_cmp);
    my_qsort(arr1,sizeof(arr1)/sizeof(arr1[0]),sizeof(arr1[0]),double_cmp);

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i){
        printf("%d ",*(arr+i));
    }
    printf("\n");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i){
        printf("%.1lf ",*(arr1+i));
    }

    return 0;
}