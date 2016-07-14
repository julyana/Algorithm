#include <iostream>
using namespace std;
#define nSize 1000

/********Problem Description********/
/* Change from c1c2...d1d2... to d1c1d2c2... */

/********Declaration********/
int a[nSize], b[nSize], t, len;

void input(){
  cin >> len;
  for(int i = 0; i < len; i ++) {
    cin >> a[i];
  }
}

void divideandConquer(int *a, int n) {  
  int t,i;  
    if (n == 1) {  
        t = a[1];  
        a[1] = a[2];  
        a[2] = t;  
        return;  
    }  
    int n2 = n * 2, n3 = n / 2;  
    if (n % 2 == 1) {  //奇数的处理  
        t = a[n];  
        for (i = n + 1; i <= n2; i ++) {  
            a[i - 1] = a[i];  
        }  
        a[n2] = t;  
        --n;  
    }  
    //到此n是偶数  
      
    for (i = n3 + 1; i <= n; i ++) {
        t = a[i];  
        a[i] = a[i + n3];  
        a[i + n3] = t;  
    }  
      
    // [1.. n /2]  
    divideandConquer(a, n3);  
    divideandConquer(a + n, n3);     
}

//翻转字符串时间复杂度O(to - from)
void cycleLeader(int *a,int from, int mod) {
  int last = a[from];
    
    for (int i = from * 2 % mod;i != from; i = i * 2 % mod) {
        t = a[i];
        a[i] = last;
        last = t;
    }
    a[from] = last;
}

//循环右移num位 时间复杂度O(n)
void right_rotate(int *a, int num, int n) {
    reverse(a, 1, n - num);
    reverse(a, n - num + 1,n);
    reverse(a, 1, n);
}

//时间O(n)，空间O(1)
void perfectShuffle(int *a, int n) {
  int n2, m, i, k,t;
    	for (;n > 1;) {
	  
        // step 1: 2m = 3^k - 1 , 3^k <= 2n < 3^(k + 1)
	// 2 * m = 3 ^ (k - 1), k circles, and the head of every circle is 1, 3, 9, ... , 3 ^ (k - 1)
        n2 = n * 2;
        for (k = 0, m = 1; n2 / m >= 3; ++k, m *= 3);
	m /= 2;
	
        // step 2
        right_rotate(a + m, m, n);
	
        // step 3
        for (i = 0, t = 1; i < k; ++i, t *= 3) {
            cycle_leader(a , t, m * 2 + 1);    
        }
	
        //step 4
        a += m * 2;
        n -= m;
    }
    // n = 1
    t = a[1];
    a[1] = a[2];
    a[2] = t;  
}

void process(){
  /***Method 1-Numerical Method(Move from original place to (2i) % (2n - 1)), Need original space bp***/
  for (int i = 1; i <= len; i ++){
    b[ (2 * i) % (2 * n - 1) ] = a[i];
  }
  for (int i = 1; i <= len; i ++){
    a[i] = b[i];
  }
  
  /***Method 2-classifications: odd, even***/
  divideandConquer(a, len / 2);
  
  /***Method 3***/
  perfectShuffle(a, len / 2);
}

void output(){
  for(int i = 0; i < len - 1; i ++) {
    cout <<  a[i] << " ";
  }
  cout << a[len - 1] << endl;
}

int main(){
  input();
  process();
  output();
  return 0;
}
