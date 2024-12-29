#include <stdio.h>
#include"datatypes.h"
#include <stdlib.h>
struct danhsach list[100]={
		{1, "Nguyen Van A", "0331967335597", "11","1","1997","A@gmail.com", "0123456789" , "open"},
        {2, "Le Thi Bbbbb","0331967335597", "20","2","1992","B@gmail.com", "0987654321","open"},
        {3, "Tran Van C", "0331967335597", "25","12","2006","C@gmail.com", "0112233445","open"},
        {4, "Pham Thi Ddddd", "0331967335597", "1","1","2000","D@gmail.com", "0223344556","open"},
        {5, "Hoang Van E", "0331967335597", "21","5","1997","E@gmail.com", "0334455667","open"}
};



int main(int argc, char *argv[]) {
int i;
int a = 0;
int vitri;
	printf("vai tro cua ban ");
	printf("\n1. Quan ly ");
	printf("\n2.nguoi dung");
	printf ("\n3. thoat");
	printf("\n ban la: ");	
	scanf("%d",&vitri);
	switch(vitri){
		case 1:  //xong 
    	account(&a); 
    	if (a == 1) {
       	printf("chao mung quan ly da toi");
       	menuchoadmin();
    	}
		break;
	
		case 3://xong
			
			break;
        
		
}
	return 0;
}
