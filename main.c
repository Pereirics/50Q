#include <stdio.h>
#include <assert.h>
#include <string.h>

int maior_inteiro(){
    int n;
    scanf("%d", &n);
    int max = n;
    while(n != 0){
        if (n > max) max = n;
        scanf("%d", &n);
    }
    return max;
}


double media_inteiros(){
    double total = 0, num = 0;
    int n = scanf("%d", &n);
    while(n != 0){
        total += n;
        num++;
        scanf("%d", &n);
    }
    return (total/(num+1));
}


int segundo_maior(){
    int n = scanf("%d",&n);
    int max = n, maxA = n;
    while (n != 0){
        if (n > max) {
            maxA = max;
            max = n;
        }
        else if (n > maxA){
            maxA = n;
        }
        scanf("%d", &n);
    }
    return maxA;
}


int bitsUm (unsigned int n){
    int cont = 0;
    while(n != 0){
        if (n%2 == 1) cont++;
        n /= 2;
    }
    return cont;
}


int trailingZ (unsigned int n){
    if (n == 0) return 32;
    int cont = 0;
    while (n != 0){
        if (n%2 == 0) cont++;
        else return cont;
        n /= 2;
    }
    return cont;
}


int qDig(unsigned int n){
    int cont = 0;
    while (n != 0){
        n /= 10;
        cont++;
    }
    return cont;
}


char* mystrcat(char s1[], char s2[]){
    unsigned int COMP = strlen(s1);
    for (int i = 0; i <= (strlen(s2)); i++){
        s1[i+COMP] = s2[i];
    }
    return s1;
}


char* mystrcpy (char* dest, char source[]){
    for (int i = 0; i <= strlen(source); i++){
        dest[i] = source[i];
    }
    return dest;
}


int mystrcmp (char s1[], char s2[]){
    unsigned int MENOR_COMP;
    if (strlen(s1) > strlen(s2)) MENOR_COMP = strlen(s1);
    else MENOR_COMP = strlen(s2);

    for (int i = 0; i < MENOR_COMP; i++){
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
    }

    if (strlen(s1) > strlen(s2)) return 1;
    if (strlen(s1) < strlen(s2)) return -1;

    return 0;
}


char* mystrstr(char s1[], char s2[]){
    if (strlen(s1) < strlen(s2)) return NULL;
    unsigned int COMP = strlen(s1);
    char *result = s1;
    int j = 0, i;
    for(i = 0; i <= COMP+1; i++) {
        if (s1[i] == s2[j]){
            result[j] = s2[j];
            j++;
        }
        else if (s2[j] == '\0') break;
        else if (s1[i+1] == s2[j]){
            result[j] = s1[i+1];
            j++;
        }
        else j = 0;
    }
    if (j>0) {
        i++;
        for (i; i <= COMP; i++, j++) {
            result[j] = s1[i];
        }
        return result;
    }
    return NULL;
}


void strrev (char s[]){
    unsigned int M = strlen(s);
    int i;
    for (i = 0; i < M; i++, M--) {
        char temp = s[i];
        s[i] = s[M-1];
        s[M-1] = temp;
    }
}

int is_vowel(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return 0;
    }
    return 1;
}


void strnoV (char s[]){
    for(int i = 0; i < strlen(s); i++){
        if (is_vowel(s[i]) == 0) {
            for (int j = i; j < strlen(s); j++){
                s[j] = s[j+1];
            }
            i--;
        }
    }
}


void truncW (char t[], int n){
    int cont = 0;
    for(int i = 0; i < strlen(t); i++){
        if (t[i] != ' ') {
            if (cont >= n) {
                for (int j = i; j < strlen(t); j++) {
                    t[j] = t[j + 1];
                }
                i--;
            }
            cont++;
        }
        else cont = 0;
    }
}


char charMaisfreq (char s[]){
    if (strlen(s) == 0) return 0;
    int count = 0, max = 0;
    char letra;
    for(int i = 0; i < strlen(s); i++){
        if (count > max){
            max = count;
            letra = s[i-1];
        }
        count = 0;
        for(int j = 0; j < strlen(s); j++){
            if (s[i] == s[j]) count++;
        }
    }
    return letra;
}


int iguaisConsecutivos (char s[]){
    int count = 0, max = 0;
    if (strlen(s) == 1) return 1;
    for(int i = 0; i < strlen(s); i++) {
        if (s[i] == s[i+1]) count = 1;
        while (s[i] == s[i + 1]) {
            count++;
            i++;
        }
        if (count > max) max = count;
        count = 0;
    }
    return max;
}


int difConsecutivos (char s[]){
    int count = 0, max = 0;
    if (strlen(s) == 1) return 1;
    for(int i = 0; i < strlen(s); i++) {
        if (s[i] != s[i+1]) count = 1;
        while (s[i] != s[i + 1]) {
            count++;
            i++;
        }
        if (count > max) max = count;
        count = 0;
    }
    return max;
}


