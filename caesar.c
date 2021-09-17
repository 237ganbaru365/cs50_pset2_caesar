#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // ??_argv[]ってでもstringじゃね
        string k = argv[1];
        for (int i = 0; i < strlen(k); i++)
        {
            if (isdigit(k[i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        printf("Success\n");
        printf("%s\n", k);
        
        //kを整数に変換
        int key = atoi(k);
        
        // ユーザーに文字の入力を求める
        string plain_text = get_string("plaintext: ");
        
        // 
        for (int i = 0; i < strlen(plain_text); i++)
        {
            if (isalpha(plain_text[i]) == 0)
            {
                plain_text[i] = plain_text[i];
            }
            else if (isupper(plain_text[i]))
            {
                plain_text[i] = (plain_text[i] - 65); // ASCII番号 から index番号への変換
                plain_text[i] = (plain_text[i] + key) % 26; // keyを足した後のindex番号
                plain_text[i] = (plain_text[i] + 65); // index番号　から　ASCII番号への変換
                
            }
            else if (islower(plain_text[i]))
            {
                plain_text[i] = (plain_text[i] - 97); // ASCII番号 から index番号への変換
                plain_text[i] = (plain_text[i] + key) % 26; // keyを足した後のindex番号
                plain_text[i] = (plain_text[i] + 97); // index番号　から　ASCII番号への変換
            }
        }
        
        printf("%s\n", plain_text);
        
    }
}