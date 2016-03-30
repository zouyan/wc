#include <stdio.h>
#include <string.h>







int *getNum(char *filename, int *s);
int main(){
    char filename[30];
// s[0]: 总行数  s[1]: 总字符数  s[2]: 总单词数
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
    FILE *fp;  // 指向文件的指针
    char buf[1011];  //缓冲区
    int bufLen;  
    int i;  // 缓冲区的第i个字符
    char j;  // 读取到的字符
    int isLastBlank = 0; 
    int charNum = 0;  // 当前行的字符数
    int wordNum = 0; // 当前行的单词数
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
        !isLastBlank && wordNum++;  // 如果最后一个字符不是空格，那么单词数加1
        isLastBlank = 1;  // 重置
        s[0]++;  // 总行数
        s[1] += charNum;  // 总字符数
        s[2] += wordNum;  // 总单词数
        printf("%-7d%-7d%d\n", s[0], wordNum, charNum);
        charNum = 0;
        wordNum = 0;
    }
    return s;
}