int maiorPrefixo (char s1 [], char s2 []){
    int cont = 0;
    int i = 0;
    while (s1[i] == s2[i]){
        cont++;
        i++;
    }
    return cont;
}


int maiorSufixo (char s1 [], char s2 []){
    int cont = 0;
    unsigned long i = strlen(s1);
    unsigned long j = strlen(s2);
    while(s1[i-1] == s2[j-1]){
        cont++;
        i--;
        j--;
    }
    return cont;
}


int sufPref (char s1[], char s2[]){
    int i = 0;
    int maior = 0;
    unsigned long j = strlen(s1) - 1;
    int cont = 0;

    for (int k = 0; k < j; k++) {
        j = strlen(s1)-1;
        cont = 0;
        while (s2[i] != s1[j] && i <= j){
            i++;
        }
        if (s1[j] == s2[i]){
            int l = i;
            while (s1[j] == s2[l] && (j >= 0 && l >= 0)){
                cont++;
                l--;
                j--;
            }
        }
        if (cont > maior) maior = cont;
        i++;
    }
    return maior;
}


int contaPal (char s[]){
    int flag = 0;
    int cont = 0;
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (flag == 0 && s[i] == ' ') {
            flag = 1;
        }
        if (s[i] != ' ') flag = 0;
        if (s[i] != ' ' && s[i] != '\n' && flag == 0 && (s[i-1] == ' ' || i == 0)) cont++;
    }
    return cont;
}


int contaVogais (char s[]){
    int cont = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A'
        || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') cont++;
    }
    return cont;
}


int contida (char a[], char b[]){
    int flag = 0;
    int i;
    int j;
    for (i = 0; i < strlen(b); i++) {
        for (j = 0; j < strlen(a); j++) {
            if (a[j] == b[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return 0;
    }
    return 1;
}


int palindorome (char s[]) {
    unsigned long N = strlen(s);
    for (int i = 0; i < N; i++) {
        if (s[i] != s[N - 1]) return 0;
        else N--;
    }
    return 1;
}


int remRep(char x[]){
    int flag = 0;
    int k = 0;
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] != x[i-1]) flag = 0;
        if (flag == 0) {
            x[k++] = x[i];
            flag = 1;
        }
    }
    x[k] = '\0';
    return k;
}


int limpaEspacos (char t[]){
   int flag = 0;
   int k = 0;
   for (int i = 0; i < strlen(t); i++) {
       if (flag == 0 && t[i] == ' '){
           t[k++] = t[i];
           flag = 1;
       }
       if (t[i] != ' ') {
           t[k++] = t[i];
           flag = 0;
       }
    }
   t[k] = '\0';
   return k;
}

//26.
void insere (int v[], int N, int x){
    int i = 0;
    if (x > v[N-1]) v[N] = x;
    else{
        while (i < N){
            if (x < v[i]){
                int temp = v[i];
                v[i++] = x;
                for (int j = i; j <= N; j++) {
                    int temp1 = v[j];
                    v[j] = temp;
                    if (j < N) temp = temp1;
                }
                break;
            }
            i++;
        }
    }
}


//27.
void merge(int r[], int a[], int b[], int na, int nb){
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb){
        if (a[i] < b[j]){
            r[k++] = a[i++];
        }
        else{
            r[k++] = b[j++];
        }
    }
    while (i < na){
        r[k++] = a[i++];
    }
    while (j < nb){
        r[k++] = b[j++];
    }
}


//28.
int crescente(int a[], int i, int j){
    for (int k = i; k < j; k++) {
        if (a[k] > a[k+1]) return 0;
    }
    return 1;
}


//29.
int retiraNeg(int v[], int N){
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] >= 0) {
            v[k++] = v[i];
        }
    }
    return k;
}


//30.
int menosFreq(int v[], int N){
    int cont = 1000;
    int menor = 0;
    for (int i = 0; i < N; i++) {
        int num = v[i];
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (v[j] == num) temp++;
        }
        if (temp < cont) {
            menor = i;
            cont = temp;
        }
    }
    return v[menor];
}


//31.
int maisFreq(int v[], int N){
    int cont = 0;
    int maior = 0;
    for (int i = 0; i < N; i++) {
        int num = v[i];
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (v[j] == num) temp++;
        }
        if (temp > cont) {
            maior = i;
            cont = temp;
        }
    }
    return v[maior];
}


//32.
int maxCres(int v[], int N){
    int cont = 0;
    for (int i = 0; i < N; i++) {
        int temp = 1;
        for (int j = i; j < N-1; j++) {
            if (v[j] <= v[j+1]) temp++;
            else break;
        }
        if (temp > cont) cont = temp;
    }
    return cont;
}


//33.
int elimRep(int v[], int N){
    int i, j;
    int k = 0;
    for (i = 0; i < N; i++) {
        int num = v[i];
        int flag = 1;
        for (j = 0; j < i; j++) {
            if (num == v[j]) flag = 0;
        }
        if (flag == 1) v[k++] = v[i];
    }
    return k;
}


