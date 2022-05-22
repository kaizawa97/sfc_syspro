#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256

struct word {
	struct word *next; //リスト構造
	char *data;
};

int main() {
	char *q, *s;
	char buf[MAXLEN];
	struct word *w, *bw = NULL, *fw = NULL;
	int a = 1;

	while (1) {
		w = malloc(sizeof(struct word)); //メモリ確保 struct wordの大きさ分
		w->next = NULL;
		if (a) {
			fw = w;
			a = 0;
		}
		q = fgets(buf, MAXLEN, stdin); //fgetsにて文字読み込み
		if(q == NULL) {
			break; 
		}
		s = strchr(buf, '\n'); //改行文字取り除く
		if (s != NULL) {
			*s = '\0';
		}

		// 文字列の格納をします
		w->data = malloc(sizeof(char) * (strlen(buf)+1));
		snprintf(w->data, strlen(buf)+1, "%s", buf);

		if (bw != NULL) { // 前のwordと連結
			bw->next = w;
		}
		bw = w;
	}

	w = fw;
	while (1) {
		printf("%s\n", w->data); //表示

		if (w->next == NULL) { //表示できるものが無くなったら終了
			break;
		}
		w = w->next;
	}	
};
