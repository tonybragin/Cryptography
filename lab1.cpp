#include "lab1.hpp"

//   генератор случайного числа
long long getRand (long long min, long long max) {
    return min + (long long)rand() % max;
}

//   проверка на простоту
bool isPrime(long long n) {
    if (n % 2 == 0) return false;
    long long s = n - 1;
    long long t = 0;
    
    while (s % 2 == 0) {
        s /= 2;
        t++;
    }
    
    int k = 0;
    while (k < 128) {
        long long a = getRand(2, n - 1);
        long long v = powFast(a, s, n);
        
        if (v == 1) return true;
        else {
            int i = 0;
            while (v != n - 1) {
                if (i == t - 1) return false;
                else {
                    v = powFast(v, 2, n);
                    i++;
                }
            }
        }
        k += 2;
    }
    
    return true;
}

//   генератор большого простого числа
long long getLargeNum () {
    
    long long l = 20000;
    long long u = 30000;
    long long n = 0;
    
    long long r = 100 * (floor(log2(u)) + 1);
    
    do {
        r -= 1;
        if (r < 0) return -1;
        n = getRand(l, u);
    } while (!isPrime(n));
    
    return n;
}

//
void getGP (long long *p, long long *g) {

    long long q = getLargeNum();
    *p = 2*q + 1;
    
    while (!isPrime(*p)) {
        q = getLargeNum();
        *p = 2*q + 1;
    }
    
    for (*g = 2; *g <= 10; *g += 1) {
        if (powFast(*g, q, *p) == 1) break;
    }
    
}

//   Функция быстрого возведения числа в степень по модулю
//   x^a(mod n)
long long powFast (long long x, long long a, long long  n) {
    long long  res = 1;
    while (a > 0)
        if (a & 1) {
            res = (res * x) % n;
            --a;
        }
        else {
            x = (x * x) % n;
            a >>= 1;
        }
    return res % n;
}

unsigned long long powFastUnsigned (unsigned long long x, unsigned long long a, unsigned long long  n) {
    unsigned long long  res = 1;
    while (a > 0)
        if (a & 1) {
            res = (res * x) % n;
            --a;
        }
        else {
            x = (x * x) % n;
            a >>= 1;
        }
    return res % n;
}

//получить взаимно простое
long long coprime(long long withP) {
    long long c;
    long long x, y, nod;
    
    do {
        c = (getRand(1, withP - 1)) | 1;
        algEvk(withP, c, &x, &y, &nod);
    } while (nod != 1);
    
    return c;
}

//получить инверсию
unsigned long long inverse (unsigned long long withP, unsigned long long c) {
    long long d, x, nod;
    
    algEvk(withP, c, &x, &d, &nod);
    if (d < 0) d += withP;
    
    return d;
}

//   алгоритм Евклида
//   ax + by = nod(a,b)
void algEvk (unsigned long long a, unsigned long long b, long long *x, long long *y, long long *d) {
    
    long long q, r, x1, x2, y1, y2;
    
    if (b == 0) {
        *d = a, *x = 1, *y = 0;
        return;
    }
    
    x2 = 1, x1 = 0, y2 = 0, y1 = 1;
    
    while (b > 0) {
        
        q = a / b;
        r = a - q * b;
        
        *x = x2 - q * x1;
        *y = y2 - q * y1;
        
        a = b;
        b = r;
        
        x2 = x1, x1 = *x, y2 = y1, y1 = *y;
    }
    
    *d = a, *x = x2, *y = y2;
}

//   алгоритм Диффи-Хеллмана
//   1 - a, g, p; 2 - b.
bool algDifHell (long long a, long long b, long long g, long long p) {
    
    long long A, B, K1, K2;
    
    A = powFast(g, a, p);
    B = powFast(g, b, p);
    
    K1 = powFast(B, a, p);
    K2 = powFast(A, b, p);
    
    return K1 == K2;
}

//   алгоритм "Шаг младенца, шаг великана"
//   g^x = h (mod n)
long long babyStepGiantStep (long long  g, long long  h, long long  n) {
    
    long long  k = (long long) sqrt (n + .0) + 1;
    map<long long, long long> vals;
    
    for (long long i = k; i >= 1; --i)
        vals[ powFast(g, i * k, n) ] = i;
    
    for (long long i = 0; i <= k; ++i) {
        long long  cur = (powFast(g, i, n) * h) % n;
        if (vals.count(cur)) {
            long long ans = vals[cur] * k - i;
            if (ans < n)
                return ans;
        }
    }
    return -1;
}