//34.
int elimRepOrd(int v[], int N){
    int k = 1;
    for (int i = 0; i < N-1; i++) {
        if (v[i] != v[i+1]) v[k++] = v[i+1];
    }
    return k;
}


//35.
int comunsOrd (int a[], int na, int b[], int nb){
    int i=0, j=0, contador=0;

    while(i<na && j<nb){
        if(a[i]>b[j])
            j++;
        else if(a[i]<b[j])
            i++;
        else{
            i++;
            j++;
            contador++;
        }
    }

    return contador;
}

//36.
int comuns (int a[], int na, int b[], int nb){
    int i, j, contador=0, flag=0;

    for(i=0; i<na; i++){
        for(j=0; j<nb && flag==0; j++){
            if(a[i]==b[j]){
                flag=1;
                contador++;
            }
        }
        flag=0;
    }

    return contador;
}


//37.
int minInd(int v[], int N){
    int menor = v[0];
    int ind = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] < menor){
            menor = v[i];
            ind = i;
        }
    }
    return ind;
}


//38.
void somasAc(int v[], int Ac[], int N){
    for (int i = 0; i < N; i++) {
        int soma = 0;
        for (int j = 0; j <= i; j++) {
            soma += v[j];
        }
        Ac[i] = soma;
    }
}


//39.
int triSUp(int N, float m [N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < j && m[j][i] != 0) return 0;
        }
    }
    return 1;
}


//40.
void transposta(int N, float m [N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
                float temp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = temp;
        }
    }
}


//41.
void addTo(int N, int M, int a[N][M], int b[N][M]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[j][i] += b[j][i];
        }
    }
}


//42.
int unionSet(int N, int v1[N], int v2[N], int r[N]){
    int cont = 0;
    for (int i = 0; i < N; i++) {
        if (v1[i] == 1 || v2[i] == 1) r[i] = 1, cont++;
    }
    return cont;
}


//43.
int intersectSet(int N, int v1[N], int v2[N], int r[N]){
    int cont = 0;
    for (int i = 0; i < N; i++) {
        if (v1[i] == 1 && v2[i] == 1) r[i] = 1, cont++;
    }
    return cont;
}


//44.
int intersectMSet(int N, int v1[N], int v2[N], int r[N]){
    int cont = 0;
    for (int i = 0; i < N; i++) {
        if (v1[i] > 0 && v2[i] > 0){
           if (v1[i] < v2[i]) r[i] = v1[i];
           else r[i] = v2[i];
           cont++;
        }
    }
    return cont;
}


//45.
int unionMSet(int N, int v1[N], int v2[N], int r[N]){
    int cont = 0;
    for (int i = 0; i < N; i++) {
        if (v1[i] > 0 || v2[i] > 0){
            if (v1[i] > v2[i]) r[i] = v1[i];
            else r[i] = v2[i];
            cont++;
        }
    }
    return cont;
}


//46.
int cardinalMSet(int N, int v[N]){
    int cont = 0;
    for (int i = 0; i < N; i++) {
        cont += v[i];
    }
    return cont;
}


typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;


//47.
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    for (int i = 0; i < N; i++) {
        if (mov[i] == Norte) inicial.y += 1;
        else if (mov[i] == Sul) inicial.y -= 1;
        else if (mov[i] == Este) inicial.x += 1;
        else inicial.x -= 1;
    }
    return inicial;
}


//48.
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i = 0;
    for(i = 0; i < N; i++){
        if (inicial.x > final.x) mov[i] = Oeste, inicial.x--;
        else if (inicial.x < final.x) mov[i] = Este, inicial.x++;
        else if (inicial.y < final.y) mov[i] = Norte, inicial.y++;
        else if (inicial.y > final.y) mov[i] = Sul, inicial.y--;
        else return i;
    }
    if (inicial.x == final.x && inicial.y == final.y) return i;
    else return -1;
}


//49.
int maisCentral (Posicao pos[], int N){
    int menor = pos[0].x*pos[0].x + pos[0].y*pos[0].y;
    int indice = 0;
    for (int i = 0; i < N; i++) {
        if (pos[i].x*pos[i].x + pos[i].y*pos[i].y < menor){
            menor = pos[i].x*pos[i].x + pos[i].y*pos[i].y;
            indice = i;
        }
    }
    return indice;
}


//50.
int vizinhos(Posicao p, Posicao pos[], int N){
    int cont = 0;
    for (int i = 0; i < N; i++) {
        if (pos[i].x == p.x+1 && pos[i].y == p.y || pos[i].x == p.x && pos[i].y == p.y+1
         || pos[i].x == p.x && pos[i].y == p.y-1 || pos[i].x == p.x-1 && pos[i].y == p.y)
            cont ++;
    }
    return cont;
}





































int main () {
    char s1[] = "Ollllaaaaaaa";
    char s2[] = "aaaaaaaaaaaaaaaaaaaaaa";
    printf("%d", limpaEspacos(s2));

    return 0;
}