// #include<cutil.h>

// /*get thread id:1D block and 2D grid*/
// #define get_tid()(blockDim.x * (blockIdx.x + blockIdx.y * gridDim.x) + threadIdx.x)

// /*get block id :2D grid*/
// #define get_bid() (blockIdx.x + blockIdx.y * gridDim.x)


// __global__void vec_add(double *x,double *y,double *z,int n){
//     int i = get_tid(); //user-defind macro/functuion

//     if(i<n){
//         z[i] = x[i] + y[i];
//     }
// }

// int main(){
//     int N = 1000000; //1M
//     int bs = 256;
//     int gs = (N+bs-1)/bs;

//     //kernel,call GPU
//     vec_add<<<gs,bs>>>(x,y,z,N);
// }