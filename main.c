#include <stdio.h>
#include <stdlib.h>

void sommeMat(int m, int n, int A[10][10], int B[10][10], int C[10][10]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void prodMat(int m, int n, int p, int A[10][10], int B[10][10], int C[10][10]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int recherche(int T[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (T[i] == x) return i;
    return -1;
}

int mult(int a, int b) {
    int r = 0;
    for (int i = 0; i < b; i++)
        for (int j = 0; j < a; j++)
            r = r + 1;
    return r;
}

int trie(int T[], int n) {
    for (int i = 0; i < n-1; i++)
        if (T[i] > T[i+1]) return 0;
    return 1;
}

void trier(int T[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (T[i] > T[j]) {
                int tmp = T[i]; T[i] = T[j]; T[j] = tmp;
            }
}

float mediane(int T[], int n) {
    trier(T,n);
    if (n % 2 == 1) return T[n/2];
    return (T[n/2-1] + T[n/2]) / 2.0;
}

void inverser(int T[], int n) {
    for (int i = 0; i < n/2; i++) {
        int tmp = T[i];
        T[i] = T[n-1-i];
        T[n-1-i] = tmp;
    }
}

void prodVect(int A[3], int B[3], int C[3]) {
    C[0] = A[1]*B[2] - A[2]*B[1];
    C[1] = A[2]*B[0] - A[0]*B[2];
    C[2] = A[0]*B[1] - A[1]*B[0];
}

void vectMat(int n, int V[], int M[10][10], int R[]) {
    for (int j = 0; j < n; j++) {
        R[j] = 0;
        for (int i = 0; i < n; i++)
            R[j] += V[i] * M[i][j];
    }
}

int main() {
    int choix;
    do {
        printf("\nMENU\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche\n");
        printf("4. Multiplication a*b avec +1\n");
        printf("5. Tester tri\n");
        printf("6. Mediane\n");
        printf("7. Inverser tableau\n");
        printf("8. Produit vectoriel (3D)\n");
        printf("9. Vecteur x Matrice\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        if (choix == 1) {
            int m,n,A[10][10],B[10][10],C[10][10];
            printf("m n: "); scanf("%d%d",&m,&n);
            for(int i=0;i<m;i++) for(int j=0;j<n;j++) scanf("%d",&A[i][j]);
            for(int i=0;i<m;i++) for(int j=0;j<n;j++) scanf("%d",&B[i][j]);
            sommeMat(m,n,A,B,C);
            for(int i=0;i<m;i++){ for(int j=0;j<n;j++) printf("%d ",C[i][j]); printf("\n"); }
        }

        else if (choix == 2) {
            int m,n,p,A[10][10],B[10][10],C[10][10];
            printf("m n p: "); scanf("%d%d%d",&m,&n,&p);
            for(int i=0;i<m;i++) for(int j=0;j<n;j++) scanf("%d",&A[i][j]);
            for(int i=0;i<n;i++) for(int j=0;j<p;j++) scanf("%d",&B[i][j]);
            prodMat(m,n,p,A,B,C);
            for(int i=0;i<m;i++){ for(int j=0;j<p;j++) printf("%d ",C[i][j]); printf("\n"); }
        }

        else if (choix == 3) {
            int n,T[100],x;
            scanf("%d",&n);
            for(int i=0;i<n;i++) scanf("%d",&T[i]);
            scanf("%d",&x);
            int pos = recherche(T,n,x);
            if(pos==-1) printf("Non trouve\n"); else printf("Position %d\n",pos);
        }

        else if (choix == 4) {
            int a,b; scanf("%d%d",&a,&b);
            printf("%d\n",mult(a,b));
        }

        else if (choix == 5) {
            int n,T[100]; scanf("%d",&n);
            for(int i=0;i<n;i++) scanf("%d",&T[i]);
            if(trie(T,n)) printf("Trie\n"); else printf("Non trie\n");
        }

        else if (choix == 6) {
            int n,T[100]; scanf("%d",&n);
            for(int i=0;i<n;i++) scanf("%d",&T[i]);
            printf("Mediane=%.2f\n",mediane(T,n));
        }

        else if (choix == 7) {
            int n,T[100]; scanf("%d",&n);
            for(int i=0;i<n;i++) scanf("%d",&T[i]);
            inverser(T,n);
            for(int i=0;i<n;i++) printf("%d ",T[i]);
            printf("\n");
        }

        else if (choix == 8) {
            int A[3],B[3],C[3];
            for(int i=0;i<3;i++) scanf("%d",&A[i]);
            for(int i=0;i<3;i++) scanf("%d",&B[i]);
            prodVect(A,B,C);
            printf("%d %d %d\n",C[0],C[1],C[2]);
        }

        else if (choix == 9) {
            int n,V[10],M[10][10],R[10];
            scanf("%d",&n);
            for(int i=0;i<n;i++) scanf("%d",&V[i]);
            for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&M[i][j]);
            vectMat(n,V,M,R);
            for(int j=0;j<n;j++) printf("%d ",R[j]);
            printf("\n");
        }

    } while(choix!=0);

    return 0;
}
