//hs_11
//18314726
//Jörg Galilee Uwimana

/*#include <stdio.h>
int main() {
    int arr[3][3][3] = {};
    for(int i =0; i< 3; i++){
        for(int j =0; j<3; j++){
            for(int k=0; k<3; k++){
               * (*( *(arr + i)+j)+ k) = k + 1;
            }
        }
    }
     for(int i =0; i< 3; i++){
        for(int j =0; j<3; j++){
            for(int k=0; k<3; k++){
                printf("arr[%d][%d][%d]: %d",i,j,k,arr[i][j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}*/
#include <stdio.h>
int main() {
//   int arr[3][3][10] = {};
//   printf("%d %d", arr[4][0][5], arr[4][3][20]);
 
//   for(int i =0; i< 5; i++){
//       for(int j= 0; j<3; j++){
//           for(int k=0; k<10; k++){
//               printf("%d \n", arr[i][j][k]);
//           }
//       }
//   }
  int arr2[0][0][5] = {};
  
  for(int i =0; i<1; i++){
      for(int j= 0; j<1; j++){
          for(int k=0; k<5; k++){
              printf("%d \n", arr2[i][j][k]);
          }
      }
  }
    return 0;
}

