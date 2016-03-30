#include <stdio.h>
#include <string.h>







int *getNum(char *filename, int *s);
int main(){
    char filename[30];
// s[0]: ������  s[1]: ���ַ���  s[2]: �ܵ�����
    int s[3] = {0, 0, 0};
    printf("Input file name: ");
    scanf("%s", filename);
    if(getNum(filename, s)){
        printf("Total: %d lines, %d words, %d chars\n", s[0], s[2], s[1]);
    }
	else{
        printf("Error!\n");
    }
    return 0;
}



int *getNum(char *filename, int *s){
    FILE *fp;  // ָ���ļ���ָ��
    char buf[1011];  //������
    int bufLen;  
    int i;  // �������ĵ�i���ַ�
    char j;  // ��ȡ�����ַ�
    int isLastBlank = 0; 
    int charNum = 0;  // ��ǰ�е��ַ���
    int wordNum = 0; // ��ǰ�еĵ�����
    if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return NULL;
    }
    printf("line   words  chars\n");
    while(fgets(buf, 1011, fp) != NULL){
        bufLen = strlen(buf);
        for(i=0; i<bufLen; i++){
            j = buf[i];
            if( j==' ' || j=='\t'){ 
                !isLastBlank && wordNum++; 
                isLastBlank = 1;
            }else if(j!='\n'&&j!='\r'){  
                charNum++; 
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++;  // ������һ���ַ����ǿո���ô��������1
        isLastBlank = 1;  // ����
        s[0]++;  // ������
        s[1] += charNum;  // ���ַ���
        s[2] += wordNum;  // �ܵ�����
        printf("%-7d%-7d%d\n", s[0], wordNum, charNum);
        charNum = 0;
        wordNum = 0;
    }
    return s;
}
