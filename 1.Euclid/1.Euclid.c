#include<stdio.h>
#include<stdlib.h>

#define x 10
#define y 100

int test = 0;

float euclid(int m, int n) {
    int r;
    float count = 0;
    while(n != 0) {
        count++;
        r = m%n;
        m = n;
        n = r;
    }
    printf("GCD is: %d", m);
    return count;
}

float consec(int m, int n) {
    int min;
    float count = 0;
    min = m<n?m:n;
    while(1) {
        count++;
        if(m%min == 0) {
            count++;
            if(n%min == 0) {
                break;
            }
            min -= 1;
        }
        else {
            min -= 1;
        }
    }
    printf("GCD is: %d", min);
    return count;

}

float modified(int m, int n) {
    float count = 0;
    while(n > 0) {
        (m > n) ? (m = m-n) : (n = n-m);
        count++;
    }
    printf("GCD is: %d", m);
    return count;   
}

void analysis(int ch) {
    int m, n;
    float mincount, maxcount, count;
    FILE *fp1, *fp2;
    for(int i=x; i<=y; i++) {
        mincount = 10000;
        maxcount = 0;
        for(int j=2; j<=i; j++) {
            for(int k=2; k<=i; k++) {
                count = 0;
                m = j; 
                n = k;
                switch(ch) {
                    case 1:
                        count = euclid(m, n);
                        break;
                    case 2:
                        count = consec(m, n);
                        break;
                    case 3:
                        count = modified(m, n);
                        break;
                }

                if(count > maxcount) {
                    maxcount = count;
                }
                if(count < mincount) {
                    mincount = count;
                }

            }

        }
        switch(ch) {
            case 1:
                fp2 = fopen("e_b.txt", "a");
                fp1 = fopen("e_w.txt", "a");
                break;
            case 2:
                fp2 = fopen("c_b.txt", "a");
                fp1 = fopen("c_w.txt", "a");
                break;
            case 3:
                fp2 = fopen("m_b.txt", "a");
                fp1 = fopen("m_w.txt", "a");
                break;
        }
        fprintf(fp2, "%d %.2f\n", i, mincount);
        fclose(fp2);
        fprintf(fp1, "%d %.2f\n", i, maxcount);
        fclose(fp1);

    }

}

int main() {
    int ch;
    while(1) {
        printf("\n1- Euclid\n2- Consecutive Integer\n3- Modified Euclid\n4- Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: 
            case 2:
            case 3:
                analysis(ch);
            case 4:
                exit(0);
        }
    }
}