#include <stdio.h>
#include <string.h> 
#include"functions.h"
extern struct danhsach list[];
int a,b,i,j,mokhoa,thongtin; 
int doi;
char khoa[10] = "mo";
int size = 5;

void start(int vitri){                         // giao dien 
	printf("vai tro cua ban ");
	printf("\n1. Quan ly ");
	printf("\n2.nguoi dung");
	printf ("\n3. thoat");
	printf("\n ban la: ");	
	scanf("%d",&vitri);
}

void account(int *a){  					// nhap tai khoan 
int stk;
int mk;
 do {
     printf("Tai khoan: ");
     scanf("%d",&stk); 
		getchar(); 
        printf("Mat khau: ");
        scanf("%d",&mk);
		getchar(); 
        if (stk==mk) {
            printf("Dang nhap thanh cong\n");
            *a = 1; 
            break;   
        } else {
            printf("Tai khoan hoac mat khau khong dung. Vui long thu lai.\n");
            *a = 0;  
        }
    } while (*a == 0); 
	
}

void hienthi(){	                        //hien thi 

		printf("\nDanh sach khach hang:\n");
	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
    printf("| ID | Name           | CCCD              | Birthday             | Gmail                | Phone         | Status  |\n");
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");

        for ( i = 0; i < size; i++) {
            if (list[i].id == 0) {
                printf("Khong co du lieu tai vi tri %d.\n", i);
                continue; 
            }
             printf("| %-2d | %-14s | %-16s | %02s/%02s/%-4s | %-20s | %-13s | %-7s |\n",
               list[i].id, list[i].name, list[i].socancuoc,
               list[i].ngay, list[i].thang, list[i].nam,
               list[i].gmail, list[i].sdt, list[i].khoa);
        }
    printf("+----+----------------+------------------+------------+----------------------+---------------+---------+-----------\n");

	}
	
void timkiem(){                         //tim kiem
int tra=0;
size = size +1;
do{
	printf("nhap id khach hang muon xem: ");
	scanf("%d",&thongtin);
	if(thongtin > 0 && thongtin < size){
			tra=1;
			printf(" khach hang chi tiet:\n");
			for(i = 0 ;i < size ;i++){
    		if(thongtin == list[i].id){
    		printf("ID: %d | Ten: %s | So can cuoc: %s | Sinh nhat: %s/%s/%s | Gmail: %s | SDT: %s | Trang thai: %s\n",
            list[i].id, list[i].name, list[i].socancuoc,
			list[i].ngay, list[i].thang, list[i].nam,
			list[i].gmail, list[i].sdt, list[i].khoa);
			break;	
			}
		}
}
if (!tra) {
            printf("Không có khách hàng nào v?i ID này. Vui lòng nh?p l?i.\n");
        }
	}while(a==0);
}

void themphantu(){						//tham phan tu vao ham 
printf("so luong khanh hang muon them: ");
	scanf("%d",&b);
	for ( i = 0 ; i < b ; i++){
    printf("Nhap thong tin khach hang moi:\n");
	
	list[size].id = size + 1; 
    printf("ID: %d\n", list[size].id);
    
	
	printf("Name: ");
    getchar(); 
    fgets(list[size].name, sizeof(list[size].name), stdin);
    list[size].name[strcspn(list[size].name, "\n")] = 0;
    fflush(stdin);
	
	printf("So can cuoc: ");
    fgets(list[size].socancuoc, sizeof(list[size].socancuoc), stdin);
    list[size].socancuoc[strcspn(list[size].socancuoc, "\n")] = 0; 
    fflush(stdin);
	
	printf("ngay: ");
    fgets(list[size].ngay, sizeof(list[size].ngay), stdin);
    list[size].ngay[strcspn(list[size].ngay, "\n")] = 0;
    fflush(stdin);
	
	printf("thang: ");
    fgets(list[size].thang, sizeof(list[size].thang), stdin);
    list[size].thang[strcspn(list[size].thang, "\n")] = 0;
    fflush(stdin);
	
	printf("nam: ");
    fgets(list[size].nam, sizeof(list[size].nam), stdin);
    list[size].nam[strcspn(list[size].nam, "\n")] = 0;
    fflush(stdin);
	
	printf("gmail: ");
    fgets(list[size].gmail, sizeof(list[size].gmail), stdin);
    list[size].gmail[strcspn(list[size].gmail, "\n")] = 0;
	fflush(stdin);
	
    printf("SDT: ");
    fgets(list[size].sdt, sizeof(list[size].sdt), stdin);
    list[size].sdt[strcspn(list[size].sdt, "\n")] = 0;
	fflush(stdin);
	strcpy(list[size].khoa, "open");
    size++;
    printf("\nKhach hang da duoc them thanh cong!\n");
	
	}
}

void sapxep(){//loi						//sap xep theo chuwx cai giam dan 
	for (i = 0; i < size - 1; i++) {  
        for (j = i; j < size; j++) {  
            if (strlen(list[j].name) < strlen(list[j + 1].name)) {
                struct danhsach temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    printf("da sap xep thanh cong");
    		hienthi();
}

void trangthai(){						// trang thai mowr / khoa
int x=0;
	hienthi();
	printf("nhap id muon thay doi la: ");
	scanf("%d",&doi);
	
	
	
	for(i=0 ; i < size ;i++){
		if(doi == list[i].id){
		printf("da tim thay khach hang");
		if(strcmp(list[i].khoa, "open") == 0){
		strcpy(list[i].khoa, "close");	
		} else if (strcmp(list[i].khoa, "close") == 0){
		strcpy(list[i].khoa, "open");
		}
		printf("\nda thay doi thanh cong");
		hienthi();
		x=1;
		}
	}
		if (x == 0) {
        printf("Khong tim thay ID. Vui long thu lai.\n");
    }
}

void menuchoadmin(){					// menu cho quan ly
    do{
    printf("\n1.them khach hang");
    printf("\n2.hien thi ta ca khach hang");
    printf("\n3.hien thi chi tiet khach hang ");
    printf("\n4.khoa / mo khoa khach hang");
    printf("\n5.sap xep khach hang ");
    printf("\n6.luu thong tin khach hang");
    printf("\n7.thoat");
    printf("\nlua chon cua ban: ");
	scanf("%d",&a);
	switch(a){	
	case 1:// da xong 
	themphantu();
 		break;
	case 2 :// da xong 
	hienthi();
		break;
	case 3: //da xong 
	timkiem();
   		break;
   	case 4: //da xong 
   		trangthai();
   	break;
	case 5 ://da xong 
 		sapxep();
	break;
	
//	case 6: // luu vao tep
//	break:
	 case 7:// da xong 
	 	printf("tam biet");
	break;
    }
	}while(a!= 7);				
}
