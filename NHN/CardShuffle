#include <stdio.h>
int C;
int P;
int N;
int card[1001];
int temp[1001];
int cc;
int main() {
	scanf("%d", &C);
	scanf("%d", &P);
	for(int i=1; i<=C; i++){
		card[i] = i;
		temp[i] = i;
	}
	for(int i=0; i<P; i++){
		scanf("%d", &N);
		cc = C;
		while(1){
			if(cc <= 2*N){
				break;
			}
			for(int j=1; j<=cc-2*N; j++){
				temp[j] = card[N+j];
			}
			for(int k=1; k<=N; k++){
				temp[cc-2*N+k] = card[k];
			}
			for(int l=1; l<=cc; l++){
				card[l] = temp[l];
			}
			cc = cc-2*N;
		}
	}
    for(int i=1; i<=5; i++){
        printf("%d\n", card[i]);
    }

	return 0;
}
