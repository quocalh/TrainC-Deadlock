#include "../inc/systemInterface.h"
#include <stdio.h>

void clearBuffer() {
  // int c;
  while (getchar() != '\n')
    ;
}

void Interface() {
  printf("\n====================================");
  printf("\n       HE THONG QUAN LY       ");
  printf("\n====================================");
  printf("\n1. Them san pham moi");
  printf("\n2. Sua thong tin san pham");
  printf("\n3. Xoa san pham");
  printf("\n4. Hien thi danh sach san pham");
  printf("\n5. Sap xep va hien thi san pham");
  printf("\n6. Cap nhat so luong kho (Stock)");
  printf("\n7. Thiet lap nguong thong bao (Threshold)");
  printf("\n0. Thoat chuong trinh");
  printf("\n------------------------------------");
  printf("\nLua chon cua ban: ");
}
