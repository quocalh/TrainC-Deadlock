

// 4:
void SystemUpdateStock(System *system, int productID, int quantityChange,
                       int type)
  {
    int found = 0;
    for (int i = 0; i < (*system).product_array.count; i++) 
    {
      if ((*system).product_array.ptr[i].ProductID == productID) 
      {
          found = 1;

          if (type == 1)
          {
                (*system).product_array.ptr[i].quantity += (unsigned long)quantityChange;
                printf("Da nhap %d vao ID %d.\n", quantityChange, productID);
          } 
          else if (type == 2)
          { 
              if ((*system).product_array.ptr[i].quantity >= (unsigned long)quantityChange) 
              {
                   (*system).product_array.ptr[i].quantity -= (unsigned long)quantityChange;
                  printf("Da xuat %d tu ID %d.\n", quantityChange, productID);
                  if ((*system).product_array.ptr[i].quantity <= (*system).product_array.ptr[i].lowStockThreshold) 
                  {
                      printf("!!! CANH BAO: San pham '%s' sap het hang (Con lai: %lu)\n", 
                              (*system).product_array.ptr[i].ProductName, 
                              (*system).product_array.ptr[i].quantity);
                  }
              } 
               else 
               {
                  printf("Khong du hang! Trong kho chi con %lu.\n", (*system).product_array.ptr[i].quantity);
               }
           }
           break; 
      }
  }

  if (found == 0) 
  {
      printf("Khong tim thay ID %d trong he thong.\n", productID);
  }
}                     
